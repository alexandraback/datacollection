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

VI kws[20];
int n, kos[20];
int wyn[1<<20];//1 - po otwarciu tych skrzyn da sie otworzyc reszte, 2 - nie da sie 
int nast[1<<20];

bool daSie(int otwarte, VI &klucze)
{
  if (wyn[otwarte])
    return wyn[otwarte]==1;
  if (otwarte==(1<<n)-1)
    return true;
  Fori(n)
  {
    int bit=1<<i;
    if (otwarte&bit)
      continue;
    int pozKlucza=-1;
    for (int j=0; j<klucze.size(); ++j)
      if (klucze[j]==kos[i])
      {
        pozKlucza=j;
        break;
      }
    if (pozKlucza==-1)
      continue;
    klucze[pozKlucza]=-1;
    for (int j=0; j<kws[i].size(); ++j)
      klucze.push_back(kws[i][j]);
    bool b=daSie(otwarte|bit, klucze);    
    klucze.resize(klucze.size()-kws[i].size());
    klucze[pozKlucza]=kos[i];
    if (b)
    {
      wyn[otwarte]=1;
      nast[otwarte]=i;
      return true;
    }
  }    
  wyn[otwarte]=2;
  return false;
}

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    int k;
    cin>>k>>n;
    VI klucze;
    Fori(k)
    {
      int a;
      cin>>a;
      klucze.push_back(a);
    }
    Fori(n)
    {
      int lk;
      cin>>kos[i]>>lk;
      kws[i].clear();
      for (int j=0; j<lk; ++j)
      {
        int a;
        cin>>a;
        kws[i].push_back(a);
      }
    } 
    memset(wyn, 0, sizeof(wyn[0])*(1<<n));
    cout<<"Case #"<<ca<<": ";
    if (!daSie(0, klucze))
    {
      cout<<"IMPOSSIBLE\n";
      continue;
    }
    int otwarte=0;
    Fori(n)
    {
      cout<<nast[otwarte]+1<<' ';
      otwarte|=(1<<nast[otwarte]);
    }
    cout<<endl;
  }

  return 0;
}
