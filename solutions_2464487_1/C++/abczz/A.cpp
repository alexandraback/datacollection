#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(n);i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

using namespace std;

bool check(LL mid, LL r, LL t) {
    long double y;
    y=(long double)mid*r*2+(long double)mid*mid*2-mid;
    if (y>t) return false;
    return true;
}

void solve(int cas)
{
    LL r, t;
    cin>>r>>t;
    printf("Case #%d: ", cas);
    int st=1, ed=1000000000;
    while (st<=ed) {
        int mid=st+ed>>1;
        if (check(mid,r,t)) st=mid+1;
        else ed=mid-1;
    }
    cout<<ed<<endl;
}

int main()
{
    int T;
//	freopen("A.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    scanf("%d", &T);
    for (int i=1; i<=T; ++i) solve(i);
    return 0;
}
