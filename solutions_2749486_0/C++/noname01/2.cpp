#include<iostream>
#include<cstdio>
using namespace std;
int q[1000001][3],t,i,found,head,tail,tx,ty,pre[1000001],flag[101][201][201];
char move[1000001];
void init(){
  scanf("%d%d",&tx,&ty);
  memset(q,0,sizeof(q));
  memset(pre,0,sizeof(pre));
  memset(flag,0,sizeof(flag));
  found=0;
}
void print(int p){
  if(pre[p]==0)return;
  print(pre[p]);
  printf("%c",move[p]);
}
void update(int x,int y,int t1,char ch){
  /*for(i=1;i<=tail;i++)
	if(q[i][0]==x&&q[i][1]==y&&q[i][2]==t1)return;*/
  if(x<-100||x>100||y<-100||y>100)return;
  if(flag[t1][x+100][y+100])return;
  tail++;
  q[tail][0]=x;
  q[tail][1]=y;
  q[tail][2]=t1;
  pre[tail]=head;
  move[tail]=ch;
  flag[t1][x+100][y+100]=1;
  if(x==tx&&y==ty){
	found=1;
	print(tail);
	printf("\n");
	return;
  }
}
void solve(){
  int x1,y1,t1;
  head=0;
  tail=1;
  q[tail][2]=1;
  flag[1][0][0]=1;
  while(head<tail){
	head++;
	x1=q[head][0];
	y1=q[head][1];
	t1=q[head][2];
	update(x1+t1,y1,t1+1,'E');
	update(x1-t1,y1,t1+1,'W');
	update(x1,y1+t1,t1+1,'N');
	update(x1,y1-t1,t1+1,'S');
	if(found)return;
  }
}
int main(){
  freopen("2.in","r",stdin);
  freopen("2.out","w",stdout);
  scanf("%d",&t);
  for(i=1;i<=t;i++){
	printf("Case #%d: ",i);
	init();
	solve();
  }
  fclose(stdin);
  fclose(stdout);
  return(0);
}
