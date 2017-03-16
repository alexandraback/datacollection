#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long i64;
int tes,n;
i64 b,s[110];
int cal(int k)
{
    int res=n-k;
    i64 a=b;
    for(int i=0;i<k;++i)
    {
        while(a<=s[i])
        {
            if(a==1)    return n;
            res++;
            a+=(a-1);
        }
        a+=s[i];
    }
    return res;
}
int main()
{
  //  freopen("A-large.in","r",stdin);
   // freopen("A-large.out","w",stdout);
    scanf("%d",&tes);
    for(int h=1;h<=tes;++h)
    {
        cin>>b>>n;
        for(int i=0;i<n;++i)    cin>>s[i];
        sort(s,s+n);
        int res=n;
        for(int i=1;i<=n;++i)
            res=min(res,cal(i));
        printf("Case #%d: %d\n",h,res);
    }
    return 0;
}
