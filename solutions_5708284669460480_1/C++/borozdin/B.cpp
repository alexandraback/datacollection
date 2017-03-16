#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 105;
const int A = 26;
const int INF = (int) 1e9;

int k, l, s;
string keyboard;
string word;

long double char_prob[A];
int pi[N];
int go[N][A];

int dp_max[N][N];
long double dp_me[N][N];
long double dp_prob[N][N];

void calc_go()
{
    for (int i = 1; i < l; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && word[i] != word[j])
            j = pi[j - 1];
        if (word[i] == word[j])
            j++;
        pi[i] = j;
    }

    for (int len = 0; len <= l; len++)
    {
        int pref = (len == 0 ? 0 : pi[len - 1]);
        for (int c = 0; c < A; c++)
        {
            if (len < l && word[len] == c + 'A')
                go[len][c] = len + 1;
            else
                go[len][c] = go[pref][c];
        }
    }
}

void maximize(int & a, int b)
{
    a = max(a, b);
}

void solve()
{
    memset(go, 0, sizeof(go));
    memset(char_prob, 0, sizeof(char_prob));

    cin >> k >> l >> s;
    cin >> keyboard >> word;

    for (char c : keyboard)
        char_prob[c - 'A']++;
    for (int i = 0; i < A; i++)
        char_prob[i] /= k;

    calc_go();

    for (int len = 0; len <= s; len++)
        for (int pref = 0; pref <= l; pref++)
            dp_max[len][pref] = -INF;
    dp_max[0][0] = 0;

    for (int len = 0; len < s; len++)
        for (int pref = 0; pref <= l; pref++)
        {
            int val = dp_max[len][pref];
            if (val == INF)
                continue;

            for (int c = 0; c < A; c++)
                if (char_prob[c] > 0)
                {
                    int to = go[pref][c];
                    maximize(dp_max[len + 1][to], val + (to == l));
                }
        }

    int allover_max = *max_element(dp_max[s], dp_max[s] + l + 1);

    for (int len = 0; len <= s; len++)
        for (int pref = 0; pref <= l; pref++)
            dp_me[len][pref] = dp_prob[len][pref] = 0;
    dp_prob[0][0] = 1;

    for (int len = 0; len < s; len++)
        for (int pref = 0; pref <= l; pref++)
        {
            long double me = dp_me[len][pref];
            long double p = dp_prob[len][pref];

            for (int c = 0; c < A; c++)
            {
                int to = go[pref][c];
                long double to_prob = char_prob[c];

                dp_prob[len + 1][to] += p * to_prob;
                if (to == l)
                    dp_me[len + 1][to] += (me + p) * to_prob;
                else
                    dp_me[len + 1][to] += me * to_prob;
            }
        }

    long double sum = 0;
    for (int pref = 0; pref <= l; pref++)
        sum += dp_me[s][pref];

    printf("%.10lf\n", (double) (allover_max - sum));
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("Case #%d: ", i + 1);
        solve();
    }

    eprintf("time = %.3lf\n", (double) clock() / CLOCKS_PER_SEC);

    return 0;
}
