#include <cstdio>
#include <cstring>

using namespace std;

const int mxn = 20;
const int mx_elem = 100000;

int n;
int niz[mxn];
bool bio[mx_elem*mxn+1];
int sol[mx_elem*mxn+1];

void output(int comb){
  for(int i = 0; i < n; i++){
    if(comb&(1<<i)) printf( "%d ", niz[i] );
  }
}

void solve(){
  memset(bio, 0, sizeof(bio));

  scanf( "%d", &n );
  for(int i = 0; i < n; i++){
    scanf("%d", &niz[i]);
  }

  for(int comb = 1; comb < (1<<n); comb++){
    int sum = 0;
    for(int i = 0; i < n; i++){
      if(comb&(1<<i)) sum += niz[i];
    }

    if(bio[sum]){
      output(sol[sum]);
      printf("\n");
      output(comb);
      break;
    } else {
      bio[sum] = 1;
      sol[sum] = comb;
    }
  }
}

int main(){
  int t;
  scanf( "%d", &t );

  for(int i = 0; i < t; i++){
    printf("Case #%d:\n",i+1);
    solve();
    printf( "\n" );
  }

  return 0;
}
