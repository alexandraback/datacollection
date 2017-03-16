#include<cstdio>

int N, s[20];
int d[1<<20];

void out(int n){
  bool b=0;
  for(int i=0; i<N; i++){
    if(n&(1<<i)){
      if(b)putchar(' ');
      printf("%d", s[i]);
      b=1;
    }
  }
  puts("");
}

int main(){
  int T;
  scanf("%d", &T);


  for(int tc=1; tc<=T; tc++){
    scanf("%d", &N);
    for(int i=0; i<N; i++)scanf("%d", s+i);

    for(int i=0; i<N; i++)
      d[1<<i]=s[i];

    for(int i=1; i<(1<<N); i++){
      int x=(i&-i), y=i-x;
      d[i]=d[x]+d[y];
    }

    printf("Case #%d:\n", tc);
    bool b=1;
    for(int i=1; b && i<(1<<N); i++){
      int x=(1<<N)-1-i, y;
      for(y=x;y;){
	if(d[i]==d[y]){
	  out(i);
	  out(y);
	  
	  b=0;
	  break;
	}
	y=(y-1)&x;
      }
    }
    if(b)puts("Impossible");
  }
  return 0;
}
