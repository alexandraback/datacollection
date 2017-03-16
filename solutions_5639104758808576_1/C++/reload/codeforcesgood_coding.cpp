#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;
#define oo 1000000007
long long int gcd(long long int a,long long int b){
      if(b==0)return a;
      return gcd(b,a%b);
}
long long int ans,t,smax,x,np;
char audience[100005];
int main(int argc, char const *argv[])
{
        cin.sync_with_stdio(0);
        cin>>t;

        for (int i = 0; i < t; ++i)
        {
            cin>>smax;
            cin>>audience;
            np=audience[0]-'0';
            ans=0;  
            for (int j= 1; j<=smax; ++j)
            {
                x=audience[j]-'0';
                if(j>np)
                {
                    ans=max(ans,j-np);
                }   
                np=np+x;
            }
            cout<<"Case #"<<i+1<<": "<<ans<<endl;
        }
}
  


