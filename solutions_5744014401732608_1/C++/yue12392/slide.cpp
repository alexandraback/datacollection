#include<bits/stdc++.h>

using namespace std;

int T,B,M,map1[60][60];
long long tot,arr[60];

int main(){
int current,l;
	freopen("slide.in","r",stdin);
	freopen("slide.out","w",stdout);
	
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d",&B,&M);
		memset(arr,0,sizeof(arr));
		memset(map1,0,sizeof(map1));
		arr[1]=1; arr[2]=1;
		for(int j=3;j<B;j++){
			arr[j]=1;
			for(int k=2;k<j;k++) arr[j]+=arr[k];
		}
		tot=0;
		for (int j=1;j<B;j++) tot+=arr[j];
		for(int j=2;j<B;j++) map1[1][j]=1;
		for(int j=1;j<B;j++) map1[j][B]=1;
		for(int j=3;j<B;j++)
			for(int k=2; k<j; k++) map1[j][k]=1;
		if (M>tot) printf("Case #%d: IMPOSSIBLE\n",i);
		else {
			current=B-1; 
			while (tot>M){
				l=current-1;
				while (l>0) {
					if (tot-arr[l]>=M){
						tot-=arr[l];
						map1[current][l]=0;
						if (l==1) {
							map1[current][B]=0; map1[1][current]=0;
						}
					}
					l--;
				}
				current--;
			}
			printf("Case #%d: POSSIBLE\n",i);
			for(int j=1;j<=B;j++){
				for(int k=1;k<=B;k++) printf("%d",map1[j][k]);
				printf("\n");
			}
		}
	//	for(int j=1;j<B;j++) printf("%lld ",arr[j]); printf("\n");

	}
	return 0;
}
