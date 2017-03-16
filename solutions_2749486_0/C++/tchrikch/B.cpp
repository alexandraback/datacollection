#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<stack>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
#define REP(i,n) for(int i=0;i<n;++i)
#define REPD(i,n) for(int i=n;i>-1;--i)
#define FOR(i,j,k) for(int i=j;i<k;++i)
#define PB push_back
#define LL unsigned long long
#define MAX_S 101
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define MAXX 100
#define MAXY 100

int x, y ;
string ret;
bool hasSolution;
bool v[MAXX][MAXY];
struct node{
	int a;
	int b;
	int l;
	string m;
};


void bfs()
{
	queue<node> s;
	
	node start; start.a=start.b=0; start.m=""; start.l=1;
	s.push(start);
	
	while(!s.empty())
	{
		node c = s.front();
		s.pop();
		
		cout<<c.a<<" "<<c.b<<" "<<c.l<<endl;
		
		if(c.a==x && c.b == y) 
		{
			//cout<<"!"<<x<<" "<<y<<endl;
		//	cout<<"!"<<c.a<<" "<<c.b<<endl;
			ret = c.m;
			return;
		}
		
		
		if(abs(c.a+c.l)<MAXX)
		{
			node e; e.a = c.a +c.l; e.b = c.b; e.l = c.l+1; e.m = c.m+"E";
			s.push(e);
		}
		
		if(abs(c.a-c.l)<MAXX)
		{
			node e; e.a = c.a -c.l; e.b = c.b; e.l = c.l+1; e.m = c.m+"W";
			s.push(e);
		}
		
		if(abs(c.b-c.l)<MAXY)
		{
			node e; e.a = c.a ; e.b = c.b-c.l; e.l = c.l+1; e.m = c.m+"S";
			s.push(e);
		}
		
		if(abs(c.b+c.l)<MAXY)
		{
			node e; e.a = c.a ; e.b = c.b+c.l; e.l = c.l+1; e.m = c.m+"N";
			s.push(e);
		}
	}
}


int main(){
	 int ts=0; cin>>ts;
	 REP(ww,ts)
	 {
	    cin>>x>>y;
	 //   cout<<"!"<<x<<" "<<y<<endl;
	    ret = ""; hasSolution=false;
	  //  bfs();
	   
	    string xP = "WE"; if(x<0) xP = "EW"; x = abs(x);
	    REP(i,x) ret+=xP;
	    
	    string yP = "SN"; if(y<0) yP = "NS"; y = abs(y);
	    REP(i,y) ret+=yP;
	    
		cout<<"Case #"<<(ww+1)<<": "<<ret<<endl;
	 }
	
	return 0;
}
