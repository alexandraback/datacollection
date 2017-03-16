#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define feach(arr,i) for(vector<pii>::itr i=(arr.begin());i!=(arr.end());++i)
#define pb push_back
#define x first
#define y second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),x.end());
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define pr pair
#define prq priority_queue
#define itr iterator
#define sf scanf
#define pf printf

#define lowbit(i) (i&(-i))

typedef long long int LL;
typedef pr<int,int> pii;

const int oo=(~0u)>>1;
const LL lloo=(~0ull)>>1;
const int INF = 0x3f3f3f3f;
const double dboo=1e+20;
const double eps=1e-8;
const double pi=3.1414926;

int T;
int a,b,k;
int bforce()
{
    int ans = 0 ;
    for (int i = 0; i <= a; ++i)
    {
        for (int j = 0; j <= b; ++j)
        {
            if((i&j) <= k )
                ans ++;
        }
    }
    return ans;
}
int main(int argc, char *argv[])
{
    sf("%d",&T);
    ft(tt,1,T)
    {

        sf("%d%d%d",&a,&b,&k);
        a--,b--,k--;
        if(a > b)
            swap(a,b);
        // pf("%d\n",k*b + k * abs(a-k));
        pf("Case #%d: %d\n",tt,bforce());
    }
    return 0;
}
