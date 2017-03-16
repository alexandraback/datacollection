#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int N;
char p[15][105];
int ans;
bool chk[30];
int temp[15];
int last;
bool can;

int main(){
  int i, j, k;

  freopen( "B-small-attempt1.in", "r", stdin);
  freopen( "Reordering_Train_Cars_s.txt", "w", stdout);

  scanf("%d", &T);
  for( int tt = 1; tt <= T; tt++){
    ans = 0;
    memset( temp, 0, sizeof temp);

    scanf("%d", &N);
    for( i = 0; i < N; i++){
      scanf("%s", p[i]);
      
      temp[i] = i;
    }

    do{
      can = true;
      memset( chk, 0, sizeof( chk));
      last = 29;

      for( i = 0; i < N && can; i++){
	for( j = 0; p[ temp[i]][j] != '\0' && can; j++){
	  if( p[ temp[i]][j] - 'a' != last){
	    if( chk[ p[ temp[i]][j] - 'a'] == 0){
	      chk[ p[ temp[i]][j] - 'a'] = 1;
	      last = p[ temp[i]][j] - 'a';
	    }
	    else can = false;
	  }
	}
      }
      if( can)ans++;
    }while( next_permutation( temp, temp + N));

    printf("Case #%d: %d\n", tt, ans % 1000000007);
  }
}
