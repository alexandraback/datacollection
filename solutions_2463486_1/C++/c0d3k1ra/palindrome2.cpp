/* @ Author   : Amit Upadhyay
 * @ Program  : PALINDROME
 */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <stdarg.h>
#include <limits>
#include <cfloat>

//#define DEBUG
#define max 10000000
typedef unsigned long long int64;

using namespace std;

//vector< pair<int64,int64> > x;
inline void scan(int64 *a)
{
	char c = 0;
	while(c<33)
	c = fgetc_unlocked(stdin);
	*a = 0;
	while(c>33)
	{
		*a = *a*10 + c - '0';
		c = fgetc_unlocked(stdin);

	}
}
/*inline bool ispalindrome(int64 t)
{
    int64 r,p;
    p=t;
    r=0;
    int64 rem;
    while(p!=0)
    {
        rem=p%10;
        r=10*r+rem;
        p=p/10;
    }
    if(r==t) return true;
    else return false;
}*/
int64 x[39]={1LL,4LL,9LL,121LL,484LL,10201LL,12321LL,14641LL,40804LL,44944LL,1002001LL,1234321LL,4008004LL,100020001LL,102030201LL,104060401LL,121242121LL,123454321LL,125686521LL,400080004LL,404090404LL,10000200001LL,10221412201LL,12102420121LL,12345654321LL,40000800004LL,1000002000001LL,1002003002001LL,1004006004001LL,1020304030201LL,1022325232201LL,1024348434201LL,1210024200121LL,1212225222121LL,1214428244121LL,1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL};
/*inline void preprocessing()
{
    int64 sqr;
    pair<int64,int64> pp;
    for(int64 i=1;i<=max;i++)
    {
        sqr=i*i;
        bool t=ispalindrome(sqr);
        bool tw=ispalindrome(i);
        if(t && tw)
        {
            pp.first=i;
            pp.second=sqr;
            x.push_back(pp);
        }

    }
}
*/
int main()
{
//    preprocessing();
    int tests;
    int64 a,b;int64 i,j,k,l,c,g;
    #ifndef DEBUG
    scanf("%d",&tests);
    for(i=1;i<=tests;++i)
    {
        scan(&a); scan(&b);
        //printf("a=%lld b=%lld ",a,b);
        c=0;
        for(j=0;j<39;++j)
        {
            if(x[j]>=a && x[j]<=b)
                c++;
        }
        printf("Case #%d: %d\n",i,c);
    }
    #endif
    #ifdef DEBUG
    for(int i=0;i<39;++i)
     printf("%lld\n",x[i]);
    #endif
    return 0;
}

