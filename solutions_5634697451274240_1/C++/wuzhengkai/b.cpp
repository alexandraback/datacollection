#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int tt,ii;

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d\n",&tt);
	for (int ii=1;ii<=tt;++ii) {
		printf("Case #%d: ",ii);
		string s;
		cin >> s;
		int n=s.size(),cnt=0;
		for (int i=1;i<n;++i)
			if (s[i]!=s[i-1]) cnt++;
		if (s[n-1]=='-') cnt++;
		printf("%d\n",cnt);
	}
}