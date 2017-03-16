/* @coder: Sidharth Gupta */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>


#define MOD 1000000007
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(a) MAX(a,-(a))
#define SET(a,b) memset(a, b, sizeof(a))
#define EVEN(a) ((a&1)==0)
#define SQR(a) ((a)*(a))
#define EPS 0.0001

typedef long long int lli;
typedef unsigned long long int llui;
typedef unsigned int uint;

using namespace std;

int main()
{
    int t, tc, n, count, l, i, j, k;
    char arr[105]={0};

    scanf("%d",&tc);

    for(t=1;t<=tc;++t)
    {
        count = 0;
        scanf("%s%d",arr,&n);

        l = strlen(arr);

        for(i=0;i<l;++i)
        {
            for(j=i+n-1;j<l;++j)
            {
                int flag = 0, c = 0;
                for(k=i;k<=j;++k)
                {
                    if(!(arr[k] == 'a' || arr[k] == 'e' || arr[k] == 'i' || arr[k] == 'o' || arr[k] == 'u'))
                    {
                        c += 1;
                        if(c==n)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    else
                        c = 0;
                }

                if(flag)
                    ++count;
            }
        }

        printf("Case #%d: %d\n", t, count);
    }
}
