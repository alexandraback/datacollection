
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef long double ld;

#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()
#define Max(a,b) (a)<(b)?(b):(a)
#define Min(a,b) (a)<(b)?(a):(b)

template<typename T, typename S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

char buf[1024];

int Solve(int N)
{
	int last_num;
	if (N == 0)
	{
		last_num = -1;
		return last_num;
	}

	int freq[10];
	// clear freq
	for (int i = 0; i < 10; i++)
		freq[i] = 0;

	// searching the number
	last_num = -1;
	for (int i = 1; i <= 100; i++)
	{
		char buf[512];
		sprintf(buf, "%d", i*N);
		int len = strlen(buf);
//		printf("%s\n", buf);
		for (int j = 0; j < len; j++)
		{
			// set freq
			int idx = buf[j] - '0';
			freq[idx] = 1;
//			printf("%d set ", idx);
		}
		// check all 1
		bool all_one = true;
		for (int k = 0; k < 10; k++)
			if (freq[k] == 0)
			{
				all_one = false;
				break;
			}
		if (all_one)
		{
			last_num = i*N;
			break;
		}
	}
	assert(N == 0 || last_num != -1);

	return last_num;
}
int main() {

	fgets(buf, 1024, stdin);
	int T = atoi(buf);
	For(tcase, 1, T) {
		uint32_t N;
		scanf("%u", &N);


		int  ans = Solve(N);

		if (ans == -1)
			printf("Case #%d: INSOMNIA", tcase);
		else
			printf("Case #%d: %d", tcase, ans);
		printf("\n");
	}
}
