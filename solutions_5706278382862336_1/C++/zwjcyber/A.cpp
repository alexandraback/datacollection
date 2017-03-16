#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>

using namespace std;

#define For(i,n) for(int i = 0;i < n;i++)

bool ispossible(long long p,long long q)
{
	while(q % 2 == 0)
		q = q /2;
	if(p % q == 0)
		return true;
	else
		return false;
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;
	cin>>t;
	int id = 0;
	while(t--)
	{
		long long p,q;
		char c;
		cin>>p>>c>>q;
		cout<<"Case #"<<++id<<": ";
		if(!ispossible(p,q))
		{
			cout<<"impossible"<<endl;
		}
		else
		{
			int count = 0;
			while(p < q)
			{
				p = p * 2;
				count++;
			}
			cout<<count<<endl;
		}
	}
	return 0;
}
