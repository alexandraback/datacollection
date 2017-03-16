#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n)
#define ll long long
#define ld long double
#define D (double)
#define LD (long double)


int main()
{
	freopen("ip.in","r",stdin);
	freopen("op.in","w",stdout);
	int t,c=0;cin>>t;
	while(t--)
	{
		c++;

		int x,y;
		cin>>x>>y;
		printf("Case #%d: ",c);
		if(x>0)for(int i=0;i<x;i++)cout<<"WE";
		else for(int i=0;i<-x;i++)cout<<"EW";
		if(y>0)for(int i=0;i<y;i++)cout<<"SN";
		else for(int i=0;i<-y;i++)cout<<"NS";
		cout<<endl;


		//cout<<ans<<endl;
	}
}
