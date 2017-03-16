#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define st first
#define nd second
#define make(a,b) make_pair(a,b)

typedef pair<int,int> pun;
typedef long long ll;

int tab[100][100];

  int n;
int test()
{
  long long m;
  scanf("%d%lld",&n,&m);
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      tab[i][j] = 0;
  for (int i=0;i<n-1;i++)
    for (int j=i+1;j<n-1;j++)
      tab[i][j] = 1;
  if ( m > (1LL<<(n-2)) ) return -1;
  if ( m == (1LL<<(n-2)) )
    for (int i=0;i<n-1;i++)
      tab[i][n-1] = 1;
  if ( m < (1LL<<(n-2)) ){
    for (int i=0;i<(n-2);i++)
      if ( (1LL<<i) & m ){
        tab[i+1][n-1] = 1;
      }
  }
  return 1;

}

void print_test()
{
  auto x = test();
  if ( x == -1 ) printf("IMPOSSIBLE\n");
  else{
    printf("POSSIBLE\n");
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++)
      {
        printf("%d",tab[i][j]);
      }printf("\n");
      }
  }
}

int main()
{
	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
    print_test();
	}
}
