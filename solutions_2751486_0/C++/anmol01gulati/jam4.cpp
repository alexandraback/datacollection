#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,ans,n,c,i,j,k,q;
    string s;
    scanf("%d",&t);
    for(q=1;q<=t;q++)
    {
        ans=0;
        cin>>s>>n;
        for(i=0;i<s.length();i++)
            for(j=i+n;j<=s.length();j++)
            {
                c=0;
                for(k=i;k<j;k++){
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

        printf("Case #%d: %d\n",q,ans);
    }
}
