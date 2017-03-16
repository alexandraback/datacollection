//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 
// Verdict: 
//******************************************************************
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

int tcs;
string s;
int n;
int ch[500];
int cnt[105];

void init()
{
    for(int i = 'a' ; i <= 'z' ; i++)
        ch[i] = 1;
    ch['a'] = ch['e'] = ch['i'] = ch['o'] = ch['u'] = 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("A.INP","r",stdin);
    freopen("A.OUT","w",stdout);
    #endif
    
    init();
    read(tcs);
    fr(t,1,tcs)
    {
        printf("Case #%d: ",t);
        read2(s,n);
        
        vector<ll> v;
        
        cnt[0] = ch[s[0]];
        //DEBUG(ch['a']);
        //DEBUG(cnt[0]);
        fr(i,1,sz(s)-1)
        {
            //DEBUG(s[i]);
            cnt[i] = cnt[i-1] + ch[s[i]];
            //DEBUG(i);
            //DEBUG(cnt[i]);
        }
        
        rep(i,sz(s)-n+1) 
            if(ch[s[i]] == 1 && ch[s[i+n-1]] == 1 && (cnt[i+n-1] - cnt[i] == n-1))
            {
                v.pb(i);
            }
        
        ll ans = 0;
        
        rep(i,sz(v))
        {
            ll start = v[i];
            //DEBUG(start);
            ll end = v[i] + n - 1;
            
            if(i == 0)
            {
                ans += (start+1)*(sz(s) - end);
            }
            else ans += (start - v[i-1]) * (sz(s) - end); 
            //DEBUG(ans);
        }
        
        cout << ans << endl;
    }
    

    return 0;
}