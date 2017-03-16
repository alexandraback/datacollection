 //if you want,you can
#include<stdio.h>
#include<iostream>  
#include<queue>  
#include<cstdio>  
using namespace std;  
#include<memory.h>  

int t,h,n,m;

int ceil[200][200];
int floor[200][200];

double value[200][200];
int have[200][200];

int move_h[]={-1,0,0,1};
int move_v[]={0,-1,1,0};

struct node
{
    friend bool operator< (node n1, node n2)
    {
        return n1.value > n2.value;
    }
    double value;
    int i;
    int j;
};



double dijs()
{
	double ret;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			have[i][j]=0;
		}
	}

	node start;
	start.value=0.0;
	start.i=0;
	start.j=0;

	priority_queue<node> qn;
	qn.push(start);
	while(!qn.empty())
	{
		node now=qn.top();
		qn.pop();
		//cout<<"sbsbs  "<<now.i<<" "<<now.j<<" "<<now.value<<endl;

		if(have[now.i][now.j])
		{
			continue;
		}
		have[now.i][now.j]=1;

		if(now.i==n-1&&now.j==m-1)
		{
			ret=now.value;
			//cout<<"shit "<<ret<<endl;
		}

		for(int i=0;i<4;i++)
		{
			int x=now.i+move_h[i];
			int y=now.j+move_v[i];
			double value=now.value;

			if(x<0 || x==n ||y<0 || y==m)
			{
				continue;
			}

			if(have[x][y])
			{
				continue;
			}

			if(floor[x][y]-ceil[now.i][now.j]<50 || floor[x][y]-ceil[x][y]<50 || floor[now.i][now.j]-ceil[x][y]<50)
			{
				continue;
			}

			double add=0;
			double height=h-10*value;
			if(floor[x][y]-height<50)
			{
				add+=(50-(floor[x][y]-height))/10;
				height=floor[x][y]-50;
			}
			if(value+add>0)
			{
				add+=1;
				if(height-ceil[now.i][now.j]<20)
				{
					add+=9;
				}
			}
			//cout<<"fuck  "<<x<<" "<<y<<" "<<(value+add)<<endl;
			node next;
			next.value=value+add;
			next.i=x;
			next.j=y;
			qn.push(next);
		}
	}

	return ret;
}


int main()
{
	freopen("b.out","w",stdout);
	scanf("%d",&t);
	for(int tt=0;tt<t;tt++)
	{
		scanf("%d %d %d",&h,&n,&m);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&floor[i][j]);
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&ceil[i][j]);
			}
		}

		double ret=dijs();
		cout<<"Case #"<<(tt+1)<<": "<<ret<<endl; 
	}
}
