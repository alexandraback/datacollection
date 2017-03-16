#include<stdio.h>
#include<string>
using namespace std;
string w1,w2;
int maxC,co;
int gen(string s,int x,int k)
{
	int n=w1.size(),m=w2.size();
	if(x==k)
	{
		co++;
		int c=0;
		for(int i=0;i<=k-m;i++)
		{
			string a=s.substr(i,m);
			if(w2==a)
				c++;
		}
		if(maxC<c)
			maxC=c;
		return c;
	}
	int out=0;
	for(int i=0;i<n;i++)
		out+=gen(s+w1[i],x+1,k);
	return out;
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int a=1;a<=t;a++)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		char c1[10],c2[10];
		scanf("%s%s",c1,c2);
		w1=c1;	w2=c2;
		maxC=0;	co=0;
		int x=gen("",0,k);
		double d=(double)x;	d/=(double)co;
		d=(double)maxC-d;
		if(d==(int)d)
			printf("Case #%d: %.1lf\n",a,d);
		else
			printf("Case #%d: %.7lf\n",a,d);
	}
}
