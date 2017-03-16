#include<iostream>
#include<stdio.h>
using namespace std;
int a[20];
int main(){
	int t,n,i,sum,x;
	freopen("re.txt","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		x=sum=0;
	
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			x+=a[i];
		}
		int num=n;
		sum=x;
		for(i=0;i<n;i++){
			if(a[i]<2*x/n){
				sum+=a[i];
			}
			else
				num--;
		}
		printf("Case #%d: ",cas);
		for(i=0;i<n;i++){
			if(a[i]>=2*sum/n){
				if(i==n-1)
					printf("0.000000\n");
				else
					printf("0.000000 ");
			}
			else{
				if(i==n-1)
					printf("%.6lf\n",(sum/(double)num-a[i])/(double)x*100);
				else
					printf("%.6lf ",(sum/(double)num-a[i])/(double)x*100);
			}
		}
	}
	return 0;
}


	

