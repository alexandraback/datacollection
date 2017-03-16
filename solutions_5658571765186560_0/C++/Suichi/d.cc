#include<cstdio>
#include<algorithm>

using namespace std;
int X,R,C;

void read(){
  scanf("%d %d %d\n",&X,&R,&C);
}

bool solve(){
  if(X==1)return true;
  if(X>=7)return false;
  if(X==2){
    return ((R*C)%2)==0;
  }
  if(X==3){
    return ((R*C)%3 == 0 && min(R,C)>=2);
  }
  if(X==4){
    if(max(R,C)<4)return false;
    if(min(R,C)<3)return false;
    return true;
  }
}

int main(){
  int T;
  scanf("%d",&T);
  for(int i=1;i<=T;i++){
    read();
    if(solve()){
    printf("CASE #%d: GABRIEL\n",i);
    }else{
    printf("CASE #%d: RICHARD\n",i);
    }
  }
}
