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
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-large.in","r",stdin);
    //freopen("output.out","w",stdout);
    long long T;
    scanf("%lld",&T);
    for(long long t=1;t<=T;t++)
    {
        printf("Case #%lld: ",t);
        string s;
        long long ans =0;
        cin >> s;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='-')
            {
                ans++;
                for(int j=0;j<=i;j++)
                {
                    if(s[j]=='-')
                    {
                        s[j] = '+';
                    }
                    else if(s[j]=='+')
                    {
                        s[j] = '-';
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
