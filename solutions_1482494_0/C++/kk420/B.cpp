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

/*
int n, a[1000], b[1000], g[1000], naj=100000;

void licz(int br)
{
  bool sa=true;
  Fori(n)
    if (g[i]<2) sa=false;
  if (sa && br==6) cout<<"xxxxxxxxxxxxx"<<endl;
  
}

int main1()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    cin>>n;
    Fori(n) cin>>a[i]>>b[i];
    licz(0);
    
    
  }

  char ccccc;
  cin>>ccccc;

  return 0;
}
    */
    
struct D
{ int a, b, g;
  const bool operator<(const D &d)
  {
    return b<d.b;
  }
} d[1000];

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    int n;
    cin>>n;
    Fori(n)
    {
      cin>>d[i].a>>d[i].b;
      d[i].g=0;
    }
    sort(d, d+n);
    int lgw=0, wyn=0;
    bool przegral=false;
    while (lgw<2*n && !przegral)
    {
      bool byl=false;
      Fori(n)
        if (d[i].g<2 && lgw>=d[i].b)
        {
          byl=true;
          lgw+=2-d[i].g;
          d[i].g=2;
          ++wyn;
        }
      if (byl) continue;
      
      int ruch=-1, poTym=lgw+1;
      
      Fori(n)
      {
        if (d[i].g==2) continue;
        if (d[i].b<=poTym) poTym+=2-d[i].g;
        else if (d[i].g==0 && d[i].a<=lgw && ruch==-1)
        {
          ruch=i;
          break;
        }
      }
      
      
      if (ruch==-1)
        Fori(n)
          if (d[i].g==0 && lgw>=d[i].a)
          {
            ruch=i;
          }
      
      if (ruch==-1) przegral=true;
      else
      {
        ++lgw;
        d[ruch].g=1;
        ++wyn;
      }
    }  
    cout<<"Case #"<<ca<<": ";
    if (przegral) cout<<"Too Bad";
    else cout<<wyn;
    cout<<endl;
  }

  char ccccc;
  cin>>ccccc;

  return 0;
}