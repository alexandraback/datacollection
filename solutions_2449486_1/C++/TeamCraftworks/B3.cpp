#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
int h,w;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int mex;

void draw(VVI &G,VVI &M,int x,int y,int dir)
{
  if(!(0 <= x && x < w && 0 <= y && y < h))
    return;
  
  bool res = false;
  mex = max(mex,G[y][x]);
  draw(G,M,x+dx[dir],y+dy[dir],dir);
  
  if(M[y][x] >= mex)
    M[y][x] = mex;

}

void print(VVI &G)
{
  cout << "--------- print" << endl;
 for(int i=0;i<h;i++)
   {
     for(int j=0;j<w;j++)
       {
	 cout << G[i][j] << " ";
       }
     cout << endl;
   }
 cout << endl;
}

int main()
{
  int T;
  int Nari = 1;
  cin >> T;
  while(T-- > 0)
    {
      cin >> h >> w;
      VVI G(h,VI(w));
      VVI M(h,VI(w));
      for(int i=0;i<h;i++)
	for(int j=0;j<w;j++)
	  cin >> G[i][j],M[i][j] = 100;

      for(int i=0;i<w;i++)
	mex = G[0][i],draw(G,M,i,0,0);
      for(int i=0;i<h;i++)
	mex = G[i][0],draw(G,M,0,i,1);

     

      cout << "Case #" << Nari++ << ": "; 
      G==M?cout << "YES" << endl:cout << "NO" << endl;

    }
  return 0;
}
