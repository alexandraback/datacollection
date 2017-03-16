#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100;
string s,t;
int len,a[N],b[N],aa[N],bb[N];
long long ans=(1LL)<<60,ans_a,ans_b;
void check()
{
    long long cur_a=0,cur_b=0;
    for(int i=0;i<len;++i)
    {
        cur_a=cur_a*10LL+a[i];
        cur_b=cur_b*10LL+b[i];
    }
    long long cur_ans=cur_a-cur_b;
    if(cur_ans<0)
    {
        cur_ans=-cur_ans;
    }
    if(cur_ans<ans||(cur_ans==ans&&cur_a<ans_a)||(cur_ans==ans&&cur_a==ans_a&&cur_b<ans_b))
    {
        ans=cur_ans;
        ans_a=cur_a;
        ans_b=cur_b;
        memcpy(aa,a,sizeof(aa));
        memcpy(bb,b,sizeof(bb));
    }
}
void dfs1(int dep)
{
    if(dep == len)
    {
        check();
        return;
    }
    if(t[dep]=='?')
    {
        for(int i=0;i<10;++i)
        {
            b[dep]=i;
            dfs1(dep+1);
        }
    }
    else
    {
        b[dep]=t[dep]-'0';
        dfs1(dep+1);
    }
}
void dfs(int dep)
{
    if(dep==len)
    {
        dfs1(0);
        return;
    }
    if(s[dep]=='?')
    {
        for(int i=0;i<10;++i)
        {
            a[dep]=i;
            dfs(dep+1);
        }
    }
    else
    {
        a[dep]=s[dep]-'0';
        dfs(dep+1);
    }
}
int main()
{
    int T,cas=0;
    cin>>T;
    while(T--)
    {
        printf("Case #%d:",++cas);
        cin>>s>>t;
        len=(int)s.size();
        ans=(1LL)<<60;
        dfs(0);
        printf(" ");
        for(int i=0;i<len;++i)
        {
            printf("%d",aa[i]);
        }
        printf(" ");
        for(int i=0;i<len;++i)
        {
            printf("%d",bb[i]);
        }
        puts("");
        //cout<<" "<<ans_a<<" "<<ans_b<<endl;
    }
    return 0;
}
