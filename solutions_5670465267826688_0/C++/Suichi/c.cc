#include<cstdio>
#include<algorithm>

using namespace std;
int mul[4][4]={{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};
long long X;
int L;
int LI[10010];

int calc(int a,int b){
  if(a<0)return -1*calc(-1*a,b);
  if(b<0)return -1*calc(a,-1*b);
  return mul[a-1][b-1];
}

void read(){
  scanf("%d %lld\n",&L,&X);
  char buf[10100];
  gets(buf);
  for(int i=0;i<L;i++){
    switch(buf[i]){
      case 'i':
        LI[i]=2;
        break;
      case 'j':
        LI[i]=3;
        break;
      case 'k':
        LI[i]=4;
    }
  }
}

bool solve(){
  int cycle=LI[0];
  for(int i=1;i<L;i++){
    cycle=calc(cycle,LI[i]);
  }
  switch(cycle){
    case 1:
      return false;
      break;
    case 2:
    case 3:
    case 4:
    case -2:
    case -3:
    case -4:
      if( (X % 2!=0) || (X % 4 ==0)){
        return false;
      }
      break;
    case -1:
      if( X%2 ==0)return false;
      break;
  }
  int leftcycle=5;
  int leftmod=0;
  int tmp=1;
  for(int i=0;i<L;i++){
    tmp=calc(tmp,LI[i]);
    int tmp_a=tmp;
    for(int j=0;j<=3;j++){
      if(tmp_a==2){
        if(j<leftcycle){
          leftcycle=j;
          leftmod=i;
        }
      }
      tmp_a=calc(cycle,tmp_a);
    }
  }
  //printf("%d %d\n",leftcycle,leftmod);
  if(leftcycle==5)return false;
  int rightcycle=5;
  int rightmod=0;
   tmp=1;
  for(int i=L-1;i>=0;i--){
    tmp=calc(LI[i],tmp);
    int tmp_a=tmp;
    for(int j=0;j<=3;j++){
      if(tmp_a==4){
        if(j<rightcycle){
          rightcycle=j;
          rightmod=i;
        }
      }
      tmp_a=calc(tmp_a,cycle);
    }
  }

 // printf("%d %d\n",rightcycle,rightmod);
  if(rightcycle==5)return false;
  if(rightcycle+leftcycle >= X) return false;
  if(rightcycle+leftcycle == X-1 && leftmod >= rightmod ) return false;
  return true;
}

int main(){
  int T;
  scanf("%d",&T);
  for(int i=1;i<=T;i++){
    read();
    if(solve()){
    printf("CASE #%d: YES\n",i);
    }else{
    printf("CASE #%d: NO\n",i);
    }
  }
}
