/*Author : Md. Al- Amin
           20th batch
           Dept. of CSE, SUST*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define pi (2*acos(0))
#define SF scanf
#define SFd1(a) scanf("%d",&a)
#define SFd2(a,b) scanf("%d%d",&a,&b)
#define SFd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PF printf
#define inf 99999999
#define eps 0.00000001
#define ll long long
#define ull long long unsigned
#define int_max 2147483647
#define int_min -2147483648
#define long_max 9223372036854775807
#define long_min -9223372036854775808
#define fr(i,n) for(i=0;i<n;i++)
#define ms(dp,a) memset(dp,a,sizeof(dp))
#define dist(x1,y1,x2,y2) sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) )
#define PB push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))

using namespace std;
//int rr[]={1,2,-1,-2,1,2,-1,-2};
//int cc[]={2,1,2,1,-2,-1,-2,-1};
//int rr[]={0,0,1,-1};
//int cc[]={-1,1,0,0};

map<string,string>mpp;
string tp,arr,str,now,tp2,bs;
ll i,j,l,X,len,t,p,x,state;

string calculate(ll n)
{
    string ret="1";
    bs="1";
    for(int ii=0LL;ii<l;ii++)
    {
        tp2=bs+arr[ii];
        bs=mpp[tp2];
    }
    while(n)
    {
        if((n%2LL)==1LL)
        {
            tp2=ret+bs;
            ret=mpp[tp2];
        }
        tp2=bs+bs;
        bs=mpp[tp2];
        n/=2LL;
    }
    return ret;
}

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("codejamDijkstraOutput.txt","w",stdout);
    mpp["11"]="1";
    mpp["1i"]="i";
    mpp["1j"]="j";
    mpp["1k"]="k";
    mpp["1-1"]="-1";
    mpp["1-i"]="-i";
    mpp["1-j"]="-j";
    mpp["1-k"]="-k";

    mpp["-11"]="-1";
    mpp["-1i"]="-i";
    mpp["-1j"]="-j";
    mpp["-1k"]="-k";
    mpp["-1-1"]="1";
    mpp["-1-i"]="i";
    mpp["-1-j"]="j";
    mpp["-1-k"]="k";

    mpp["i1"]="i";
    mpp["ii"]="-1";
    mpp["ij"]="k";
    mpp["ik"]="-j";
    mpp["i-1"]="-i";
    mpp["i-i"]="1";
    mpp["i-j"]="-k";
    mpp["i-k"]="j";

    mpp["-i1"]="-i";
    mpp["-ii"]="1";
    mpp["-ij"]="-k";
    mpp["-ik"]="j";
    mpp["-i-1"]="i";
    mpp["-i-i"]="-1";
    mpp["-i-j"]="k";
    mpp["-i-k"]="-j";

    mpp["j1"]="j";
    mpp["ji"]="-k";
    mpp["jj"]="-1";
    mpp["jk"]="i";
    mpp["j-1"]="-j";
    mpp["j-i"]="k";
    mpp["j-j"]="1";
    mpp["j-k"]="-i";

    mpp["-j1"]="-j";
    mpp["-ji"]="k";
    mpp["-jj"]="1";
    mpp["-jk"]="-i";
    mpp["-j-1"]="j";
    mpp["-j-i"]="-k";
    mpp["-j-j"]="-1";
    mpp["-j-k"]="i";

    mpp["k1"]="k";
    mpp["ki"]="j";
    mpp["kj"]="-i";
    mpp["kk"]="-1";
    mpp["k-1"]="-k";
    mpp["k-i"]="-j";
    mpp["k-j"]="i";
    mpp["k-k"]="1";

    mpp["-k1"]="-k";
    mpp["-ki"]="-j";
    mpp["-kj"]="i";
    mpp["-kk"]="1";
    mpp["-k-1"]="k";
    mpp["-k-i"]="j";
    mpp["-k-j"]="-i";
    mpp["-k-k"]="-1";

    scanf(" %lld",&t);

    for(p=1LL;p<=t;p++)
    {
        now="";
        scanf(" %lld %lld",&l,&x);
        cin>>arr;
        if((l*x)<=10000LL)
        {
            str="";
            for(i=0LL;i<x;i++)
            {
                for(j=0LL;j<l;j++)
                {
                   str+=arr[j];
                }
            }
            len=l*x;
            now="1";
            state=0LL;
            for(i=0LL;i<len;i++)
            {
                tp=now+str[i];
                now=mpp[tp];
                if(state==0LL)
                {
                    if(now=="i")
                    {
                        state++;
                        now="1";
                    }
                }
                else if(state==1LL)
                {
                    if(now=="j")
                    {
                        state++;
                        now="1";
                    }
                }
            }
            if(now=="k"&&state==2LL)
                printf("Case #%lld: YES\n",p);
            else
                printf("Case #%lld: NO\n",p);
        }
        else if(x<=20LL)
        {
            str="";
            for(i=0LL;i<x;i++)
            {
                for(j=0LL;j<l;j++)
                {
                   str+=arr[j];
                }
            }
            len=l*x;
            now="1";
            state=0LL;
            for(i=0LL;i<len;i++)
            {
                tp=now+str[i];
                now=mpp[tp];
                if(state==0LL)
                {
                    if(now=="i")
                    {
                        state++;
                        now="1";
                    }
                }
                else if(state==1LL)
                {
                    if(now=="j")
                    {
                        state++;
                        now="1";
                    }
                }
            }
            if(now=="k"&&state==2LL)
                printf("Case #%lld: YES\n",p);
            else
                printf("Case #%lld: NO\n",p);
        }
        else
        {
            X=x-(10000/l);
            x=(10000/l);

            //X=x-20LL;
            //x=20LL;

            str="";
            for(i=0LL;i<x;i++)
            {
                for(j=0LL;j<l;j++)
                {
                   str+=arr[j];
                }
            }
            len=l*x;
            now="1";
            state=0LL;
            for(i=0LL;i<len;i++)
            {
                tp=now+str[i];
                now=mpp[tp];
                if(state==0LL)
                {
                    if(now=="i")
                    {
                        state++;
                        now="1";
                    }
                }
                else if(state==1LL)
                {
                    if(now=="j")
                    {
                        state++;
                        now="1";
                    }
                }
            }
            if(state==2LL)
            {
                tp=now+calculate(X);
                now=mpp[tp];
                if(now=="k")
                printf("Case #%lld: YES\n",p);
                else
                printf("Case #%lld: NO\n",p);
            }
            else
                printf("Case #%lld: NO\n",p);

        }
    }
    return 0;
}





