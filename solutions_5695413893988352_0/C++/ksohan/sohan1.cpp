#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<sstream>

using namespace std;

#define open  freopen("B-small-attempt0.in","r",stdin)
#define close  freopen ("B-small-attempt0.out","w",stdout)
#define db double
#define ll long long
#define llu unsigned long long
#define loop(i,a,n) for(int i=a;i<=n;i++)
#define sf scanf
#define sf1(a) sf("%d",&a)
#define sf2(a,b) sf("%d %d",&a,&b)
#define sf3(a,b,c) sf("%d %d %d",&a,&b,&c)
#define sf4(a,b,c,d) sf("%d %d %d %d",&a,&b,&c,&d)
#define sfd(a) sf("%lf",&a);
#define sfd2(a,b) sf("%lf %lf",&a,&b)
#define sfl(a) sf("%lld",&a)
#define sfl2(a,b) sf("%lld %lld",&a,&b)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pf printf
#define bug pf("here is bug\n")
#define pft(tc) printf("Case #%d:",tc++)
#define PI (2.0*acos(0.0))
//#define PI acos(-1.0)
#define mem(a,v) memset(a,v,sizeof a)
#define pb push_back
#define xx first
#define yy second
#define mp make_pair
#define inf 99999999
#define MX 1000006
#define mod (ll) 1000000007


template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}   // M is prime}
template <class T> inline T bpow(T p,T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}


//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={0,1,0,-1};int dy[]={1,0,-1,0}; //4 Direction

struct zz
{
    int el1,el2;
    zz() {}
    zz(int a,int c)
    {
        el1=a,el2=c;
    }
    bool friend operator<(zz a,zz b)
    {
        return  a.el1> b.el1;// sort decreasingly but increasingly for priority_queue
    }
};


//void sieve()
//{
//    is[0]=1;
//    is[1]=1;
//    for(int i=4;i<=1000000;i+=2)
//    {
//        is[i]=1;
//    }
//    for(int i=3;i*i<=1000000;i+=2)
//    {
//        if(!is[i])
//        {
//            for(int j=i*i;j<=1000000;j+=2*i)
//            {
//                is[j]=1;
//            }
//        }
//    }
//}



string s1,s2;

vector <string> v1,v2;
int z1[10000];
int z2[10000];
void gen(int i,string k,int l)
{
    //pf("%d %d ",k.size(),l);
    //cout<<k<<endl;
    if(i>l)
    {
        return;
    }

    if(k.size()==l)
    {
        v1.pb(k);
        return;

    }
    if(s1[i]!='?')
    {
        k+=s1[i];
        gen(i+1,k,l);
    }
    else if(s1[i]=='?')
    {
        for(int j='0';j<='9';j++)
        {
            string s=k;
            s+=j;
            gen(i+1,s,l);
        }
    }

}

void gen2(int i,string k,int l)
{
    //pf("%d %d ",k.size(),l);
    //cout<<k<<endl;
    if(i>l)
    {
        return;
    }

    if(k.size()==l)
    {
        v2.pb(k);
        return;

    }
    if(s2[i]!='?')
    {
        k+=s2[i];
        gen2(i+1,k,l);
    }
    else if(s2[i]=='?')
    {
        for(int j='0';j<='9';j++)
        {
            string s=k;
            s+=j;
            gen2(i+1,s,l);
        }
    }

}


int stoi(string s)
{
    int l=s.size();
    int sum=0;
    int gun=10;
    for(int i=0;i<l;i++)
    {
        sum=sum*10+(s[i]-'0');

    }
    return sum;
}

int main()
{


    int n,m;
    int t,tc=1;
    int cnt=0;
    ll N,M,K;
    sf1(t);
    while(t--)
    {
        cin>>s1>>s2;
        int l1=s1.size();
        int l2=s2.size();
        string p="";
        gen(0,p,l1);
        p="";
        gen2(0,p,l2);
        for(int i=0;i<v1.size();i++)
        {
            z1[i]=stoi(v1[i]);
        }

        for(int i=0;i<v2.size();i++)
        {
            z2[i]=stoi(v2[i]);
        }
        int I=v1.size();
        int J=v2.size();
        sort(z1,z1+I);
        sort(z2,z2+J);
        int dif=9999999;
        int q1,q2;
        for(int i=0;i<I;i++)
        {
            for(int j=0;j<J;j++)
            {
                if(abs(z1[i]-z2[j])<dif)
                {
                    dif=abs(z1[i]-z2[j]);
                    q1=z1[i];
                    q2=z2[j];
                }
            }
        }
        pft(tc);
        pf(" ");
        cout << setw(l1) << setfill('0') << q1<< " ";
        cout << setw(l1) << setfill('0') << q2<< endl;
        v1.clear();
        v2.clear();



    }

    return 0;
}

/*

? + ? + ? + ? + ? + ? = 5


*/
