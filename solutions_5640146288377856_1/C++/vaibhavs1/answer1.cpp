#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,b;
	int r,c,w;
	FILE *fpr=fopen("input.txt","r");
	FILE *fpw=fopen("output2.txt","w");
	fscanf(fpr,"%d",&t);
	for(int igh=1;t-->0;igh++)
	{
		fscanf(fpr,"%d %d %d",&r,&c,&w);
		int ans=(c/w) + (w-1);
		if((c%w)>=1)
		ans++;
		if((c/w)>1)
		ans=max(ans,(w-1)+(c/w));
		ans+=(r-1)*(c/w);
		fprintf(fpw,"Case #%d: %d\n",igh,ans);
	}
	return 0;
}
