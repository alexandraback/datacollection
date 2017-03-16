#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int ar[101];
int main()
{
    int a,n,t,k,j,i,s,ans;
    cin>>t;
    j=1;
    for(j=1;j<=t;j++)
    {
               cin>>a>>n;
               for(i=0;i<n;i++)
                       cin>>ar[i];
               sort(ar,ar+n);
               s=a;
               for(i=0;i<n;i++)
               {
                       if(s>ar[i])
                       s+=ar[i];
                       else break;
               }
               ans=n-i;
               for(k=1;k<=ans;k++)
               {
                       s=s+s-1;
                       for(;i<n;i++)
                       {
                       if(ar[i] < s)
                       {s=s+ar[i];}
                       else break;
                       }
                      ans=min(ans,(k+n-i));
               }
    cout<<"Case #"<<j<<": "<<ans<<endl;
    }
    return 0;   
}
