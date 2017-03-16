#include<bits/stdc++.h>
using namespace std;

string ll2str(long long n)
{
    stringstream ss;
    ss<<n;
    return ss.str();
}

int main()
{
    long long T;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%lld",&T);
    for(long long cas=1;cas<=T;++cas)
    {
        long long n;
        long long k=0;
        scanf("%lld",&n);
        if(n==0) {printf("Case #%lld: INSOMNIA\n",cas);continue;}
        set<long long> s;
        while(s.size()!=10)
        {
            ++k;
            long long tmp=n*k;
            string tmpstr=ll2str(tmp);
            long long len=tmpstr.length();
            for(long long i=0;i<len;++i) s.insert(tmpstr[i]-'0');
        }
        printf("Case #%lld: %lld\n",cas,k*n);
    }
    return 0;
}
