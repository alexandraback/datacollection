#include<cstdio>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 1024;
int T;
int N;

int d[MAXN];
int n[MAXN];
int w[MAXN];
int e[MAXN];
int s[MAXN];
int delta_d[MAXN];
int delta_p[MAXN];
int delta_s[MAXN];
int h[MAXN];
struct Attack{
  int d;
  int l,r;
  int s;
};

vector<Attack> attacks;
bool operator<(const Attack& a, const Attack& b){
  return a.d<b.d;
}

void input(){
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%d%d%d%d%d%d%d%d", &d[i], &n[i], &w[i], &e[i], &s[i], &delta_d[i],
      &delta_p[i], &delta_s[i]);
  }
  attacks.clear();
  for (int i = 0; i < N; i++){
    //printf("%d", n[i]);
    for (int ni = 0; ni < n[i]; ni++){
      Attack a;
      a.d = d[i] + ni*delta_d[i];
      a.l = 100+ w[i] + ni*delta_p[i];
      a.r = 100+ e[i] + ni*delta_p[i] - 1;
      a.s = s[i] + ni*delta_s[i];
      attacks.push_back(a);
    }
  }
  //printf("%d\n", (int)attacks.size());
  sort(attacks.begin(), attacks.end());
}

bool sucess(const Attack &a){
  for (int i = max(a.l, 0); i<= min(a.r, 200); i++){
    if (h[i] < a.s)
      return true;
  }
  return false;
}

void update(const Attack &a){
  for (int i = max(a.l,0); i <= min(a.r, 200); i++){
    h[i] = max(h[i], a.s);
  }
}

int solve(){
  memset(h, 0, sizeof(h));
  int total = 0;
//  for (int i = 0; i < (int)attacks.size(); i++){
//    printf("attacks %d: %d %d %d %d\n", i,attacks[i].d, attacks[i].l, attacks[i].r, attacks[i].s);
 // }
  for (int i = 0; i < (int)attacks.size(); i++){
  //  printf("==%d\n", i);
    if (i!=0 && attacks[i].d==attacks[i-1].d)
      continue;
    int j;
    for (j = i; j < (int)attacks.size(); j++){
      if (attacks[j].d != attacks[i].d)
        break;
    }
//    printf("%d %d\n", i, j);
    for (int k = i; k < j; k++){
 //     printf("try: %d\n", k);
      if (sucess(attacks[k])){
        total++;
      }
    }
    for (int k = i; k < j; k++){
      update(attacks[k]);
    }
  }
  return total;
}

int main(){
  scanf("%d", &T);
  for (int i = 1; i <= T; i++){
    input();
    int ans = solve();
    printf("Case #%d: %d\n", i, ans);
  }
}

