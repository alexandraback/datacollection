#include<bits/stdc++.h>
#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;
int X,R,C,T;

int ans[6][6][6];

void preproc(){
  memset(ans,0,sizeof ans);
  //cota=1
  ans[1][1][1]=1;
  ans[2][1][1]=ans[2][1][2]=1;
  ans[3][1][1]=1;
  ans[4][1][1]=ans[4][1][2]=1;
  
  //cota=2
  ans[2][2][1]=ans[2][2][2]=1;
  ans[3][2][1]=ans[3][2][2]=ans[3][2][3]=1;
  ans[4][2][1]=ans[4][2][2]=1;

  //cota=3
  ans[3][3][1]=ans[3][3][3]=1;
  ans[4][3][1]=ans[4][3][2]=ans[4][3][3]=ans[4][3][4]=1;
  
  //cota=4
  ans[4][4][1]=ans[4][4][2]=ans[4][4][4]=1;

}

int main(){
  preproc();
  cin >> T;
  FOR(t,T){
    printf("Case #%d: ",t+1);
    cin >> X >> R >> C;
    if(R<C) swap(R,C);
    if(ans[R][C][X])  {
      printf("GABRIEL");
    }
    else printf("RICHARD");
    puts("");
  }


	return 0;
}
