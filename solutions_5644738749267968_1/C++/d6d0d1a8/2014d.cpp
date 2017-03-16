#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void sort(double a[],int n){
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				double temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
}

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=0;tt<t;){
		tt++;
		int n;
		double a[1000],b[1000];
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%lf",&a[i]);
		for(int i=0;i<n;i++)scanf("%lf",&b[i]);
		sort(a,n);
		sort(b,n);
		int c1,c2;
		c1=0;c2=0;
		int i1,j1;
		i1=0;j1=0;
		while(j1<n){
			if(a[i1]>b[j1])j1++;
			else {
				i1++;
				j1++;
			}
		}
		c2=n-i1;
		i1=0;j1=n-1;
		for(int i=0;i<n;i++){
			if(a[i]>b[i1]){
				c1++;
				i1++;
			}else{
				j1--;
			}
		}
		printf("Case #%d: %d %d\n",tt,c1,c2);
	}
	return 0;
}