#include<cstdio>
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<utility>
using namespace std;

long long min_num(long long a,long long b)
{
    return a>b?b:a;
}

string find_digit(long long val)
{
    string digits,rev_digits;
    while(val)
    {
        if(val%2)
            digits+='1';
        else
            digits+='0';
        val /=2;
    }
    for (std::string::reverse_iterator rit=digits.rbegin(); rit!=digits.rend(); ++rit)
    {
        rev_digits += *rit;
    }
    return rev_digits;

}

long long convert_to_base(string s,int base)
{
    long long ans =0;
    long long mul = 1;
    for(int i =s.length()-1;i>=0;i--)
    {
        if(s[i]=='1')
            ans+=mul;
        mul*=base;
    }
    return ans;
}

long long find_mul(long long digit)
{
    for(long long i=2;i<=(long long)sqrt(digit)+1;i++)
    {
        if(digit%i==0)
            return i;
    }
    return -1;
}

int main()
{
    //freopen("practice.in","r",stdin);
    //freopen("D-small-attempt0.in","r",stdin);
    //freopen("D-large.in","r",stdin);
    //freopen("output.out","w",stdout);
    long long T;
    scanf("%lld",&T);
    for(long long t=1;t<=T;t++)
    {
        printf("Case #%lld: ",t);
        long long k,c,s;
        scanf("%lld %lld %lld",&k,&c,&s);
        for(long long i=1;i<=k;i++)
            printf("%d ",i);
        printf("\n");
    }
    return 0;
}
