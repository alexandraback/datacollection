#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <array>
using namespace std;

#ifdef _LOCAL_
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

#define prev pppppppprev
#define next nnnnnnnnext

#ifdef _LOCAL_
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define DB1(x) cerr<<#x<<" = "<<(x)<<"\n"
#define DB2(x, y) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<"\n"
#define DB3(x, y, z) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<"\n"
#define DB4(x, y, z, w) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<", "<<#w<<" = "<<(w)<<"\n"
#define DB5(x, y, z, w, t) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<", "<<#w<<" = "<<(w)<<", "<<#t<<" = "<<(t)<<"\n"
#define DB6(x0, x1, x2, x3, x4, x5) cerr<<#x0<<" = "<<(x0)<<", "<<#x1<<" = "<<(x1)<<", "<<#x2<<" = "<<(x2)<<", "<<#x3<<" = "<<(x3)<<", "<<#x4<<" = "<<(x4)<<", "<<#x5<<" = "<<(x5)<<"\n"
#define DB7(x0, x1, x2, x3, x4, x5, x6) cerr<<#x0<<" = "<<(x0)<<", "<<#x1<<" = "<<(x1)<<", "<<#x2<<" = "<<(x2)<<", "<<#x3<<" = "<<(x3)<<", "<<#x4<<" = "<<(x4)<<", "<<#x5<<" = "<<(x5)<<", "<<#x6<<" = "<<(x6)<<"\n"
#define DB8(x0, x1, x2, x3, x4, x5, x6, x7) cerr<<#x0<<" = "<<(x0)<<", "<<#x1<<" = "<<(x1)<<", "<<#x2<<" = "<<(x2)<<", "<<#x3<<" = "<<(x3)<<", "<<#x4<<" = "<<(x4)<<", "<<#x5<<" = "<<(x5)<<", "<<#x6<<" = "<<(x6)<<", "<<#x7<<" = "<<(x7)<<"\n"
#define DB9(x0, x1, x2, x3, x4, x5, x6, x7, x8) cerr<<#x0<<" = "<<(x0)<<", "<<#x1<<" = "<<(x1)<<", "<<#x2<<" = "<<(x2)<<", "<<#x3<<" = "<<(x3)<<", "<<#x4<<" = "<<(x4)<<", "<<#x5<<" = "<<(x5)<<", "<<#x6<<" = "<<(x6)<<", "<<#x7<<" = "<<(x7)<<", "<<#x8<<" = "<<(x8)<<"\n"
#else
#define eprintf(...) static_cast<void>(0)
#define DB1(x) static_cast<void>(0)
#define DB2(x, y) static_cast<void>(0)
#define DB3(x, y, z) static_cast<void>(0)
#define DB4(x, y, z, w) static_cast<void>(0)
#define DB5(x, y, z, w, t) static_cast<void>(0)
#define DB6(x0, x1, x2, x3, x4, x5) static_cast<void>(0)
#define DB7(x0, x1, x2, x3, x4, x5, x6) static_cast<void>(0)
#define DB8(x0, x1, x2, x3, x4, x5, x6, x7) static_cast<void>(0)
#define DB9(x0, x1, x2, x3, x4, x5, x6, x7, x8) static_cast<void>(0)
#endif
template <class Container>
void print_cont(const Container &cont)
{
	cerr << "{ ";
	for(auto it = cont.begin(); it != cont.end(); ++it)
	{
		if(it != cont.begin())
			cerr << ", ";
		cerr << *it;
	}
	cerr << " }\n";
}
#ifdef _LOCAL_
#define eprint_cont(cont) cerr<<#cont<<" = ", print_cont(cont)
#else
#define eprint_cont(cont) static_cast<void>(0)
#endif

#define rep(x,y,z) for (int x = (y), e##x = (z);x < e##x; x++)
typedef long long ll;
typedef pair<int,int> pii;

const double EPS = 1e-8;

const int MAXN = 1e6;
int dist[MAXN+1] = {0};
int Q[MAXN + 1], qh = 0, qt = 0;
ll p10[16];

int rev_num(int n)
{
	char S[20];
	sprintf(S, "%d", n);
	int len = strlen(S);
	reverse(S, S + len);
	sscanf(S, "%d", &n);
	return n;
}

void test(int tnum)
{
	ll n;
	scanf("%lld", &n);
	printf("Case #%d: %lld\n", tnum, dist[n]);
	return;
	//while(1)
	{
		//n = 1 + rand() % (MAXN - 1);
	if(n <= 9)
	{
		printf("Case #%d: %d\n", tnum, dist[n]);
		return;
	}
	int len = 1;
	ll ans = 0;
	for(len = 1; p10[len] <= n; ++len)
		ans += p10[len / 2] + p10[len / 2 + (len & 1)] - 1;
	DB2(len, ans);
	if(p10[len - 1] < n)
	{
		char S[20];
		sprintf(S, "%lld", n);
		ll add;
		sscanf(S + (len / 2), "%lld", &add);
		if(add)
		{
			ans += add;
			reverse(S, S + (len / 2));
			S[len / 2] = 0;
			sscanf(S, "%lld", &add);
			if(add > 1)
				ans += add;
		}
		else
		{
			S[len / 2] = 0;
			sscanf(S, "%lld", &add);
			--add;
			sprintf(S, "%lld", add);
			reverse(S, S + len / 2);
			sscanf(S, "%lld", &add);
			ans += add;
			ans += p10[len / 2 + (len & 1)];
		}
	}
	printf("Case #%d: %lld\n", tnum, ans);
	if(!(n > 1e6 || ans == dist[n]))
	{
		printf("dist[%lld] = %d, ans = %lld\n", n, dist[n], ans);
	return;}}
}

void run()
{
	dist[1] = 1;
	Q[qt++] = 1;
	while(qh < qt)
	{
		int n = Q[qh++];
		int d = dist[n];
		int nn = n + 1;
		if(nn <= MAXN && dist[nn] == 0)
		{
			dist[nn] = 1 + d;
			Q[qt++] = nn;
		}
		nn = rev_num(n);
		if(nn <= MAXN && dist[nn] == 0)
		{
			dist[nn] = 1 + d;
			Q[qt++] = nn;
		}
	}

	//for(int n = 1; n <= MAXN; n *= 10)
	//	printf("ans[%d] = %d\n", n, ans[n] - ans[n / 10]);
	p10[0] = 1;
	for(int i = 1; i <= 15; ++i)
		p10[i] = p10[i - 1] * 10;

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
		test(t);
}

//#define file_name "barduck"

int main()
{
#ifdef _LOCAL_
    if(freopen("input.txt", "r", stdin) == NULL)
    {
        printf("Can't open input.txt\n");
        return 0;
    }
    if(freopen("output.txt", "w", stdout) == NULL)
    {
    	printf("Can't open output.txt\n");
    	return 0;
    }
#else
#ifdef file_name
    freopen(file_name".in", "r", stdin);
    freopen(file_name".out", "w", stdout);
#endif
#endif
    run();
#ifdef _LOCAL_
    //puts("================");
#endif

    return 0;
}
