#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	freopen("inputB","r",stdin);
	freopen("outputB","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d:",t);
		int num[2501]={0};
		int n;
		scanf("%d",&n);
		for(int i=0;i<2*n-1;i++)
			for(int j=0;j<n;j++){
				int tmp;
				scanf("%d",&tmp);
				num[tmp]++;
			}
		for(int i=0;i<=2500;i++)if(num[i]%2==1)printf(" %d",i);
		puts("");
	}
}

