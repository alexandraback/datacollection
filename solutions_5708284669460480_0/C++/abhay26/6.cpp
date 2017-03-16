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
typedef long long ll;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,1,0,-1};
int k,l,s;
char G[10];
char B[10];
char A[10];
//int cnt = 0;
int hi;
double sum = 0;
double count1 = 0;
void calc(int pos)
{
    if(pos >= s)
    {
        int tot = 0;
        for(int i=0;i<s;i++)
        {
            int cur = 0;
            for(int j=i;j<s;j++)
            {
                if(A[j] != B[cur])
                    break;
                cur++;
                if(cur >= l)
                    break;
            }
            if(cur >= l)
                tot++;
        }
       // cout << A << " " << B << " " << tot << endl;
        sum += tot;
        hi = max(hi, tot);
        count1++;
        return;
    }
    FOR(i,k)
    {
        A[pos] = G[i];
        calc(pos+1);
    }
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    int kas = 0;
    while(t--)
    {
    	kas++;
        hi = 0;
        //cnt = 0;
        count1 = 0;
        sum = 0;
    	cin >> k >> l >> s;
        scanf("%s %s",G,B);
        FOR(i,k)
        {
            A[0] = G[i];
            calc(1);
        }
        //cout << hi << " " << count1 << " " << sum << endl;
        double ans = (double)hi*count1 - sum;
        ans = ans/count1;
        printf("Case #%d: %.8lf\n",kas,ans);
    }
return 0;
}
