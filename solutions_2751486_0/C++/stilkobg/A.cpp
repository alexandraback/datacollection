#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int it[1000005];
int main()
{
    int t=0,T;
    scanf("%d",&T);
    while(t++<T)
    {
        int n;
        string s;
        cin>>s;
        scanf("%d",&n);
        memset(it,0,sizeof(it));
        int i,j,sz=s.size(),ans=0;
        for(i=0;i<sz;i++)
        {
            for(j=i;j<sz;j++)
            {
                int k,br=0;
                for(k=i;k<=j;k++)
                {
                    if(s[k]!='a'&&s[k]!='e'&&s[k]!='i'&&s[k]!='o'&&s[k]!='u')
                    br++;
                    else
                    br=0;
                    if(br>=n){ans++;break;}
                }
            }
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
