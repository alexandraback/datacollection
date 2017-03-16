#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807
#define INF 2000000000
#define PI acos(-1.0)
#define EPS 1e-9
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair

using namespace std;

LL gcd(LL x, LL y)
{
    if(y == 0)
        return x;
    return gcd(y,x%y);
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int t;
    cin >> t;
    int counter=0;
    while(t--)
    {
        string input;
        cin >> input;
        LL p=0,q=0;
        int k=0;
        while(input[k] != '/')
            p*=10,p+=input[k++]-'0';
        k++;
        while(k < input.size())
            q*=10,q+=input[k++]-'0';
        LL temp = gcd(p,q);
        p/=temp,q/=temp;
        int res=1;
        bool found = false;
        if(q == 1 && p == 1)
            found = true;
        while(q%2 == 0 && q > 0)
        {
            if(p >= q/2)
            {
                found = true;
                break;
            }
            q/=2;
            res++;
        }
        while(q > 1 || p > 1)
        {
            if(p >= q)
                p-=q;
            if(q%2 != 0 && q > 1)
            {
                found = false;
                break;
            }
            else q/=2;
        }
        if(p != q)
            found = false;
        if(!found)
            printf("Case #%d: impossible\n",++counter);
        else printf("Case #%d: %d\n",++counter,res);
    }
    return 0;
}
