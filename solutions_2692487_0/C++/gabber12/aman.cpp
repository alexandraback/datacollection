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
#include <cmath>

using namespace std;

#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define forall(i,a,n) for(int i=(a); i < (n); i++)
#define forev(i, a, n) for(int i = (a); i >= (n); i--)
#define fill(i,a) memset(i, a, sizeof(i))
#define V(x) vector<x>
#define vii vector<int>
#define sii set<int>
#define sz(a) a.size()
#define prnt(n) printf("%d\n", n)
#define INF INT_MAX
#define gc getchar_unlocked
#define M  100001
using namespace std;
int n,flag;
int a[1000003];
map <pair <int, int>, int> m;
int fun (int value, int index)
{
 
    if (index == n) {
        return 0;
    }
    pair <int, int> p (value, index);
    if (m.find (p) != m.end()) {
        return m[p];
    }
    m[p] = 1000000;
    int result;
    result = 1000000;
    if (value > a[index]) {
        result = fun (a[index]+value, index+1);
        m[p] = result;
        return result;
    }
    result = 1 + fun (value, index+1);
    int l = 0;
    
    result = min (result, 1 + fun (2*value - 1, index));
    m[p] = result;
    return result;
}
 
 int main()
{
    flag = 0;
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int t,i,j,aa,ii=1;
    cin >> t;
    while (t--) {
        cin >> aa >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort (a, a+n);
        m.clear();
        cout << "Case #" << ii << ": ";
        ii++;
        cout << fun (aa, 0) << endl;
    }
    return 0;
}