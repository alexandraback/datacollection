#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>


using namespace std;

struct EDGE_T{
  int x, y;
  int t;
  EDGE_T(int x, int y, double t):x(x), y(y), t(t){};
};
bool operator<(EDGE_T a, EDGE_T b){
  return a.t>b.t;
}

int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};

int N, M, H, F[111][111], C[111][111];
double t[111][111];


int main(){
  int T;
  scanf("%d", &T);

  for(int tc=1; tc<=T; tc++){

    scanf("%d%d%d", &H, &N, &M);
    for(int j=0; j<N; j++)
      for(int i=0; i<M; i++)
	scanf("%d", C[j]+i);
    for(int j=0; j<N; j++)
      for(int i=0; i<M; i++)
	scanf("%d", F[j]+i);

    for(int j=0; j<N; j++)
      for(int i=0; i<M; i++)
	t[j][i]=1e99;

    t[0][0]=0;
    
    priority_queue<EDGE_T>Q;
    Q.push(EDGE_T(0, 0, 0));
    for(;!Q.empty();){
      EDGE_T e=Q.top(); Q.pop();
      for(int i=0; i<4; i++){
	int x=e.x+dx[i], y=e.y+dy[i];
	if(x<0 || y<0 || x>=M || y>=N)continue;
      	if(C[y][x]-max(H, F[y][x])>=50 && C[e.y][e.x]-max(H, F[y][x])>=50 && C[y][x]-max(H, F[e.y][e.x])>=50){
	  if(t[y][x]>0){
	    t[y][x]=0;	  
	    Q.push(EDGE_T(x, y, 0));
	  }
	}
      }
    }
    for(int y=0; y<N; y++)
      for(int x=0; x<M; x++)
	if(t[y][x]==0.0)Q.push(EDGE_T(x, y, 0));


    for(;!Q.empty();){
      EDGE_T e=Q.top(); Q.pop();
      int h=max(0, H-e.t);
      for(int i=0; i<4; i++){
	int x=e.x+dx[i], y=e.y+dy[i];
	if(x<0 || y<0 || x>=M || y>=N)continue;
	if(C[y][x]-F[y][x]>=50 && C[e.y][e.x]-F[y][x]>=50 && C[y][x]-F[e.y][e.x]>=50){
	  
	  int tm=max(max(0, 50+h-C[y][x]), 50+h-C[e.y][e.x])+e.t;
	  int hh=max(0, H-tm), tt;
	  if(hh-F[e.y][e.x]>=20)tt=tm+10;
	  else tt=tm+100;
	  if(tt<t[y][x]){
	    t[y][x]=tt;
	    Q.push(EDGE_T(x, y, tt));
	  }
	}
      }
    }
        
    printf("Case #%d: %.9f\n", tc, t[N-1][M-1]/10.0);
  }
  return 0;
}
