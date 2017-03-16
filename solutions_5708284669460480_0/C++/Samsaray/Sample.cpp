#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;
int T,test,k,l,s,cnt[210];
double ans;
char s1[210];
bool cp(int a)
{
    for(int i=a;i<l;++i)
      if(s1[i]!=s1[i-a]) return 0;
    return 1;
}
int calc()
{
    for(int i=0;i<l;++i)
      if(cnt[s1[i]-'A']==0) return 0;
    for(int i=1;i<l;++i)
      if(cp(i)) return (s-l)/i+1;
    return s/l;
}
int main()
{
    freopen("B-small-attempt0.in","rb",stdin);
    freopen("test.out","wb",stdout);
    scanf("%d",&T);
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d%d",&k,&l,&s); ans=s-l+1;
        if(ans<0) {printf("Case #%d 0.00000000\n",++test); continue;}
        scanf("%s",s1);
        for(int i=0;i<k;++i) ++cnt[s1[i]-'A'];
        scanf("%s",s1);
        for(int i=0;i<l;++i) ans=ans*cnt[s1[i]-'A']/(double)k;
        ans=calc()-ans;
        printf("Case #%d: %.8f\n",++test,ans);
    }
    return 0;
}
