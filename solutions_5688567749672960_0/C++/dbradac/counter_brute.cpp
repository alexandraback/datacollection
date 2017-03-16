#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 10000000;

queue <int> Q;
int bio[MAX];

int Rev(int n)
{
  int p[20], i=0;

  for (; n; n /= 10, i++)
    p[i] = n % 10;
  
  int ret=0;
  for (int j=0; j<i; j++)
    ret = 10 * ret + p[j];

  return ret;
}


void Bfs()
{
  bio[1] = 1;
  Q.push(1);

  for (; !Q.empty(); ) {
    int n = Q.front();
    Q.pop();
    if (n + 1 < MAX && !bio[n+1]) {
      bio[n+1] = bio[n] + 1;
      Q.push(n+1);
    }
    int tmp = Rev(n);
    if (tmp < MAX && !bio[tmp]) {
      bio[tmp] = bio[n] + 1;
      Q.push(tmp);
    }
  }
}


int main()
{
  int tt;

  Bfs();
  fprintf(stderr, "DONE\n");

  scanf("%d", &tt);


  for (int i=1; i<=tt; i++) {
    int tmp;
    scanf("%d", &tmp);
    printf("Case #%d: %d\n", i, bio[tmp]);
  }

  return 0;
}
