#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <utility>
#include <functional>
#define LL long long
#define vi vector<int>
#define pb push_back
#define sz size
#define all(x) (x).begin(),(x).end()
#define it iterator
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define REPX(i,a,b,c) for(int i=(a);i<(b);i+=(c))
#define DEP(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define REX(i,x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end();i++)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define spii stack<pii >
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define em empty
#define mems(x) memset(x,0,sizeof(x))
#define memc(x,y) memcpy(x,y,sizeof(y))
#define ord(c) (c-'0')
#define MAX 1010
using namespace std;
char x[MAX];
int main()
{
  int tc; scanf("%d",&tc);
  REP(t,0,tc)
  {
    int n,s=0,v=0; scanf("%d",&n);
    scanf("%s",x);
    REP(i,0,n+1)
    {
      if(i>s) { v+=i-s; s=i; }
      s+=ord(x[i]);
    }
    printf("Case #%d: %d\n",t+1,v);
  }
  return 0;
}

