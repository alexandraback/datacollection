#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define bg begin()
#define end end()
#define sz size()
typedef pair<int, int> pii;
typedef vector<int> vii;
#define sd(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define inf 2000000000
#define D double
#define LD long double
int a[1000010];
int count(int x)
{
	int sum=0;
	while(x!=0)
	{
		sum*=10;
		sum+=x%10;
		x=x/10;
	}
	return sum;
}
int counti(int x)
{
	int sum=0;
	while(x!=0)
	{
		sum++;
		x=x/10;
	}
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t,n,i,j,x,y,z;
	//cout<<count(13)<<endl;
	cin>>t;
	for(j=1;j<=1000000;j++)
		a[j]=j;
	for(j=1;j<=1000000;j++)
	{
		x=count(j);
		y=counti(j);
		z=counti(x);		
		//cout<<j<<" "<<x<<" "<<y<<" "<<z<<endl;
		if(z==y)
			a[j]=min(a[j-1],a[x])+1;
		else
			a[j]=a[j-1]+1;	
		//cout<<a[z]<<" "<<a[j-1]<<endl;	
	}
	for(i=1;i<=t;i++)
	{
		cin>>n;
		cout<<"Case #"<<i<<": "<<a[n]<<endl;
	}
	return 0;
}
