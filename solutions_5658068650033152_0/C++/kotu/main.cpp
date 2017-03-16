#include <cstdio>

using namespace std;
int T;
int N,M,K;
//N<=M;
int kansu(int n){
  return 2*n*n-2*n+1;
}
int saikou(int i){
  if(i<4)return 0;
  int j=i/4;
  if( j > N-2 ){
    int k=i-(N-2)*4;
    return kansu(N-2)+(k/2)*(N-2)+k%2;
  }else{ //Œø—¦“I‚È’u‚«•û
    int k=i%4;
    if(k==0)return kansu(j);
    if(k==1)return kansu(j)+j-1;
    if(k==2)return kansu(j)+j*2-1;
    if(k==3)return kansu(j)+j*2-1+j;
  }
}
int main(){

  scanf("%d",&T);
  int ans=0;
  for(int cnt=0;cnt<T;++cnt){
    scanf("%d%d%d",&N,&M,&K);
    if(N>M){
      int s=N;
      N=M;
      M=s;
    }
    

    for(int i=0;i<=N*M;++i){
      if(i+saikou(i) >=K){
	ans=i;
	break;
      }
    }
    
    printf("Case #%d: %d\n",cnt+1,ans);

  }

}
