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
string st;
long long res;
int near;
int n,T,i,j,s[1000010];

int con(char u)
{
    if (u!='a'&&u!='e'&&u!='i'&&u!='o'&&u!='u') return 1; else return 0;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("ACJ1C.out","w",stdout);
    cin>>T;
    FOR(so,1,T)
    {
        cin>>st>>n;
        s[0]=0;
        FOR(i,1,st.length()) s[i]=s[i-1]+con(st[i-1]);
        res=0;
        near=-1;
        FOR(i,1,st.length())
        {
            if (s[i]-s[i-n]==n) near=i-n+1;
            if (near!=-1) res=res+near;
        }
        cout<<"Case #"<<so<<": "<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

