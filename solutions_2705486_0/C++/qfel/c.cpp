#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <string>
#include <algorithm>

const int p = 15485867;
const int b = 26;
const int inf = 1000000000;

std::vector<std::string> index_long[3][b * b];  // ?CC, C?C, CC?
bool index_2[b * b];  // CC
bool index_2_0[b]; // ?C
bool index_2_1[b]; // C?
bool index_1[b];

void load_dict() {
    char w[12];
    FILE *f = fopen("garbled_email_dictionary.txt", "rb");
    int c = 0;
    while (fscanf(f, "%s", w) == 1) {
        if (w[1]) {
            if (w[2]) {
                index_long[0][w[1] - 'a' + b * (w[2] - 'a')].push_back(w);
                index_long[1][w[0] - 'a' + b * (w[2] - 'a')].push_back(w);
                index_long[2][w[0] - 'a' + b * (w[1] - 'a')].push_back(w);
            } else {
                index_2[w[0] - 'a' + b * (w[1] - 'a')] = true;
                index_2_0[w[1] - 'a'] = true;
                index_2_1[w[0] - 'a'] = true;
            }
        } else {
            index_1[w[0] - 'a'] = true;
        }
        c++;
    }

    assert(c == 521196);
    fclose(f);
}

int try_word(const char *s, const char *w) {

}

int T[4001][5];
char s[4001];

void process_long(int start, const std::vector<std::string> &words) {
    for (std::vector<std::string>::const_iterator it = words.begin();
         it != words.end(); it++) {
        int first_change = 5;
        int last_change;
        int c = 0;
        for (int i = 0; i < it->length(); i++) {
            if (s[start + i] != (*it)[i]) {
                if (c == 0) {
                    first_change = last_change = i;
                } else if (i - last_change < 5) {
                    c = inf;
                    break;
                }
                c++;
            }
        }

        for (int i = 0; i <= first_change; i++) {
            T[start][i] = std::min(
                T[start][i],
                c + T[start + it->length()][std::max(0,
                                                     i - (int)it->length())]);
        }
    }
}

int solve() {
    scanf("%s", s);
    int n = strlen(s);
    std::fill(T[n], T[n] + 5, 0);
    for (int i = n - 1; i >= 0; i--) {
        if (index_1[s[i] - 'a']) {
            T[i][0] = T[i][1] = T[i + 1][0];
            T[i][2] = T[i + 1][1];
            T[i][3] = T[i + 1][2];
            T[i][4] = T[i + 1][3];
        } else {
            T[i][0] = 1 + T[i + 1][4];
            T[i][1] = T[i][2] = T[i][3] = T[i][4] = inf;
        }
        if (n - i >= 2) {
            if (index_2[s[i] - 'a' + b * (s[i + 1] - 'a')]) {
                T[i][0] = std::min(T[i][0], T[i + 2][0]);
                T[i][1] = std::min(T[i][1], T[i + 2][0]);
                T[i][2] = std::min(T[i][2], T[i + 2][0]);
                T[i][3] = std::min(T[i][3], T[i + 2][1]);
                T[i][4] = std::min(T[i][4], T[i + 2][2]);
            }
            if (index_2_0[s[i + 1] - 'a'])
                T[i][0] = std::min(T[i][0], 1 + T[i + 2][0]);
            if (index_2_1[s[i] - 'a']) {
                T[i][0] = std::min(T[i][0], 1 + T[i + 2][0]);
                T[i][1] = std::min(T[i][1], 1 + T[i + 2][0]);
            }
            if (n - i >= 3) {
                process_long(
                    i,
                    index_long[0][s[i + 1] - 'a' + b * (s[i + 2] - 'a')]);
                process_long(
                    i,
                    index_long[1][s[i] - 'a' + b * (s[i + 2] - 'a')]);
                process_long(
                    i,
                    index_long[2][s[i] - 'a' + b * (s[i + 1] - 'a')]);
            }
        }
        for (int j = 3; j >= 0; j--) // ?
            T[i][j] = std::min(T[i][j], T[i][j + 1]);
    }
    return T[0][0];
}

int main() {
    int n;
    load_dict();
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        printf("Case #%d: %d\n", i, solve());
    return 0;
}
