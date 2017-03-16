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
lldd gcd(lldd a,lldd b) {
   if (b == 0) {
      return a;
   } else {
      return gcd(b, a % b);
   }
}
int main()
{
freopen("A-a-attempt0.in","r",stdin);
freopen("output.txt","w",stdout);
int t;
scanf("%d",&t);
for(int q=1;q<=t;q++)
	{
		lldd num,den;
		char text[100];
		scanf("%s",text);
		sscanf(text,"%lld/%lld",&num,&den);
		lldd ans=0;
		lldd hcd=gcd(num,den);
		if(hcd!=0)
		{
		num=num/hcd;
		den/=hcd;
		}
		lldd tmp=den;
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