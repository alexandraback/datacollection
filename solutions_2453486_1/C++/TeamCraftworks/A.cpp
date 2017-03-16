#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef vector<vector<char> > VVC;
int dx[] = {0,1,0,-1,1,1,-1,-1};
int dy[] = {1,0,-1,0,1,-1,1,-1};
bool NC;

bool dirCheck(VVC &G,int x,int y,int dir)
{
  char c = G[y][x];
  for(int j=0;j<3;j++)
    {
      int nx = x + (j+1)*dx[dir];
      int ny = y + (j+1)*dy[dir];
      if(!(0 <= nx && nx < 4 && 0 <= ny && ny < 4))
	return false;	  
      if(!((G[ny][nx] == c) || (G[ny][nx] == 'T')))
	return false;
    }
  
  return true;
}

int check(VVC &G)
{
  int Xwon,Cwon;
  Xwon = Cwon = 0;
  for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
	{
	  if(G[i][j] == '.' || G[i][j] == 'T')
	    continue;
	  for(int k=0;k<8;k++)
	    {
	      if(dirCheck(G,j,i,k))
		G[i][j] == 'X'?Xwon++:Cwon++;
	    }
	}
    }
  // cout << Xwon << " " << Cwon << endl;
  if(Xwon && !Cwon)
    return 1;
  if(!Xwon && Cwon)
    return 2;
  if(!NC && !Xwon && !Cwon)
    return 3;
  return 0;
}

int main()
{
  int T,Nari;
  cin >> T;
  Nari = 1;
  while(T-- > 0)
    {
      NC = false;
      VVC G(4,vector<char>(4));
      for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	  {
	    cin >> G[i][j];
	    if(G[i][j] == '.')
	      NC = true;
	  }

      int res = check(G);
      cout << "Case #" << Nari++ << ": "; 
      !res?cout << "Game has not completed" << endl:res == 1?cout << "X won" << endl:res == 2?cout << "O won" << endl:cout << "Draw" << endl;;
    }
  return 0;
}
