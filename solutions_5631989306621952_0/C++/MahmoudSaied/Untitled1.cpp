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
            string s;
            cin >> s;
            string alt = "";
            alt += s[0];
            lop(i, s.size() - 1)
            {
                    char ch = s[i];
                    if(ch >= alt[0])
                    {
                            alt.insert(0, 1, ch);
                    }
                    else
                    {
                            alt += ch;
                    }
            }
            cout << alt << "\n";

    }
    return 0;
}
