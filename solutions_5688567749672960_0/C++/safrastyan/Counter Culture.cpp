#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int rev(int x)
{
	int y=x;
	int len=0;
	int ten=1;
	while(y!=0)
	{
		y/=10;
		++len;
		ten*=10;
	}
	ten/=10;
	int ans=0;
	while(x!=0)
	{
		ans+=(x%10)*ten;
		ten/=10;
		x/=10;
	}
	return ans;
}
const int N=10000000;
int main()
{
	if(true)
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	vector<bool> mark(N+100,false);
		vector<int> ans(N+100,0);
		queue< pair<int,int>> q;
		ans[1]=1;
		q.push( make_pair(1,1));
		while( !q.empty())
		{
			int b=q.front().first+1;
			int c=rev(q.front().first);
			if( b<=N && ans[b]==0)
			{
				ans[b]=ans[q.front().first]+1;
				q.push(make_pair(b,q.front().second+1));
			}
			if( c<=N && ans[c]==0)
			{
				ans[c]=ans[q.front().first]+1;
				q.push(make_pair(c,q.front().second+1));
			}
			q.pop();
		}
	int a,b;
	int t;
	cin>>t;
	for(int k=1;k<=t;++k)
	{
		int n;
		cin>>n;
		
		cout<<"Case #"<<k<<": "<<ans[n]<<endl;
	}
	return 0;
}