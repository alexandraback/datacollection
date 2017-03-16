#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

int tt;
int d;
int pi[1010];
int cut;

int biSearch(int left, int right){
  int i, j, k;
  int mid;
  bool done;
  while(left < right){
    mid = (left+right) / 2;
    done = false;
    for(i=0; i<=cut && i<=mid && !done; ++i){
      priority_queue<int> p;
      for(j=0; j<d; ++j){
        p.push(pi[j]);
      }

      for(j=0; j<i; ++j){
        k = max(1, mid-i);
        p.push(k);
        p.push(p.top()-k);
        p.pop();
      }
      if(i + p.top() <= mid){
        done = true;
      }
    }
    if(done){
      right = mid;
    }else{
      left = mid+1;
    }
  }
  return left;
}

int main(void){
  int i, j, k;
  int time;
  int maxi;
  scanf("%d", &tt);
  for(int tc=1; tc<=tt; ++tc){
    scanf("%d", &d);
    maxi = cut = 0;
    for(i=0; i<d; ++i){
      scanf("%d", &pi[i]);
      maxi = max(maxi, pi[i]);
      cut += pi[i] / 2;
    }

    printf("Case #%d: %d\n", tc, biSearch(0, maxi));
  }
  return 0;
}
