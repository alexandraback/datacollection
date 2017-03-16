#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
 
int t[(int)1e6+5];
int f[(int)1e6+5];

bool con(char c) {
	return c !='a' && c !='u' && c !='e' && c !='i' && c !='o';
}

int main() {
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int test; cin >> test;
    for (int it = 0; it < test; it++) {
		long long ans = 0;
		string s; int n; cin >> s >> n;
		int r = 1, k = con(s[0]);
		for (int i=0; i<s.size(); i++) {
			if (!con(s[i])){t[i]=0; continue;}
			if (i >= r) {
				if (con(s[i])) k = 1; else k = 0;
				r = i + 1;
			}
			while (r<s.size()&& con(s[r])){
				r++; k++;
			}
			if (k>=n) t[i]=1; else t[i]=0;
			k--;
		}
	//	for (int i=0; i<s.size(); i++)
		//	cout << t[i] << " ";
		f[0] = t[0];
		for (int i=1; i<s.size(); i++)	f[i] = f[i-1]+t[i];
		for (int i=0; i<=s.size()-n; i++) {
			int lm=-1, rm=s.size();
			while (rm-lm>1) {
				int m=(rm+lm)/2;
				int x = min((int)s.size()-1, i+m); 
				int s = f[x];
				if (i > 0) s = f[x] - f[i - 1];
				if (s <= 0) {
					lm=m;
				} else {
					rm=m;
				}
			}
			if (i + n - 1 + rm < s.size())
				ans += s.size() - (i+n-1+rm);
		}
		//cout << ans;
	 	//cout << endl;
        printf("Case #%d: %lld\n", it+1, ans);
    }
    return 0;
}
