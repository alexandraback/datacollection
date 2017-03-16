#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define REP(i,x)for(int i=0;i<(int)x;i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
int T;
int H,width,height;
int F[100][100];
int C[100][100];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int minDist[100][100]; //ダイクストラ用
bool init[100][100]; //最初に移動出来る場所
struct State{
	int time;
	int x,y;
};
// 時間の逆順で比較
bool operator<(const State &a,const State &b){
	return a.time>b.time;
}
bool canMove(int curX,int curY,int d,int h){
	int nx=curX+dx[d],ny=curY+dy[d];
	if(nx>=0&&nx<width&&ny>=0&&ny<height){
		if(F[curX][curY]<=C[nx][ny]-50){

			if(h<=C[nx][ny]-50){
				if(F[nx][ny]<=C[nx][ny]-50){
					if(F[nx][ny]<=C[curX][curY]-50){
						return true;
					}
				}
			}
		}
	}
	return false;
}
void dfs(int x,int y){
	//最初に移動出来る場所を求める
	for(int i=0;i<4;i++){
		if(canMove(x,y,i,H)){
			int nx=x+dx[i],ny=y+dy[i];
			if(!init[nx][ny]){
				init[nx][ny]=true;
				dfs(nx,ny);
			}
		}
	}
}
int main() {
	cin>>T;
	for(int tc=1;tc<=T;tc++){
		cout<<"Case #"<<tc<<": ";
		cin>>H>>height>>width;
		REP(y,height){
			REP(x,width){
				cin>>C[x][y];
			}
		}
		REP(y,height){
			REP(x,width){
				cin>>F[x][y];
			}
		}

		memset(init,0,sizeof(init));
		init[0][0]=true;
		dfs(0,0); //最初に移動出来る場所を探索する
		set<int> sChangeTime;
		REP(y,height){
			REP(x,width){
				int tar=H-(C[x][y]-50);
				if(tar>=0)sChangeTime.insert(tar);
			}
		}
		vector<int> changeTime[100][100];
		REP(y,height){
			REP(x,width){
				REP(i,4){
					if(canMove(x,y,i,-100)){
						int nx=x+dx[i],ny=y+dy[i];
						int tar=H-(C[nx][ny]-50);
						if(tar>=0)changeTime[x][y].push_back(tar);
					}
				}
				sort(changeTime[x][y].begin(),changeTime[x][y].end());
			}
		}
		//全部10倍して考える
		//1秒に1ごとhが下る
		//移動には10秒or200秒
		memset(minDist,0x7F,sizeof(minDist));
		priority_queue<State> que;
		REP(y,height){
			REP(x,width){
				if(init[x][y]){
					que.push((State){0,x,y});
					minDist[x][y]=0;
				}
			}
		}
		while(!que.empty()){
			State now=que.top();que.pop();
			if(now.x==width-1&&now.y==height-1){
				cout<<now.time/10;
				cout<<"."<<now.time%10;
				break;
			}
			vector<int>::iterator it=upper_bound(changeTime[now.x][now.y].begin(),changeTime[now.x][now.y].end(),now.time);
			if(it!=changeTime[now.x][now.y].end()){
				que.push((State){*it,now.x,now.y});
			}
			REP(i,4){
				int cost=100;
				if(H-now.time>=F[now.x][now.y]+20){
					cost=10;
				}
				if(canMove(now.x,now.y,i,H-now.time)){
					int nx=now.x+dx[i];
					int ny=now.y+dy[i];
					if(minDist[nx][ny]>now.time+cost){
						minDist[nx][ny]=now.time+cost;
						que.push((State){minDist[nx][ny],nx,ny});
					}
				}
			}
			//
		}
#if 0
		REP(y,height){
			REP(x,width){
				cout<<init[x][y];
			}
			cout<<endl;
		}
#endif
		cout<<endl;
	}
	return 0;
}
