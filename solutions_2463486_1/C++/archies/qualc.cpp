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
#define FORE(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)((x).size()))
#define fi first
#define se second
#define inp(n) int (n); scanf("%d",&(n));
#define inp2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define inp3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
#define SSD(x) (scanf("%d",&x))
#define SSL(x) (scanf("%lld",&x))
#define SSF(x) (scanf("%f",&x))
#define SSS(x) (scanf("%s",x))
inline void prt(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS inp(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define MAX(a,b) (a)=max((a),(b));
#define MIN(a,b) (a)=min((a),(b));
#define INRAN(a,b,c) ((a)>=(b) && (a)<(c))
bool ispal(long long n)
{
    stringstream ss;
    string s;
    ss<<n;
    ss>>s;
    FOR(i,s.size()/2)
    {
        if(s[i]!=s[s.size()-1-i]) return false;
    }
    return true;
}
vector<long long> a(3);
long long makeno(long long n)
{
    return n;
}
int main ()
{
     freopen("C-large-1.in","r",stdin);
    freopen("output.txt","w+",stdout);
   /* TESTS
    {
        FOR(i,n)
        {

        }*/
    a[0]=1;a[1]=4;a[2]=9;
    int len=3;
    long long int n=(long long)1e7;
    long long int i=10;
    int c=0;
    while(i<n)
    {
        c++;
        //cout<<i<<endl;
        long long k=i;
        if(ispal(k))
        {
            if(ispal(k*k)) //cout<<k<<' '<<k*k<<endl;
            {
                a.push_back(k*k);
               // cout<<k*k<<endl;
            }
        }
        i++;
        int mod=1;
        while((i%(mod*10))/mod==3)
        {
            i=i-3*mod+mod*10;
            mod*=10;
        }
    }
    inp(t);
    FORE(test,t)
    {
        long long a1,b1;
        cin>>a1>>b1;
        int ans=0;
        FOR(i,a.size())
        {
            if(a[i]>=a1 && a[i]<=b1) ans++;
        }
        printf("Case #%d: %d\n",test,ans);
    }

    return 0;

}

