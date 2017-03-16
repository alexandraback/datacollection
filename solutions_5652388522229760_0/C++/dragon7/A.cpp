#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int ans(int n)
{
	bool a[10]={0};
	for(int x = n ;; x+=n)
	{
		int yy = x;
		while(yy)
		{
			a[yy%10]=1;
			yy/=10;
		}
		bool ok = 1;
		for(int i=0;i<10;i++)
		{
			if(!a[i]){
				ok=0;break;
			}
		}
		if(ok)return x;
	}
}
int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		int n;
		cin>>n;
		if(n==0)
		{
			cout<<"Case #"<<z<<": INSOMNIA"<<endl;
			continue;
		}
		int x = ans(n);
		cout<<"Case #"<<z<<": "<<x<<endl;
	}
}
