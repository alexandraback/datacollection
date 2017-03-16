// GCJ2012Round1B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "iostream"
#include "string"
#include "string.h"
#include "stdio.h"
#include "vector"
#include "queue";
#include "algorithm"

using namespace std;

int mx[]={0,1,0,-1};
int my[]={1,0,-1,0};

int C[105][105];
int F[105][105];
int visited[105][105];

struct status
{
	int t;
	int x;
	int y;
};
bool operator < (const status &lhs, const status &rhs)
{
	return lhs.t > rhs.t;
}

void dfs(priority_queue<status> & queue, int x, int y, int N, int M, int H)
{
	for(int r=0;r<4;r++)
	{
		int xx=x+mx[r];
		int yy=y+my[r];
		if(xx>=0 && xx<N && yy>=0 && yy<M)
		{
			if(F[x][y]<=C[xx][yy]-50 && F[xx][yy]<=C[x][y]-50 && F[xx][yy]<=C[xx][yy]-50 && H<=C[xx][yy]-50)
			{
				if(visited[xx][yy]==-1)
				{
					visited[xx][yy]=0;
					status next={0,xx,yy};
					queue.push(next);
					dfs(queue,xx,yy,N,M,H);
				}
			}
		}
	}
}

int main()
{
	int T;
	cin>>T;
	for(int tc=0;tc<T;tc++)
	{
		int H,N,M;
		cin>>H>>N>>M;
		memset(visited,-1,sizeof(visited));
		memset(C,0,sizeof(C));
		memset(F,0,sizeof(F));
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				cin>>C[i][j];
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				cin>>F[i][j];
		priority_queue<status, vector<status>, less<status> > queue;
		status start={0,0,0};
		visited[0][0]=0;
		queue.push(start);
		dfs(queue,0,0,N,M,H);
		while(!queue.empty())
		{
			status cur=queue.top();
			queue.pop();
			if(cur.x==N-1 && cur.y==M-1)
			{
				printf("Case #%d: %.1lf\n",tc+1,0.1*cur.t);
				break;
			}
			for(int r=0;r<4;r++)
			{
				int xx=cur.x+mx[r];
				int yy=cur.y+my[r];
				if(xx>=0 && xx<N && yy>=0 && yy<M)
				{
					if(F[cur.x][cur.y]<=C[xx][yy]-50 && F[xx][yy]<=C[cur.x][cur.y]-50 && F[xx][yy]<=C[xx][yy]-50)
					{
						int startt=max(H-(C[xx][yy]-50),cur.t);
						int w=max(H-startt,0);
						int endt=startt+10;
						if(w-F[cur.x][cur.y]<20)
							endt=startt+100;
						if(visited[xx][yy]==-1 || visited[xx][yy]>endt)
						{
							visited[xx][yy]=endt;
							status next={endt,xx,yy};
							queue.push(next);
						}
					}
				}
			}
		}
	}
	return 0 ;
}


//
//int main()
//{
//	int T;
//	cin>>T;
//	for(int tc=0;tc<T;tc++)
//	{
//		int N;
//		cin>>N;
//		s.clear();
//		for(int i=0;i<N;i++)
//		{
//			int t;
//			cin>>t;
//			s.push_back(t);
//		}
//		vector<int> g(N);
//		cout<<"Case #"<<tc+1<<":"<<endl;;
//		if(dfs(g,0,N)==0)
//			cout<<"Impossible"<<endl;
//	}
//	return 0;
//}