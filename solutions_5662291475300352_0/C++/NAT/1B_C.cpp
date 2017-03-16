#include <cstdio>

int T;
int N;
int D[2], H[2], M[2];
int ans;
int a, b;

int main(){
  scanf("%d", &T);

  for(int tt = 1; tt <= T; tt++){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
      scanf("%d %d %d", &D[i], &H[i], &M[i]);

    if(N == 1)
      ans = 0;
    else{
      if(D[0] < D[1]){
	a = 0;
	b = 1;
      }
      else{
	a = 1;
	b = 0;
      }

      if(M[a] == M[b])
	ans = 0;
      else if(M[a] < M[b]){
	if((360 - D[b]) * M[b] + 1 < (720 - D[a]) * M[a])
	  ans = 0;
	else ans = 1;
      }
      else{
	if((360 - D[a]) * M[a] + 1 < (720 - D[b]) * M[b])
	  ans = 0;
	else ans = 1;
      }
    }

    printf("Case #%d: %d\n", tt, ans);
  }
}
