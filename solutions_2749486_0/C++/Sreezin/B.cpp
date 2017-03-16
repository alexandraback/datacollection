#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cctype>
#include<iostream>
#include<stack>
#include<set>
#include<list>
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define pb push_back
#define sz(c) (int)(c).size()
#define INF  (1<<30)
#define EPS  1e-8
#define SET(NAME)   (memset(NAME,-1,sizeof(NAME)))
#define CLR(NAME)   (memset(NAME,0,sizeof(NAME)))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define LL long long
#define FOR(_name,_A,_B)  for(int _name=_A;_name<=(_B);_name++)

#define IN CAT(FILE_NAME,".in")
#define OUT CAT(FILE_NAME,".out")
#define CAT(a,b) a##b
//---------------------------------------------------------------
struct node{

	int x,y;
	int j;
};
const int SIZ=1202;

int T,X,Y,cas=1;
int vis[SIZ][SIZ];
node pre[SIZ][SIZ];
char dir[SIZ][SIZ];
map<int,int> mpx;
map<int,int> mpy;
void reset(){}
node make(int a,int b,int c){

	node r;
	r.x=a;
	r.y=b;
	r.j=c;
	return r;
}
int sum(int n){

	return n*(n+1)/2;
}

int getX(int n){

	if(mpx.find(n)==mpx.end())
		mpx[n]=mpx.size()+1;
	
	return mpx[n];
	
}

int getY(int n){

	if(mpy.find(n)==mpy.end()){
		mpy[n]=mpy.size()+1;
		
	}
	//cout<<mpy[n]<<endl;;
	return mpy[n];
	
}

void bfs(){

		mpx.clear();
		mpy.clear();
		
			queue<node> q;
			CLR(vis);
			node u,i,v;			
			
			q.push(make(0,0,1));
			vis[getX(0)][getY(0)]=1;
			while(!q.empty()){

			
				u=q.front(); 
				//cout<<u.x<<" "<<u.y<<endl;
				
				q.pop();
				if(u.x==X&& u.y==Y){
					//cout<<"mak"<<endl;
					break;
				}
				//if() continue;
				
				v=make(u.x+u.j,u.y,u.j+1);
				if(vis[getX(v.x)][getY(v.y)]==0){
					vis[getX(v.x)][getY(v.y)]=1;
					q.push(v);
					pre[getX(v.x)][getY(v.y)]=u;
					dir[getX(v.x)][getY(v.y)]='E';
				}
				
				v=make(u.x-u.j,u.y,u.j+1);
				if(vis[getX(v.x)][getY(v.y)]==0){
					vis[getX(v.x)][getY(v.y)]=1;
					q.push(v);
					pre[getX(v.x)][getY(v.y)]=u;
					dir[getX(v.x)][getY(v.y)]='W';
				}
				v=make(u.x,u.y+u.j,u.j+1);
				if(vis[getX(v.x)][getY(v.y)]==0){
					vis[getX(v.x)][getY(v.y)]=1;
					q.push(v);
					pre[getX(v.x)][getY(v.y)]=u;
					dir[getX(v.x)][getY(v.y)]='N';
				}
				v=make(u.x,u.y-u.j,u.j+1);
				if(vis[getX(v.x)][getY(v.y)]==0){
					vis[getX(v.x)][getY(v.y)]=1;
					q.push(v);
					pre[getX(v.x)][getY(v.y)]=u;
					dir[getX(v.x)][getY(v.y)]='S';
				}
			
			}
			
			//cout<<"m.";
	
	}

void show(int x,int y){
	//cout<<x<<" "<<y<<endl;
	if(x==0&& y==0) return ;
	show(pre[getX(x)][getY(y)].x,pre[getX(x)][getY(y)].y);
	cout<<dir[getX(x)][getY(y)];
}
void process(){
	
	
	bfs();
	show(X,Y);
	cout<<endl;

}

//#define FILE_NAME "B-small-attempt0"

int main(){
	
	//freopen("in.txt","rt",stdin);
	freopen("B-small-attempt0.in","rt",stdin);
	freopen("out.out","wt",stdout);
	cin>>T;
	while(T--){
		
		cin>>X>>Y;
		printf("Case #%d: ",cas++);
		process();
	}	
	
	

	return 0;
}
