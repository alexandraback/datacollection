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
template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
typedef pair<int,int> pii;

const string dgt[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
map<char,int>mp;
string ans;
string in;
const string sign="ZWUXGHFSOI";
const string digit="0246835719";


void getAns(){

  int l = SZ(in);
  mp.clear();

  rii(l)    mp[ in[i] ]++;

  ans="";
  int  oc, no,di;
  int len = SZ(sign);

  rii(len)
  {
    oc = mp[sign[i]];
    di = digit[i];
    rij(oc)
      ans+=di;
    
    no = di - '0';

    rij(SZ(dgt[no]))
      mp[ dgt[no][j] ] -= oc;
  }
  sort(all(ans));
}

int main()
{
#ifdef FILEINPUT
    freopen("A-small-attempt0.in","r",stdin);
    // freopen("A.in","r",stdin);
   freopen("out.out","w",stdout);
#endif // FILEINPUT

   ios_base::sync_with_stdio(0);cin.tie(0);
    // rii(10)
    // {
    //   rij(SZ(dgt[i]))
    //     mp[dgt[i][j]]++;
    // }
    // fore(it,mp)
    //   cout<<(char)it->fs<<" -> "<<it->sc<<endl;


    int tks,ks=1;
    cin>>tks;
    while(tks--){
      cin>>in;
      // deb(in);
      getAns();
        cout<<"Case #"<<ks++<<": "<<ans<<"\n";
    }

    return 0;
}





