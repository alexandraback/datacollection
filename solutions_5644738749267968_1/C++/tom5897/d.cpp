#include<stdio.h>
#include<algorithm>
double a[1005],b[1005];
int main()
{
	FILE *fi=fopen("input.txt","r");
	FILE *fo=fopen("output.txt","w");
	int i,j,k,t,n,cnt=0,temp;

	fscanf(fi,"%d",&t);
	for(i=0;i<t;i++){
		fscanf(fi,"%d",&n);
		for(j=0;j<n;j++) fscanf(fi,"%lf",&a[j]);
		for(j=0;j<n;j++) fscanf(fi,"%lf",&b[j]);
		std::sort(a,a+n);
		std::sort(b,b+n);
		cnt = 0;
		temp = 0;
		for(j=0;j<n;j++){
			for(k=temp;k<n;k++){
				if( a[k]>b[j]){
					cnt++; temp = k+1;
					break;
				}
			}
		}
		fprintf(fo,"Case #%d: %d",i+1,cnt);
		cnt = 0;
		temp = 0;
		for(j=0;j<n;j++){
			for(k=temp;k<n;k++){
				if( a[j]<b[k]){
					cnt++; temp = k+1;
					break;
				}
			}
		}
		fprintf(fo," %d\n",n-cnt);
	}
	return 0;
}