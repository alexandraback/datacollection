#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
#include <memory>
#include <time.h>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
const double EPS = 1e-9;
const double PI  = acos(-1.0);

const int MAX=INT_MAX/10;

int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};
void dfs(int y,int x,vvi &f,vvi &visited,int h,int w, vvi &inside){
	visited[y][x]=1;
	inside[y][x]=false;
	bool ret=true;
	REP(d,4){
		int yy=y+dy[d];
		int xx=x+dx[d];
		if(yy>=0&&xx>=0&&yy<h&&xx<w&&!visited[yy][xx]){
			if(f[yy][xx]==0){
				dfs(yy,xx,f,visited,h,w,inside);
			}
		}
	}
}

int main(){
	int num_cases;
	cin>>num_cases;
	REP(test_case,num_cases){
		int h,w,k;
		cin>>w>>h>>k;
		int ans=MAX;
		REP(mask,1<<(h*w)){
			int num_stones=0;
			vvi f(h,vi(w));
			REP(i,h){
				REP(j,w){
					if(mask&(1<<(i*w+j))){
						f[i][j]=1;
						num_stones++;
					}
				}
			}
			vvi visited(h,vi(w));
			vvi inside(h,vi(w,1));
			int ji=0;
			REP(i,h){
				if(!f[i][0])dfs(i,0,f,visited,h,w,inside);
				if(!f[i][w-1])dfs(i,w-1,f,visited,h,w,inside);
			}
			REP(i,w){
				if(!f[0][i])dfs(0,i,f,visited,h,w,inside);
				if(!f[h-1][i])dfs(h-1,i,f,visited,h,w,inside);
			}
			REP(i,h){
				REP(j,w){
					if(inside[i][j]){
						ji++;
					}
				}
			}
			if(ji>=k){
				ans=min(ans,num_stones);
			}
		}
		cout<<"Case #"<<test_case+1<<": "<<ans<<endl;
	}
}