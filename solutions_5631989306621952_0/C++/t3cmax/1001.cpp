#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;


int t;
char s[1011];
int n;

char ans[1011];

int main()
{
    int i,j,k,times;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("ans.out","w",stdout);
    
    cin>>t;
    for(times=1;times<=t;times++)
    {
        cin>>s;
        n=strlen(s);
        
        ans[0]=s[0];
        ans[1]='\0';
        for(i=1;i<n;i++)
        {
            if(s[i]==ans[0])
            {
                int flag=1;
                for(j=0;j<i-1;j++)
                {
                    if(ans[j]<ans[j+1])
                    {
                        flag=1;
                        break;
                    }
                    else if(ans[j]>ans[j+1])
                    {
                         flag=2;
                         break;
                    }
                }
                if(flag==1)
                {
                   ans[i]=s[i];
                   ans[i+1]='\0';
                }
                else
                {
                    ans[i+1]='\0';
                    for(j=i-1;j>=0;j--)
                    {
                        ans[j+1]=ans[j];
                    }
                    ans[0]=s[i];
                }
                
            }
            else if(s[i]>ans[0])
            {
                ans[i+1]='\0';
                for(j=i-1;j>=0;j--)
                {
                    ans[j+1]=ans[j];
                }
                ans[0]=s[i];
            }
            else
            {
                ans[i]=s[i];
                ans[i+1]='\0';
            }
            //cout<<ans<<endl;
        }
        
        cout<<"Case #"<<times<<": ";
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}
