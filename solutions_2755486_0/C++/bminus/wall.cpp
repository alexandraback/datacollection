
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<sstream>

#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<bitset>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<string> vs; 
typedef pair<int,int> ii;
typedef long long int LLI;
typedef long double Lf;
typedef unsigned long long int ULLI;
   template <typename T>
ostream& operator <<(ostream &o,vector < T >  &v)
{
   for(typeof(v.size()) i=0;i<v.size();++i)
      o<<v[i]<<" ";
   o<<endl;
   return o;
}
template < class T1, class T2, class T3 > 
struct trio{
   T1 first;
   T2 second;
   T3 third;
   trio(): first(T1()),second(T2()),third(T3()){}
   trio(const T1 &x, const T2 &y, const T3 &z): first(x),second(y),third(z){}
   template < class X, class Y, class Z >
      trio (const trio < X, Y , Z > &p) : first(p.first),second(p.second), third(p.third){}

};
typedef trio < int, int , int > tiii;
   template < class T1, class T2, class T3 > 
bool operator < (const trio < T1, T2 , T3 > &x,const trio < T1, T2 , T3 > &y)
{
   if(x.first<y.first) return true;
   else if(x.first> y.first) return false;
   if(x.second<y.second) return true;
   else if(x.second> y.second) return false;
   if(x.third<y.third) return true;
   else if(x.third> y.third) return false;
   return true;
}

#define sz(a)                        int((a).size()) 
#define pb                           push_back 
#define mp                           make_pair
#define F                            first
#define S                            second
#define present(c,x)                 ((c).find(x) != (c).end()) 
#define cpresent(c,x)                (find(all(c),x) != (c).end())
#define tr(c,i)                      for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define all(c)                       (c).begin(),(c).end()
#define si(n)                        scanf("%d",&n)
#define sl(n)                        scanf("%lld",&n)
#define sf(n)                        scanf("%f",&n)
#define sd(n)                        scanf("%lf",&n)
#define ss(n)                        scanf("%s",n)

#define abs(x)                       ((x)<0?-(x):(x))
#define fill(a,v)                    memset((a),(v),sizeof (a))
#define INF                          INT_MAX
#define LINF                         (long long)1e18
#define EPS                          1e-9
#define MODBY 1000000007
#define MAX                          1123456
int main()
{
   int cases;
   int i,j,n;
   int a[MAX];
   int casectr=1;
   for(scanf("%d",&cases);casectr<=cases;casectr++){
      printf("Case #%d: ",casectr);
      scanf("%d",&n);
      vector < int > d(n),attacks(n),w(n),e(n),s(n),deld(n),delp(n),dels(n);
      priority_queue < ii > minheap;
      for(i=0;i<n;++i){
         scanf("%d",&d[i]);
         scanf("%d",&attacks[i]);
         scanf("%d",&w[i]);
         scanf("%d",&e[i]);
         scanf("%d",&s[i]);
         scanf("%d",&deld[i]);
         scanf("%d",&delp[i]);
         scanf("%d",&dels[i]);
         int tid=i;
         attacks[tid]--;
         minheap.push(ii(-d[i],tid));
      }
      int base[500]={};
      int less[500]={};
      int *wall=base+250;
      map < int, int  > newwall;
      int ans=0;//number of succ attacks
      while(!minheap.empty()){
         ii tmp=minheap.top();
         minheap.pop();
         int day=-tmp.first;
         int tid=tmp.second;
         int bad=0;
         //printf("tribe %d attacked on day %d from %d to %d with strength %d\n",tid,day,w[tid],e[tid],s[tid]);
         for(i=w[tid]+1;i<=e[tid];++i)
            if(wall[i]<s[tid]){
               bad=1;
               newwall[i]=max(newwall[i],s[tid]);
            }
//         if(bad) printf("attack succ\n");         else printf("attacks fail\n");
         ans+=bad;
         if(attacks[tid]){
            attacks[tid]--;
            minheap.push(ii(-(day+deld[tid]),tid));
            w[tid]+=delp[tid];
            e[tid]+=delp[tid];
            s[tid]+=dels[tid];
         }
         if(!minheap.empty())
            tmp=minheap.top();
         if((minheap.empty())||(tmp.first!=-day)){
            tr(newwall,it)
               wall[it->first]=it->second;
            newwall.clear();
         }
      }
      printf("%d\n",ans);
   }
   return 0;
}
