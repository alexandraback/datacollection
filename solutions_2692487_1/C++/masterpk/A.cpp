#include<cstdio>
#include<vector>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<sstream>
#include<bitset>
#include<deque>
#include<utility>
#include<cstdlib>
#include<iomanip>
#include<cctype>
#include<climits>
#include<iostream>
using namespace std;
#define ll             long long
#define ull            unsigned long long
string tostr(long long x) { stringstream ss; ss << x; return ss.str(); }
long long toint(const string &s) { stringstream ss; ss << s; long long x; ss >> x; return x; }
using namespace std;
int n,flag;
int a[300];
map <pair <int, int>, int> m;
int solve (int value, int index)
{

    if (index == n)
    {
        return 0;
    }
    pair <int, int> p (value, index);
    if (m.find (p) != m.end())
    {
        return m[p];
    }
    m[p] = 1000000;
    int result;
    int xx=0;
    result = 1000000;
    if (value > a[index])
    {
        result = solve (a[index]+value, index+1);
        m[p] = result;
        return result;
    }
    result = 1 + solve (value, index+1);

    result = min (result, 1 + solve (2*value - 1, index));
    m[p] = result;
    return result;
}

 int main()
{
    flag = 0;
freopen("A-large.in","r",stdin);
//freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
   int test,i,j,aa,ii=1;
    cin >> test;
    while (test--)
    {
        cin>>aa>> n;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort (a, a+n);
        m.clear();
        cout << "Case #" << ii << ": ";
        ii++;
        cout << solve(aa, 0) << endl;
    }
    return 0;
}
