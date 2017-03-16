#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
bool pal(long long x)
{
	long long y = 0,z=x;
	while(x>0)
	{
		y*=10;
		y+=(x%10);
		x/=10;
	}
	if(z==y)
		return true;
	else
		return false;
}
vector<long long>v;
bool arr[10000003];
void gen()
{
	for(long long f=1;f<10000003;f++)
	{
		if(pal(f)&&pal(f*f))
		{
			v.push_back(f);
			arr[f]=true;
		}
		else
			arr[f]=false;
	}
}
int main ()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int n,N=0;
	gen();
	long long a,b,ans;
	cin>>n;//)cout<<pal(n)<<endl;
	while(++N<=n)
	{
		ans=0;
		cin>>a>>b;
		for(int i=0;i<v.size();i++)//=ceil(sqrt(a));f<=sqrt(b);f++)
		{
			if(v[i]>=ceil(sqrt(a))&&v[i]<=sqrt(b))
				ans++;
		}
		printf("Case #%d: %lld\n",N,ans);
	}
}