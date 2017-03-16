#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<fstream>
#include<sstream>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<utility>
#include<climits>
#include<iomanip>
#include<ctime>
#include<complex>
#include<set>

using namespace std;


#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define INF INT_MAX/3
#define PB push_back
#define pb push_back
#define MP make_pair
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PII pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in.txt","r",stdin)
#define OUTFILE()freopen("out.txt","w",stdout)
#define in scanf
#define out printf
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define eps 1e-14
#define MOD 1000000007


//TYO conversion
template<typename T>inline string toString(T a)
{
    ostringstream os("");
    os<<a;
    return os.str();
}
template<typename T>inline ll toLong(T a)
{
    ll res;
    istringstream os(a);
    os>>res;
    return res;
}
//MATHEMATICS
template<typename T>inline T  S(T a)
{
    return a*a;
}
template<typename T>inline T gcd(T a, T b)
{
    if (b == 0)return a;
    else return gcd(b, a % b);
}
template<typename T>inline ull bigmod(T a, T b, T m)
{
    if (b == 0)return 1;
    else if (b % 2 == 0)return S(bigmod(a, b / 2, m)) % m;
    else return (a % m*bigmod(a, b - 1, m)) % m;
}
template<typename T>inline VS parse(T str)
{
    VS res;
    string s;
    istringstream os(str);
    while(os>>s)res.pb(s);
    return res;
}
template<typename T>inline ull  dist(T A,T B)
{
    ull res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return res;
}
template<typename T>inline double cosAngle(T a,T b,T c)
{
    double res=a*a+b*b-c*c;
    res=res/(2*a*b);
    res=acos(res);
    return res;
}
template<typename T>inline T power(T base,int po)
{
    T res=1;
    if(base==0)return 0;
    FOR(i,0,po)res*=base;
    return res;
}
//BIT
template<typename T>inline bool isOn(T mask,T pos)
{
    return mask&(1<<pos);
}
template<typename T>inline int Off(T mask,T pos)
{
    return mask^(1<<pos);
}
template<typename T>inline int On(T mask,T pos)
{
    return mask|(1<<pos);
}

//node * root =new node(0,n-1);
string aa,bb,cc;
string bin(LL a)
{
    VI v;
    while(a)
    {
        v.pb(a%2);
        a/=2;
    }

    reverse(all(v));

    string aaa="";

    FOR(i,0,v.size())
    {
        char ch='0';
        if(v[i])ch++;
        aaa=aaa+ch;
    }

    while(aaa.size()!=40)
    aaa="0"+aaa;

    return aaa;
        //cout<<v[i]<<endl;
}

LL dp[50][2][2][2][2][2]; // pos,lasta, lastb ,a ,b,c

LL solve(int pos , int lasta, int lastb, int aok , int bok , int cok)
{
    if(pos==40)
    {
       // cout<<aa[pos-1]<<" "<<bb[pos-1]<<" ** "<<cc[pos-1]<<endl;
    //return 1;//
        if(aok==1 && bok==1 &&cok==1)
        {
            return 1;
        }
        return 0;
    }

    VI va,vb;

    if(aok==1 || aa[pos]=='1')
    {
        va.pb(0);
        va.pb(1);
    }
    else
    {
        va.pb(0);
    }

    if(bok==1 || bb[pos]=='1')
    {
        vb.pb(0);
        vb.pb(1);
    }

    else vb.pb(0);

    int na,nb,nc,x,y,Xor,i,j,A,B,C;
    A=aa[pos]-'0';
    B=bb[pos]-'0';
    C=cc[pos]-'0';

    if(dp[pos][lasta][lastb][aok][bok][cok]!=-1)return dp[pos][lasta][lastb][aok][bok][cok];

    LL &ret=dp[pos][lasta][lastb][aok][bok][cok]=0;
    for(i=0;i<va.size();i++)
    {
        for(j=0;j<vb.size();j++)
        {
            x=va[i];
            y=vb[j];
            Xor=(x&y);

            na=aok;
            nb=bok;
            nc=cok;

            if((x<A)  )na=1;
            if((y<B)  )nb=1;
            if((Xor<C) )nc=1;

            if(cok==1)
            {
                ret+=solve(pos+1,x,y,na,nb,cok);
            }
            else{
                if((Xor<C)  )nc=1;
                else if(Xor==C)nc=cok;
                else nc=-1;

                if(nc!=-1)
                {
                ret+=solve(pos+1,x,y,na,nb,nc);
                }

            }
        }
    }
    return ret;

}


int main()
{

    INFILE();
    OUTFILE();

   // bin(4);

    int ks,cas;
    int i,j,k,n;
    int cn=0;
//    for(i=0;i<3;i++)
//    {
//        for(j=0;j<4;j++)
//        {
//            if( (i ^ j)<=2 ){cn++;cout<<i<< " "<<j<<endl;}
//        }
//    }
//    cout<<cn<<endl;

    cin>>ks;
    LL a,b,c;
    bool stat;
    for(cas=1; cas<=ks; cas++)
    {

    cin>>a>>b>>c;

    a;
    b;
    c;
    aa=bin(a);
    bb=bin(b);
    cc=bin(c);

    SET(dp,-1);
    cout<<"Case #"<<cas<<": ";
    LL res=solve(0,0,0,0,0,0);
    cout<<res<<endl;


    }

    return 0;
}
