#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int tt;

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		int n,s,p;
		cin >> n >> s >> p;
		int cnt=0;
		for (int i=0;i<n;++i) {
			int x;
			scanf("%d",&x);
			if (x==0) {
				if (p==0) cnt++;
				continue;
			}
			int p1=0;
			if (x % 3==0) p1=x/3;
			else p1=x/3+1;
			if (p1>=p) cnt++;
			else {
				if (s==0) continue;
				p1=0;
				if (x%3==2) p1=x/3+2;
				else p1=x/3+1;
				if (p1>=p) cnt++,s--;
			}
		}
		printf("Case #%d: %d\n",ii,cnt);
	}
}
