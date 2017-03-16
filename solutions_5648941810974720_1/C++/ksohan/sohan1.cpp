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

#define open  freopen("A-large0.in","r",stdin)
#define close  freopen ("A-large0.out","w",stdout)
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



string s;
int a[30];
int res[1000];
int main()
{


    int n,m;
    int t,tc=1;
    int cnt=0;
    ll N,M,K;
    sf1(t);
    while(t--)
    {
        int k=0;
        mem(a,0);
        mem(res,0);
        cin>>s;
        int l=s.size();
        int cnt=l;
        for(int i=0;i<l;i++)
        {
            int p=s[i]-'A'+1;
            a[p]++;

        }
        while(cnt)
        {
            if(a[26]>0)
            {
                res[k++]=0;
                a[26]--;
                cnt--;
                a[5]--;

                cnt--;
                a[18]--;
                cnt--;
                a[15]--;
                cnt--;
            }
            else if(a[24]>0)
            {
                res[k++]=6;
                a[24]--;
                a[19]--;
                a[9]--;
                cnt-=3;
            }
            else if(a[7]>0)
            {
                res[k++]=8;
                a[7]--;
                a[5]--;
                a[9]--;
                a[8]--;
                a[20]--;
                cnt-=5;
            }
            else if(a[23]>0)
            {
                res[k++]=2;
                a[23]--;
                a[20]--;
                a[15]--;
                cnt-=3;
            }
            else if(a[21]>0)
            {
                res[k++]=4;
                a[21]--;
                a[6]--;
                a[15]--;
                a[18]--;
                cnt-=4;

            }
            else if(a[15]>0 && a[14]>0 && a[5]>0)
            {
                res[k++]=1;
                a[15]--;
                a[14]--;
                a[5]--;
                cnt-=3;
            }
            else if(a[5]>1 && a[20]>0 && a[8]>0 && a[18]>0)
            {
                res[k++]=3;
                a[5]-=2;
                a[20]--;
                a[8]--;
                a[18]--;
                cnt-=5;
            }
            else if(a[5]>0 && a[9]>0 && a[22]>0 && a[6]>0)
            {
                res[k++]=5;
                cnt-=4;
                a[5]--;
                a[6]--;
                a[9]--;
                a[22]--;
            }
            else if(a[14]>1 && a[9]>0 && a[5]>0)
            {
                res[k++]=9;
                cnt-=4;
                a[14]-=2;
                a[5]--;
                a[9]--;
            }
            else
            {
                res[k++]=7;
                cnt-=5;
                a[5]-=2;
                a[19]--;
                a[22]--;
                a[14]--;
            }

        }
        pft(tc);
        sort(res,res+k);
        pf(" ");
        for(int i=0;i<k;i++)
        {
            pf("%d",res[i]);
        }
        pf("\n");

    }

    return 0;
}

/*

? + ? + ? + ? + ? + ? = 5


*/
