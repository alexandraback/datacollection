#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int a[105][105];

inline void solv(int case_number){
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d", &a[i][j]);
    }
  }

  printf("Case #%d: ", case_number);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      
      int cnt = 2;
      
      for(int k = 0; k < n; k++){
	if(a[k][j] > a[i][j]){
	  cnt--;
 	  break;
	}
      }

      for(int k = 0; k < m; k++){
	if(a[i][k] > a[i][j]){
	  cnt--;
	  break;
	}
      }

      if(not cnt){
	goto f;
      }
      
    }
  }
  
  printf("YES\n");
  return;
 f:;
  printf("NO\n");
}

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 1; i <= T; i++){
    solv(i);
  }
}
