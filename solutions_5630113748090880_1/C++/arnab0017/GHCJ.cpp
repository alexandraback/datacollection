#include<bits/stdc++.h>
using namespace std;

int main(){

	freopen("input.txt", "r" , stdin);
	freopen ("output.txt","w",stdout);
	int t,r,i,n,j,k,num;
	scanf("%d",&t);
	for(r=1;r<=t;++r){
            int mark[2509]={0};
		scanf("%d",&n);
		for(i=1;i<2*n;++i){
            for(j=0;j<n;++j){
                scanf("%d",&num);
                mark[num]+=1;
            }
		}
		int arr[100],z=0;
		for(i=1;i<=2500;++i){
            if(mark[i]%2!=0){
                arr[z]=i; ++z;
            }
		}
		sort(arr,arr+z);
			printf("Case #%d: ",r);
			for(i=0;i<z;++i){
                printf("%d ",arr[i]);
			}
			printf("\n");
	}
	fclose(stdout);
	return 0;
}
