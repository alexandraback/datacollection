#include<bits/stdc++.h>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >

int main() {
  int r,c,m,T, kase = 0;
  char board[64][64];
  cin>>T;
  while(T--) {
    cin>>r>>c>>m;
    printf("Case #%d:\n",++kase);
    if(r > 1 && c > 1 && m > r*c - 4) {
      printf("Impossible\n");
      continue;
    }
    fill(&board[0][0], &board[0][0] + sizeof(board)/sizeof(board[0][0]), '*');
    board[0][0] = 'c';
    m++;
    for(int i=1;i<r;i++) {
      for(int j=0;j<=i;j++) {
        if(r*c > m) {
          board[i][j] = '.';
        }
        m++;
      }
      for(int j=i-1;j>=0;j--) {
        if(r*c > m) {
          board[j][i] = '.';
        }
        m++;
      }
    }
    for(int i=0;i<r;i++) {
      for(int j=0;j<c;j++) {
        printf("%c",board[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
