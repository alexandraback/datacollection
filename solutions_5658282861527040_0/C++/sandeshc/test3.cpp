#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;

const double eps=1e-11;
//const double pi=acos(-1.0);
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;


#define ff first
#define ss second
#define pb push_back
#define mkp make_pair
#define lpu(i,s,e) for(i=s;i<e;i++)
#define lpd(i,s,e) for(i=s;i>e;i--)
#define lpui(i,s,e) for(i=s;i<=e;i++)
#define lpdi(i,s,e) for(i=s;i>=e;i--)
#define abs(a) (a<0?-(a):a)
#define nl() cout << '\n'
#define nlf() cout << endl

inline void swap(int& a,int &b){ a^=b; b^=a; a^=b; }
inline lli min(lli& a,lli &b){ if(a<b) { return a; } else return b; }
inline lli max(lli& a,lli &b){ if(a>b) { return a; } else return b; }

# define getcx getchar
ull inp_ull()//fast input function
{
        ull n=0;
        int ch=getcx();
        while( ch < '0' || ch > '9' )
        {ch=getcx();}
        while( ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
        return n;
}

lli inp_lli()//fast input function
{
        lli n=0;
        int ch=getcx();
        int sign=1;
        while( ch < '0' || ch > '9' )
        {if(ch=='-')sign=-1; ch=getcx();}
        while( ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
        n=n*sign;
        return n;
}

int inp_int()//fast input function
{
        int n=0;
        int ch=getcx();
        int sign=1;
        while( ch < '0' || ch > '9' )
        {if(ch=='-')sign=-1; ch=getcx();}
        while( ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
        n=n*sign;
        return n;
}

void output(lli x)
{
  if(x<0)
    {
      putchar('-');
      x=-x;
    }
  int len=0,data[25];
  while(x)
    {
      data[len++]=x%10;
      x/=10;
    }
  if(!len)
    data[len++]=0;
  while(len--)
    putchar(data[len]+48);
  putchar('\n');
}

int main()
{  
  #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  
  int t,tp ;
  t=inp_int(); tp=0;
  lli a,b,k; lli i,j; lli cnt;
  while(tp<t){
    cnt = 0;
    a=inp_lli();b=inp_lli();k=inp_lli();
    lpu(i,0,a) lpu(j,0,b){
      if((i&j)<k) cnt++;
    }
    tp++; cout << "Case #" << tp << ": " << cnt << endl;
  }

  return 0;
}