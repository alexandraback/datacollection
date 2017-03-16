#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);
    int t;
    string s;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        cin>>s;
        int l=s.length()-1;
        printf("Case #%d: ",i);
        while(l>=0&&s[l]=='+')
            l--;
        if(l==-1)
        {
            printf("0\n");
            continue;
        }
        int an=1;
        for(int i=l-1;i>=0;i--)
        {
            if(s[i]!=s[i+1])
                an++;
        }
        printf("%d\n",an);
    }
}
