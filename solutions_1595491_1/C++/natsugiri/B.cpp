#include<cstdio>


int N, S, p, t;

int a,b;


int main(){
  int T;
  scanf("%d", &T);
  
  for(int tc=1; tc<=T; tc++){
    scanf("%d%d%d", &N, &S, &p);

    a=b=0;
    
    for(int i=0; i<N; i++){
      scanf("%d", &t);
      
      if(t<p)continue;
      if((t-p)/2 > p-3)a++;
      if((t-p)/2 > p-2)b++;
    }

    a=a-b<S?a-b:S;
    printf("Case #%d: %d\n", tc, b+a);
  }
  return 0;
}
