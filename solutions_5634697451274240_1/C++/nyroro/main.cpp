#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[120];

void flip(int n)
{
    char tmp[120];

    for(int i=0;i<n;i++)
    {
        tmp[i]=str[n-1-i];
    }

    for(int i=0;i<n;i++)
    {
        if(tmp[i]=='+')
            str[i]='-';
        else
            str[i]='+';
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;

    for(int ti=1;ti<=t;ti++)
    {
        cin>>str;

        cout<<"Case #"<<ti<<": ";

        int n=strlen(str);
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i==0)
            {
                if(str[i]=='-')ans++;
            }
            else
            {

                if(str[i]=='-')
                {

                    ans++;
                    if(str[0]=='+')
                    {
                        int j=0;

                        while(j<=i&&str[j]=='+')
                        {
                            j++;
                        }
                        flip(j);
                        ans++;
                    }
                    flip(i+1);
                    //cout<<str<<endl;
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}
