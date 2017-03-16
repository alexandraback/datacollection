#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>

using namespace std;

int T;
char str[1010];

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);

    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%s",str);
        int len=strlen(str);
        string ans="";
        for(int i=0;i<len;i++)
            if(((str[i])+ans)>(ans+str[i]))
                ans=str[i]+ans;
            else
                ans=ans+str[i];
        printf("Case #%d: ",t);
        cout<<ans<<endl;
    }
    return 0;
}
