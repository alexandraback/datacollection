#include <list>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <ext/hash_map>
#include <stdint.h>
#include <ctime>
#include <queue>
#include <sstream>
#include <sys/time.h>
#include <fstream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef long long LL;
typedef unsigned char BYTE;

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORU(i, s, e) for (int i = (s); i <= (e); ++i)
#define FORD(i, s, e) for (int i = (s); i >= (e); --i)
#define ALL(x) x.begin(),x.end()
#define FOREACH(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define SIZE(x) ((int)x.size())
#define MP make_pair
#define PB push_back
#define BIT(x, b) (((x) >> (b)) & 1)
#define SWAP(a, b, t) do {t = a; a = b; b = t;} while (0);
#define INF 1000000000
#define EPS 1e-9
#define TIME_LEFT_UNTIL(end) ((curTime=getTime()-startTime) < (end))
#define TIME_LEFT() TIME_LEFT_UNTIL(MAX_TIME)
#define INIT_TIME() startTime = getTime()

inline double getTime () {
   timeval tv;
   gettimeofday(&tv, 0);
   return tv.tv_sec + tv.tv_usec * 1e-6;
}

int main () {
	double time = getTime();

	int T;
	scanf("%d", &T);
	FOR(itr, T) {
		int N;
		scanf("%d", &N);
		int s1, s2;
		int t1, t2;
		if (N == 1) {
			int d, h, m;
			scanf("%d%d%d", &d, &h, &m);
			if (h == 1) {
				printf("Case #%d: 0\n", itr+1);
				continue;
			}
			else if (h == 2) {
				s1 = d;
				s2 = d;
				t1 = m+1;
				t2 = m;
			}
			else {
				cerr << "FAIL" << endl;
			}
		}
		else if (N == 2) {
			int d, h, m;
			scanf("%d%d%d", &d, &h, &m);
			s1 = d;
			t1 = m;
			if (h != 1)
				cerr << "FAIL" << endl;
			scanf("%d%d%d", &d, &h, &m);
			if (h != 1)
				cerr << "FAIL" << endl;
			s2 = d;
			t2 = m;
			if (s2 < s1 || (s2 == s1 && t1 < t2)) {
				int s3, t3;
				SWAP(s1, s2, s3);
				SWAP(t1, t2, t3);
			}
		}
		else {
			cerr << "FAIL" << endl;
		}

		if (s1 > s2 || (s1 == s2 && t1 < t2))
			cerr << "FAIL" << endl;
//		cerr << s1 << " " << s2 << " " << t1 << " " << t2 << endl;

		if (t1 > t2) { //further back one is also slower
			if (t1*(360LL-s1) < t2*(720LL-s2))
				printf("Case #%d: 0\n", itr+1);
			else
				printf("Case #%d: 1\n", itr+1);
		}
		else { //behind one is faster
			// if catch up before 360, reduce to previous case, o/w 0
			if (t1*(360LL-s1) >= t2*(360LL-s2))
				printf("Case #%d: 0\n", itr+1);
			else {
				if (t2*(360LL-s2) < t1*(720LL-s1))
					printf("Case #%d: 0\n", itr+1);
				else
					printf("Case #%d: 1\n", itr+1);
			}
		}
	}
	cerr << getTime() - time << endl;
}
