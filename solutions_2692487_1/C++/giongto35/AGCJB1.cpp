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
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define push(a,b) (a).push_back((b))

typedef vector<int> VI ;
typedef vector<string> VS ;
template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
long long a,n;
int s[1000],T;
long long res;
long long op;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("AGCJ.out","w",stdout);
    cin>>T;
    FOR(st,1,T)
    {
        cout<<"Case #"<<st<<": ";
        cin>>a>>n;
        FOR(i,1,n) cin>>s[i];
        sort(s+1,s+1+n);
        op=0;
        res=n;
        FOR(i,1,n)
        {

                while (a<=s[i])
                {
                    op++;
                    if (op>n) break;
                    a+=a-1;
                }
                a+=s[i];
            if (op>n) break;
            res=min(res,op+n-i);
        }
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

