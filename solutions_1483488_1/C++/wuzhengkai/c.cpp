#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

int tt;

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		int a,b;
		scanf("%d%d",&a,&b);
		int cnt=0;
		for (int i=a;i<=b;++i) {
			char s[20];
			memset(s,0,sizeof(s));
			itoa(i,s,10);
			set<int> hash;
			hash.clear();
			for (int j=1;j<(int)strlen(s);++j) {
				char s1[20];
				memset(s1,0,sizeof(s1));
				memcpy(s1,s+j,strlen(s)-j);
				memcpy(s1+strlen(s)-j,s,j);
				int tmp=atoi(s1);
				if (tmp>i && tmp<=b && hash.find(tmp)==hash.end()) cnt++,hash.insert(tmp);
			}
		}
		printf("Case #%d: %d\n",ii,cnt);
	}

	return 0;
}
