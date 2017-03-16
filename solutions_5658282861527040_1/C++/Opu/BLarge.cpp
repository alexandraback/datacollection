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

int last;
string strA, strB, strK;

string ToBinaryString(int n)
{
    string ret = "";

    while(n)
    {
        ret += (n%2) + '0';
        n /= 2;
    }
    return ret;
}

LL dp[33][2][2][2];

LL calc(int pos, bool fA, bool fB, bool fK)
{
    if(pos == last) return 1;
    LL &ret = dp[pos][fA][fB][fK];
    if( ret != -1 ) return ret;

    ret = 0;
    for(int i = 0;i<2;++i) for(int j = 0;j<2;++j)
    {
        int val = (i&j);

        if( pos >= strA.size() && i ) continue;
        if( pos >= strB.size() && j ) continue;
        if( pos >= strK.size() && val ) continue;

        if( (pos+1) >= strA.size() && (i && fA) ) continue;
        if( (pos+1) >= strB.size() && (j && fB) ) continue;
        if( (pos+1) >= strK.size() && (val && fK) ) continue;

        bool _fA = fA, _fB = fB, _fK = fK;

        if( pos < strA.size() )
        {
            if( strA[pos] == '0' && i ) _fA = 1;
            if( strA[pos] == '1' && i == 0 ) _fA = 0;
        }
        if( pos < strB.size() )
        {
            if( strB[pos] == '0' && j ) _fB = 1;
            if( strB[pos] == '1' && j == 0 ) _fB = 0;
        }
        if( pos < strK.size() )
        {
            if( strK[pos] == '0' && val ) _fK = 1;
            if( strK[pos] == '1' && val == 0 ) _fK = 0;
        }
        ret += calc(pos+1,_fA,_fB,_fK);
    }
    return ret;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

    int caseCnt = INPT_INT;

    for(int cNo = 1;cNo<=caseCnt;++cNo)
    {
        int A = INPT_INT, B = INPT_INT, K = INPT_INT;

        strA = ToBinaryString(A-1);
        strB = ToBinaryString(B-1);
        strK = ToBinaryString(K-1);

        last = max( max(strA.size(),strB.size()),strK.size() );
        memset(dp,-1,sizeof(dp));

        printf("Case #%d: ",cNo);
        cout<<calc(0,0,0,0)<<endl;
    }
    return 0;
}
