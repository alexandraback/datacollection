#define __LOCAL__
#define FILEINPUT 1

//#include<bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <utility>
#include <functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <assert.h>


#include<unordered_set>
#include<unordered_map>



#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;


#define popcount(a) (__builtin_popcountll(a))
#define SZ(a)       ((int)a.size())
#define fs           first
#define sc           second
#define pb          push_back
#define ll          long long
#define ld          long double
#define MP          make_pair
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define CON(a,b)  ((a).find(b)!=(a).end())
#define mem(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define accu(a,b,c) accumulate((a),(b),(c))
#define fii(a,b)    for(int i=a;i<b;i++)
#define fij(a,b)    for(int j=a;j<b;j++)
#define fik(a,b)    for(int k=a;k<b;k++)
#define fil(a,b)    for(int l=a;l<b;l++)
#define ri(i,a)     for(int i=0;i<a;i++)
#define rii(a)      for(int i=0;i<a;i++)
#define rij(a)      for(int j=0;j<a;j++)
#define rik(a)      for(int k=0;k<a;k++)
#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define ERR         (1e-7)
#define EQ(a,b)     (fabs((a)-(b))<ERR)
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define p2(a)       (1LL<<a)
#define EX(msk,a)   (msk&p2(a))
#define isInRange(v,l,h) (min(l,h)<=v && v<=max(l,h))




#ifdef __LOCAL__
	#define deb(a)      cerr<<"#"<<__LINE__<<" -> "<<#a<<"  "<<a<<endl;
	// #define deb(a)      cout<<"#"<<__LINE__<<" -> "<<#a<<"  "<<a<<endl;
#define debug(a...)          {cout<<" #--> ";dbg,a; cout<<endl;}

struct debugger
{
    ///Collected from rudradevbasak
    template<typename T> debugger& operator , (const T v)
    {
        cout<<v<<" ";
        return *this;
    }
} dbg;
#else

#define deb(a) ;
#define debug(a...)  ;        

#endif



const double pi=acos(-1.0);
const double eps=1e-7;

template<class TT>TT sqr(TT a){return a*a;}
template<class TT>TT Abs(TT a){if(a<0)  return -a;return a;}
typedef pair<int,int> pii;

ll to(string s)
{
  SS ss;
  ss<<s;
  ll k;
  ss>>k;
  return k;
}

string sc,sj;
string fc,fj;
ll dif,minc,minj;
int L;

void go(int p,string c,string j,int stat)
{
  if(p == L)
  {
    ll a=to(c),b=to(j);
    if(dif > Abs(a-b)  || (dif == Abs(a-b) && minc >a ) ||  (dif == Abs(a-b) && minc == a && minj > b))
    {
      dif  = Abs(a-b);
      minc = a;
      minj = b;
      fc = c;
      fj = j;
    }
    return ;
  }

  if(stat==0)
  {
    char a=sc[p],b=sj[p];
      if(a =='?' && b=='?')
      {
          go(p+1,c+"0",j+"0",stat);
          go(p+1,c+"1",j+"0",1);
          go(p+1,c+"0",j+"1",2);

      }
      else if(a =='?')
      {
          go(p+1,c+b,j+b,stat);
          if(b<'9') go(p+1,c+char(b+1),j+b,1);
          if(b>'0') go(p+1,c+char(b-1),j+b,2);
      }
      else if(b=='?')
      {
          go(p+1,c+a,j+a,stat);
          if(a<'9') go(p+1,c+a, j+char(a+1), 2);
          if(a>'0') go(p+1,c+a, j+char(a-1), 1);
      }
      else 
      {
        int s=0;
        if(a>b) s=1;
        else if(a<b)  s=2;
        go(p+1,c+a,j+b,s);
      }
  }
  else if(stat==1)  //C already greater
  {
      go(p+1,sc[p]=='?'? c+"0": c+sc.substr(p,1), sj[p]=='?'? j+"9": j+sj.substr(p,1) ,stat);
  }
  else {
      go(p+1,sc[p]=='?'? c+"9": c+sc.substr(p,1), sj[p]=='?'? j+"0": j+sj.substr(p,1) ,stat);
  }
}

int main()
{
#ifdef FILEINPUT
    // freopen("in.in","r",stdin);
    freopen("B-small-attempt.in","r",stdin);
   freopen("out.out","w",stdout);
#endif // FILEINPUT

   ios_base::sync_with_stdio(0);cin.tie(0);



    int tks,ks=1;

    cin>>tks;
    while(tks--){
      cin>>sc>>sj;
      L = SZ(sc);
      minj = minc = dif = -1ull/2;

      // int a=0,b=0;
      // rii(L)if(sc[i]=='?')  a++;
      // rii(L)if(sj[i]=='?')  b++;
      // a = min(a,b);

      go(0,"","",0);
        cout<<"Case #"<<ks++<<": "<<fc<<" "<<fj<<"\n";
    }


   // int tks,ks=1;
   // scanf("%d",&tks);
   // while(tks--){
   //     printf("Case %d:\n",ks++);
   // }


    return 0;
}


//    ios_base::sync_with_stdio(0);cin.tie(0);
//    cout << fixed << setprecision(3) << (-20/3.0) << endl;
//    cout << setprecision(10)<<(-20/3.0)<<std::endl;


