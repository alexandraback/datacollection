#include <cstdio>
#include <vector>
using namespace std;

vector<int> dict[2000010];
int a[30],T,n;

int main()
{
	scanf("%d",&T);
	for (int cases=0;cases<T;++cases){
		scanf("%d",&n);
		int tot=0;
		for (int i=0;i<n;++i){
			scanf("%d",&a[i]);
			tot+=a[i];
		}
		for (int i=0;i<=tot;++i) dict[i].clear();
		for (int i=0;i<(1<<n);++i){
			int sum=0;
			for (int j=0;j<n;++j)
				if ((i&(1<<j))!=0) sum+=a[j];
			dict[sum].push_back(i);
		}
		printf("Case #%d:\n",cases+1);
		bool t=false;
		for (int i=0;i<=tot;++i){
			if (dict[i].size()>=2){
				for (int j=0;j<dict[i].size();++j){
					for (int k=j+1;k<dict[i].size();++k){
						if ((dict[i][j]&dict[i][k])==0){
							vector<int> ans1,ans2;
							ans1.clear();
							ans2.clear();
							for (int l=0;l<n;++l){
								if ((dict[i][j]&(1<<l))!=0) ans1.push_back(a[l]);
								if ((dict[i][k]&(1<<l))!=0) ans2.push_back(a[l]);
							}
							for (int i=0;i<ans1.size();++i){
								printf("%d",ans1[i]);
								if (i+1!=ans1.size()) printf(" ");
								else printf("\n");
							}
							for (int i=0;i<ans2.size();++i){
								printf("%d",ans2[i]);
								if (i+1!=ans2.size()) printf(" ");
								else printf("\n");
							}
							t=true;
							break;
						}
					}
					if (t) break;
				}
			}
			if (t) break;
		}
		if (!t) printf("Impossible\n");
	}
	return 0;
}
