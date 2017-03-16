// QualB.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "stdio.h"

using namespace std;


int cmp(pair<int,double> &a, pair<int,double> &b)
{
	return a.second<b.second;
}

int solve()
{
	int N;
	cin>>N;
	vector<pair<int,double> > g;
	for(int i=0;i<N;i++)
	{
		int D,H,M;
		cin>>D>>H>>M;
		for(int j=0;j<H;j++)
		{
			g.push_back(make_pair(D,(M+j)));
		}
	}
	if(g.size()<=1) return 0;
	if(g.size()==2)
	{
		sort(g.begin(),g.end(),cmp);
		double x=g[0].first;
		double v=g[0].second;
		double x1=g[1].first;
		double v1=g[1].second;
		double t1=(720.0-x)*v;
		double t2=(360.0-x1)*v1;
		if(fabs(t1-t2)<0.00001) return 1;
		return t1<t2;
	}
	return -1;
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

//B
//int solve()
//{
//	int R,C,N;
//	cin>>R>>C>>N;
//	vector<int> g1,g2;
//	for(int i=0;i<R;i++)
//	{
//		for(int j=0;j<C;j++)
//		{
//			int x=4;
//			if(i==0) x--;
//			if(i==R-1) x--;
//			if(j==0) x--;
//			if(j==C-1) x--;
//			if((i+j)%2)
//			{
//				g1.push_back(x);
//			}
//			else
//			{
//				g2.push_back(x);
//			}
//		}
//	}
//	sort(g1.rbegin(),g1.rend());
//	int ans1=2*R*C-R-C;
//	for(int i=0;i<R*C-N;i++)
//	{
//		if(ans1==0) return 0;
//		ans1-=g1[i];
//	}
//	sort(g2.rbegin(),g2.rend());
//	int ans2=2*R*C-R-C;
//	for(int i=0;i<R*C-N;i++)
//	{
//		if(ans2==0) return 0;
//		ans2-=g2[i];
//	}
//	return min(ans1,ans2);
//}
//
//int main()
//{
//	int T;
//	cin>>T;
//	for(int tc=0;tc<T;tc++)
//	{
//		int ret=solve();
//		cout<<"Case #"<<tc+1<<": "<<ret<<endl;
//	}
//	return 0;
//}


//A small
//int reverse(int x)
//{
//	int ret=0;
//	while(x)
//	{
//		ret*=10;
//		ret+=x%10;
//		x/=10;
//	}
//	return ret;
//}
//
//char visited[1000005]={};
//
//int putnum(int x)
//{
//	if(x>1000000) return 0;
//	if(visited[x]==0)
//	{
//		visited[x]=1;
//		return 1;
//	}
//	return 0;
//}
//
//int solve()
//{
//	memset(visited,0,sizeof(visited));
//	int N;
//	cin>>N;
//	vector<int> queue;
//	queue.push_back(1);
//	int p=0,q=1;
//	int step=1;
//	while(p<q)
//	{
//		int x=queue[p];
//		if(x==N) return step;
//		if(putnum(x+1))
//		{
//			queue.push_back(x+1);
//		}
//		int y=reverse(x);
//		if(putnum(y))
//		{
//			queue.push_back(y);
//		}
//		p++;
//		if(p==q)
//		{
//			q=queue.size();
//			step++;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int T;
//	cin>>T;
//	for(int tc=0;tc<T;tc++)
//	{
//		int ret=solve();
//		cout<<"Case #"<<tc+1<<": "<<ret<<endl;
//	}
//	return 0;
//}
