/*
    ID: tiendao1
    LANG: C++
    TASK: milk6
*/

#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <list>
#include <functional>
#include <cmath>
#include <ctime>
#include <utility>
#include <bitset>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define inf 1e9
#define linf 1e18
#define BASE 1000000
#define EPS 1e-10
#define PI acos(-1)
#define pii pair<int,int>
#define fi first
#define se second
#define ALL(x) (x).begin(), (x).end()
#define ms(x,val) memset(x, val, sizeof(x))
#define pb(x) push_back(x)
#define make_unique(x) sort(ALL(x)) ; x.erase( unique(ALL(x)), x.end()) ;
#define dbg(x) do { cout << #x << " = " << x << endl; } while(0)
#define mp(x, y) make_pair(x, y)

const int bfsz = 1 << 16;
char bf[bfsz + 5];
int rsz = 0;
int ptr = 0;
char gc() {
    if (rsz <= 0) {
        ptr = 0;
        rsz = fread(bf, 1, bfsz, stdin);
        if (rsz <= 0)
            return EOF;
    }
    --rsz;
    return bf[ptr++];
}
void ga(char &c) {
    c = EOF;
    while (!isalpha(c))
        c = gc();
}
int gs(char s[]) {
    int l = 0;
    char c = gc();
    while (isspace(c))
        c = gc();
    while (c != EOF && !isspace(c)) {
        s[l++] = c;
        c = gc();
    }
    s[l] = '\0';
    return l;
}
template<class T> bool gi(T &v) {
    v = 0;
    char c = gc();
    while (c != EOF && c != '-' && !isdigit(c))
        c = gc();
    if (c == EOF)
        return false;
    bool neg = c == '-';
    if (neg)
        c = gc();
    while (isdigit(c)) {
        v = v * 10 + c - '0';
        c = gc();
    }
    if (neg)
        v = -v;
    return true;
}

/*** IMPLEMENTATION ***/
bool exitInput = false;
int ntest = 1, itest = 1 ;

const int dx[4] = { -1, +0, +1, -0 };
const int dy[4] = { +0, +1, +0, -1 };
// const int dx[8] = {-2, -1, -1, +0, +0, +1, +1, +2};
// const int dy[8] = {+0, -1, +1, -2, +2, -1, +1, +0};

const ll Mod = 1e9 + 7;
const int maxn = 100 + 5;
const int maxv = 20 + 5;
const int maxe = 4 + 5;

double C, F, X, increment, cookies, tTime;

void pre() {
	
}

void read() {
#define endread {exitInput = 1 ; return;}
	scanf("%lf %lf %lf", &C, &F, &X);
	increment = 2;
	cookies = tTime = 0;
}

void solve() {
	double time_noInc, time_toInc, ans = 1e9;
	
	time_noInc = time_toInc = 0;
	
	for(; tTime <= ans; )
	{
		/*
			cookies + increment * time_noInc = X
			time_noInc = (X - cookies) / increment
		*/
		time_noInc = (X - cookies) / increment;
		ans = min(ans, tTime + time_noInc);
		
		/*
			increment * time_toInc = C
			time_toInc = C / increment;
		*/
		time_toInc = C / increment;
		tTime += time_toInc;
		increment += F;
	}
	printf("Case #%d: %.7lf\n", itest, ans);
}

int main()
{
#ifdef HOME
	freopen("gentest.txt", "r", stdin); freopen("output.txt", "w", stdout);    
#else
	freopen("A-small.in","r",stdin) ; freopen("A-small.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0);

    scanf("%d",&ntest);

   // gi(ntest);

    pre();
	
	#ifdef HOME
	time_t t1, t2; t1 = clock();
	#endif

    for (itest = 1; itest <= ntest ; ++itest)
    {
        read();
        if (exitInput)
        {
            break;
        }
        solve();
    }
	
	#ifdef HOME
	//t2 = clock(); printf("\nRunning time: %.6lf\n", ((float)t2 - (float)t1) / CLOCKS_PER_SEC);
	#endif
	
	fclose(stdout);
	fclose(stdin);
	
    return 0;
}


