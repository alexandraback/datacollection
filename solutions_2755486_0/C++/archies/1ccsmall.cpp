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


long long d[10],n[10],w[10],e[10],s[10],_d[10],_p[10],_s[10];
int main ()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("output.txt","w+",stdout);
    inp(t);

    int off=500;
    FORE(test,t)
    {
        vector<long long> oldhe(1000);
        vector<long long> newhe(1000);
        long long b;
        int ans=0;
        inp(N);
        FOR(i,N)
        {
            cin>>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>_d[i]>>_p[i]>>_s[i];
            w[i]*=2;
            e[i]*=2;
            _p[i]*=2;
        }
        FOR(day,676060)
        {
            FOR(i,N)
            {

                if(day==d[i] && n[i])
                {
                    int flag=0;
                    n[i]--;
                    for(int k=w[i];k<=e[i];k++)
                    {
                        if(oldhe[k+off]<s[i]) flag=1;
                        newhe[k+off]=max(newhe[k+off],s[i]);
                    }
                    d[i]=d[i]+_d[i];
                    w[i]+=_p[i];
                    e[i]+=_p[i];
                    s[i]+=_s[i];
                    if(flag) ans++;
                }

            }
            oldhe=newhe;
        }
        printf("Case #%d: %d\n",test,ans);
    }
    return 0;

}

