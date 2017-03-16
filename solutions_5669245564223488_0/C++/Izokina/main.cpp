#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const long long MOD = 1000000000 + 7;

int solve(){
	int n;
	scanf("%d\n", &n);
	vector <string> s(n);
	for(int i = 0; i < n; i++)
		cin >> s[i];
	vector <int> f(26);
	vector <bool> c(26), b(26);
	vector <char> l(26), r(26);
	for(int i = 0; i < n; i++){
		const string& g = s[i];
		char lc = g[0];
		char rc = g.back();
		int li = lc - 97;
		int ri = rc - 97;
		b[li] = true;
		b[ri] = true;
		if(lc == rc)
			f[li]++;
		else{
			if(l[ri] != 0)
				return 0;
			if(r[li] != 0)
				return 0;
			l[ri] = lc;
			r[li] = rc;
		}
		int lb = 0;
		int rb = g.size() - 1;
		while(lb < g.size() && g[lb] == lc)
			lb ++;
		while(rb >= 0 && g[rb] == rc)
			rb --;
		if(lb <= rb && lc == rc)
			return 0;
		while(lb <= rb){
			char gg = g[lb];
			int gi = gg - 97;
			if(c[gi])
				return 0;
			c[gi] = true;
			while(lb <= rb && g[lb] == gg)
				lb++;
		}
	}
	for(int i = 0; i < 26; i++)
		if(c[i] && b[i])
			return 0;
	long long ans = 1;
	for(int i = 0; i < 26; i++)
		while(f[i] > 1){
			ans = (ans * f[i]) % MOD;
			f[i]--;
			n--;
		}
	for(int i = 0; i < 26; i++){
		char& lc = l[i];
		char& rc = r[i];
		if(rc || lc)
			n -= f[i];
		if(lc && rc){
			if(lc == rc)
				return 0;
			l[rc - 97] = lc;
			r[lc - 97] = rc;
			lc = rc = 0;
			n--;
		}
	}
	while(n > 1){
		ans = (ans * n) % MOD;
		n--;
	}
	return ans;
}

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int tests;
	scanf("%d", &tests);
	for(int test = 1; test <= tests; test++)
		printf("Case #%d: %d\n", test, solve());
}
