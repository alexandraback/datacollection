#include<iostream>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define mod 1000000007



ll gcd (ll a, ll b){
	if (a == 0) return b;
	return gcd (b%a, a);
}


int main (){
	int t; cin >> t;
	f (tt, 1, t+1){
		ll a, b; 
		scanf("%lld/%lld", &a, &b);
		ll g = gcd (a,b);
		a /= g, b /= g;
		printf("Case #%d: ", tt);
		if (a > b){
			cout << "impossible" << endl;
		}
		ll p = 1;
		ll qm = 50;
		for (ll ans = 0; ans <= 40; ans++){
			if (p%b == 0){
				ll nivel = 1;
				ll aa = a, bb = b;
				while (aa + aa < bb) nivel++, bb/= 2;
				qm = min (qm, nivel);
				break;
			}
			p += p;
		}
		if (qm == 50) 
			cout << "impossible" << endl;
		else cout << qm << endl;

	}
	return 0;
}










