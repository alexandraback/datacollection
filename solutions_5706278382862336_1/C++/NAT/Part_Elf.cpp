#include <cstdio>

int T;
long long A, B;
long long C;
long long p2[41];
bool can;
int ans;

long long gcd( long long X, long long Y){
  if( X % Y == 0)return Y;
  return gcd( Y, X % Y);
}

int main(){
  int i;

  freopen( "A-large.in", "r", stdin);
  freopen( "Part_Elf_large.txt", "w", stdout);

  p2[0] = 1;
  for( i = 1; i <= 40; i++)
    p2[i] = 2 * p2[i - 1];

  scanf("%d", &T);
  for( int tt = 1; tt <= T; tt++){
    scanf("%lld/%lld", &A, &B); 

    C = gcd( A, B);
    
    A /= C;
    B /= C;

    can = false;
    for( i = 0; i <= 40; i++)
      if( p2[i] == B){
	can = true;
	break;
      }

    printf("Case #%d: ", tt);
    if( !can || A == 0)printf("impossible\n");
    else{
      ans = 1;
      while( A < B / 2){
	ans++;
	B /= 2;
      }
      printf("%d\n", ans);
    }
  }
}
