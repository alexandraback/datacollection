#include <cstdio>
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string.h>
#include <iostream>
#define lldd long long int
using namespace std;
int main()
{
freopen("A-a-attempt0.in","r",stdin);
freopen("output.txt","w",stdout);
int t;
scanf("%d",&t);
for(int q=1;q<=t;q++)
	{
		int num,den;
		char text[10];
		scanf("%s",text);
		sscanf(text,"%d/%d",&num,&den);
		lldd ans=0;
		int tmp=den;
		while(tmp%2==0)
			tmp/=2;
		if(tmp!=1)
		{
			printf("Case #%d: impossible\n",q);
			continue;
		}
		else
		{
			double inv=den*1.0/num;
			while(inv>1.0)
			{
				inv/=2;
				ans++;
			}
		}
		printf("Case #%d: %lld\n",q,ans);
	}
return 0;	
}