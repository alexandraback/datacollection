#include <cstdio>
#include <algorithm>

using namespace std;

const int max_n = 1000;

int a;
int n;
int x[max_n];

void read_input()
{
  scanf("%d %d",&a,&n);
  for(int i=0; i<n; i++)
    scanf("%d",&x[i]);
  sort(x,x+n);
}

void solve(int t)
{
  int uneat = 0;
  int best = n;
  int cur = 0;
  while(uneat < n) {
    if(cur > n)
      break;
    if(x[uneat] < a) {
      a+=x[uneat];
      uneat++;
      if(cur + n - uneat < best)
        best = cur + n - uneat;
    } else {
      a+=(a-1);
      cur++;
    }
  }
  printf("Case #%d: %d\n",t+1,best);
}

main()
{
  int t;
  scanf("%d",&t);
  for(int tt=0; tt<t; tt++) {
    read_input();
    solve(tt);
  }
}
