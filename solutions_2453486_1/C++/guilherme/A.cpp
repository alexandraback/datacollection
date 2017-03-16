#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<functional>
#include<sstream>
#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

#define DEBUG(x...) printf(x)
#define allv(v) (v).begin(),(v).end()
#define rall(v) (v).begin(),(v).rend()
#define _foreach(it,b,e) for(__typeof__(b); it!=(e);++it)
#define foreach(x...) _foreach(x)

typedef long long int huge;

const int inf = 0x3f3f3f3f;
const huge hugeinf = 0x3f3f3f3f3f3f3f3fll;//dois L's
const double eps = 1e-9;

char board[4][4];
bool invalid(int a, int b, char c){
  return board[a][b]!=c && board[a][b]!='T';
}
bool ganha(char c){
  for(int i=0;i<4;i++){
    bool ok=true;
    for(int j=0;j<4;j++)
      if(invalid(i,j,c))ok=false;
    if(ok)return true;

    ok=true;
    for(int j=0;j<4;j++)
      if(invalid(j,i,c))ok=false;
    if(ok)return true;

    ok=true;
    for(int j=0;j<4;j++)
      if(invalid(j,j,c))ok=false;
    if(ok)return true;

    ok=true;
    for(int j=0;j<4;j++)
      if(invalid(j,3-j,c))ok=false;
    if(ok)return true;

  }
}
bool fim(){
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      if(board[i][j]=='.')return false;
  return true;
}
int main ()
{
  int tt;
  scanf("%d",&tt);
  for(int pp=1;pp<=tt;pp++)
    {
      for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	  scanf(" %c",&board[i][j]);
      bool x=ganha('X');
      bool y=ganha('O');
      bool end=fim();
      assert(!(x&&y));
      printf("Case #%d: ",pp);
      if(x)printf("X won\n");
      else if(y)printf("O won\n");
      else if(end)printf("Draw\n");
      else printf("Game has not completed\n");
    }
  return 0;
}
