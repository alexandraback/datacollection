#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <map>
#define LL long long
#define pb push_back
#define mp make_pair

using namespace std;

int a[1010][2];
int state[1010];
int n,tt;
int p,cnt;

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		p=0,cnt=0;
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%d%d",&a[i][0],&a[i][1]);
		memset(state,0,sizeof(state));

		while (1) {
			int tmp=-1;
			for (int i=0;i<n;++i)
				if (state[i]<2) {
					if (state[i]==0 && cnt>=a[i][1]) {
						tmp=i;
						break;
					} else {
						if (state[i]==1 && cnt>=a[i][1]) {
							tmp=i;
							break;
						} else {
							if (state[i]==0 && cnt>=a[i][0]) {
								if (tmp==-1 || a[i][1]>a[tmp][1]) tmp=i;
							}
						}
					}
				}
			if (tmp==-1) break;
			if (cnt>=a[tmp][1]) {
				p++;
				cnt+=2-state[tmp];
				state[tmp]=2;
			} else {
				p++;
				cnt++;
				state[tmp]=1;
			}
		}
		bool flag=true;
		for (int i=0;i<n;++i)
			if (state[i]!=2) flag=false;
		printf("Case #%d: ",ii);
		if (!flag) printf("Too Bad\n");
		else printf("%d\n",p);
	}

	return 0;
}


