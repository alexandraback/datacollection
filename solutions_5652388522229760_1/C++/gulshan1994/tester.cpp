#include<cstdio>
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<utility>
using namespace std;

long long min_num(long long a,long long b)
{
    return a>b?b:a;
}

int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("output.out","w",stdout);
    long long T;
    scanf("%lld",&T);
    for(long long t=1;t<=T;t++)
    {
        printf("Case #%lld: ",t);
        long long n,ans=-1;
        set<int> digits;
        scanf("%lld\n",&n);
        for(long long i=1;i<1000001;i++)
        {
            long long num = n*i;
            while(num)
            {
                digits.insert(num%10);
                num /= 10;
            }
            if(digits.size()==10)
            {
                ans = n*i;
                break;
            }
        }
        if(ans == -1)
        {
            printf("INSOMNIA\n");
        }
        else
        {
            printf("%lld\n",ans);
        }
    }
    return 0;
}
