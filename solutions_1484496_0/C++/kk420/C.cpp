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

int n, s[1000], g[1000];

bool licz(int ile, int su1, int su2)
{
  if (su1 && su1==su2) 
  {
    for (int i=ile; i<n; ++i)
      g[i]=0;
    return true;
  }
    
  if (ile==n) return false;
  g[ile]=0;
  if (licz(ile+1, su1, su2)) return true;
  g[ile]=1;
  if (licz(ile+1, su1+s[ile], su2)) return true;
  g[ile]=2;
  if (licz(ile+1, su1, su2+s[ile])) return true;
  return false;
}

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    cin>>n;
    Fori(n) cin>>s[i];
    cout<<"Case #"<<ca<<": "<<endl;
    Fori(n) g[i]=0;
    int a=0, b=0;
    if (licz(0, 0, 0)) 
    {
      Fori(n)
        if (g[i]==1) {cout<<s[i]<<' '; a+=s[i];}
      cout<<endl;
      Fori(n)
        if (g[i]==2) {cout<<s[i]<<' '; b+=s[i];}
      cout<<endl;
     // cout<<"======= "<<a<<' '<<b<<endl;
    }
    else cout<<"Impossible"<<endl;
  }

  char ccccc;
  cin>>ccccc;

  return 0;
}
