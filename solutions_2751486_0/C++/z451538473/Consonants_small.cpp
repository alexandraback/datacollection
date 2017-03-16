#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[105];
int n;
bool judge(int b,int e)
{
    int count=0;
    for(int i=b;i<=e;i++)
        if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u')
            count++;
        else
        {
            if(count>=n)
                return true;
            else count=0;
        }
    if(count>=n)
        return true;
    return false;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        cin>>str>>n;
        printf("Case #%d: ",cas);
        int len=strlen(str),ans=0;
        for(int i=0;i<len;i++)
            for(int j=i;j<len;j++)
            {
                if(judge(i,j))
                {
                    ans++;
                }
            }
        printf("%d\n",ans);
    }
}
