#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
bool flag[3][55][55],visited[3][55][55];
int tc,r,c,left;
pii next[8]={mp(-1,1),mp(-1,0),mp(-1,-1),mp(0,-1),mp(1,-1),mp(1,0),mp(1,1),mp(0,1) };
queue<pii> q;

void open(){
 freopen("C-small-attempt0.in","r",stdin);
 freopen("Cf.out","w",stdout);
}

void close(){
 fclose(stdin);
 fclose(stdout);
}

 inline bool cek(int d,int rr,int cc){
 bool ok=0;
 for(int i=0;i<8;i++){
 int h=rr+next[i].fi,j=cc+next[i].se;
 if(h>=0 && h<r && j>=0 && j<c)
  ok|=flag[d][h][j];
 }
 return ok;
}

 inline int flood(int d){
 q.push(mp(0,0));
 int ret=0;
 visited[d][0][0]=1;
 while(!q.empty()){
  ret++;
  //printf("%d\n",ret);
  int x=q.front().fi,y=q.front().se;
  q.pop();
  //printf("%d %d %d\n",d,x,y);
  if(cek(d,x,y)==0)
  for(int i=0;i<8;i++){
   int xx=x+next[i].fi,yy=y+next[i].se;
   if(xx>=0 && xx<r && yy>=0 && yy<c && !flag[d][xx][yy] && !visited[d][xx][yy]){
    visited[d][xx][yy]=1;
    q.push(mp(xx,yy));
   }
  }
 }
 //printf("%d %d\n",d,ret);
 return ret;
}

inline void print(int d){
 for(int i=0;i<r;i++){
  for(int j=0;j<c;j++)
   if(i==0 && j==0) printf("c");
   else if(flag[d][i][j]) printf("*");
   else printf(".");
  printf("\n");
 }
}

int main(){
 open();
 scanf("%d",&tc);
 for(int t=1;t<=tc;t++){
  scanf("%d %d %d",&r,&c,&left);
  for(int i=0;i<3;i++)
   for(int j=0;j<r;j++)
    for(int k=0;k<c;k++)
     flag[i][j][k]=1,visited[i][j][k]=0;
  left=r*c-left;
  int hm=left;
  int mini=min(r,c);
  if(mini*mini>=left){
    for(int i=0;i<mini&&left>0;i++){
     for(int j=0;j<=i&&left>0;j++){
      left--,flag[0][i][j]=0;
     }
     for(int j=0;j<i&&left>0;j++)
      left--,flag[0][j][i]=0;
    }
  }
  left=hm;
  for(int i=0;i<c&&left>0;i++)
    for(int j=0;j<r&&left>0;j++)
       left--,flag[1][j][i]=0;
   left=hm;
     for(int i=0;i<r&&left>0;i++)
      for(int j=0;j<c&&left>0;j++)
       left--,flag[2][i][j]=0;
   left=hm;
   bool found=0;
  printf("Case #%d:\n",t);
   for(int i=0;i<3;i++){
    int ret=flood(i);
    if(ret==hm){
     print(i);
     //printf("%d %d\n",i,ret);
     found=1;
     //printf("ayaz");
     break;
    }
   }
  if(!found) puts("Impossible");
 }
 close();
 return 0;
}
