#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
//#define s second
#define f first
#define MP make_pair
#define PB push_back
#define LL long long
#define LD long double
#define PII pair<int,int>
#define VI vector<int>
int t[1000006];
char ch[1000004];
int z,n,a,b,c,d,e,l;
long long wyn,bylo,lewa,prawa;
main()
{
scanf("%d",&z);
for(int uu=1;uu<=z;uu++)
	{
	printf("Case #%d: ",uu);
	scanf("%s%d",ch,&l);
	n=strlen(ch);
	for(int i=0;i<n;i++)
		{
		if(ch[i]=='a'||ch[i]=='e'||ch[i]=='i'||ch[i]=='o'||ch[i]=='u')t[i]=0;
		else t[i]=1;
		}
	for(int i=1;i<n;i++)
		{
		if(t[i]==0)continue;
		t[i]+=t[i-1];
		}
	wyn=0;
	bylo=0;
	for(int i=0;i<n;i++)
		{
		//printf("%d ",t[i]);
		if(t[i]>=l)
			{
			lewa=(long long)i-l+1+1-bylo;
			prawa=(long long)n-i-1+1;
			wyn+=(long long)lewa*prawa;
			bylo+=lewa;
			}
		}
	printf("%lld\n",wyn);
	}
}
