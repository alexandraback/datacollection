#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<time.h>//srand(time(NULL))

using namespace std;

#include <cstring>

#define REP(i,N)    for(int i=0;i<N;i++)
#define REV(i,N)    for(int i=N;i>=0;i--)
#define FOR(i,a,b)  for(int __n=b,i=a;i<=__n;i++)
#define FORD(i,a,b) for(int __n=b,i=a;i>=__n;i--)

#define SZ(a)       (int)a.size()
#define ll          long long
#define ull         unsigned long long
#define ISS         istringstream
#define OSS         ostringstream
#define VS          vector<string>
#define vi          vector<int>
#define vd          vector<double>
#define vll         vector<long long>
#define SII         set<int>::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define fs          first
#define sc          second
#define pii         pair < int , int >
#define mp          make_pair

#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a,b,c)  for(int I=0;I<b;I++)    a[I] = c
#define CROSS(a,b,c,d) ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define FORE(i,a)   for(typeof((a).begin())i=(a).begin();i!=(a).end();i++)//reverse_iterator
#define BE(a)       a.begin(),a.end()
#define rev(a)      reverse(ALL(a));
#define sorta(a)    sort(ALL(a))
#define pb          push_back
#define popb        pop_back
#define round(i,a)  i = ( a < 0 ) ? a - 0.5 : a + 0.5;
#define makeint(n,s)  istringstream(s)>>n
#define read()      freopen("test.txt","r",stdin)

//ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}
//int BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (int)R;} /// (B^P)%M
//ll Gcd(ll a,ll b){ if(b==0)return a; Gcd(b,a%b); return;}

//bool operator()(const int &p,const int &q){return p<q;}//for map,set sort
//bool operator<(const data &p)const{return p.w<w;}


///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

int kkaass=1;
#define KAS()       printf("Case %d: ",kkaass++)
#define oo          (1<<30)
#define PI          3.141592653589793
#define pi          2*acos(0)
#define ERR         1e-5
#define PRE         1e-8
#define MAX         1000009
//binary search backtracking map<int , bool>
//go dist1 mat2 way seen data mat box cont store dag nume var

vector<int>vec;
int A,n;

int dp[102][2*MAX];

int rec(int ind,int sum)
{
    if(ind==SZ(vec))return 0;
    int &ret=dp[ind][sum];
    if(ret!=-1)return ret;

    ret=oo;
    if(sum>vec[ind]) ret=min(ret,rec(ind+1,min(sum+vec[ind],MAX)));
    else
    {
        ret=min(ret,rec(ind,min(2*sum-1,MAX))+1) ;
        ret=min(ret,rec(ind+1,sum)+1);
    }
    return ret;
}

int main()
{
    freopen("A.txt","r",stdin);
    freopen("Aans.txt","w",stdout);

    int t;cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        vec.clear();
        cin>>A>>n;
        for(int i=0;i<n;i++)
        {
            int tmp;cin>>tmp;
            vec.pb(tmp);
        }
        sort(BE(vec));
        mem(dp,-1);

        printf("Case #%d: %d\n",cas,rec(0,A));
    }
    return 0;
}
