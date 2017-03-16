#include <bits/stdc++.h>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define PI acos(-1)
#define EPS 1e-8
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
#define bits(a) __builtin_popcount(a)

using namespace std;

int arr[105][55];
bool done[105];

int main()
{
  freopen("B-large.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;
  cin >> t;
  for(int tt=1;tt<=t;tt++)
  {
    int n;
    scanf("%d", &n);
    for(int i=0;i<2*n-1;i++)
      for(int j=0;j<n;j++)
        scanf("%d", &arr[i][j]);
    printf("Case #%d:", tt);
    setzero(done);
    for(int i=0;i<n;i++)
    {
      pair<int, int> ch = mp(-1, -1);
      for(int j=0;j<2*n-1;j++)
      {
        if(done[j]) continue;
        if(ch.f == -1 || arr[j][i] < arr[ch.f][i])
        {
          ch.f = j;
          ch.s = -1;
        }
        else if(arr[j][i] == arr[ch.f][i])
          ch.s = j;
      }
      done[ch.f] = true;
      if(ch.s == -1)
        printf(" %d", arr[ch.f][i]);
      else
      {
        done[ch.s] = true;
        multiset<int> s;
        for(int j=0;j<n;j++)
          s.insert(arr[ch.f][j]), s.insert(arr[ch.s][j]);
        for(int j=0;j<2*n-1;j++)
          s.erase(s.find(arr[j][i]));
        printf(" %d", (*s.begin()));
      }
    }
    printf("\n");
  }
  return 0;
}
