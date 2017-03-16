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

void printans(char a, char b, int n)
{
    if(a!='\0' && b!='\0')
    {
        for(int i=0;i<n;++i)
        {
            printf("%c%c",a,b);
        }
    }
}

int main()
{
    int t, tc, x, y;

    scanf("%d",&tc);

    for(t=1;t<=tc;++t)
    {
        scanf("%d%d",&x,&y);

        char a = '\0';
        char b = '\0';

        printf("Case #%d: ",t);

        if(x<0)
        {
            a = 'E';
            b = 'W';
        }
        else if(x>0)
        {
            a = 'W';
            b = 'E';
        }

        if(x!=0)
            printans(a,b,ABS(x));

        a = '\0';
        b = '\0';

        if(y<0)
        {
            a = 'N';
            b = 'S';
        }
        else if(y>0)
        {
            a = 'S';
            b = 'N';
        }

        if(y!=0)
            printans(a,b,ABS(y));

        printf("\n");
    }

    return 0;
}
