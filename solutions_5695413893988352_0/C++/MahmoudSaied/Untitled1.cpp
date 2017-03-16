#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fore(i,n) for(int i = 0; i< n ; i++ )
#define lop(i,n) for(int i = 1 ; i<=n ; i++ )
#define ops(i,n) for(int  i = n-1 ; i>=0 ; i-- )
#define forall( it,g )  for( typeof(g.begin()) it=g.begin();it!=g.end();it++ )
#define PI  3.141592653589793
#define mod  1000000007
#define inf 2000000000
#define INF -2000000000000000
#define modulo 1000000009
#define MH 1234533333333337
#define MH2 7779845079489377
#define enter endl
//ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;
typedef vector <int> vi;
typedef vector <vector <int> > vv;
typedef vector <pair <int,int > >vp;
typedef vector <vector <pair <int ,int > > > vvp;
typedef vector <pair <int ,pair <int ,int > > > vpp;
typedef pair<int,int> pp;
typedef long long ll;
typedef unsigned long long ull;
string x, y;
int mi = 100000000;
map<pair<string, string>, bool> dp;
void ways(int n, string aa, string bb)
{
        if(n == aa.size())
        {
                int X = atoi(aa.c_str()), Y = atoi(bb.c_str());
                int d = abs(X - Y);
                if(d < mi)
                {
                        mi = d;
                        x = aa, y = bb;
                }
                else if(d == mi)
                {
                        if(X < atoi(x.c_str()))
                        {
                                x = aa;
                                y = bb;
                        }
                        else if(X == atoi(x.c_str()) && Y < atoi(y.c_str()))
                        {
                                y = bb;
                        }
                }
                return;
        }
        if(dp.find(mp(aa, bb)) != dp.end())
        {
                return;
        }
        fore(i, 10)
        {
                fore(j, 10)
                {
                        string alt1 = aa, alt2 = bb;
                        if(aa[n] == '?')
                        {
                                alt1[n] = i + '0';
                        }
                        if(bb[n] == '?')
                        {
                                alt2[n] = j + '0';
                        }
                        ways(n + 1, alt1, alt2);
                }
        }
        dp[mp(aa, bb)] = true;

}
int main()
{
        //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        freopen("1.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        int t, cases = 0;
        scanf("%d", &t);
        while(t--)
        {
                cases++;
                printf("Case #%d: ", cases);
                string a, b;
                cin >> a >> b;
                ways(0, a, b);
                cout << x << " " << y << "\n";
                mi = 1000000;
                x = "", y = "";
                dp.clear();
        }
        return 0;
}
