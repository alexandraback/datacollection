#include<cassert>
#include<queue>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<iostream>
#include<algorithm>

#define eps 1e-12

#define sqr(a) ((a)*(a))
#define mp(a,b) make_pair(a,b) 
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define taskname ""
#ifdef DEBUG
#define deb(x) cerr<<#x<<'='<<x<<endl
#else
#define deb(x) 
#endif
typedef long long ll;

using namespace std;

int cnt(vector<int> st,int x){
  int ans = 0;
  forn(mask, 1 << st.size()){
    ll mul = 1;
    forn(i, st.size())
      if(mask >> i & 1)
        mul *= st[i];
    if(mul == x)
      ans++;
  }
  return ans;
    
}
double func(vector<int> st,vector<int> get){
  double ans = 0;
  forn(i, get.size()){
    int tmp = cnt(st,get[i]);
    if(tmp == 0)
      return -1;
    ans += log(tmp);
  }
  return ans;
    
}
int main()         
{
  assert(freopen(taskname"in","r",stdin));
  assert(freopen(taskname"out","w",stdout));
  int test_n;
  scanf("%d",&test_n);
  forn(test_id,test_n)
  {
    printf("Case #%d:\n",test_id+1);
    int r,n,m,k;
    scanf("%d %d %d %d\n",&r,&n,&m,&k);
    forn(i,r){ 
      vector<int> get;
      forn(j,k){
        int a;
        scanf("%d",&a);
        get.push_back(a);
      }
      vector<int> st(3);
      vector<int> best(3,2);
      for( st[0] = 2; st[0] <= m;st[0]++)
        for(st[1] = 2;st[1] <= m;st[1]++)
          for( st[2] = 2; st[2] <= m;st[2]++)
            if(func(st,get) > func(best,get))
              best = st;
      forn(i,3)
        printf("%d",best[i]);
      printf("\n");
    }
  }
  return 0;
}

