#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long power(long long a, long long b)
{
	if(b == 0)
		return 1;
	if(b == 1)
		return a;
	long long temp = power(a,b/2);
	long long ans = temp*temp;
	if(b%2 == 0) return ans;
	else return ans*a;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	int k =1;
	while(t--)
	{
		cout<<"Case #"<<k<<": ";
		k++;
		int b,m;
		cin>>b>>m;
		long long p = power(2,b-2);
		//cout<<"p: "<<p<<endl;
		if(m > p)
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		else
		{
			cout<<"POSSIBLE"<<endl;
			vector<int> v;
			long long tempM = m;
			if(m == p)
				tempM--;
			while(tempM)
			{
				v.push_back(tempM%2);
				tempM /= 2;
			}
			for(int i=v.size();i<b-1;i++)
			{
				v.push_back(0);
			}
			int ans[60][60];
			for(int i=0;i<60;i++)
			{
				for(int j=0;j<60;j++)
				{
					ans[i][j] = 0;
				}
			}
			for(int i=b-1;i>=2;i--)
			{
				for(int j=i+1;j<=b;j++)
				{
					ans[i][j] = 1;
				}
			}
			for(int i=0;i<v.size();i++)
			{
				if(v[i] == 1)
				{
					ans[1][b-1-i] = 1;
				}
			}
			if(m == p)
				ans[1][b] = 1;
			for(int i=1;i<=b;i++)
			{
				for(int j=1;j<=b;j++)
				{
					cout<<ans[i][j];
				}
				cout<<endl;
			}
		}
	}
	return 0;
}