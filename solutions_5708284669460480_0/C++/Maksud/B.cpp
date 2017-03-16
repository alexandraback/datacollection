//#include<bits/stdc++.h>
#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<utility>
#include<functional>
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

#define deb(a)      cerr<<"#"<<__LINE__<<" -> "<<#a<<"  "<<a<<endl;
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
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fii(a,b)    for(i=a;i<b;i++)
#define fij(a,b)    for(j=a;j<b;j++)
#define fik(a,b)    for(k=a;k<b;k++)
#define fil(a,b)    for(l=a;l<b;l++)
#define ri(i,a)     for(i=0;i<a;i++)
#define rii(a)      for(i=0;i<a;i++)
#define rij(a)      for(j=0;j<a;j++)
#define rik(a)      for(k=0;k<a;k++)
#define ril(a)      for(l=0;l<a;l++)
#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define ERR         (1e-7)
#define EQ(a,b)     (fabs((a)-(b))<ERR)
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define p2(a)       (1LL<<a)
#define EX(msk,a)   (msk&p2(a))




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


const double pi=acos(-1.0);
const double eps=1e-7;

template<class TT>TT sqr(TT a){return a*a;}
template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
typedef pair<int,int> pii;


char p[111];
int pf[111];
char keys[111];
double K;

int cal()
{
    int lp,i,m,cnt=0;

    lp = strlen(p);

    m = 0;
    pf[0] = 0;

    for(i=1;i<lp;i++)
    {
        while(m>0 && p[m]!=p[i])    m = pf[m-1];
        if(p[m]==p[i])  m++;
        pf[i]=m;
    }
}


long double mm[111][111];
int S,L;

map<char,int>mp;


int getMax()
{
    int m=0,curM=0;

    for(int i=0;i<L;i++)
        if(mp.find(p[i])==mp.end()) return 0;


    for(int i=0;i<S;i++)
    {
        curM++;
        if(curM==L)
        {
            curM = pf[curM-1];
            m++;
        }
//        debug(i,curM);
    }
    return m;
}

long double go(int cur,int mat)
{
    if(cur==S)  return 0;
    long double &re = mm[cur][mat];
    if(re>-2)   return re;

    re =0;

    fore(I,mp)
    {
        char c=I->fs;
        double f=I->sc;
        int curM=mat;

        while(curM>0 && p[curM]!=c)    curM = pf[curM-1];
        if(p[curM]==c)  curM++;
        int m=0;
        if(curM==L)
        {
            curM = pf[curM-1];
            m=1;
        }
        re+=(f/K)*(m+go(cur+1,curM));
    }
    return re;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
//    freopen("in.in","r",stdin);
    freopen("out.in","w",stdout);

    int k,l,ks=1,tks,mx;

    double ans;

    scanf("%d",&tks);
    while(tks--){
        scanf("%d%d%d",&k,&l,&S);
        scanf("%s%s",keys,p);

        K=k;
        L=l;

        mp.clear();

        for(int i=0;i<k;i++)
            mp[keys[i] ]++;

        cal();

        mx=getMax();
//        deb(mx);



        for(int i=0;i<=S+2;i++)
            for(int j=0;j<=L+2;j++)
                mm[i][j]=-5;

        ans = go(0,0);
//        deb(ans);

        ans=mx-ans;
        printf("Case #%d: %.10lf\n",ks++,ans);
    }


    return 0;
}




