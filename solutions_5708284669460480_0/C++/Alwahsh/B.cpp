#include <bits/stdc++.h>

using namespace std;

#define ll long long

int t;

int k,l,s;
string s1,s2;

int count(string too) {
	int cnt = 0;
	for (int i = 0; i < s; i++) {
		bool valid = true;
		for (int j = 0; j < l; j++) {
			if (too[i+j] != s2[j])
				valid = false;
		}
		cnt+= valid;
	}
	return cnt;
}

double solve(int i, string too) {
	if (i == s) {
		return count(too);
	}
	double res = 0;
	for (int z = 0; z < k; z++) {
		string h = too + s1[z];
		res+= 1.0/k * solve(i+1,h);
	}
	return res;
}

int main() {
	/*
	s = 4;
	l = 3;
	s2 = "AAA";
	cout << count("AAAA") << endl;
	*/
	ios::sync_with_stdio(0);
	freopen("B-small-attempt0 (1).in","r",stdin);
	freopen("final_B.out","w",stdout);
	cin >> t;
	for (int cntt = 1; cntt <= t; cntt++) {
		printf("Case #%d: ",cntt);
		cin >> k >> l >> s;
		cin >> s1 >> s2;
		int mx = 0;
		bool found;
		for (int i = 0; i < l; i++) {
			 found = false;
			for (int j = 0; j < k; j++) {
				if (s1[j] == s2[i])
					found = true;
			}
			if (!found)
				break;
		}
		if (!found) {
			printf("0.0\n");
			continue;
		}
		int mn_need= l;
		for (int i = 0; i < l; i++) {
			for (int j = 1; j < l; j++) {
				bool valid = true;
				for (int z = 0; z < l-j; z++) {
					if (s2[z] != s2[j+z])
						valid = false;
				}
				if (valid)
					mn_need = min(mn_need,j);
			}
		}
		int len = s;
		len-= l;
		mx = 1;
		while(len > 0) {
			len-= mn_need;
			if (len >= 0)
				mx++;
		}
		double exp = solve(0,"");
		//cout << mx << endl;
		//cout << exp << endl;
		printf("%.7lf\n",mx-exp);
	}
	return 0;
}
