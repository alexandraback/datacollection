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
ll val=1,ti=1;
I main()
{
    I t;
    cin>>t;
    w(t)
    {
        t--;
        I k,c,s;
        cin>>k>>c>>s;
        if(c==1)val=0;
        else if(c==2)val=k;
        else
        {
            val=k;
            f(i,3,c+1)
                val=val*k+k;
        }
        cout<<"Case #"<<ti<<": ";
        ll co=1;
        f(i,0,s)
        {
            cout<<co<<" ";
            co+=val;
            co++;
        }
        cout<<endl;
        val=1;
        ti++;
    }
}

