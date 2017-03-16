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
int n;
LL ansdiff, ansc, ansj;
void solve(LL c, LL j, int i, int cmp)
{
    if(i == n)
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
        return ;
    }
    if(cmp == 0)//C == J
    {
        if(C[i] != '?' && J[i] != '?')
        {
            if(C[i] == J[i])
                solve(c * 10 + C[i] - '0', j * 10 + J[i] - '0', i + 1, 0);
            else if(C[i] < J[i])
                solve(c * 10 + C[i] - '0', j * 10 + J[i] - '0', i + 1, -1);
            else
                solve(c * 10 + C[i] - '0', j * 10 + J[i] - '0', i + 1, 1);
        }
        else if(C[i] != '?')
        {
            solve(c * 10 + C[i] - '0', j * 10 + C[i] - '0', i + 1, 0);
            if(C[i] != '9') solve(c * 10 + C[i] - '0', j * 10 + C[i] - '0' + 1, i + 1, -1);
            if(C[i] != '0') solve(c * 10 + C[i] - '0', j * 10 + C[i] - '0' - 1, i + 1, 1);
        }
        else if(J[i] != '?')
        {
            solve(c * 10 + J[i] - '0', j * 10 + J[i] - '0', i + 1, 0);
            if(J[i] != '0') solve(c * 10 + J[i] - '0' - 1, j * 10 + J[i] - '0', i + 1, -1);
            if(J[i] != '9') solve(c * 10 + J[i] - '0' + 1, j * 10 + J[i] - '0', i + 1, 1);
        }
        else
        {
            solve(c * 10, j * 10, i + 1, 0);
            solve(c * 10, j * 10 + 1, i + 1, -1);
            solve(c * 10 + 1, j * 10, i + 1, 1);
        }
    }
    else if(cmp < 0)//C < J
    {
        char tmpC, tmpJ;
        if(C[i] == '?')
            tmpC = '9';
        else
            tmpC = C[i];
        if(J[i] == '?')
            tmpJ = '0';
        else
            tmpJ = J[i];
        solve(c * 10 + tmpC - '0', j * 10 + tmpJ - '0', i + 1, -1);
    }
    else//C > j
    {
        char tmpC, tmpJ;
        if(C[i] == '?')
            tmpC = '0';
        else
            tmpC = C[i];
        if(J[i] == '?')
            tmpJ = '9';
        else
            tmpJ = J[i];
        solve(c * 10 + tmpC - '0', j * 10 + tmpJ - '0', i + 1, 1);
    }
}
int main()
{
#ifdef ACM_TEST
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
#endif
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        scanf("%s%s", C, J);
        n = strlen(C);
        ansdiff = 0x3f3f3f3f3f3f3f3fll;
        solve(0, 0, 0, 0);
        for(int i = n - 1; i >= 0; --i)
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
