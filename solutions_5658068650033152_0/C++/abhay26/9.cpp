/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
typedef long long ll;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,1,0,-1};
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(Z,t)
    {
        int ans = 0;
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        printf("Case #%d: ",Z+1);
        if(m > n)
            swap(m,n);
        if(m <= 2)
        {
            printf("%d\n",k);
        }
        if(m == 3 && n == 3)
        {
            if(k >= 5)
                printf("%d\n",k-1);
            else
                printf("%d\n",k);
        }
        if(m == 3 && n == 4)
        {
            if(k >= 8)
                printf("%d\n",k-2);
            else if(k >= 5)
                printf("%d\n",k - 1);
            else
                printf("%d\n",k);
        }
        if(m == 3 && n == 5)
        {
            if(k >= 11)
                printf("%d\n",k-3);
            else if(k >= 8)
                printf("%d\n",k-2);
            else if(k >= 5)
                printf("%d\n",k - 1);
            else
                printf("%d\n",k);
        }
        if(m == 3 && n == 6)
        {
            if(k >= 14)
                printf("%d\n",k-4);
            if(k >= 11)
                printf("%d\n",k-3);
            else if(k >= 8)
                printf("%d\n",k-2);
            else if(k >= 5)
                printf("%d\n",k - 1);
            else
                printf("%d\n",k);
        }
        if(m == 4 && n == 4)
        {
            if(k >= 12)
                printf("%d\n",k-4);
            else if(k >= 10)
                printf("%d\n",k-3);
            else if(k >= 8)
                printf("%d\n",k-2);
            else if(k >= 5)
                printf("%d\n",k - 1);
            else
                printf("%d\n",k);
        }
        if(m == 4 && n == 5)
        {
            if(k >= 16)
                printf("%d\n",k-6);
            else if(k >= 14)
                printf("%d\n",k-5);
            else if(k >= 12)
                printf("%d\n",k-4);
            else if(k >= 10)
                printf("%d\n",k-3);
            else if(k >= 8)
                printf("%d\n",k-2);
            else if(k >= 5)
                printf("%d\n",k - 1);
            else
                printf("%d\n",k);
        }
    }
return 0;
}
