#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

#define lim 100000000000000ll
#define max 2001003

long long i,a,b;
int ot;
short t,T;
std::vector<long long>ans;

inline bool pal(long long a)
{
    static char buf[22];
    static std::string s;
    sprintf(buf,"%lld",a);
    s=buf;
    std::reverse(s.begin(),s.end());
    return s==buf;
}

int main()
{
    ans.push_back(1ll);
    for(i=2ll;i<max;++i)
        if(pal(i) && pal(i*i))
            ans.push_back(i*i);
    scanf("%hd",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%lld %lld",&a,&b);
        for(ot=0,i=std::lower_bound(ans.begin(),ans.end(),a)-ans.begin();i<ans.size() && ans[i]<=b;++i,++ot);
        printf("Case #%hd: %d\n",t,ot);
    }
    return 0;
}
