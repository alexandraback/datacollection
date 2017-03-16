#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n;char s[1000001];int a[1000001]={0};
long long ans=0;
int pd[27]={0};
int main()
{
    for(int i=0;i<26;++i) pd[i]=1;
    pd['a'-'a']=pd['e'-'a']=pd['i'-'a']=pd['o'-'a']=pd['u'-'a']=0;
    freopen("A-large (1).in","r",stdin);
    freopen("A-large (1).out","w",stdout);
    scanf("%d\n",&t);
    for(int tt=1;tt<=t;++tt)
    {
        scanf("%s %d\n",s,&n);
        ans=0;a[0]=0;int cur=0,j,l=strlen(s);
        for(int i=0;i<l;++i) a[i+1]=a[i]+pd[s[i]-'a'];
        //for(int i=0;i<=l;++i) cout<<a[i]<<" ";cout<<"!";
        for(int i=n;i<=l;++i)
        {
            if(a[i]-a[i-n]==n)
            {
                //cout<<i-n+1<<" "<<i<<endl;
                j=i-n+1;
                ans+=(j-cur)*(l-i+1);
                cur=j;
            }
        }
        printf("Case #%d: %lld\n",tt,ans);
    }
    return 0;
}
