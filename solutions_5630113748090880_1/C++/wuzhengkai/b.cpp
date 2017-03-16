#include <cassert>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int tt;
int hei[2501];
int n;
vector<int> ans;

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d",&tt);
	for (int ii=1;ii<=tt;++ii) {
		printf("Case #%d:",ii);
		
		scanf("%d",&n);
		memset(hei,0,sizeof(hei));
		for (int i=0;i<2*n-1;++i)
			for (int j=0;j<n;++j) {
				int x;
				scanf("%d",&x);
				hei[x]++;
			}

		ans.clear();
		for (int i=1;i<=2500;++i)
			if (hei[i]&1) ans.push_back(i);
		assert(ans.size()==n);
		for (int i=0;i<n;++i)
			printf(" %d",ans[i]);
		printf("\n");
	}
}