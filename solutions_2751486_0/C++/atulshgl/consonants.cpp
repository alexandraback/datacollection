#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    freopen("A-small-attempt0 (6).in","r",stdin);
    freopen("consonantsout.in","w",stdout);
    int t,cs=1,ans,n,c,i,j,k;
    string s;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>s;
        cin>>n;
        for(i=0;i<s.length();i++)
        {
                for(j=i+n;j<=s.length();j++)
                {
                        c=0;
                        for(k=i;k<j;k++)
                        {
                                if(s[k]=='a' || s[k]=='e' || s[k]=='i'|| s[k]=='o' || s[k]=='u')
                                             c=0;
                                else
                                             c++;
                                if(c>=n)
                                {
                                        ans++;
                                        break;
                                }
                        }
            }
        } 
        printf("Case #%d: %d\n",cs++,ans);
    }
    return 0;
}
 
