#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<iomanip>
using namespace std;
#define maxn 1000
#define eps 1e-6
double a[maxn];
int fa[maxn];
int main()
{
	ifstream cin("A-small-attempt9.in");
	ofstream cout("A-small-attempt9.out");
	cout.precision(6);
	int N,k;
	cin>>N;
	for(k=1;k<=N;k++)
	{
		int i,n,num;	
		double x=0,y,av;
		memset(fa,0,sizeof(fa));
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		x=0;
		num=n;
		for(i=0;i<n;i++)
			x+=a[i];
		av=2*x/n;
		y=2*x;
		for(i=0;i<n;i++)
			if(a[i]-av>-eps)
			{
				fa[i]=true;
				num--;
				y-=a[i];
			}
		av=y/num;
		cout<<"Case #"<<k<<":";
		for(i=0;i<n;i++)
			if(fa[i]) cout<<" "<<fixed<<0.0;
			else cout<<" "<<fixed<<(av-a[i])/x*100;
		cout<<endl;
	}
	return 0;
}