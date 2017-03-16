#include <bits/stdc++.h>
using namespace std;
int T, n,a ,b, c, k, m1[33334], m2[33334], m3[33334];
vector<int>v;
void solve(int test) {
	scanf("%d %d %d %d",&a, &b, &c, &k);
	printf("Case #%d: ", test);
	v.clear();
	for (int i=1; i<=a; i++) for (int j=1; j<=b; j++) for (int l=1; l<=c; l++) {
		v.push_back(i*10000+j*100+l);
	}
	n=a*b*c;
	int maxx=0, maxi;
	for (int i=0; i<(1<<n); i++) {
		if (a==3&&b==3&&c==3&&k>3) break;
		else if (k>=c) break;
		bool ok=true;
		int cnt=0;
		for (int j=0; j<n; j++) {
			if (i&(1<<j)) {
				cnt++;
				int x=v[j]/10000, y=v[j]/100%100, z=v[j]%100;
				m1[x*100+y]++;
				m2[x*100+z]++;
				m3[y*100+z]++;
				if (m1[x*100+y]>k||m2[x*100+z]>k||m3[y*100+z]>k) {
					ok=false;
					break;
				}
			}
		}
		if (ok) {
			if (cnt>maxx) {
				maxx=cnt;
				maxi=i;
			}
		}
		for (int j=0; j<n; j++) {
			if (i&(1<<j)) {
				int x=v[j]/10000, y=v[j]/100%100, z=v[j]%100;
				m1[x*100+y]=0;
				m2[x*100+z]=0;
				m3[y*100+z]=0;
			}
		}
	}
	if (a==3&&b==3&&c==3&&k>3) maxx=27, maxi=(1<<n)-1;
	else if (k>=c) maxx=n, maxi=(1<<n)-1;
	printf("%d\n", maxx);
	for (int i=0; i<n; i++) {
		if (maxi&(1<<i))printf("%d %d %d\n", v[i]/10000, v[i]/100%100, v[i]%100);
	}
}
int main () {
	freopen("C-small.in", "r", stdin);
	freopen("C-small.out", "w", stdout);
	scanf("%d", &T);
	for (int i=1; i<=T; i++) {
		solve(i);
	}
	return 0;
}
