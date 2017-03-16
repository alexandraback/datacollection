#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;


int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char pos[]={'N','S','E','W'};
int vis[1000][10000];
int ex,ey;
int time[1000][1000];
char direc[1000][1000];
string anss[1000][1000];

int f(char x)
{
	if(x=='N' || x=='S') return 0;
	else if(x=='E') return 1;
	return -1;
}
int g(char x)
{
	if(x=='E' || x=='W') return 0;
	else if(x=='N') return 1;
	return -1;
}

string bfs()
{
	queue< pair < pair<int,string> , pair<int,int > > > q;
	q.push(make_pair(make_pair(0,""),make_pair(0,0)));
	//vis[500][500]=1;
	time[0+500][0+500]=0;
	direc[0+500][0+500]='l';
	int p=0;
	while(!q.empty())
	{
		int x=q.front().first.first;
		int y=q.front().second.first;
		int t=q.front().second.second+1;
		string s = q.front().first.second;
		char d='x';
		//p++;
		//if(p>6) return "";
		if(x==ex && y==ey)
		{
			return s;
		}
		q.pop();
		//cout<<" now we have " <<x<<" "<<y<<" "<<t<<"\n";
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i]*t;
			int ny=y+dy[i]*t;	
			char dir=pos[i];		
			//if(vis[nx+500][ny+500]==0)
			if(nx>200 || nx<-200 || ny>200 || ny<-200) continue;
			if(vis[nx+500][ny+500]==0)	
			{			
				q.push(make_pair(make_pair(nx,s+dir),make_pair(ny,t)));				
				time[nx+500][ny+500]=t;
				direc[nx+500][ny+500]=dir;
		//		vis[nx+500][ny+500]=1;
			}			
			{
				int prevt=t;
				char prevdir=dir;
				int prevx=nx;
				int prevy=ny;
				string ans="";
				int m=0;
				//cout<<"finding ans\n";
				while(m<=500)
				{
					if(prevx==0 && prevy==0) break;
					//cout<<prevx<<" "<<prevy<<" "<<prevt<<" "<<prevdir<<"\n";
					//cout<<ans<<"\n";
									
					ans=ans+prevdir;
					prevx=prevx-f(prevdir)*prevt;
					prevy=prevy-g(prevdir)*prevt;
					prevt=time[prevx+500][prevy+500];
					prevdir=direc[prevx+500][prevy+500];
					//cout<<prevx<<" "<<prevy<<" "<<prevt<<" "<<prevdir<<"\n";
					m++;
				}
				//cout<<nx<<" "<<ny<<" "<<ans<<"\n";
				anss[nx+500][ny+500]=ans;
				vis[nx+500][ny+500]=1;
			}
		}
	}
	return "";
}

int main()
{
	int t,p=1;
	cin>>t;
	while(t--)
	{		
		cin>>ex>>ey;
		string ans=bfs();
		string ans1="";
		for(int i=0;i<1000;i++)
		 for(int j=0;j<1000;j++) 
		 	vis[i][j]=0;
		for(int i=ans.length();i>=0;i--)
		  ans1+=ans[i];			
		printf("Case #%d: ",p);	
		cout<<ans<<"\n";
		p++;
	}
}
