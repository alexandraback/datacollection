#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t;
int a[1050],b[1050],n,cmp[1050];


int level(int k,int star)
{
	if(cmp[k] == 2) return 0;
	if(cmp[k] == 1)
	{
		if(star >= b[k]) return 3;
	}
	if(cmp[k] == 0)
	{
		if(star >= a[k] && star >= b[k] )
			return 2;
		else if(star >= a[k])
			return 1;
		else return 0;
	}
	return 0;
}

int main()
{
	FILE *in,*out;
	in=fopen("a.in","r");
	out=fopen("a.out","w");
	fscanf(in,"%d",&t);
	for(int tt=1;tt <= t;tt++)
	{
		fscanf(in,"%d",&n);
		for(int i=0;i<n;i++)
			fscanf(in,"%d%d",&a[i],&b[i]);
		memset(cmp,0,sizeof(cmp));
		int star=0;
		int ans=0;

		while(star <= 2*n)
		{
			int k=-1;
			for(int i=0;i<n;i++)
				if(k== -1)
					{if(level(i,star)) k=i;}
				else
				{
					int k1=level(i,star);
					if(level(k,star) == k1 && k1 == 1 && b[k]<b[i])
							k=i;
					if(k1>level(k,star))
						k=i;
				}

			if(k == -1) break;

			ans++;
			if(cmp[k] == 0)
			{
				if(star >= b[k]) star += 2,cmp[k]=2;
				else if(star >= a[k]) star++,cmp[k]=1;
			}
			else if(cmp[k] == 1 && star >= b[k])
				star++,cmp[k]=2;
		}
		if(star<2*n) fprintf(out,"Case #%d: Too Bad\n",tt);
		else fprintf(out,"Case #%d: %d\n",tt,ans);
	}
	fclose(in);
	fclose(out);
	return 0;
}

