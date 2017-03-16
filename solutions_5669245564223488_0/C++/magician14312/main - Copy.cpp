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


int n, ans = 0;
string s[105];
int p[15], xet[15];
int Free[30];

string chuanhoa(string s){
	s += '_';
	string ans = "";
	FOR(i,0,s.size()-2){
		if(s[i] != s[i+1]) ans += s[i];
	}
	return ans;
}

inline int check(string s){
	FOR(i,0,25) Free[i] = -1;
	FOR(i,0,s.size()-1){
		int tmp = s[i]-'a';

		if(Free[tmp] != -1) {
			if(Free[tmp]+1 != i) return 0;
		}
		Free[tmp] = i;
	}

	return 1;
}

inline void dequy(int step){
	if(step > 2){
		string tmp = s[p[step-2]] + s[p[step-1]];
		if(check(tmp) == 0) return;
	}

	if(step > n){
		string tmp = "";
		FOR(i,1,n) tmp += s[p[i]];
		//FOR(i,1,n) cout << p[i] << " "; cout << endl;
		if(check(tmp)) {
			ans++;
			//cout << tmp << endl;
		}
		return;
	}
	FOR(i,1,n){
		if(xet[i] == 0){
			xet[i] = 1;
			p[step] = i;
			dequy(step+1);
			xet[i] = 0;
		}
	}
}

void solve(){
	FOR(i,1,n) s[i] = chuanhoa(s[i]);
	//FOR(i,1,n) cout << s[i] << endl;
	FOR(i,1,n){
		if(check(s[i]) == 0) {cout << 0 << endl; return;}
	}
	ans = 0;
	memset(xet,0,sizeof(xet));
	dequy(1);

	cout << ans << endl;
}

int main(){
    //ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    #endif

	int sotest;
	cin >> sotest;
	FOR(test,1,sotest){
		cin >> n; cin.ignore(1);
		FOR(i,1,n) cin >> s[i];
		printf("Case #%d: ", test);
		solve();
	}



    return 0;
}

