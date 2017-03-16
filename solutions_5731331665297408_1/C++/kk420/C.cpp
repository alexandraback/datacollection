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

struct S
{
  string kod;
  vector<int> sa;
  bool odw1, odw2;
};

int n, m;
S g[50];
vector<int> stos;

int lDocel(int skad)
{
  g[skad].odw2=true;
  int wyn=0;
  Fori(g[skad].sa.size())
  {
    int dokad=g[skad].sa[i];
    if (!g[dokad].odw1 && !g[dokad].odw2)
      wyn+=1+lDocel(dokad);
  }
  return wyn;
}

int lDocelowych(int rozmStosu)
{
  Fori(n)
    g[i].odw2=false;
  int wyn=0;
  Fori(rozmStosu)
    wyn+=lDocel(stos[i]);
  return wyn;
}

string idz(int cel)
{
  int byloOdw=1;
  g[cel].odw1=true;
  string wyn=g[cel].kod;
  stos.push_back(cel);
  
  while (byloOdw<n)
  {
    string mi="";
    int nrNaj=-1, rozmStosuNaj=-1;
    for (; ; )
    {
      string naj="x";
      for (int i=stos.size()-1; i>=0; --i)
      {
        int ii=stos[i];
        for (int j=0; j<g[ii].sa.size(); ++j)
        {
          int jj=g[ii].sa[j];
          if (g[jj].odw1)
            continue;
          if (g[jj].kod>mi && g[jj].kod<naj)
          {
            naj=g[jj].kod;
            nrNaj=jj;
            rozmStosuNaj=i+1;
          } 
        }  
      }
      mi=naj;
      if (lDocelowych(rozmStosuNaj)+byloOdw==n)
        break;
    }
    while (stos.size()>rozmStosuNaj)
      stos.pop_back();
    wyn+=g[nrNaj].kod;
    stos.push_back(nrNaj);
    g[nrNaj].odw1=true;
    ++byloOdw;
  }
  return wyn;
}

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    cin>>n>>m;
    int pierw=-1;
    string kodPierw="x";
    Fori(n)
    {
      cin>>g[i].kod;
      g[i].sa.clear();
      g[i].odw1=false;      
      if (g[i].kod<kodPierw)
      {  
        pierw=i;
        kodPierw=g[i].kod;
      }
    }
    Fori(m)
    {
      int a, b;
      cin>>a>>b;
      --a;
      --b;
      g[a].sa.push_back(b);
      g[b].sa.push_back(a);
    }
    stos.clear();
    cout<<"Case #"<<ca<<": "<<idz(pierw)<<endl;
  }


  return 0;
}
