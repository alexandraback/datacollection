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
I ha[10];
I ti=1;
void solve(ll n)
{
    if(n==0){cout<<"Case #"<<ti<<": "<<"INSOMNIA"<<endl;return;}
    f(i,0,10)ha[i]=0;
    I co=1;
    while(true)
    {
        ll x=co*n;
        bool check=true;
        while(x>0)
        {
            ha[x%10]=1;
            x/=10;
        }
        f(i,0,10)
        {
            if(ha[i]==0)
                {
                    check=false;
                    break;
                }
        }
        if(check){cout<<"Case #"<<ti<<": "<<co*n<<endl;break;}
        co++;
    }
}
int main() {
    I t;
    cin>>t;
    while(t>0)
    {
        t--;
        ll n;
        cin>>n;
        solve(n);
        ti++;
    }
    return 0;
}

