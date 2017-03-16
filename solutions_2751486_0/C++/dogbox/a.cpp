#include <iostream>
#include <vector>

using namespace std;

const int N = 1000000;
char s[N + 5];
int ct[N + 5];
int len;
int n;

vector<int> vstarts;
vector<int> vends;

bool is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    int T; scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        vstarts.clear();
        vends.clear();
        scanf("%s %d", s, &n);
        len = strlen(s);
        for (int i = 0; i < len; i++) {
            int it = i;
            while (!is_vowel(s[it]) && it < len) {
                it++;
            }
            if (it - i >= n) {
                vstarts.push_back(i);
                vends.push_back(it);
                i = it;
            }
        }
        long long res = 0;
        for (int i = 0; i < vstarts.size(); i++) {
            long long start = vstarts[i];
            long long end = vends[i];

            // from left to start
            long long left = 0;
            if (i != 0) {
                left = vends[i - 1] - n + 1;
            }
            long long mult = start - left;
            long long tail = len - (start + n) + 1;
            res += mult * tail;

            // from start to end - n
            for (int j = start; j <= end - n; j++) {
                res += len - (j + n) + 1;
            }
            left = end;
        }

        printf("Case #%d: %lld\n", test, res);
    }
}