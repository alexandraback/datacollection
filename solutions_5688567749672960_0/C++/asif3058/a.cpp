#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

#define mx 10000000
#define ip freopen("in.txt","r",stdin)

#define sint1(a) scanf("%d",&a)
#define sint2(a,b) scanf("%d %d",&a,&b)
#define sint3(a,b,c) scanf("%d %d %d",&a,&b,&c)


#define sch1(a) scanf("%c",&a)
#define sch2(a,b) scanf("%c %c",&a,&b)
#define sch3(a,b,c) scanf("%c %c %c",&a,&b,&c)


#define sll1(a) scanf("%lld",&a)
#define sll2(a,b) scanf("%lld %lld",&a,&b)
#define sll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)

#define ll long long int

#define lpi0(a,b) for(int a=0;a<b;a++)
#define lpd0(a,b) for(int a=b-1;a>=0;a--)

#define lpi1(a,b) for(int a=1;a<=b;a++)
#define lpd1(a,b) for(int a=b;a>0;a--)

#define vi vector<int>
#define pii pair<int,int>
#define mp make_pair

#define mm(a,b) memset(a,b,sizeof(a))
int f[1000100];

int rev(int x)
{
	int sum=0;

	while(x)
	{
		sum=sum*10+x%10;
		x=x/10;
	}

	return sum;

}

int func(int x)
{

	if(f[x]<mx)
	{
		if(f[x]>f[x-1]+1)
		{
			f[x]=f[x-1]+1;
		}
		return f[x];
	}

//	cout<<x<<endl;

	int p=rev(x);
	int q=x-1;

	int a=mx;

	if(f[p]!=0&&rev(p)==x)
	{
		a=f[p];
	}


	int b=func(q);

//	f[p]=a;
	f[q]=b;

	int s=min(a,b)+1;

	f[x]=s;
	if(s<f[p])
	{
		f[p]=s+1;
	}

//	if(x==92)
//	{
//		cout<<a<<" "<<b<<" "<<s<<endl;
//	}
	return s;
}

int main()
{
//    ip;
//    freopen("out.txt","w",stdout);

	for(int i=0;i<=1000003;i++)
	{
		f[i]=mx;
	}

//	cout<<f[10]<<endl;
	for(int i=0;i<=20;i++)
	{
		f[i]=i;
	}

	for(int i=21;i<=1000001;i++)
	f[i]=func(i);

//	cout<<"y"<<endl;
//	for(int i=999990;i<1000000;i++)
//	{
//		printf("%d %d\n",i,f[i]);
//	}

	int t;
	sint1(t);
	int cs=1;
	while(t--)
	{
		int n;
		sint1(n);
		printf("Case #%d: %d\n",cs++,f[n]);
	}


}


