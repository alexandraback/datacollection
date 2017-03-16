// QualB.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "stdio.h"

using namespace std;


int reverse(int x)
{
	int ret=0;
	while(x)
	{
		ret*=10;
		ret+=x%10;
		x/=10;
	}
	return ret;
}

char visited[1000005]={};

int putnum(int x)
{
	if(x>1000000) return 0;
	if(visited[x]==0)
	{
		visited[x]=1;
		return 1;
	}
	return 0;
}

int solve()
{
	memset(visited,0,sizeof(visited));
	int N;
	cin>>N;
	vector<int> queue;
	queue.push_back(1);
	int p=0,q=1;
	int step=1;
	while(p<q)
	{
		int x=queue[p];
		if(x==N) return step;
		if(putnum(x+1))
		{
			queue.push_back(x+1);
		}
		int y=reverse(x);
		if(putnum(y))
		{
			queue.push_back(y);
		}
		p++;
		if(p==q)
		{
			q=queue.size();
			step++;
		}
	}
	return 0;
}

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int ret=solve();
		cout<<"Case #"<<tc+1<<": "<<ret<<endl;
	}
	return 0;
}