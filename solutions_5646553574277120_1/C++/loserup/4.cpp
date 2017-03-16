#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <queue>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define mp make_pair
#define LL long long
#define pb push_back
using namespace std;
#define sz 300005
#define inf 0x7fffffff
int v,c,d;
vector <long long> p;
int f()
{
	sort(p.begin(), p.end());
	LL now = 0;
	int i = 0, ans = 0;
	while(now < v)
	{
		if(i >= p.size() || p[i] > now + 1)
		{
			now += (now+1)*c;
			ans ++;
		}
		else
		{
			now += (LL)p[i++]*c;
		}
	}
	return ans;
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int T;
    cin>>T;
    rep(cas,T)
    {
        cin>>c>>d>>v;
        p.clear();
        rep(i,d)
        {
            int a;
            cin>>a;
            p.pb(a);
        }
        cout << "Case #"<< cas+1 <<": " << f() << endl;
    }
}
