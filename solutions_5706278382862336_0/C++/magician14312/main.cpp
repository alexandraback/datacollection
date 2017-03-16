#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <fstream>
#include <ctime>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOD(i,a,b) for(int i=a;i>b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl

using namespace std;

typedef pair<int,int>II;
typedef pair<int,II>PII;
template<class T> T gcd(T a, T b) {T r; while(b!=0) {r=a%b;a=b;b=r;} return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }

const double PI = 2*acos(0.0);
const double eps = 1e-9;
const int infi = 1e9;
const LL Linfi = (LL) 1e18;
const int MOD = 1000000007;
#define maxn 500005


LL P, Q;
LL POW[50];

void Init(){
	POW[0] = 1;
	FOR(i,1,40) POW[i] = POW[i-1]*2;
}

void solve(){
	//cout << P << " " << Q << endl;
	if(P == Q) {cout << 0 << endl; return;}
	else if(P > Q) { cout << "impossible" << endl; return;}
	LL uoc = gcd(P,Q);
	P /= uoc; Q /= uoc;
	int ok = 0;
	FOR(i,1,40){
		if(POW[i] == Q) ok = 1;
	}
	if(ok == 0) { cout << "impossible" << endl; return;}

	int ans = 0;
	while(1){
		ans++;
		if(P*2 >= Q) break;
		else Q /= 2;
	}
	cout << ans << endl;
}

int main(){
    //ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    Init();
	int sotest;
	cin >> sotest;
	FOR(test,1,sotest){
		scanf("%lld/%lld", &P, &Q);
		printf("Case #%d: ", test);
		solve();
	}



    return 0;
}

