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
int k,n;
int keys[200];
int ans[25];
int m[1<<21];
int mykey[25];
vector<vector<int> > ihave;
bool solve(int ch,int mask)
{
    if(ch==n) return true;
    if(m[mask]==1) return false;
    m[mask]=1;
    FOR(i,n)
    {
        if(((mask&(1<<i))==0) && keys[mykey[i]]!=0)
        {
            //cout<<i<<'-';
            mask^=1<<i;

            keys[mykey[i]]--;
            FOR(j,ihave[i].size()) keys[ihave[i][j]]++;
            bool val=solve(ch+1,mask);
            if(val==true) {ans[ch]=i;return true;}
            mask^=1<<i;
            keys[mykey[i]]++;
            FOR(j,ihave[i].size()) keys[ihave[i][j]]--;
            //cout<<endl;
        }
    }
    return false;
}
int main ()
{
     freopen("D-small-attempt0.in","r",stdin);
    freopen("output.txt","w+",stdout);
    inp(t)
    FORE(test,t)
    {
        cin>>k>>n;
        ihave.clear();
        ihave.resize(21);
        memset(keys,0,sizeof(keys));
        memset(m,0,sizeof(m));
        FOR(i,k)
        {
            inp(g);
            keys[g]++;
        }
        FOR(i,n)
        {
            cin>>mykey[i];
            inp(me);
            FOR(j,me)
            {
                inp(temp);
                ihave[i].push_back(temp);
            }
        }
        bool flag=solve(0,0);
        if(flag==true)
        {
            printf("Case #%d:",test);
            FOR(i,n) cout<<' '<<ans[i]+1;
            cout<<endl;
        }
        else printf("Case #%d: IMPOSSIBLE\n",test);

    }
    return 0;

}

