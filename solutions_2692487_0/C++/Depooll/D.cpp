#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#pragma comment(linker, "/STACK:10000000") 
#define md 1000000007

using namespace std;

int j,x,p,i,t,test,n,a[105],ans,cur;

FILE* f,*g;

int main()
{
	f = fopen("input.txt","r");
	g = fopen("output.txt","w");
	fscanf(f,"%d",&t);
	for (test = 1; test<=t;test++)
	{
		fscanf(f,"%d %d",&p,&n);
	    for (i=1;i<=n;i++)
			fscanf(f,"%d",&a[i]);
		if (p==1) 	fprintf(g,"Case #%d: %d\n",test,n);
		else
		{		
		for (i=2;i<=n;i++)
			for (j=n;j>=i;j--) if (a[j-1]>a[j])
			{
				x = a[j-1];
				a[j-1] = a[j];
				a[j] = x;	
			}
		cur = 0;
		ans = 1000000000;
		for (i=1;i<=n;i++)
		{
			if (cur+n-i+1<ans) ans = cur+n-i+1;
			while (p<=a[i])
			{
				cur++;
				p = p + (p - 1);	
			}
			p = p + a[i];
		}	
		if (cur<ans) ans = cur;
		fprintf(g,"Case #%d: %d\n",test,ans);
		}
	}
}
