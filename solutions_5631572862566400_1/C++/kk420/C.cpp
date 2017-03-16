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

int n, nast[1000];
VI poprz[1000];

int wGore(int ten, int skad)
{
  int wyn=0;
  VI &w=poprz[ten];
  Fori(w.size())
    if (w[i]!=skad)
      wyn=max(wyn, 1+wGore(w[i], ten));
  return wyn;
}

int cykl(int k)
{
  bool odw[1000]={};
  int dl=0, a;
  for (a=k; !odw[a]; a=nast[a])
  {
    odw[a]=true; 
    ++dl; 
  }
  return a==k ? dl : 0;
}

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    cin>>n;
    Fori(n)
      poprz[i].clear();
    Fori(n)
    {
      int a;
      cin>>a;
      --a;
      nast[i]=a;
      poprz[a].push_back(i);
    }
    int wyn=0;
    Fori(n)
      wyn=max(wyn, cykl(i));
    
    int u=0;
    Fori(n)
      for (int j=i; j<n; ++j)
        if (nast[i]==j && nast[j]==i)
        {
          u+=2+wGore(i, j)+wGore(j, i);
        }  
    wyn=max(wyn, u);  
    cout<<"Case #"<<ca<<": "<<wyn<<endl;
  }


  return 0;
}
