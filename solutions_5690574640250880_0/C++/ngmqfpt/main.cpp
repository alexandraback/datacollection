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

const int dx[4] = { +0, +1, +0, -1 };
const int dy[4] = { +1, +0, -1, +0 };
// const int dx[8] = {-2, -1, -1, +0, +0, +1, +1, +2};
// const int dy[8] = {+0, -1, +1, -2, +2, -1, +1, +0};

const ll Mod = 1e9 + 7;
const int maxn = 50 + 5;
const int maxv = 20 + 5;
const int maxe = 4 + 5;

const char mine = '*', blank = '.';

int R, C, M, deg[maxn][maxn];
char s[maxn][maxn];

bool valid(int i, int j)
{
	return i >= 0 && i < R && j >= 0 && j < C;
}

bool seeAround(int r, int c, int x)
{
	int i, j, ix, iy;
	
	for(ix = -1; ix <= 1; ++ix)
	{
		for(iy = -1; iy <= 1; ++iy)
		{
			i = r + ix;
			j = c + iy;
			if(valid(i, j) && deg[i][j] == x)
				return true;
		}
	}
	return false;
}

void fillS(char x)
{
	int i, j;
	for(i = 0; i < R; ++i)
	{
		for(j = 0; j < C; ++j)
		{
			s[i][j] = x;
		}
	}
}
void printS()
{
	//return;
	int i, j;
	for(i = 0; i < R; ++i)
	{
		s[i][C] = 0;
		printf("%s\n", s[i]);
	}
}

void pre() {
	
}

void read() {
#define endread {exitInput = 1 ; return;}
	scanf("%d %d %d", &R, &C, &M);
}

void solve() {
	printf("Case #%d:\n", itest);
	
	fillS(blank);
	
	int i, j, w, h, cnt, maxC = C - 2, maxR = R - 2;
		
	if(R == 1)
	{
		for(j = 0; j < M; ++j)
			s[0][j] = mine;
		s[R-1][C-1] = 'c';
		printS(); 
		return;
	}
	if(C == 1)
	{
		for(j = 0; j < M; ++j)
			s[j][0] = mine;
		s[R-1][C-1] = 'c';
		printS(); 
		return;
	}
	if(M + 1 == R * C)
	{
		fillS(mine);
		s[R-1][C-1] = 'c';
		printS();
		return;
	}
	
	int w2, h2, S, gh;
	for(w = 2; w <= C; ++w)
	{
		for(h = 2; h <= R; ++h)
		{
			w2 = C - w;
			h2 = R - h;
			S  = h2 * C + w2 * R - h2 * w2;
			
			if(M >= S)
			{
				fillS(blank);
				i = j = cnt = 0;
				for(i = 0; i < h2; ++i)
				{
					for(j = 0; j < C; ++j)
						s[i][j] = mine;
				}
				for(i = 0; i < w2; ++i)
				{
					for(j = 0; j < R; ++j)
						s[j][i] = mine;
				}
				cnt += S;
				
				i = h2; j = w2;
				for(; cnt < M && i < maxR;)
				{
					if(j < maxC)
					{
						s[i][j] = mine; 
						++j;
						++cnt;
					}
					else
					{
						j = w2; 
						++i;
					}
				}	
				if(cnt == M)
				{
					s[R-1][C-1] = 'c';
					printS();
					return;
				}
			}
		}
	}
	
	//if(R * C != 25) printf("%d %d %d\n", R, C, M);
	puts("Impossible");
}

int main()
{
#ifdef HOME
	freopen("gentest.txt", "r", stdin); freopen("output.txt", "w", stdout);    
#else
	//freopen("A-small.in","r",stdin) ; freopen("A-small.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0);

    scanf("%d", &ntest);

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


