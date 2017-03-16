#include <iostream>
#include <stdio.h>
#include <string.h>
//#include <time.h>
//#include <stdlib.h>
//#include <math.h>
//#include <queue>
//#include <vector>
//#include <stack>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <sstream>
using namespace std;

const int maxn=105;

int n,s,p,t[maxn];
int ans;

void solve() {
	ans=0;
	sort(t,t+n);
	int now,a,b,c;
	for (int i=0;i<n;i++) {
		a=t[i]/3;
		b=a;c=a;
		if (t[i]%3>=1) c++;
		if (t[i]%3==2) b++;
//		cout<<t[i]<<":"<<a<<" "<<b<<" "<<c<<"   "<<ans<<endl;
		if (c>=p) {
			ans++;
			continue;
		}
		if (s) {
			if (t[i]%3==2) {
				c++;b--;
			}
			if (t[i]%3==0) {
				c++;a--;
			}
			if (c>=p&&a>=0) {
				ans++;
				s--;
			}
		}
	}
}

int main() {
	int T,kase=0;
	cin>>T;
	while (T--) {
		cin>>n>>s>>p;
		for (int i=0;i<n;i++)
			cin>>t[i];
		solve();
		printf("Case #%d: %d\n",++kase,ans);
	}
        return 0;
}

