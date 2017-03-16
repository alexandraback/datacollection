#include <iostream>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define mp make_pair
#define pb push_back
#define put(x) { cout << #x << " = "; cout << (x) << endl; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef double db;

const int M = 1020;
const ll Q = 1e18 + 7;


int Gl, ans;

void gen(string cur, int s, int l, string t, string kk, int k){
	int n = (int)cur.size();
	if (n == s){
		int res = 0;
	//	cout << cur << " " << t << endl;
		for (int i = 0; i <= n - l; i++){
			bool ok = true;
			for (int j = 0; j < l; j++)
				if (cur[i + j] != t[j])
					ok = false;
			if (ok){
				Gl++;
				res++;
			}	
		}
	//	cout << res << endl;
		ans = max(ans, res);
		return;
	}
	for (int i = 0; i < k; i++)
		gen(cur + kk[i], s, l, t, kk, k);
}

int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tq = 1; tq <= t; tq++){
		int k,l,s;
	   	cin >> k >> l >> s;
		string s1, s2;
		cin >> s1 >> s2;
	
		Gl = 0, ans = 0;
		int p = 1;
		for (int i = 0; i < s; i++)
			p *= k;

		gen("", s, l, s2, s1, k);
		printf("Case #%d: %.15f\n", tq, (db)((p * ans - Gl + 0.) / p));
		cerr << tq << endl;
	}
	return 0;
}