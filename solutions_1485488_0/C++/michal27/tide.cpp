#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,pair<int,int> > Tri;

bool moze(int c1,int f1,int w1,int c2,int f2,int w2)
{
  if(c2-max(w2,f2)<50) return false;
  if(c2-max(w1,f1)<50) return false;
  if(c1-max(w2,f2)<50) return false;
  return true;
}

int main()
{
  int t1;
  scanf("%d ",&t1);
  for(int i1=1; i1<=t1; i1++)
  {
    int h,n,m;
    scanf("%d %d %d ",&h,&n,&m);
    vector<vector<int> > C;
    vector<vector<int> > F;
    C.resize(n+2); F.resize(n+2);
    for(int i=0; i<m+2;  i++) {C[0].push_back(0); F[0].push_back(0);}
    for(int i=1; i<=n; i++)
    {
      C[i].push_back(0);
      for(int j=1; j<=m; j++) {int x; scanf("%d ",&x); C[i].push_back(x);}
      C[i].push_back(0);
    }
    for(int i=1; i<=n; i++)
    {
      F[i].push_back(0);
      for(int j=1; j<=m; j++) {int x; scanf("%d ",&x); F[i].push_back(x);}
      F[i].push_back(0);
    }
    for(int i=0; i<m+2;  i++) {C[n+1].push_back(0); F[n+1].push_back(0);}
    //printf("@\n");
    //podme zitit kam vsade sa viem dostat z 1 1
    vector<vector<bool> > Kam; Kam.resize(n+2);
    for(int i=0; i<n+2; i++) {Kam[i].resize(m+2,false);}
    Kam[1][1]=true;
    queue<pair<int,int> > Q; Q.push(make_pair(1,1));
    while(!Q.empty())
    {
      pair<int,int> b=Q.front(); Q.pop();
      int dx[]={0,0,1,-1};
      int dy[]={1,-1,0,0};
      for(int i=0; i<4; i++)
      {
	pair<int,int> b1;
	b1.first=b.first+dy[i];
	b1.second=b.second+dx[i];
	if(moze(C[b.first][b.second],F[b.first][b.second],h,C[b1.first][b1.second],F[b1.first][b1.second],h) && Kam[b1.first][b1.second]==false)
	{
	  Kam[b1.first][b1.second]=true;
	  Q.push(b1);
	}
      }
    }
    //z kazdeho takeho vrchola musim pustit dijkstru
    int vys=n*m*100+47;
    for(int y1=1; y1<=n; y1++)
      for(int x1=1; x1<=m; x1++)
      {
	if(Kam[y1][x1]==false) continue;
	vector<vector<bool> > T; T.resize(n+2);
	for(int i=0; i<n+2; i++) T[i].resize(m+2,false);
	priority_queue<Tri> Halda;
	Halda.push(make_pair(0,make_pair(y1,x1)));
	while(!Halda.empty())
	{
	  while(!Halda.empty() && T[Halda.top().second.first][Halda.top().second.second]==true) Halda.pop();
	  if(!Halda.empty())
	  {
	    int cas=-Halda.top().first;
	    int y=Halda.top().second.first,x=Halda.top().second.second;
	    //printf("%d %d %d\n",cas,y,x);
	    T[y][x]=true;
	    if(y==n && x==m) vys=min(vys,cas);
	    int dy[]={0,0,1,-1};
	    int dx[]={1,-1,0,0};
	    int vyska=max(0,h-cas);
	    for(int i=0; i<4; i++)
	    {
	      int y2=y+dy[i],x2=x+dx[i];
	      //printf("#%d %d\n",y2,x2);
	      if(moze(C[y][x],F[y][x],vyska,C[y2][x2],F[y2][x2],vyska) && vyska-F[y][x]>=20) Halda.push(make_pair(-cas-10,make_pair(y2,x2)));
	      else if(moze(C[y][x],F[y][x],vyska,C[y2][x2],F[y2][x2],vyska)) Halda.push(make_pair(-cas-100,make_pair(y2,x2)));
	      else
	      {
		//printf("kontrola %d\n",moze(C[y][x],F[y][x],vyska-17,C[y2][x2],F[y2][x2],vyska-17));
		for(int j=1; j<=vyska; j++)
		{
		  if(moze(C[y][x],F[y][x],vyska-j,C[y2][x2],F[y2][x2],vyska-j) && vyska-j-F[y][x]>=20) {Halda.push(make_pair(-cas-10-j,make_pair(y2,x2))); break;}
		  else if(moze(C[y][x],F[y][x],vyska-j,C[y2][x2],F[y2][x2],vyska-j)) {Halda.push(make_pair(-cas-100-j,make_pair(y2,x2))); break;}
		}
	      }
	    }
	  }
	}
      }
      printf("Case #%d: %0.1f\n",i1,vys/(double)10.0);
  }
return 0;
}