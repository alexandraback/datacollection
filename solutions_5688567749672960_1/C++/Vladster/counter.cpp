#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define INP_FILE "A-large.in"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
//#define x first 
#define y second
#define inf 1000000000
#define vi vector<int>
#define vvi vector<vi >
#define ll long long
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int

ll rev(ll x)
{
    ll c = 0;
    while(x) {
        c = c*10 + (x%10);
        x/=10;
    }
    return c;
}

int solve1(ll x)
{
    if (x<10) return x;
    if (x%10==0) return solve1(x-1)+1;
    ll cc = 1; while(cc<=x) cc*=10; cc/=10;
    if (x==cc+1) return solve1(x-2)+2;
    ll z= 1;
    ll c=cc;
    ll best = x;
    ll rx= rev(x);
    while(rx) {
        ll t = x % z;
        if (t>0) {
            ll cand = t-1;
            if (rx>1) { cand+= rx;}
            best=min(best,cand);
        }
        z*=10;
        rx %= c;
        c/=10;
        
    }
    return solve1(cc-1)+best+2;
}

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
        ll n;cin>>n;
        ll ans = solve1(n);
        printf("Case #%d: %ld\n",tst, ans);
		//printf("Case #%d: ",tst);
	}
	
	return 0;
}