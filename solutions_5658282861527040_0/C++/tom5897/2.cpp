#include<stdio.h>

int main()
{
	FILE *fi=fopen("input.txt","r");
	FILE *fo=fopen("output.txt","w");
	int a,b,k,t,m,cnt,i,j,l,temp;

	fscanf(fi,"%d",&t);
	for(m=0;m<t;m++){
		fprintf(fo,"Case #%d: ",m+1);
		fscanf(fi,"%d %d %d",&a,&b,&k);
		cnt=0;
		if(a>b) temp=a,a=b,b=temp;
		if(k>a) k = a;
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				if((i&j) <= k-1) cnt++;
			}
		}
		//cnt+=(a-1)*b;
		fprintf(fo,"%d\n",cnt);
	}
}