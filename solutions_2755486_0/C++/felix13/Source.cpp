////#pragma comment(linker,"/STACK:16777216") /*16Mb*/
////#pragma comment(linker,"/STACK:33554432") /*32Mb*/
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <string>
//#include <stack>
//#include <cmath>
//#include <list>
//#include <iomanip>
//#include <set>
//#include <map>
//using namespace std;
//
//typedef  long long LL;
//typedef  unsigned long long ULL;
//typedef  long double LD;
//typedef  pair<int,int> PII;
//
//#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
//#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i)) 
//#define MP make_pair
//#define MOD 1000000007
//#define INF 1000000000
//#define PB push_back
////#define X first
////#define Y second
//
//char dir [500][500];
//int mid=150;
//int xx,yy;
//struct str{int X;int Y;int Step;
//str(int xx,int yy,int stp)
//{
//	X=xx;
//	Y=yy;
//	Step=stp;
//}
//};
//int bfs(int x,int y)
//{
//	queue<str> q;
//	q.push(str(x,y,1));
//	dir[x][y]='O';
//	int step;
//	while(!q.empty()&&!dir[xx][yy])
//	{
//		str v=q.front();
//		q.pop();
//		step=v.Step;
//		if(!dir[v.X+step][v.Y])
//		{
//			dir[v.X+step][v.Y]='E';
//			q.push(str(v.X+step,v.Y,step+1));
//		}
//		if(!dir[v.X-step][v.Y])
//		{
//			dir[v.X-step][v.Y]='W';
//			q.push(str(v.X-step,v.Y,step+1));
//		}
//		if(!dir[v.X][v.Y+step])
//		{
//			dir[v.X][v.Y+step]='N';
//			q.push(str(v.X,v.Y+step,step+1));
//		}
//		if(!dir[v.X][v.Y-step])
//		{
//			dir[v.X][v.Y-step]='S';
//			q.push(str(v.X,v.Y-step,step+1));
//		}
//		
//	}
//	return step;
//}
//
//
//void outp(int x,int y,int step)
//{
//	if(dir[x][y]!='O')
//	{
//		char c=dir[x][y];
//		if(c=='N')outp(x,y-step,step-1);
//		else
//		if(c=='S')outp(x,y+step,step-1);
//		else
//		if(c=='W')outp(x+step,y,step-1);
//		else
//		if(c=='E')outp(x-step,y,step-1);
//	cout<<dir[x][y];
//	}
//}
//int main()
//{
//	//ios_base::sync_with_stdio(0);
//	//freopen("input.txt","r",stdin);
//	//freopen("output.txt","w",stdout);
//	int t;
//	cin>>t;
//	FOR(i,0,t)
//	{
//		cin>>xx>>yy;
//		xx+=mid;yy+=mid;
//		int ln=bfs(mid,mid);
//		cout<<"Case #"<<i+1<<" ";
//		outp(xx,yy,ln);
//		cout<<'\n';
//	}
//	return 0;
//}


//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <cmath>
#include <list>
#include <iomanip>
#include <set>
#include <map>
using namespace std;

typedef  long long LL;
typedef  unsigned long long ULL;
typedef  long double LD;
typedef  pair<int,int> PII;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i)) 
#define MP make_pair
#define MOD 1000000007
#define INF 1000000000
#define PB push_back

int wall[10000];
int mid=5000;
struct attack
{
	int day;
	int l;
	int r;
	int h;
	attack(int d,int w,int e,int s)
	{
		day=d;
		l=w;
		r=e;
		h=s;
	}
};

bool cmp(attack a,attack b)
{
	return a.day<b.day;
}

int d,n,w,e,s,dd,dp,ds;
int main()
{
	//ios_base::sync_with_stdio(0);
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	int N;
	FOR(tt,0,T)
	{
		cin>>N;
		vector<attack> a;

		FOR(i,0,N)
		{
			cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
			w+=mid;e+=mid;
			FOR(j,0,n)
				a.push_back(attack(d+j*dd,w+j*dp,e+j*dp,s+j*ds));
		}
		int ans=0;
		sort(a.begin(),a.end(),cmp);
		bool sucs=false;
		memset(wall,0,sizeof(wall));
		for(int j=a[0].l;j<=a[0].r;j++)
			if(wall[j]<a[0].h){sucs=true;break;}		
		if(sucs)ans++;
		FOR(i,1,a.size())
		{
			if(a[i].day!=a[i-1].day)
			{
				for(int j=i-1;j>=0&&a[j].day==a[i-1].day;--j)
					for(int ii=a[j].l;ii<a[j].r;++ii)
						if(wall[ii]<a[j].h)wall[ii]=a[j].h;
			}
			sucs=0;
			for(int j=a[i].l;j<a[i].r;j++)
				if(wall[j]<a[i].h){sucs=true;break;}
			if(sucs)ans++;
		}
		printf("Case #%d: %d\n",tt+1,ans);
	}
	return 0;
}