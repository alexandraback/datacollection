#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> paii;
typedef pair< ll, ll > pall;


#define PI (2.0*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define SZ(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define MAX 1000500
#define twoL(X) (((ll)(1))<<(X))

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}


template<class T> T Abs(T x) {return x > 0 ? x : -x;}
template<class T> inline T sqr(T x){return x*x;}
ll Pow(ll B,ll P){      ll R=1; while(P>0)      {if(P%2==1)     R=(R*B);P/=2;B=(B*B);}return R;}
ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

bool is_vowel(char ch)
{
    if(ch=='a') return true;
    if(ch=='e') return true;
    if(ch=='i') return true;
    if(ch=='o') return true;
    if(ch=='u') return true;

    return false;
}

int ok(string str, int n)
{
    int mx=0,cnt=0;
    for(int i=0;i<SZ(str);i++)
    {
        if( !is_vowel(str[i]) ) cnt++;
        else cnt=0;
        mx=max(mx,cnt);
    }
    return mx;
}
int arr[MAX];

vector<paii>v;

int main()
{
    freopen("in2.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    string str;
    int cas,loop=0,n;
    ll ans=0,len;
    scanf("%d",&cas);
    while(cas--)
    {
        cin>>str>>n;
        ans=0;
        v.clear();

        for(int i=0;i<SZ(str);i++)
        {
            if(!is_vowel(str[i]))
            {
                if(i-1>=0) arr[i]=arr[i-1]+1;
                else arr[i]=1;
            }
            else arr[i]=0;
        }

        for(int i=0;i<SZ(str);i++)
        {
            if(arr[i]>=n) v.pb( mp(i-n+1 ,i) );
        }

        len=SZ(str);

        for(int i=0;i<SZ(v);i++)
        {
            if(i==0)
            {
                ans+= (ll)(v[i].fs+1)*(ll)(len-v[i].sc);
            }
            else {

                ll now_fs= ( v[i].fs + 1 ) - ( v[i-1].fs+1 );
                ans+=(ll)(now_fs)*(ll)(len-v[i].sc);
            }
        }

        printf("Case #%d: %lld\n",++loop,ans);
    }

    return 0;
}


