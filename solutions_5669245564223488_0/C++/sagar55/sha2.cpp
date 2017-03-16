#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
 
using namespace std;
 
#define s(n)          scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define ss(n)           scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF           (int)1e9
#define LINF          (long long)1e18
#define swap(a,b)                int temp; temp=a;a=b;b=temp;
#define EPS           1e-9
#define maX(a,b)        ((a)>(b)?(a):(b))
#define miN(a,b)        ((a)<(b)?(a):(b))
#define abS(x)          ((x)<0?-(x):(x))
#define FOR(i,a,b)        for(int i=a;i<b;i++)
#define FORREV(k,a,b)           for(int i=a;i>b;i--)
#define REP(i,n)        FOR(i,0,n)
#define FOREACH(v,c)            for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define CASEN(n)                int cas=1;while(scanf("%d",&n)!=EOF)
#define CASE(T)                 int T;scanf("%d ",&T);while(T--)
#define mp            make_pair
#define FF            first
#define SS            second
#define tri(a,b,c)        mp(a,mp(b,c))
#define XX            first
#define YY            second.first
#define ZZ            second.second
#define pb            push_back
#define fill(a,v)         memset(a,v,sizeof a)
#define pb                push_back  
#define all(x)          x.begin(),x.end()
#define SZ(v)         ((int)(v.size()))
#define SORT(v)             sort((v).begin(),(v).end())
#define DREP(a)         sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)      (lower_bound(all(arr),ind)-arr.begin())
#define FILEI                    freopen("input.txt","r",stdin);
#define FILEO                    freopen("output.txt","w",stdout);

#define SIZE(X) ((int)(X.size()))//NOTES:SIZE(
#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(
#define MP(X,Y) make_pair(X,Y)//NOTES:MP(
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
#define two(X) (1<<(X))//NOTES:two(
#define twoL(X) (((int64)(1))<<(X))//NOTES:twoL(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
#define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL(
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
typedef pair<int,int> ipair;//NOTES:ipair
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
//ENDTEMPLATE_BY_SAGAR55
struct data{
    int i;int j;
};
bool my_cmp(const data& a, const data& b)
{
    return a.j<b.j;
} 
 
 
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
 
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
 
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;
bool cmp(const vector<int>& a,const vector<int>& b){
  for(int i=0;i<2;i++){
    if(a[i]<b[i])return true;
    else if(a[i]==b[i])continue;
    else return false;
  }
}
LL gcd(LL i,LL j)
      {
           if(j==0)
            return i;
            else
              return gcd(j,i%j);
              }

              int cse=1;
main()
{
    FILEI; FILEO;
    CASE(T)
    {
        int n,mp[105];
        int ans=0;
        s(n);
        char a[105][105];
        int flag=1;
       int tot=0;
        for(int i=0;i<n;i++)
        {
          scanf("%s",a[i]);
          int l=strlen(a[i]);
       //   if(j==l) mp[i]=l-1;
          tot+=l;
        }
        int perm[11]={0,1,2,3,4,5,6,7,8,9,10};
          int tmp[26];
        do {
          memset(tmp,0,sizeof tmp);
          char fs[1005];
         fs[0]='\0';
            for(int i=0;i<n;i++)
            {
             // if(a[perm[i]][mp[perm[i]]] == a[perm[i+1]][0] || a[perm[i]][mp[perm[i]]] == a[perm[i+1]][0])
              strcat(fs,a[perm[i]]);
            }
          //  printf("%s\n",fs);

            tmp[fs[0]-'a']=1;
            int ii=1;
            for(ii=1;ii<tot;ii++)
            {
              if(tmp[fs[ii]-'a']==0)tmp[fs[ii]-'a']++;
              else
              {
                if(tmp[fs[ii]-'a']&&fs[ii-1]==fs[ii]) continue;
                else break;
              }
            }
            if(ii==tot) ans++;

     } while ( std::next_permutation(perm,perm+n));
     printf("Case #%d: %d\n",cse++,ans);
  }
    return 0;
}