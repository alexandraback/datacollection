#include<fstream>
#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

class ms
{
public:
	int x,y,t;
};

class mycomparison
{
public:
  bool operator() (const ms& lhs, const ms& rhs) const
  {
    return (lhs.t>rhs.t);
  }
};

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("b.in");
	fout.open("b.out");
	int tr,rnd;
	int m,n,h,i,j,x,y,xx,yy,v,old,now;
	int c[100][100],f[100][100],t[100][100];
	bool b[100][100];
	ms ts;
	int dx[4]={0,1,0,-1};
	int dy[4]={1,0,-1,0};
	fin>>rnd;
	for (tr=1;tr<=rnd;tr++)
	{
		fin>>h>>m>>n;
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				fin>>c[i][j];
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				fin>>f[i][j];
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
			{
				b[i][j]=false;
				t[i][j]=2000000;
			}
		t[0][0]=0;
		priority_queue<ms,vector<ms>,mycomparison> s;
		ts.x=0;ts.y=0;ts.t=0;
		s.push(ts);
		while(!s.empty())
		{
			x=s.top().x;
			y=s.top().y;
			old=s.top().t;
			s.pop();
			if (b[x][y])
				continue;
			b[x][y]=true;
			for (v=0;v<4;v++)
			{
				xx=x+dx[v];
				yy=y+dy[v];
				if (xx<0 || xx>=m || yy<0 || yy>=n)
					continue;
				if (c[xx][yy]<f[xx][yy]+50)
					continue;
				if (c[xx][yy]<f[x][y]+50)
					continue;
				if (c[x][y]<f[xx][yy]+50)
					continue;
				if (h+50-c[xx][yy]>old)
					now=h+50-c[xx][yy];
				else
					now=old;
				if (now>0)
					if (h-now-f[x][y]>=20)
						now=now+10;
					else
						now=now+100;
				if (now<t[xx][yy])
				{
					t[xx][yy]=now;
					ts.x=xx;
					ts.y=yy;
					ts.t=now;
					s.push(ts);
				}
			}
		}
		fout<<"Case #"<<tr<<": "<<t[m-1][n-1]/10<<"."<<t[m-1][n-1]%10<<endl;
	}
	fin.close();
	fout.close();
}