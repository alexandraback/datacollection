#include<iostream>
#include<vector>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<map>
#include<string>
#include <sstream>
#include<set>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,a,b) for(ll i=a;i>=b;i--)
#define ff(i,a,b,c) for(int i=a;i<b;i+=c)
#define w(n) while(n>0)
#define vi vector<int>
#define vll vector<long long int>
typedef pair<pair<int,int> ,int> PII;
typedef pair<long long int,long long int> PI;
typedef long long int ll;
typedef long double ld;
typedef int I;
typedef string S;
bool prime(I a[],I n)
{
    vll V;
    f(i,2,11)
    {
        ll ans=0;
        f(j,0,n)
            ans+=a[j]*pow(i,n-j-1);
        bool check=false;
        f(j,2,sqrt(ans)+1)
        {
           if(ans%j==0)
               {
                  check=true;
                  V.push_back(j);
                  break;
               }
        }
        if(!check)return false;
    }
    f(i,0,n)cout<<a[i];
    cout<<" ";
    f(i,0,V.size())cout<<V[i]<<" ";
    cout<<endl;
    return true;
}
I main()
{
    I t;
    cin>>t;
    I n,k;
    cin>>n>>k;
    I a[n];
    cout<<"Case #1:"<<endl;
    f(i,1,pow(2,n))
    {
        if((i&(1<<0)>0) && (i&(1<<(n-1)))>0)
            {
                f(j,0,n)a[j]=0;
                a[0]=1;a[n-1]=1;
                f(j,1,n-1)
                    {
                        if(i&(1<<j))
                            a[j]=1;
                    }
                if(prime(a,n))k--;
            }
        if(k==0)break;
    }
}

