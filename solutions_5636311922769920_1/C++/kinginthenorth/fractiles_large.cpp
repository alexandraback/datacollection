#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	freopen("D-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cno=1;cno<=t;cno++)
	{
		long long k,c,s;
		cin>>k>>c>>s;
		cout<<"Case #"<<cno<<": ";
		long long r=(1>(k-(c-1)))?1:(k-(c-1));
		if(s<r)
		{
			cout<<"IMPOSSIBLE";
		}
		else
		{
			long long index=1,level=0;
			while(level<c)
			{
				level++;
				index=(index-1)*k;
				if(level<=k)
					index+=level;
				else
					index++;
			}
			for(long long i=index;i<(index+r);i++)
			{
				cout<<i<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
