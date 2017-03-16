#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#define INF 2000000000
#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define PI pair<int, int>
#define ST first
#define ND second
#define CLR(a, b) memset(a, b, sizeof(a))
#ifdef DEBUG
  #define DBG printf
#else
  #define DBG 
#endif
using namespace std;

int t[2005];
int ab[2005][2];
vector<PI> two, one;
bool comp( const PI &A, const PI &B){
  if( A.ST < B.ST)return true;
  if( A.ST == B.ST){
    if( ab[A.ND][1] > ab[B.ND][1]) return true;
    else if( ab[A.ND] == ab[B.ND]) return A.ND < B.ND;
  }
  return false;
}

int main(){
  int d, n, a, b;
  scanf("%d",&d);
  int casenum = 0;
  while(d--){
    casenum++;
    scanf("%d",&n);
    CLR(t, 0);
    one.clear();
    two.clear();
    REP(i, n){
      scanf("%d %d",&a, &b);
      ab[i][0] = a;
      ab[i][1] = b;
      one.push_back(PI(a, i));
      two.push_back(PI(b, i));
    }
    sort(two.begin(), two.end(), comp);
    sort(one.begin(), one.end(), comp);
/*
    REP(i, one.size()){
      printf("(%d %d) ",one[i].ST, one[i].ND);
    }
    printf("\n");*/
    int res = 0;
    int won = 0;
    int games = 0;
    int fail = 0;
    while( won != n){
      int found2 = -1, found1 = -1;
      REP(i, two.size()){
        if( two[i].ST > res ) break;
        if( t[two[i].ND] == 0 ){
          found2 = 1;
          won++;
          games++;
          //printf("2play_game %d\n", two[i].ND);
          res+=2;
          t[two[i].ND] = 2;
        }
        else if( t[two[i].ND] == 1) found1 = two[i].ND;
      }
      if( found2 != -1) continue;
      else if(found1 != -1){
        t[found1] = 2;
        //printf("1play_game %d\n", found1);
        games++;
        won++;
        res++;
      }
      else{
        REP(i, one.size()){
          if( one[i].ST > res) break;
          if( t[one[i].ND] == 0){found1 = one[i].ND; break;}
        }
        if( found1 != -1){
          t[found1] = 1;
          //printf("0play_game %d\n", found1);
          games++;
          res++;
        }
        if( found1 == -1 && won != n){
          fail = 1;
          break;
        }
      }
    }
    if( fail == 1) printf("Case #%d: Too Bad\n",casenum);
    else printf("Case #%d: %d\n", casenum, games);
  }

  return 0;
}
