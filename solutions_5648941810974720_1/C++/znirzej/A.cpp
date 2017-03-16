#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define VVI vector<VI>
using namespace std;
int n,m,a,b,c,d;
string t[]={"EIGHT", "NINE"};
const int MXS = 2022;
char buf[MXS];
int cnt[146];
void solve()
  {
  scanf("%s", buf+1);
  n = strlen(buf+1);
  FOR(i,1,n)
    {
    cnt[buf[i]]++;
    }
  VI res;
  while(cnt['X'])
    {
    cnt['S']--;
    cnt['I']--;
    cnt['X']--;
    
    res.PB(6);
    }
    
  while(cnt['Z'])
    {
    cnt['Z']--;
    cnt['E']--;
    cnt['R']--;
    cnt['O']--;
    res.PB(0);
    }
    
  while(cnt['W'])
    {
    cnt['T']--;
    cnt['W']--;
    cnt['O']--;
    res.PB(2);
    }
  
  while(cnt['U'])
    {
    cnt['F']--;
    cnt['O']--;
    cnt['U']--;
    cnt['R']--;
    res.PB(4);
    }
  
  while(cnt['O'])
    {
    cnt['O']--;
    cnt['N']--;
    cnt['E']--;
    res.PB(1);
    }
  while(cnt['R'])
    {
    cnt['T']--;
    cnt['H']--;
    cnt['R']--;
    cnt['E']--;
    cnt['E']--;
    res.PB(3);
    } 
    
  while(cnt['F'])
    {
    cnt['F']--;
    cnt['I']--;
    cnt['V']--;
    cnt['E']--;
    res.PB(5);
    } 
  while(cnt['V'])
    {
    cnt['S']--;
    cnt['E']--;
    cnt['V']--;
    cnt['E']--;
    cnt['N']--;
    res.PB(7);
    } 
    
  while(cnt['G'])
    {
    cnt['E']--;
    cnt['I']--;
    cnt['G']--;
    cnt['H']--;
    cnt['T']--;
    res.PB(8);
    } 
    
  while(cnt['I'])
    {
    cnt['N']--;
    cnt['I']--;
    cnt['N']--;
    cnt['E']--;
    res.PB(9);
    } 
  
  sort(ALL(res));
  REP(i,res.size())printf("%d",res[i]);puts("");
  
  FOR(i,1, 130)
  if(cnt[i])
    {
    cerr<<"WUA"<<endl;
    exit(-1);
    }
  }
main()
{
int z;
scanf("%d",&z);
FOR(iii,1,z)
  {
  printf("Case #%d: ",iii);
  solve();
  }
}
