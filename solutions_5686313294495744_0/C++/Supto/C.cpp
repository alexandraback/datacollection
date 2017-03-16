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
pair < string, string> nam[17];
char a[25], b[25];
map <string, int> _map1, _map2;
int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output1.txt", "w", stdout);
    int ncase, tcase = 1, i, j, n;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%s %s", a, b);
            nam[i] = make_pair(a, b);
        }
        int lim = 1<<n;
        int ans = 0;
        for(i = 1; i < lim; i++)
        {
            _map1.clear();
            _map2.clear();
            int cnt = 0;
            for(j = 0; j < n; j++)
            {
                if(i&(1<<j))
                {
                    _map1[nam[j].ff] = 1;
                    _map2[nam[j].ss] = 1;
                    cnt++;
                }
            }
            int cnt1 = 0;
            for(j = 0; j < n; j++)
            {
                if(!(i&(1<<j)))
                {
                    if(_map1.find(nam[j].ff) == _map1.end() || _map2.find(nam[j].ss) == _map2.end()) break;
                    cnt1++;
                }
            }
            if(cnt + cnt1 == n) ans = max(ans, cnt1);
        }
        printf("Case #%d: %d\n", tcase++, ans);
    }
    return 0;
}

