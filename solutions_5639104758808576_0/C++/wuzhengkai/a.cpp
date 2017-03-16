#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int tt,n;
string s;
int cur,ans;

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	cin >> tt;
	for (int ii=1;ii<=tt;++ii) {
		cin >> n >> s;
		cur=0,ans=0;
		for (int i=0;i<=n;++i) {
			if (cur<i) ans+=i-cur,cur=i;
			cur+=s[i]-'0';
		}

		printf("Case #%d: %d\n",ii,ans);
	}
}
