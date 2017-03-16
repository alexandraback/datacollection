#include <bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
int len;
void dfs(char *s,vector<int>& v,int l,int val)
{
    if (l==len)
    {
        v.push_back(val);
        return;
    }
    if (s[l]=='?')
        for (int i=0;i<10;++i)
            dfs(s,v,l+1,val*10+i);
    else
        dfs(s,v,l+1,val*10+s[l]-'0');
}
int main()
{
    freopen("B.in","r",stdin);
    freopen("B.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    char format[10],s1[20],s2[20];
    for (int run=1;run<=cas;++run)
    {
        scanf("%s%s",s1,s2);
        len=strlen(s1);
        sprintf(format," %%0%dd",len);
        int d=999999,xx,yy;
        v1.clear();
        v2.clear();
        dfs(s1,v1,0,0);
        dfs(s2,v2,0,0);
        for (int x:v1)
            for (int y:v2)
                if (abs(x-y)<d)
                {
                    d=abs(x-y);
                    xx=x;
                    yy=y;
                }
                else if (abs(x-y)==d)
                {
                    if (xx>x)
                    {
                        xx=x;
                        yy=y;
                    }
                    else if (xx==x&&yy>y)
                        y=yy;
                }
        printf("Case #%d:",run);
        printf(format,xx);
        printf(format,yy);
        printf("\n");
    }
    return 0;
}
