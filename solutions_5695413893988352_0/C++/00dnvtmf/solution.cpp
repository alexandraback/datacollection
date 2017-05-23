//writed by dnvtmf
#include <bits/stdc++.h>
#define INF 1000000007
#define FI first
#define SE second
#define PB push_back
#define VI vector<int>
using namespace std;
typedef long long LL;
typedef pair <int, int> P;
const int NUM = 100010;
char C[100], J[100];
int ansdiff, ansc, ansj;
void solve(int c, int j, int i, int is_c)
{
    if(is_c)
    {
        if(C[i] == '\0')
        {
            solve(c, j, 0, 0);
        }
        else
        {
            if(C[i] == '?')
            {
                for(int k = 0; k <= 9; ++k)
                {
                    solve(c * 10 + k, j, i + 1, is_c);
                }
            }
            else
            {
                solve(c * 10 + C[i] - '0', j, i + 1, is_c);
            }
        }
    }
    else
    {
        if(J[i] == '\0')
        {
            if(abs(c - j) < ansdiff)
            {
                ansdiff = abs(c - j);
                ansc = c;
                ansj = j;
            }
            else if(abs(c - j) == ansdiff)
            {
                if(c < ansc)
                {
                    ansc = c;
                    ansj = j;
                }
                else if(c == ansc && j < ansj)
                {
                    ansj = j;
                }
            }
        }
        else
        {
            if(J[i] == '?')
            {
                for(int k = 0; k < 10; ++k)
                {
                    solve(c, j * 10 + k, i + 1, is_c);
                }
            }
            else
            {
                solve(c, j * 10 + J[i] - '0', i + 1, is_c);
            }
        }
    }
}
int main()
{
#ifdef ACM_TEST
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        scanf("%s%s", C, J);
        ansdiff = INF;
        solve(0, 0, 0, 1);
        int len = strlen(C);
        for(int i = len - 1; i >= 0; --i)
        {
            C[i] = ansc % 10 + '0';
            ansc /= 10;
            J[i] = ansj % 10 + '0';
            ansj /= 10;
        }
        printf("Case #%d: %s %s\n", cas, C, J);
    }
    return 0;
}
