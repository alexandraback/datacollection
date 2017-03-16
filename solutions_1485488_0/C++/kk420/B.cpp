#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MaxInt=numeric_limits<int>::max();
typedef vector<int> VI;
typedef vector<string> VS;
#define For(i,a,n) for (int i=a; i<n; ++i)
#define Fori(n) For(i,0,n)

struct Wsp
{ int x, y;
  Wsp(int yy, int xx)
  {
    x=xx;
    y=yy;
  }
};

int wo, pod[100][100], suf[100][100], we[100][100], szer, wys;//[y, wys][x, szer]

bool mozna(Wsp a, Wsp b)
{
   if (b.x<0 || b.x>=szer || b.y<0 || b.y>=wys) return false;
   int s250=suf[b.y][b.x]-50;
   return wo<=s250 && pod[a.y][a.x]<=s250 && pod[b.y][b.x]<=s250 && pod[b.y][b.x]<=suf[a.y][a.x]-50;
}

int &wej(Wsp w)
{
  return we[w.y][w.x];
}

int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    
    cin>>wo>>wys>>szer;
    for (int y=0; y<wys; ++y)
      for (int x=0; x<szer; ++x)
      {
        cin>>suf[y][x];
        we[y][x]=MaxInt/2;
      }
    for (int y=0; y<wys; ++y)
      for (int x=0; x<szer; ++x)
        cin>>pod[y][x];
    we[0][0]=0;
    vector<Wsp> odw;
    odw.push_back(Wsp(0, 0));
    while (!odw.empty())
    {
      vector<Wsp> nast;
      for (int o=0; o<odw.size(); ++o)
      {
        Wsp &a=odw[o];
        for (int i=0; i<4; ++i)
        {
          Wsp b(a.y+dy[i], a.x+dx[i]);
          if (mozna(a, b) && wej(b))
          {
            nast.push_back(b);
            wej(b)=0;
          }
        }
      }
      odw.swap(nast);
    }
    for (int x=0; x<szer; ++x)
      for (int y=0; y<wys; ++y)
        if (!we[y][x]) odw.push_back(Wsp(y, x));
    int ter=0;
    while (we[wys-1][szer-1]>ter)
    {
      ++ter;
      --wo;
      vector<Wsp> nast;
      for (int o=0; o<odw.size(); ++o)
      {
        Wsp &a=odw[o];
        nast.push_back(a);
        int &wea=wej(a);
        if (wea>ter) 
          continue;
        Fori(4)
        {
          Wsp b(a.y+dy[i], a.x+dx[i]);
          int cz=ter+(wo-pod[a.y][a.x]>=20 ? 10 : 100);
          if (mozna(a, b) && wej(b)>cz)
          {
            nast.push_back(b);
            wej(b)=cz;
          }
        }  
      }
      odw.swap(nast);
    }
    
    
    cout<<"Case #"<<ca<<": "<<(we[wys-1][szer-1]/10)<<'.'<<(we[wys-1][szer-1]%10)<<endl;
  }

  char ccccc;
  cin>>ccccc;

  return 0;
}
