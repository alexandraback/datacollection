#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){ if (x>t) t=x;}
template <class T> void checkmin(T &t, T x){ if (x<t) t=x;}
template <class T> void _checkmax(T &t, T x){ if (t==-1 || x>t) t=x;}
template <class T> void _checkmin(T &t, T x){ if (t==-1 || x<t) t=x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it=(v).begin(); it!=(v).end(); ++it)
#define clr(a, b) memset(a, b, sizeof(a))
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define sz(a) ((int)(a).size())
#define pb push_back
#define itr iterator

int i,j,k,m,n,l;


ll gao(ll a, int x, ll b, int y, ll c, int z){
	ll ret=1;
	rep(i, z){
		int k=1;
		if (i<x) ret*=2;
		if (i<y) ret*=2;
	}
	repf(i, z, l){
		if (c&(1ll<<i)){
			if (i>=x && !(a&(1ll<<i))) return 0;
			if (i>=y && !(b&(1ll<<i))) return 0;
		}
		else{

			if (i>=x){
				if (a&(1ll<<i)){
					if (i>=y){
						if (b&(1ll<<i)){
						   	return 0;
							
						}
					}
				}
				else{
					if (i<y) ret*=2;
				}
			}
			else{
				if (i<y) ret*=3;
				else if (!(b&(1ll<<i))) ret*=2;
			}

		}
	}
	
	return ret;
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int ts;
	scanf("%d", &ts);
	repf(te, 1, ts){
		ll a, b, c, x=0, y=0, z=0, n=0;
		cin>>a>>b>>c;

		ll k=max(a, max(b, c));
		l=0;
		while (k) k>>=1, l++;


		repd(i, l, 0) if ((1ll<<i)&a){
			y=0;
			repd(j, l, 0) if ((1ll<<j)&b){
				z=0;
				repd(k, l, 0) if ((1ll<<k)&c){
					n+=gao(x, i, y, j, z, k);
					z+=(1ll<<k);
				}
				y+=(1ll<<j);
			}
			
			x+=(1ll<<i);
		}
		

		printf("Case #%d: %lld\n",te, n);
	}
	return 0;
}

