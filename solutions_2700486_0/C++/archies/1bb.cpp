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

struct mat
{
    int a[20][10];
    int maxy;
};
vector<vector<int> > coun(21);

vector<vector<mat> > li(21);
bool equals(mat &old,mat &news)
{
    FOR(i,20)
    {
        FOR(j,10)
        {
            if(old.a[i][j]!=news.a[i][j]) return false;
        }
    }
    return true;
}
int presentcount;
void checknupdate(mat old, int x,int y,int cell)
{
    old.a[x][y]=true;
    if(x==10) old.maxy+=2;
    FOR(i,li[cell].size())
    {
        if(equals(old,li[cell][i]))
        {
            coun[cell][i]+=presentcount;
            return ;
        }
    }
    //cout<<cell<<' ';
    li[cell].push_back(old);
    coun[cell].push_back(presentcount);
}
void update(mat &old, int x,int y,int cell)
{
   // cout<<"p";
    if(y==0) { checknupdate(old,x,y,cell);return ;}
    if(old.a[x-1][y-1] & old.a[x+1][y-1]) return checknupdate(old,x,y,cell);
    if(old.a[x-1][y-1] ==0)  update(old,x-1,y-1,cell);
    if(old.a[x+1][y-1]==0)  update(old,x+1,y-1,cell);
}

int main ()
{
    freopen("B-small-attempt4.in","r",stdin);
    freopen("output.txt","w+",stdout);
    mat temp;
    memset(&temp,0,sizeof(temp));
    li[0].pb(temp);
    coun[0].pb(1);
    FORE(i,20)
    {
        FOR(j,li[i-1].size())
        {
            presentcount=coun[i-1][j];
            update(li[i-1][j],10,li[i-1][j].maxy,i);
           // cout<<presentcount<<' ';
        }
       // cout<<endl;
    }
    //FOR(i,20)
    //{FOR(j,10) cout<<li[20][1].a[i][j]<<' ';cout<<endl;}
    //cout<<li[6].size();
    inp(t);

    FORE(test,t)
    {
        inp3(cell,x,y);
        x+=10;
        int total=0;
        int tr=0;
        if(x>=0 && x<20 && y<10)
        {
            FOR(i,li[cell].size())
            {
                total+=coun[cell][i];
                if(li[cell][i].a[x][y]==1)
                {
                    tr+=coun[cell][i];
                }
            }
             printf("Case #%d: %.8f\n",test,1.0*tr/total);
        }
        else printf("Case #%d: 0.0000000\n",test);
    }
    return 0;

}
