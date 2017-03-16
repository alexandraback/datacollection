#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

const inline int __GET_INT(){int ret;scanf("%d",&ret);return ret;}
#define INPT_INT __GET_INT()

typedef long long LL;
const int limit = 7;//limit digits.

vector<LL> nums[8];

void gen_palindromes()
{
    LL p[10];
    p[0] = 1;
    for(int i = 1;i<9;++i) p[i] = p[i-1]*10;

    for(int i = 1;i<=7;++i)
    {
        if( i == 1 )
        {
            for(int j = 1;j<10;++j) nums[i].push_back(j);
        }
        else if( i % 2 )
        {
            for(int j = 0;j<nums[i-1].size();++j)
            {
                int base = (nums[i-1][j] / p[i/2]) * p[i/2+1] + nums[i-1][j] % p[i/2];

                for(int k = 0;k<10;++k)nums[i].push_back( base+(p[i/2]*k) );
            }
        }
        else
        {
            for(int j = 0;j<nums[i-1].size();++j)
            {
                nums[i].push_back( (nums[i-1][j]/p[i/2-1])*p[i/2] + (nums[i-1][j]/p[i/2-1])%10*p[i/2-1] + nums[i-1][j]%p[i/2-1] );
            }
        }
    }
}

bool is_good(LL num)
{
    string s;
    ostringstream os;
    os<<num;
    s = os.str();
    reverse(s.begin(),s.end());
    return s==os.str();
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C_small.out","w",stdout);

    int T = INPT_INT;

    gen_palindromes();
    vector<LL> good;
    for(int i = 1;i<=7;++i)
    {
        for(int j = 0;j<nums[i].size();++j)
        {
            LL sq = nums[i][j] * nums[i][j];
            if( is_good(sq) ) good.push_back(sq);
        }
    }

    for(int ca = 1;ca<=T;++ca)
    {
        LL A,B;
        cin>>A>>B;

        int res = 0;
        for(int i = 0;i<good.size();++i) if( good[i] >= A && good[i] <= B )++res;

        printf("Case #%d: %d\n",ca,res);
    }
    return 0;
}
