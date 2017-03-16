#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	freopen("D-small-attempt1 (1).in","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cno=1;cno<=t;cno++)
	{
		long long k,c,s;
		cin>>k>>c>>s;
		long long step=(long long)pow(k,c-1);
		cout<<"Case #"<<cno<<": ";
		long long index=1;
		for(int i=1;i<=s;i++)
		{
			cout<<index<<" ";
			index+=step;
		}
		cout<<endl;
	}
	return 0;
}
