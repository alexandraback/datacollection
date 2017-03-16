/* Divanshu Garg */
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
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%lld",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl

#define INF 1000000

int a[1000005],n;
map <pii,int> m;

void pre() {

}

void pre2() {

}

int fun (int value, int abc)
{
    if (abc == n) {
        return 0;
    }
    pii p (value, abc);
    if (m.find (p) != m.end()) 
        return m[p];
    m[p] = INF;
    int ans;
    ans = INF;
    int xx = 0;
    if (value > a[abc]) {
        ans = fun (a[abc]+value, abc+1);
        m[p] = ans;
        return ans;
    }
    ans = 1 + fun (value, abc+1);
    ans = min (ans, 1 + fun (2*value - 1, abc));
    m[p] = ans;
    return ans;
}

 int main()
{
    pre();
    pre();
    int t,i;
    int aa,test=1;
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;
    while (t--) {
        pre2();
        m.clear();
        cin >> aa >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        sort (a, a+n);
        cout << "Case #" << test << ": " << fun (aa, 0) << endl;
        test++;
    }
    return 0;
}
