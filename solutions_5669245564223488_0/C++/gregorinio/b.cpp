#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1001001001
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define pcc pair<char,char>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define IOS ios_base::sync_with_stdio(0);

const ll mod = 1000000007;
vector<string> in;
vector<pcc> v;
int luzne[1042];
bool luznefixed[1042];
bool was[1042];
bool bad;
ll silnia[1042];

pcc get(string s)
{
    if(was[s[0]])bad=1;
    if(s.size()==1)return mp(s[0],s[0]);
    
    char b=s[0],e=s[s.size()-1];
    if(was[e])bad=1;
    
    pcc res=mp(b,e);
    bool middle=0;
    int left=0, right=s.size()-1;
    
    while(s[left]==b && left<=s.size()-1)left++;
    if(left>right)return res;
    
    while(s[right]==e && right>=0)right--;
    if(left>right)return res;
    
    char temp=s[left];
    for(int i=left;i<=right;i++)
    {
           if(was[s[i]])bad=1; 
           if(s[i]==b || s[i]==e)
           {
                 bad=1;   
                 return res;        
           }         
           if(s[i]!=temp)was[temp]=1;
           if(i==right)was[s[i]]=1;
           temp=s[i];
    }  
    return res;
}

int clean()
{
    if(v.size()==0)return 0;
    for(int i=0;i<v.size();i++)
    {
            for(int j=0;j<v.size();j++)
            {
                    if(i==j)continue;
                    if(v[i].second == v[j].first)
                    {
                            if(luznefixed[v[i].second]==1)bad=1;
                            luznefixed[v[i].second]=1;
                            if(v[i].first == v[j].second)
                            {
                                    bad=1;
                                    return 0;                    
                            }               
                            v[i].second = v[j].second;
                            v.erase(v.begin() + j);
                            clean();
                            return 0;
                    }
            }        
    }   
}

int solve(int test)
{
    cout<<"Case #"<<test<<": "; 
    in.clear();
    v.clear();
    for(int i=0;i<1000;i++){was[i]=0; luzne[i]=0; luznefixed[i]=0;}
    wez(n);
    for(int i=0;i<n;i++)
    {
            string s;
            cin>>s;
            in.pb(s);        
    }
    for(int i=0;i<n;i++)
    {
            bad=0;
            pcc p=get(in[i]);  
            if(bad)
            {
                   //cout<<"AAA";
                   cout<<"0"<<endl;
                   return 0;       
            }     
            if(p.first==p.second)
            {
                   //cout<<p.first<<" "<<(int)p.first<<" ";
                   luzne[p.first]++;
            }
            else v.pb(p);
    }
    //cout<<endl;
    
    bad=0;
    clean();
    /*for(int i=0;i<v.size();i++)
    {
            cout<<v[i].first<<","<<v[i].second<<" ";        
    }
    cout<<endl;
    */
    //for(int i=0;i<v.size();i++)
    
    if(bad)
    {
            //cout<<"BBB";
            cout<<"0"<<endl;
            return 0; 
    }
    
    int liczba=0;
    for(int i=0;i<1000;i++)
    {
            if(luzne[i]!=0)liczba++;        
    }
    liczba+=v.size();
    //cout<<"liczba "<<liczba<<endl;
    for(int i=0;i<v.size();i++)
    {
            if(luzne[v[i].first]!=0)liczba--;
            if(luzne[v[i].second]!=0)liczba--;        
    }
    for(int i=0;i<1000;i++)
    {
            if(luzne[i]!=0 && luznefixed[i]==1)liczba--;        
    }
    for(int i=0;i<v.size();i++)
    {
            for(int j=0;j<v.size();j++)
            {
                    if(i==j)continue;
                    if(v[i].first==v[j].first || v[i].second==v[j].second)
                    {
                             cout<<"0"<<endl;
                             return 0;                          
                    }        
            }        
    }
    
    ll res=silnia[liczba];
    for(int i=0;i<1000;i++)
    {
            if(luzne[i]!=0)res=(res*silnia[luzne[i]])%mod;        
    }
    cout<<res<<endl;
    return 0; 
}

int main()
{
    silnia[0]=1;
    silnia[1]=1;
    for(ll i=2;i<=1000;i++)
    {
           silnia[i]=(silnia[i-1]*i)%mod;       
    }
    wez(t);
    for(int i=1;i<=t;i++)solve(i);
    return 0;   
}
