
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
#define MAX 1123456
int isvowel(char c)
{
   return strchr("aeiou",c)!=NULL;
}
int main()
{
   int cases;
   int i,j,n;
   char a[MAX];
   int casectr=1;
   for(scanf("%d",&cases);casectr<=cases;++casectr){
      scanf("%s",a);
      int len=strlen(a);
      scanf("%d",&n);
      printf("Case #%d: ",casectr);
      LLI ans=0;
      int cnt=0,sign=0;
      int start=-1;
      vector < ii > isle;
      for(j=0;a[j];++j){
         if(sign==0){//last was a vowel
            if(strchr("aeiou",a[j])){
            }
            else{
               sign=1;
               start=j;
               cnt++;
            }
         }
         else{
            if(strchr("aeiou",a[j])){
               sign=0;cnt=0;
               isle.pb(ii(start,j-1));
            }
            else cnt++;
         }
      }
      if(sign){
         //printf("line %d\n",__LINE__);
         isle.pb(ii(start,j-1));
      }
      queue < ii > q;
      tr(isle,tr)
         if(((tr-> second)-(tr -> first) >= n-1)){
//            printf("%d,%d\n",tr->first,tr->second);
            q.push(*tr);
         }



      int end=-1;
      start=-1;
      for(i=0;a[i];++i){
         int ind=max(i,start);
         while(((end-ind)<n-1)&&(!q.empty())){
            ii tmp=q.front();
            q.pop();
            start=tmp.first;
            end=tmp.second;
            ind=max(i,start);
         }
         //printf("line %d\n",__LINE__);
         if(end - ind < n-1){
            //printf("ind is %d\n",ind);
           // printf("end is %d\n",end);
            break;
         }
      //   printf("line %d\n",__LINE__);
     //    printf("is is %d\n",i);
         if(i<=start)
            ans+=(len+1-start-n);
         else ans+=(len+1-i-n);
       ///  printf("ans is is %d\n",ans);
      }

      printf("%lld\n",ans);
   }
   return 0;
}
