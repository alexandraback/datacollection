#include<bits/stdc++.h>

using namespace std;

#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define FOR(i,a,b) for(i=a;i<b;i++)

int main()
{
        freopen ("input.in","r",stdin);
        freopen ("output.txt","w",stdout);
        int t;
        cin>>t;
        int test;
        FOR(test,1,t+1)
        {
                int a,b,k;
                cin>>a>>b>>k;
                int ct=0;
                for(int i=0;i<a;i++)
                        for(int j=0;j<b;j++)
                                if((i&j)<k)
                                        ct++;
                cout<<"Case #"<<test<<": ";
                cout<<ct<<endl;
                
        }
        return 0;
}
