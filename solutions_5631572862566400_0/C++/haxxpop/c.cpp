#include <stdio.h>
#include <vector>
using namespace std;
int next[100000];
vector<int> rev[10000];
int ch[10000];
int n;
int find_max(int k){
  int maxx = 0;
  ch[k] = 1;
  for(int i = 0 ; i < rev[k].size() ; i++ ){
    if( ch[rev[k][i]] == 0 ){
      int res = find_max(rev[k][i]);
      if( res > maxx ) maxx = res;
    }
  }
  maxx++;
  return maxx;
}

int main(){
  int t;
  scanf("%d",&t);
  for(int e = 0 ; e < t ; e++ ){
    scanf("%d",&n);
    for(int i = 0; i < n ; i++ ) rev[i].clear();
    for(int i = 0; i < n ; i++ ){
      int x;
      scanf("%d",&x);
      x--;
      next[i] = x;
      rev[x].push_back(i);
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++ ) ch[i] = 0;
    for(int i = 0 ; i < n ; i++ ){
      if( ch[i] == 0 ){
        int pos = i;
        for( ; ch[pos] == 0 ; ){
          ch[pos] = i+1;
          pos = next[pos];
        }
        if( ch[pos] == i+1 ){
          int tmp = pos;
          int cur = 1;
          tmp = next[tmp];
          for( ; tmp != pos ; ){
            cur++;
            tmp = next[tmp];
          }
          if( cur > ans ) ans = cur;
        }
      }
    }
    // printf("Case #%d: %d\n",e+1,ans);

    for(int i = 0 ; i < n ; i++ ) ch[i] = 0;
    int res = 0;
    for(int i = 0 ; i < n ; i++ ){
      if( ch[i] == 0 && next[next[i]] == i ){
        ch[i] = 1;
        ch[next[i]] = 1;
        res += find_max(i) + find_max(next[i]);
      }
    }
    if( res > ans ) ans = res;
    printf("Case #%d: %d\n",e+1,ans);
  }
}
