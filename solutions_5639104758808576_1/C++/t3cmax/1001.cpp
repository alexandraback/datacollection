#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
using namespace std;

int t;
int n;
char s[1011];

int ans;
int main()
{
    int i,j,k,times;
    int temp;
    int xx,yy;
    
    freopen("A-large.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    
    cin>>t;
    
    for(times=1;times<=t;times++)
    {
        cin>>n;
        cin>>s;
        
        ans=0;temp=0;
        for(i=0;i<=n;i++)
        {
            k=s[i]-'0';
            
            if(temp<i && k!=0)
            {
                ans+=i-temp;
                temp=i;
            }
            
            temp+=k;
        }
        
        cout<<"Case #"<<times<<": "<<ans<<endl;
    }
    
    
    return 0;
}
