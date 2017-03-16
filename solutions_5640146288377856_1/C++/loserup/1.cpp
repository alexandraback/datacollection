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

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    int T,r,c,w;
    cin>>T;
    rep(cas,T)
    {
        cin>>r>>c>>w;
        int ans = r * (c/w) + w;
        if(c%w==0)ans--;
        cout << "Case #"<< cas+1 <<": " << ans << endl;
    }
}
