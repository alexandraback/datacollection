#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

#define st first
#define nd second

typedef pair<int,int> pun;
typedef long long ll;
typedef pair<int, pair<int,int> > tri;

#define make(a,b,c) make_pair(a, make_pair(b,c) )

pun ori[N];

int f[1000][1000];
int deg[N];
int war[N];

int n = 0;
int dfs(int x,int y){
//  printf("dfs %d %d\n", x, y);
  if ( x == n ) return y;
  int flower = 0;
  if ( y == 0 ) return 0;
  for (; deg[x] <= n; deg[x]++) {
    if ( war[ deg[x] ] != war[x] + 1 ) continue;
    int ff = dfs( deg[x], min(y, f[x][deg[x]]) );
    f[x][deg[x]] -= ff;
    f[deg[x]][x] += ff;
    y -= ff;
    flower += ff;
    if ( y == 0 ) return flower;
  }
  return flower;
}

bool bfs(){
  queue<int> kol;
  kol.push(0);
  war[0] = 1;
  while( !kol.empty() ){
    int x = kol.front();
//    printf("bfs %d\n", x);
    if ( x == n ) return true;
    kol.pop();
    for (int i=0;i<=n;i++)
      if ( f[x][i] > 0 && war[i] == 0 ){
      war[i] = war[x]+1;
      kol.push(i);
    }
  }
  return false;
}

void flow(){
  while(1){
  for (int i=0;i<=n;i++)
    deg[i] = war[i] = 0;
  if ( bfs() == false ) return;
  dfs(0, 10000);
  }
}

int licz[11][11];

vector<tri> test()
{
  int A, B, C, K;
  scanf("%d%d%d%d",&A, &B, &C, &K);
  n = B + C + 1;

 vector<tri> wynik;
  for (int i=1;i<=A;i++)
  {
  for (int i=1;i<=B;i++){
    f[0][i] = K;
    f[i][0] = 0;
    }
   for (int i=1;i<=C;i++){
   f[n][B+i] = 0;
    f[B+i][n] = K;
    }
 
    for (int i=1;i<=B;i++)
      for (int j=1;j<=C;j++){
        if (licz[i][j] < K ) f[i][B+j] = 1;
        else f[i][B+j] = 0;
        f[B+j][i] = 0;
        }
    flow();
    for (int bi=1;bi<=B;bi++)
      for (int j=1;j<=C;j++) 
        if ( f[bi][B+j] == 0) {
          licz[bi][j] ++;
          wynik.push_back(make(i, bi, j) );
        }
        }
  for (int i=0;i<=n;i++){
    for (int j=0;j<=n;j++)
      f[i][j] = 0;
  }
    return wynik;
}

void print_test()
{
  auto x = test();
  printf("%d\n", x.size());
  for (auto y : x ) {
    printf("%d %d %d\n", y.first, y.second.first, y.second.second);
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
