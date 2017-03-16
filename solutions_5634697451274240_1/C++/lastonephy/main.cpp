#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#define LL long long
#define eps 1e-8
#define mem(a,b) memset(a,b,sizeof(a))
#define zero(x) ((x > +eps) - (x < -eps))
#define MAX 100010
using namespace std;

char str[110];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int ii = 1; ii <= t; ii ++)
    {
        scanf("%s",str);
        int cou = 0;
        for(int i = 0; str[i]; i ++)
        {
            if(str[cou] != str[i])
            {
                cou ++;
                str[cou] = str[i];
            }
        }
        if(str[cou] == '+')
        {
            cou --;
        }
        cou ++;
        printf("Case #%d: %d\n",ii,cou);
    }
    return 0;
}
