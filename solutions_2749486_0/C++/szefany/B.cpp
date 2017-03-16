#include "iostream"
#include "cstring"
#include "cstdio"
#include "string"
#include "map"
#include "queue"
using namespace std;
#define MP make_pair
#define F first
#define S second
map<pair<int,int>,string> mp;
queue<pair<int,int> >que;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
string dir[4];
int ab(int x)
{
	return x>0?x:-x;
}
int main(void)
{
	dir[0]="N";
	dir[1]="S";
	dir[2]="W";
	dir[3]="E";
	pair<int,int> p;
	p.F=0;p.S=0;
	mp[p]="";
	que.push(p);
	while(!que.empty()){
		pair<int,int> p=que.front(),q;
		que.pop();
		int u=mp[p].size()+1;
		for(int i=0;i<4;i++){
			q.F=p.F+dx[i]*u;
			q.S=p.S+dy[i]*u;
			if(mp.find(q)!=mp.end()||ab(q.F)>300||ab(q.S)>300){
				continue;
			}else{
				mp[q]=mp[p]+dir[i];
				que.push(q);
			}
		}
	}
	freopen("B-small-attempt0.in","r",stdin);
	int T,x,y,g=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",++g);
		cout<<mp[MP(x,y)]<<endl;
	}
	return 0;
}
