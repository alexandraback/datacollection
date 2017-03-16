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

string toStr(LL n)
{
    ostringstream os;
    os<<n;
    return os.str();
}

LL toLong(string num)
{
    LL ret = 0;
    stringstream is(num);
    is>>ret;
    return ret;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    int total_test = INPT_INT;

    for(int cur_test = 1; cur_test <= total_test; ++cur_test)
    {
        LL n, res = 0;
        cin>>n;

        while(n > 9)
        {
            string num = toStr(n);

            string right = num.substr(num.size()/2);

            reverse(num.begin(),num.end());
            string left = num.substr(num.size()/2+num.size()%2);

            LL leftVal  = max(0LL,toLong(left)-1);
            LL rightVal = max(0LL,toLong(right)-1);

            if(toLong(right) != 0)
            {
                string tmp = num;
                tmp[0] = '1'; tmp[tmp.size()-1] = '1';
                for(int i = 1; (i+1) < tmp.size(); ++i) tmp[i] = '0';

                n = min(n,toLong(tmp));
                res += leftVal+rightVal + (leftVal?1:0);
            }
            if(n%10==1) {++res;--n;}
            --n;++res;
        }
        res += n;
        printf("Case #%d: %lld\n",cur_test,res);
    }
	return 0;
}
