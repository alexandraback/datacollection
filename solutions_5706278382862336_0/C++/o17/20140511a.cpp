#include <iostream>
#include <cstdio>
#include <cmath> 
using namespace std;
int main()
{ freopen("A1-small-attempt1.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t,l,ans;
    char ch;
    long long a,b,c;
    double p;
   
    cin>>t;
    for(l=1;l<t+1;l++)
    {
       // cout<<l<<endl;
        ans=0;
        cin>>a>>ch>>b;
        c=b;
        while (b%2==0)
        {
                
          b=b/2;    
          ans++;
        }    
        if (a%b==0) 
        {
          a=a/b;
          while (a>1)
          {
              a=a/2;
              ans--;    
          }
          printf("Case #%d: %d\n",l,ans);
          //cout<<ans;
        }
        else 
        {
           printf("Case #%d: impossible\n",l,ans);
        }
    }    
}
