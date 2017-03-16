#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

const int MAXN = 26;
const int MAXM = 10;

int T, K, L, S;
double res;
bool is_sa;
int src[MAXN], tar[MAXN];
char key[MAXM], word[MAXM], qua[MAXM << 1];

bool check(int x)
{
    for (int i = 0; i < L; i++) {
        if (word[i] != qua[x + i])
            return false;
    }
    return true;
}

double add_qua(double p)
{
    int num = 0;
    for (int i = 0; i <= S - L; i++) {
        if (check(i))
            num++;
    }
    return num * p;
}

void dfs(int x, double p)
{
    if (x >= S) {
        res += add_qua(p);
        return;
    }
    for (int i = 0; i < MAXN; i++) {
        if (src[i]) {
            qua[x] = i + 'A';
            dfs(x + 1, p * (double)src[i] / K);
        }
    }
}

int max_num(void)
{
    if (is_sa)
        return S - L + 1;
    if (L == 2)
        return S / 2;
    int k;
    for (k = L - 1; k > 0; k--) {
        int i = 0, j = L - k;
        while (j < L && word[i] == word[j])
            i++, j++;
        if (j >= L)
            break;
    }
    if (k <= 0)
        return S / L;
    else
        return (S - L) / (L - k) + 1;
}

int main(void)
{
    scanf("%d", &T);
    for (int cases = 1; cases <= T; cases++) {
        scanf("%d %d %d", &K, &L, &S);
        scanf("%s %s", key, word);
        memset(src, 0, sizeof(src));
        for (int i = 0; i < K; i++)
            src[key[i] - 'A']++;
        memset(tar, 0, sizeof(tar));
        tar[word[0] - 'A'] = 1;
        is_sa = true;
        for (int i = 1; i < L; i++) {
            if (word[i] != word[i - 1])
                is_sa = false;
            tar[word[i] - 'A']++;
        }
        int i;
        for (i = 0; i < MAXN; i++) {
            if (tar[i] && !src[i])
                break;
        }
        if (i < MAXN) {
            printf("Case #%d: 0.0\n", cases);
            continue;
        }
        res = 0.0;
        dfs(0, 1.0);
        printf("Case #%d: %lf\n", cases, max_num() - res);
    }
    return EXIT_SUCCESS;
}