#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>

using namespace std;

#define maxn 110

set<int>s;

int main()
{
	int t,i,j,a,k,b,ca,x,y,l;
	char ch[20];
	long long ans;
	scanf("%d",&t);
	for(ca=1;ca<=t;ca++)
	{
		scanf("%d%d",&a,&b);
		ans=0;
		printf("Case #%d: ",ca);
		for(i=a;i<=b;i++)
		{
			sprintf(ch,"%d",i);
			l=strlen(ch);
			s.clear();
			s.insert(i);
			for(j=1;j<l;j++)
			{
				x=0;
				for(k=0;k<l;k++)
				{
					x=x*10+ch[(k+j)%l]-'0';
				}
				if(x>=a&&x<=b)
				s.insert(x);
			}
			ans+=s.size()-1;
		}
		printf("%lld\n",ans/2);
	}
}
