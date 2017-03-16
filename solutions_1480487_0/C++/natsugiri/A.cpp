#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
  int T;
  int N, s[222], p[222];

  scanf("%d", &T);
  
  for(int tc=1; tc<=T; tc++){
    scanf("%d", &N);
    for(int i=0; i<N; i++)scanf("%d", s+i);
    for(int i=0; i<N; i++)p[i]=0;
    
    double x=0, y, z;
    int r=0;
    for(int i=0; i<N; i++)x+=s[i];
    z=x*2;
    y=z/N;
    for(int j=0; j<N; j++){
      for(int i=0; i<N; i++){
	if(p[i])continue;
	if(s[i]>y){
	  p[i]=1;
	  r++;
	  z-=s[i];
	  y=z/(N-r);
	}
      }
    }
    
    printf("Case #%d:", tc);
    for(int i=0; i<N; i++){
      double ans;
      if(p[i]==1)ans=0;
      else ans=(y-s[i])/x*100;
      printf(" %.9f", ans);
    }
    puts("");
  }
  return 0;
}
