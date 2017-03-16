#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

struct pos{
  int x,y;
  double time;
};

bool operator<(const pos& a,const pos&b){
  return a.time>b.time;
}

int main(){
  int T;
  cin>>T;
  for (int t=1;t<=T;t++){
    int H,N,M;
    cin>>H>>N>>M;
    vector<vector<int> > fl(N);
    vector<vector<int> > ce(N);
    for (int i=0;i<N;i++){
      ce[i].resize(M);
      for (int j=0;j<M;j++){
	cin>>ce[i][j];
      }
    }
    for (int i=0;i<N;i++){
      fl[i].resize(M);
      for (int j=0;j<M;j++){
	cin>>fl[i][j];
      }
    }

    priority_queue<pos> Q;
    pos start;
    start.x=start.y=start.time=0;
    Q.push(start);
    while(!Q.empty()){
      pos cur = Q.top();
      Q.pop();
      //      cout<<cur.y<<' '<<cur.x<<' '<<cur.time<<endl;
      if (fl[cur.y][cur.x]==-1) continue;
      if (cur.y == N-1 && cur.x == M-1){
	cout<<"Case #"<<t<<": "<<cur.time<<endl;
	break;
      }
      for (int i=0;i<4;i++){
	int ny=cur.y+dy[i];
	int nx=cur.x+dx[i];
	if (ny<0 || nx<0 || ny>N-1 || nx>M-1 ) continue;
	pos npos;
	npos.x=nx;
	npos.y=ny;
	if (ce[ny][nx]-fl[ny][nx]<50) continue;
	if (ce[ny][nx]-fl[cur.y][cur.x]<50) continue;
	if (ce[cur.y][cur.x]-fl[ny][nx]<50) continue;
	double mintime = (H-(ce[ny][nx]-50))/10.0;
	if (mintime<cur.time)
	  mintime=cur.time;
	if (mintime!=0){
	  if ((fl[cur.y][cur.x]+20)<=H-mintime*10.0)
	    mintime+=1;
	  else
	    mintime+=10;
	}
	npos.time=mintime;
	Q.push(npos);
      }
      fl[cur.y][cur.x]=-1;
    }
  }
}
	  
	
    
