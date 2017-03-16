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
I ti=1;
void solve(S s,I n)
{
    I ans=0;
    while(true)
    {
        bool check=true;
        f(j,0,n)
        {
            if(s[j]=='-')
            {
                check=false;
                break;
            }
        }
        if(check)
        {
            cout<<"Case #"<<ti<<": "<<ans<<endl;
            ti++;
            break;
        }
        ans++;
        I i=0;
        if(s[i]=='-')
        {
            while(s[i]=='-' && i<n)
            {
                s[i]='+';
                i++;
            }
        }
        else
        {
            while(s[i]=='+' && i<n)
            {
                s[i]='-';
                i++;
            }
        }
    }
}
I main()
{
    I t;
    cin>>t;
    w(t)
    {
        t--;
        S s;
        cin>>s;
        solve(s,(I)s.length());
    }
}
