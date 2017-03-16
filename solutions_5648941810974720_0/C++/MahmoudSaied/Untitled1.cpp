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
const int M = 300;
int c[M];
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
                vi ans;
                string s;
                cin >> s;
                fore(i, s.size())
                {
                        c[s[i] - 'A']++;
                }
                printf("Case #%d: ", cases);
                int x = c[25];
                if(x)
                {
                       fore(i, x)
                       {
                               ans.pb(0);
                       }
                       c['E' - 'A']-=x;
                       c['R' - 'A']-=x;
                       c['O' - 'A']-=x;
                       c[25] = 0;
                }
                x = c['X' - 'A'];
                if(x)
                {
                        fore(i, x)
                        {
                                ans.pb(6);
                        }
                        c['S' - 'A']-=x;
                        c['I' - 'A']-=x;
                        c['X' - 'A'] = 0;
                }
                x = c['S' - 'A'];
                if(x)
                {
                        fore(i, x)
                        {
                                ans.pb(7);
                        }
                        c['E' - 'A']-=2 * x;
                        c['V' - 'A']-=x;
                        c['N' - 'A']-=x;
                        c['S' - 'A'] = 0;
                }
                x = c['V' - 'A'];
                if(x)
                {
                        fore(i, x)
                        {
                                ans.pb(5);
                        }
                        c['F' - 'A']-=x;
                        c['I' - 'A']-=x;
                        c['E' - 'A']-=x;
                        c['V' - 'A'] = 0;
                }

                x = c['F' - 'A'];
                if(x)
                {
                        fore(i, x)
                        {
                                ans.pb(4);
                        }
                        c['O' - 'A']-=x;
                        c['U' - 'A']-=x;
                        c['R' - 'A']-=x;
                        c['F' - 'A'] = 0;
                }

                x = c['W' - 'A'];
                if(x)
                {
                        fore(i, x)
                        {
                                ans.pb(2);
                        }
                        c['T' - 'A']-=x;
                        c['O' - 'A']-=x;
                        c['W' - 'A'] = 0;
                }

                x = c['R' - 'A'];
                if(x)
                {
                        fore(i, x)
                        {
                                ans.pb(3);
                        }
                        c['E' - 'A']-=2 * x;
                        c['T' - 'A']-=x;
                        c['H' - 'A']-=x;
                        c['R' - 'A'] = 0;
                }

                x = c['G' - 'A'];
                if(x)
                {
                        fore(i, x)
                        {
                                ans.pb(8);
                        }
                        c['E' - 'A']-=x;
                        c['I' - 'A']-=x;
                        c['H' - 'A']-=x;
                        c['T' - 'A']-=x;
                        c['G' - 'A'] = 0;
                }

                x = c['I' - 'A'];
                if(x)
                {
                        fore(i, x)
                        {
                                ans.pb(9);
                        }
                        c['N' - 'A']-=2 * x;
                        c['E' - 'A']-=x;
                        c['I' - 'A'] = 0;
                }
                x = c['O' - 'A'];
                if(x)
                {
                        fore(i, x)
                        {
                                ans.pb(1);
                        }

                }
                sort(ans.begin(), ans.end());
                fore(i, ans.size())
                {
                        cout << ans[i];
                }
                cout << "\n";
                memset(c, 0, sizeof c);
        }
        return 0;
}
