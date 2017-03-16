#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;


int t;
char s[111];
int n;
int ans;
int main()
{
    int i,j,k,times;
    char la;
    
    freopen("B-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    
    
    cin>>t;
    for(times=1;times<=t;times++)
    {
        cin>>s;
        n=strlen(s);
        ans=0;
        la='$';
        for(i=0;i<n;i++)
        {
            //cout<<i<<' '<<la<<' '<<s[i]<<endl;
            if(la!=s[i])
            {
                ans++;
                la=s[i];
            }
        }
        ans--;
        
        if(s[n-1]=='-')ans++;
        
        cout<<"Case #"<<times<<": "<<ans<<endl;
    }
    
    
    return 0;
}
