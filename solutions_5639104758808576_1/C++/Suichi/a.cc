#include<cstdio>
#include<algorithm>

using namespace std;
int member;
int mem[1001];


void read(){
  char buf;
  scanf("%d",&member);
 // printf("%d",member);
    scanf("%c",&buf);
  for(int i=0;i<=member;i++){
    scanf("%c",&buf);
    mem[i]=buf-'0';
   // printf("%d",mem[i]);
  }
 // printf("\n");
}

int solve(int T){
  int total=0;
  int ans=0;
  for(int i=0;i<=member;i++){
    if(mem[i]==0)continue;
    ans+=max(0,i-total);
    total+=mem[i]+max(0,i-total);
  }
  printf("Case #%d: %d\n",T,ans);
}
int main(){
  int T;
  scanf("%d",&T);
  for(int i=1;i<=T;i++){
    read();
    solve(i);
  }
}
