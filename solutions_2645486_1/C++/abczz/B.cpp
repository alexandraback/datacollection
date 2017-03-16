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

int E, R, N;

void solve(int cas)
{
    printf("Case #%d: ", cas);
    cin>>E>>R>>N;
    LL ans=0, rem=E, v;
    stack<pair<LL,LL> > s;
    REP(i,N) {
        cin>>v;
        while (!s.empty()) {
            PII x=s.top();
            if (x.first<v && rem+x.second<=E) {
                rem+=x.second;
                ans-=x.first*x.second;
                s.pop();
            } else break;
        }
        if (!s.empty()) {
            PII x=s.top();
            if (x.first<v) {
                x.second-=E-rem;
                ans-=x.first*(E-rem);
                rem=E;
            }
        }
        s.push(MP(v,rem));
        ans+=rem*v;
        rem=R;
    }
    cout<<ans<<endl;
}

int main()
{
    int T;
//	freopen("B.in","r",stdin);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
    scanf("%d", &T);
    for (int i=1; i<=T; ++i) solve(i);
    return 0;
}
