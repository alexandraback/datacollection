#include<cstdio>
using namespace std;
int main ()
{
  int t;
  scanf ( "%d", &t );
  for ( int tt = 1; tt <= t; tt ++ )
  {
	int r, c, w;
	scanf( "%d %d %d", &r,&c,&w);
	int ans = c / w;
	ans *= r;
	if ( c % w == 0 ) ans += w - 1;
	else ans += w;
	printf ( "Case #%d: %d\n", tt, ans );
  }
}