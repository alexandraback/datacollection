#include <bits/stdc++.h>
using namespace std;
#define D(x) cerr<<#x " = "<<(x)<<endl
#define pb push_back
#define ff first
#define ss second
#define mem(a) memset(a,0,sizeof(a))
#define _set(a) memset(a,-1,sizeof(a))
typedef long long int ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define eps 1e-9
#define MAX 100000
#define MAXL 20
#define MAXE 100000
//ll mod = 1000000000+7;
//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};
char s[2005];
int fr[30];
int ans[10];
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int ncase, tcase = 1, n, i, j, k;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%s", s);
        int l = strlen(s);
        mem(fr);
        mem(ans);
        for(i = 0; i < l; i++) fr[s[i]-65]++;
        if(fr['Z'-65])
        {
            ans[0] = fr['Z'-65];
            fr['E'-65] -= fr['Z'-65];
            fr['R'-65] -= fr['Z'-65];
            fr['O'-65] -= fr['Z'-65];
            fr['Z'-65] = 0;
        }
        if(fr['W'-65])
        {
            ans[2] = fr['W'-65];
            fr['T'-65] -= fr['W'-65];
            fr['O'-65] -= fr['W'-65];
            fr['W'-65] = 0;
        }
        if(fr['G'-65])
        {
            ans[8] = fr['G'-65];
            fr['I'-65] -= fr['G'-65];
            fr['E'-65] -= fr['G'-65];
            fr['H'-65] -= fr['G'-65];
            fr['T'-65] -= fr['G'-65];
            fr['G'-65] = 0;
        }
        if(fr['U'-65])
        {
            ans[4] = fr['U'-65];
            fr['F'-65] -= fr['U'-65];
            fr['O'-65] -= fr['U'-65];
            fr['R'-65] -= fr['U'-65];
            fr['U'-65] = 0;
        }
        if(fr['X'-65])
        {
            ans[6] = fr['X'-65];
            fr['S'-65] -= fr['X'-65];
            fr['I'-65] -= fr['X'-65];
            fr['X'-65] = 0;
        }
        if(fr['F'-65])
        {
            ans[5] = fr['F'-65];
            fr['I'-65] -= fr['F'-65];
            fr['V'-65] -= fr['F'-65];
            fr['E'-65] -= fr['F'-65];
            fr['F'-65] = 0;
        }
        if(fr['S'-65])
        {
            ans[7] = fr['S'-65];
            fr['E'-65] -= 2*fr['S'-65];
            fr['V'-65] -= fr['S'-65];
            fr['N'-65] -= fr['S'-65];
            fr['S'-65] = 0;
        }
        ans[1] = fr['O'-65];
        ans[9] = fr['I'-65];
        ans[3] = fr['H'-65];
        printf("Case #%d: ", tcase++);
        for(i = 0; i < 10; i++)
        {
            for(int j = 0; j < ans[i]; j++) printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}
