#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdlib>
using namespace std;

int a_orig[1001];
int b_orig[1001];
int a_des[1001];
int b_des[1001];
int a_inc[1001];
int b_inc[1001];

int desind[1001];
int incind[1001];

bool slvd1[1001];
bool slvd2[1001];

int compare_des(const void * n1, const void * n2)
{ return ( b_orig[*(int*)n2] - b_orig[*(int*)n1] ); }
int compare_inc(const void * n1, const void * n2)
{ return ( b_orig[*(int*)n1] - b_orig[*(int*)n2] ); }

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    int cnt = 0;
    bool success = false;
    
    int N; cin >> N;
    for (int i=1;i<=N;i++) {
      cin >> a_orig[i] >> b_orig[i];
      slvd1[i] = false;
      slvd2[i] = false;
    }
    
    //if (t != 8) continue;

    for (int i=1;i<=N;i++) {desind[i]=i; incind[i]=i;}
    qsort(&desind[1], N, sizeof(int), compare_des);
    qsort(&incind[1], N, sizeof(int), compare_inc);
    
    for (int i=1;i<=N;i++) {
      a_des[i] = a_orig[desind[i]];
      b_des[i] = b_orig[desind[i]];
      a_inc[i] = a_orig[incind[i]];
      b_inc[i] = b_orig[incind[i]];
    }

    int jump_st = 1;

    int rem = N;
    int st = 0;
    while (true) {
      if (rem == 0) {success=true;break;}

      bool flag = false;
      for (int n=jump_st;n<=N;n++) {
        if(slvd2[incind[n]])break;
        if(b_inc[n]<=st) {
          slvd2[incind[n]]=true;
          rem--; st++;
          if(!slvd1[incind[n]]) {st++;slvd1[incind[n]]=true;}
          cnt++;
          jump_st = n+1;
          flag = true;
        }
      }

      if (flag) continue;

      for (int n=1;n<=N;n++) {
        if(slvd1[desind[n]])continue;
        if(a_des[n]<=st) {
          slvd1[desind[n]]=true;
          st++;
          cnt++;
          flag=true;
          break;
        }
      }

      if (!flag) break;
    }

    if (success) {
      printf("Case #%d: %d\n",t,cnt);
    } else {
      printf("Case #%d: Too Bad\n",t);
    }
  }
}
