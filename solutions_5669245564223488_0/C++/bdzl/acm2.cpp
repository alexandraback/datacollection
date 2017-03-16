#include <iostream>

#include <cstring>
using namespace std;

typedef long long ll;

const int modulo = 1e9 + 7;

const int max_s = 111;
const int max_n = 111;
const int max_c = 26;

int n;
char s[max_n][max_s];
int len[max_n];

int answer;

int used_c[max_c];

int fact[max_n];

int left_in[max_n][max_c];
int right_in[max_n][max_c];

int cmiddle[max_c];
int cinside[max_c];
int cleft[max_c];
int cright[max_c];

int left_neig[max_c];

/*
int order[max_n];

int used[max_n];
int answer2;

bool check()
{
    for (int c = 0; c < max_c; ++c) used_c[c] = 0;
    char last = s[order[0]][0];
    used_c[last - 'a'] = 1;
    for (int i = 0; i < n; ++i) {
        int id = order[i];
        for (int j = (i == 0); j < len[id]; ++j)
            if (s[id][j] != last) {
                last = s[id][j];
                if (used_c[last - 'a']) return false;
                used_c[last - 'a'] = 1;
            }
    }
    return true;
}

void dfs(int v)
{
    if (v == n) {
        if (check()) {
            ++answer2;
        }
        return ;
    }
    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            used[i] = 1;
            order[v] = i;
            dfs(v + 1);
            used[i] = 0;
        }
}
*/
int main()
{
    fact[0] = 1;
    for (int i = 1; i < max_n; ++i)
        fact[i] = (1LL * fact[i - 1] * i) % modulo;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    scanf("%d\n", &tests);
    for (int test = 1; test <= tests; ++test) {
        printf("Case #%d: ", test);
        scanf("%d\n", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
            len[i] = strlen(s[i]);
        }
        scanf("\n");
        /*
        answer2 = 0;
        for (int i = 0; i < n; ++i) used[i] = 0;
        dfs(0);
        printf("%d ", answer2);
        */
        bool good = true;
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c < max_c; ++c)
                left_in[i][c] = right_in[i][c] = -1;
            for (int j = 0; j < len[i]; ++j) {
                int c = s[i][j] - 'a';
                if (left_in[i][c] == -1) {
                    left_in[i][c] = right_in[i][c] = j;
                } else {
                    if (right_in[i][c] + 1 != j) {
                        good = false;
                        break;
                    } else {
                        ++right_in[i][c];
                    }
                }
            }
        }
        if (!good) {
            printf("0\n");
            continue;
        }
        for (int c = 0; c < max_c; ++c) 
            cmiddle[c] = cinside[c] = cleft[c] = cright[c] = 0;
        for (int i = 0; i < n; ++i)
            for (int c = 0; c < max_c; ++c)
                if (left_in[i][c] == 0 && right_in[i][c] == len[i] - 1) {
                    ++cmiddle[c];
                } else if (left_in[i][c] == 0) {
                    ++cleft[c];
                } else if (right_in[i][c] == len[i] - 1) {
                    ++cright[c];
                } else if (left_in[i][c] != -1 && right_in[i][c] != -1) {
                    ++cinside[c];
                }
        for (int c = 0; c < max_c; ++c)
            if (cinside[c] > 0) {
                if (cinside[c] > 1 || cmiddle[c] + cleft[c] + cright[c] > 0) {
                    good = false;
                    break;
                }
            } else if (cleft[c] > 1 || cright[c] > 1) {
                good = false;
                break;
            }
        if (!good) {
            printf("0\n");
            continue;
        }
        for (int c = 0; c < max_c; ++c)
            if (cinside[c] > 0)
                used_c[c] = 1;
            else if (cmiddle[c] + cleft[c] + cright[c] == 0)
                used_c[c] = 1;
            else {
                used_c[c] = 0;
            }
        answer = 1;
        for (int c = 0; c < max_c; ++c)
            left_neig[c] = -1;
        for (int i = 0; i < n; ++i)
            for (int c = 0; c < max_c; ++c)
                if (!used_c[c] && right_in[i][c] == len[i] - 1 && left_in[i][c] != 0) {
                    left_neig[c] = (s[i][0] - 'a');
                }
        int gs = 0;
        for (int c = 0; c < max_c; ++c) 
            if (!used_c[c] && cleft[c] == 0 && cright[c] == 0) {
                answer = (1LL * answer * fact[cmiddle[c]]) % modulo;
                used_c[c] = 1;
                ++gs;
            }
        for (int c = 0; c < max_c; ++c)
            if (!used_c[c] && left_neig[c] != -1 && cleft[c] == 0) {
                int gc = c;
                while (gc != -1) {
                    answer = (1LL * answer * fact[cmiddle[gc]]) % modulo;
                    used_c[gc] = 1;
                    gc = left_neig[gc];
                }
                ++gs;
            }
        answer = (1LL * answer * fact[gs]) % modulo;
        for (int c = 0; c < max_c; ++c)
            if (!used_c[c]) {
                answer = 0;
                break;
            }
        printf("%d\n", answer);
    }

    return 0;
}
