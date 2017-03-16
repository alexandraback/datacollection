#include<bits/stdc++.h>
#define scan(n) scanf("%d",&n)
#define scanll(n) scanf("%lld",&n)
#define For(i,a,b) for(i=a;i<b;i++)
#define fill(a,b) memset(a,b,sizeof(a))
#define swap(a,b) a=a+b;b=a-b;a=a-b;
#define ll long long int
#define pb push_back
#define MAX 1000000007
#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);
using namespace std;
int abs(int s)
{
	if(s<0)
	s=-s;
	return s;

}
struct point {
	int x;
	int y;
};
int sq(int x)
{
	return x*x;
}
int main()
{
	int tt;
	cin>>tt;
	int t=1;
	for(t=1;t<=tt;t++)
	{
		cout<<"Case #"<<t<<": ";
		int j,p,s,num;
                cin>>j>>p>>s>>num;

		int sum=0;
		
		for(int i=1;i<=j;i++)
		{
			int ctr=0;
			for(int l=1;l<=p;l++)
			{
				for(int k=1;k<=min(s,num);k++)
				{
					
					sum++;
					ctr++;
				}
			}
		}
		cout<<sum<<endl;
		int result=0;
		for(int i=1;i<=j;i++)
		{
			int ctr=0;
			for(int l=1;l<=p;l++)
			{
				for(int k=1;k<=min(s,num);k++)
				{
					if(ctr==num)
					{
						ctr=0;
						result++;
					}
					cout<<i<<" "<<l<<" "<<k+result<<endl;
					ctr++;
				}
			}
		}
	}
 	return 0;
}


