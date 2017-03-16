#include <stdio.h>

int main() {
	int T, noOfClass, adj[1002][1002], path[1002][1002], cnt, reach1[1002], reach2[1002], cnt1,cnt2;
	scanf("%d",&T);

	for(int cas=1;cas<=T;++cas) {
		scanf("%d",&noOfClass);

		for(int i=0;i<1002;++i) {
			for(int j=0;j<1002;++j) {
				adj[i][j] = 0;
				path[i][j] = 0;
			}
		}
		for (int i=1;i<=noOfClass;++i) {
			scanf("%d",&cnt);
			for(int j=0;j<cnt;++j)
			{
				int go;
				scanf("%d",&go);
				adj[i][go] = 1;
			}
		}

		int isDiamond = 0;
		cnt1 = 0;
		cnt2 = 0;

		for(int i=1;i<=noOfClass && !isDiamond;++i) {
			reach1[0] = i;
			cnt1 = 1;
			while(cnt1 && !isDiamond) {
				cnt2 = 0;
				for(int j=0;j<cnt1 && !isDiamond;++j) {
					if(reach1[j]!=i) {
						path[i][reach1[j]]++;
						if(path[i][reach1[j]]>1) {
							isDiamond = 1;
							break;
						}
					}
					for(int k=1;k<=noOfClass;++k){
						if(adj[reach1[j]][k]==1) {
							reach2[cnt2++] = k;
						}
					}
				}
				cnt1 = cnt2;
				for(int l=0;l<cnt2;++l) {
					reach1[l] = reach2[l];
				}
			}			
		}

		if(isDiamond)
			printf("Case #%d: Yes\n",cas);
		else
			printf("Case #%d: No\n",cas);
	}
}