/*Author:rednivrug15*/
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define MOD 1000000007

long long power(long long a,long long b,long long mod)
{
    long long ret=1;

    while(b)
    {
        if(b%2==1)
            ret=(ret*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ret;
}

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

char K[100],L[100];
char form[100];
double total=0,sum=0;
int k,l,s,maxim;

void solve(int cur,int len)
{
        if(cur==len)
        {
            int occurs=0;
            for(int i=0; i<len; i++)
            {
                if(i+l>len) break;
                bool flag=true;
                for(int j=0; j<l; j++)
                {
                    if(form[i+j]!=L[j])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag==true)
                    occurs++;
            }
            sum+=occurs;
            maxim=max(maxim,occurs);
            total++;
            return;
        }

        for(int i=0; i<k; i++)
        {
            form[cur]=K[i];
            solve(cur+1,len);
        }
}

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("op.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int kase=1; kase<=t; kase++)
    {
       cin>>k>>l>>s;
       printf("Case #%d: ",kase);
       total=0,sum=0;
       maxim=0;
       scanf("%s %s",K,L);
       solve(0,s);
       printf("%.6lf\n",(maxim*total-sum)/total);
    }
    return 0;
}
