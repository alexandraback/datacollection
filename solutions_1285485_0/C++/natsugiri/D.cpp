#include<cstdio>
#include<set>

using namespace std;

int H, W, D;
char F[32][32];

int X, Y;

set<pair<int, int> >se;

int gcd(int a, int b){return b?gcd(b, a%b):a;}

int tate(int x, int y, int dx, int dy){
  int lx, ly;
  lx=x/2*2*(W-2);
  if(x%2){
    if(dx==1)lx+=(W-X-2)*2+1;
    else lx+=(X-1)*2+1;
  }
  ly=y/2*2*(H-2);
  if(y%2){
    if(dy==1)ly+=(H-Y-2)*2+1;
    else ly+=(Y-1)*2+1;
  }

  
  if(lx*lx+ly*ly>D*D)return 0;

  int tmp=0;
  int g=gcd(lx, ly);
  se.insert(make_pair(lx/g, ly/g));
  tmp++;
  tmp+=tate(x, y+1, dx, dy);
  return tmp;
}

int yoco(int x, int y, int dx, int dy){
  int tmp=tate(x, y, dx, dy);
  
  int lx=x/2*2*(W-2);
  if(x%2){
    if(dx==1)lx+=(W-X-2)*2+1;
    else lx+=(X-1)*2+1;
  }
  if(lx>D)return 0;
  return tmp+yoco(x+1, y, dx, dy);
}

int main(){
  int T;
  scanf("%d", &T);
  for(int tc=1; tc<=T;tc++){
    scanf("%d%d%d", &H, &W, &D);
    for(int i=0; i<H; i++)scanf("%s", F[i]);

    for(int j=0; j<H; j++)
      for(int i=0; i<W; i++)
	if(F[j][i]=='X')X=i, Y=j;

    int ans=0;
    yoco(1, 0, 1, 1);
    ans+=se.size(); se.clear();
    yoco(0, 1, 1, -1);
    ans+=se.size(); se.clear();
    yoco(1, 0, -1, -1);
    ans+=se.size(); se.clear();
    yoco(0, 1, -1, 1);
    ans+=se.size(); se.clear();

    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}
