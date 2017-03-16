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
#include <iomanip>

using namespace std ;

#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define REP(i,n) FOR(i,0,(n)-1)
#define DEP(i,n) DOW(i,(n)-1,0)
#define all(a) (a).begin() , (a).end()
#define mp(a,b) make_pair((a),(b))

#define RESET(c,x) memset (c, x, sizeof (c))

#define oo 1000111000

#define PI acos(-1.0)
#define fi first
#define se second
#define SIZE(c) (c).size()


typedef vector<int> VI ;
typedef vector<string> VS ;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

template<class T> inline int size(const T&c) { return c.size(); }

using namespace std;
int fastMax(int x, int y) { return (((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return (((y-x)>>(32-1))&(x^y))^x; }

int T;
long long n;
long long F[20];
long long m10[10];
int extra;

void preprocessing() {
	m10[0] = 1;
	F[0] = 0;
	for (int i = 1; i < 10; i++) {
		m10[i] = m10[i-1] * 10;
	}
	for (int i = 1; i <= 14; i++) {
		F[i] = F[i-1] + m10[i / 2] + m10[i - i / 2] - 1;
	}
	F[0] = 1;
}

long long calc(long long n) {
	stringstream ss;
	ss << n;
	string st = ss.str();
	string s1 = st.substr(0, st.length() / 2);
	reverse(s1.begin(), s1.end());
	string s2 = st.substr(st.length() / 2, st.length() -  st.length() / 2);
	if (s2 == "") s2 = "0";
	if (s1 == "") s1 = "0";
	// cout<<stoi(s1)<<' '<<stoi(s2)<<' '<<F[st.length() - 1]<<endl;
	return stoi(s1) + stoi(s2) + F[st.length() - 1] + (stoi(s1) == 1 ? -1 : 0 );
}

int main()
{
    freopen("A.inp","r",stdin);
    freopen("CC.out","w",stdout);
    scanf("%d",&T);
    preprocessing();
    for (int st = 1; st <= T; st++) {
    	cin>>n;
    	extra = 0;
    	if (n % 10 == 0) {
    		n = n - 1;
    		extra = 1;
    	}
    	cout<<"Case #"<<st<<": "<<min(calc(n) + extra , n + extra)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}