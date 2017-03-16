#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<climits>
#include<cassert>
#include<time.h>

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define ss second
#define ff first
#define vi vector<int>
#define vl vector<ll>
#define s(n) scanf("%d",&n)
#define ll long long
#define mp make_pair
#define PII pair <int ,int >
#define PLL pair<ll,ll>
#define inf 1000*1000*1000+5
#define v(a,size,value) vi a(size,value)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define tri pair < int , PII >
#define TRI(a,b,c) mp(a,mp(b,c))
#define xx ff
#define yy ss.ff
#define zz ss.ss
#define in(n) n = inp()
#define vii vector < PII >
#define vll vector< PLL >
#define viii vector < tri >
#define vs vector<string>
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define ok if(debug)
#define trace1(x) ok cerr << #x << ": " << x << endl;
#define trace2(x, y) ok cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)    ok      cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)  ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                << #d << ": " << d << endl;
#define trace5(a, b, c, d, e) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                     << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
                                    << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout)
ll MOD = int(1e9) + 7;

int debug = 1;
const int N = int(1e6) + 5;
using namespace std;
void sub(int freq[300],string a,int cnt)
{
        int i;
        rep(i,sz(a))
        freq[a[i]] -= cnt;
}
int main()
{
        int i,j,n,t;
        ios::sync_with_stdio(false);
        cin>>t;
        int t1 = t;
        while(t--)
        {
                string s;
                cin>>s;
                int freq[300] = {0};
                rep(i,sz(s))freq[s[i]]++;
                int cnt[10] = {0};
                cnt[0] = freq['Z'];
                sub(freq,"ZERO",cnt[0]);
                cnt[2] = freq['W'];
                sub(freq,"TWO",cnt[2]);
                cnt[6] = freq['X'];
                sub(freq,"SIX",cnt[6]);
                cnt[7] = freq['S'];
                sub(freq,"SEVEN",cnt[7]);
                cnt[5] = freq['V'];
                sub(freq,"FIVE",cnt[5]);
                cnt[4] = freq['F'];
                sub(freq,"FOUR",cnt[4]);
                cnt[8] = freq['G'];
                sub(freq,"EIGHT",cnt[8]);
                cnt[3] = freq['T'];
                sub(freq,"THREE",cnt[3]);
                cnt[1] = freq['O'];
                sub(freq,"ONE",cnt[1]);
                cnt[9] = freq['I'];
                cout<<"Case #"<<t1-t<<": ";
                rep(i,10)
                rep(j,cnt[i])cout<<i;
                cout<<endl;
        }
}
