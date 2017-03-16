# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>
#include <iomanip> 
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define p(n)                        printf("%d\n",n)
#define ps(n)                       printf("%s\n",n)
#define pl(n)                       printf("%lld\n",n);
 
// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9
 
// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
 
// Useful container manipulation / traversal macros
#define all(n)                      for(int i=0;i<n;i++)
#define alls(m)                      for(int j=0;j<m;j++)
#define forall(i,a,b)                   for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all1(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
 
// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

//STL output ********************************
template<typename T1,typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){return os << "(" << p.first << ", " << p.second << ")";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v){bool first=true;os<<"[";for(unsigned int i=0;i<v.size();i++){if(!first)os<<", ";os<<v[i];first=false;}return os<<"]";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v){bool first=true;os << "[";for(typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){bool first = true; os << "[";for (typename std::map<T1,T2>::const_iterator ii =v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0){for(T2 i=beg;i<sz;i++) cout<<a[i]<<" ";}
 
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)
 
inline ll binpow(ll x,ll n){ll res=1;while(n){if(n&1)res*=x;x*=x;n>>=1;}return res;}
inline ll powmod(ll x,ll n, ll _mod){ll res=1;while(n){if(n&1)res=(res*x)%_mod;x=(x*x)%_mod;n>>=1;}return res;}
inline ll mulmod(ll x,ll n, ll _mod){ll res=0;while(n){if(n&1)res=(res+x)%_mod;x=(x+x)%_mod;n>>=1;}return res;}
inline ll gcd(ll a,ll b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline int gcd(int a,int b){int t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline ll lcm(int a,int b){return a/gcd(a,b)*(ll)b;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll gcd(ll a,ll b,ll c){return gcd(gcd(a,b),c);}
inline int gcd(int a,int b,int c){return gcd(gcd(a,b),c);}
inline ll lcm(ll a,ll b,ll c){return lcm(lcm(a,b),c);}
inline ll lcm(int a,int b,int c){return lcm(lcm(a,b),(ll)c);}
 
inline ll max(ll a,ll b){return (a>b)?a:b;}
inline int max(int a,int b){return (a>b)?a:b;}
inline double max(double a,double b){return (a>b)?a:b;}
inline ll max(ll a,ll b,ll c){return max(a,max(b,c));}
inline int max(int a,int b,int c){return max(a,max(b,c));}
inline double max(double a,double b,double c){return max(a,max(b,c));}
inline ll min(ll a,ll b){return (a<b)?a:b;}
inline int min(int a,int b){return (a<b)?a:b;}
inline double min(double a,double b){return (a<b)?a:b;}
inline ll min(ll a,ll b,ll c){return min(a,min(b,c));}
inline int min(int a,int b,int c){return min(a,min(b,c));}
inline double min(double a,double b,double c){return min(a,min(b,c));} 
using namespace std;

int a,b,d,test,i,j,k,l,n,t,ar[1000001],ar2[1000001],flag,p[1001][1001],w[1000001],ans=0,sum=0,v;
char ch[101][1001];

bool AreSame(double a, double b)
{
    return fabs(a - b) < 100000;
}

int main()
{
    //freopen("in.txt","r",stdin);
    freopen("in.txt","r",stdin);
   freopen("out1.txt","w",stdout);
    //cout<<"hello";
    
    s(test);
    t=0;
    for(t=1;t<=test;t++)
    {
        int r,c,m,flag;
        flag=0;
        
        cin>>r>>c>>m;
        a=r*c-m;
        
        for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        ch[i][j]='*';
        
        if(a==1)
        {
        	ch[0][0]='c';
			cout<<"Case #"<<t<<": \n";
            for(i=0;i<r;i++)
            {
            for(j=0;j<c;j++)
            cout<<ch[i][j];
            cout<<"\n";
            }
			continue;
        }
        
		if(r==1)
		{
			for(i=0;i<a;i++)
			ch[0][i]='.';
			ch[0][0]='c';
			cout<<"Case #"<<t<<": \n";
            for(i=0;i<r;i++)
            {
            for(j=0;j<c;j++)
            cout<<ch[i][j];
            cout<<"\n";
            }
			continue;
		}
		
			if(c==1)
		{
			for(i=0;i<a;i++)
			ch[i][0]='.';
			ch[0][0]='c';
			cout<<"Case #"<<t<<": \n";
            for(i=0;i<r;i++)
            {
            for(j=0;j<c;j++)
            cout<<ch[i][j];
            cout<<"\n";
            }
			continue;
		}
		
		for(i=2;i<=r;i++)
        {
            for(j=2;j<=c;j++)
            {
           
                if(i*j==a)
                { //cout<<"hello";
                    for(k=0;k<i;k++)
                    for(l=0;l<j;l++)
                    ch[k][l]='.';
                    flag=1;
                    break;
                }
            }
            if(flag)
            break;
        }
        
        if(a==7)
        {
        	cout<<"Case #"<<t<<": \n";
            cout<<"Impossible\n";
            continue;
        }
        
        for(i=2;i<r;i++)
        {
            if(flag)
            break;
            for(j=2;j<c;j++)
            {
            	
                if(i*j+i+j>=a && a!=i*j+1 && a>i*j)
                {
                   // cout<<"hello";
                   //cout<<i<<" "<<j;
                    flag=1;
                    for(k=0;k<i;k++)
                    for(l=0;l<j;l++)
                    ch[k][l]='.';
                    a-=i*j; 
                    for(k=0;k<j&&a>0;k++)
                    {
                        ch[i][k]='.';
                        a--;
                    }
                     if(a==1)
                     {
                        ch[i][j-1]='*';
                        a++;
                     }
                    
                        for(k=0;k<i&&a>0;k++)
                    {
                        ch[k][j]='.';
                        a--;
                    }
                    
                }
                if(flag)
                break;
             }
        }
        
        if(flag)
        {
            ch[0][0]='c';
            cout<<"Case #"<<t<<": \n";
            for(i=0;i<r;i++)
            {
            for(j=0;j<c;j++)
            cout<<ch[i][j];
            cout<<"\n";
            }
        
        }
        else
        {
                cout<<"Case #"<<t<<": \n";
                cout<<"Impossible\n";
                
                
        }
            

    }
return 0;       
}
