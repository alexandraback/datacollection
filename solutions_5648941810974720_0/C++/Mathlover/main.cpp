#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int cnt[500];
string ch[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char s[20005];
int ans[10];
void reduce(int x)
{
    for(int i=0;i<ch[x].length();++i)
        cnt[ch[x][i]]-=ans[x];
}
int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("1.out","w",stdout);
    int ca=0;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        memset(cnt,0,sizeof(cnt));
        scanf("%s",s);
        for(int i=0;s[i];++i)
            cnt[s[i]]++;
        int cal[10]={6,0,2,8,4,3,1,5,9,7};
        char cal2[]="xzwgutofiv";
        for(int i=0;i<10;++i)
        {
            ans[cal[i]]=cnt[cal2[i]-'a'+'A'];
            reduce(cal[i]);
        }
        printf("Case #%d: ",++ca);
        for(int i=0;i<=9;++i)
            for(int j=0;j<ans[i];++j)
                putchar('0'+i);
        puts("");




    }
}
