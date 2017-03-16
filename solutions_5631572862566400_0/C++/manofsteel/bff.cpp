#include<stdio.h>


int main(){
	int t;
	scanf("%d",&t);
	int q=t;
	
	while(t--){
		int n;
		printf("Case #%d: ",q-t);
		scanf("%d",&n);
		int a[1001],cc[1001]={0};
		int i,max=0,count=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			cc[a[i]]++;
		}
		for(i=1;i<=n;i++){
			count=0;
			int k=i;
			int j=0;
			int b[1000]={0};
			
			while(i!=j ){
				if(b[k]==0){
				
				j=a[k];
				b[k]++;
				k=j;
				count++;
			}
			else{
				if(a[j]!=i){
					if(cc[i]>1){
						count++;
					}
				}
				if(cc[a[j]]>1){
					count++;
					
				}
				break;
			}
			
			}
			if(count>max){
				max=count;
			}
		}		
		printf("%d\n",max);
			
	}
	
}
