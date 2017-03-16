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
    //freopen("C-small-attempt0.in","r",stdin);
    //freopen("C-large.in","r",stdin);
    //freopen("output.out","w",stdout);
    long long T;
    scanf("%lld",&T);
    for(long long t=1;t<=T;t++)
    {
        long long ans = 1,n,num,limit=0;
        string s;
        map<string, vector<int> > val;
        printf("Case #%lld:\n",t);
        scanf("%lld %lld",&n,&num);
        ans <<= (n-1);
        ans++;
        for(int i=0;i<(long long)(1<<(n-2));i++)
        {
            if(limit>=num)
            {
                break;
            }
            s = find_digit(ans);
            vector<int> mul;
            for(int j=2;j<=10;j++)
            {
                long long cur_digit = convert_to_base(s,j);
                long long get_mul = find_mul(cur_digit);
                if(get_mul == -1)
                    break;
                else
                    mul.push_back(get_mul);
            }
            if(mul.size()==9)
            {
                val.insert(make_pair(s,mul));
                cout << s << " ";
                for(vector<int>::iterator it = mul.begin();it!=mul.end();it++)
                {
                    cout << *it << " ";
                }
                printf("\n");
                limit++;
            }
            ans += 2;

        }

    }
    return 0;
}
