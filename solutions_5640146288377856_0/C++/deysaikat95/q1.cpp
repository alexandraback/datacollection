#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,j;
	FILE *fp,*fp1;
	fp=fopen("input.txt","r");
	fp1=fopen("output.txt","w");
	fscanf(fp,"%d",&t);
	for(j=0;j<t;j++){
		int r,c,k,ans;
        fscanf(fp,"%d %d %d",&r,&c,&k);
       	if(c==k)
       		ans=r+k-1;
       	else if(k==1)
       		ans=r*c;
       	else
       		ans=(r*(c-1))/k+k;
		fprintf(fp1,"Case #%d: %d\n",j+1,ans);
	}
	return 0;
}