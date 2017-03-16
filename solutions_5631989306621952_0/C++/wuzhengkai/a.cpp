
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int tt;
string s,ans;
int n;

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	cin >> tt;
	for (int ii=1;ii<=tt;++ii) {
		printf("Case #%d: ",ii);
		cin >> s;
		n=s.size();
		ans="";
		for (int i=0;i<n;++i) {
			string p1,p2;
			p1=s[i]; p1+=ans;
			p2=ans+s[i];
			if (p1<p2) ans=p2;
			else ans=p1;
		}
		cout << ans << endl;
	}
}