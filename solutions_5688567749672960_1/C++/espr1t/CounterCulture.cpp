#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>

using namespace std;
FILE* in; FILE* out;

const int MAX = 1048576;

int dist[MAX];

long long revNum(long long num) {
    long long ret = 0;
    while (num) {
        ret = ret * 10 + num % 10;
        num /= 10;
    }
    return ret;
}

void bfs() {
    queue <int> q;
    memset(dist, 63, sizeof(dist));
    q.push(1); dist[1] = 1;
    while (!q.empty()) {
        int num = q.front(); q.pop();
        if (num + 1 < MAX && dist[num] + 1 < dist[num + 1]) {
            dist[num + 1] = dist[num] + 1;
            q.push(num + 1);
        }
        int rev = (int)revNum(num);
        if (rev > 0 && rev < MAX && dist[num] + 1 < dist[rev]) {
            dist[rev] = dist[num] + 1;
            q.push(rev);
        }
    }
}

long long eval(long long n) {
    if (n <= 10)
        return n;

    int numDigits = 0;
    for (long long tmp = n; tmp; tmp /= 10)
        numDigits++;

    long long ans = 10;
    long long cur = 10; int digs = 2;
    
    while (digs < numDigits) {
        int half = digs / 2;
        long long add = 1;
        for (int i = 0; i < half; i++)
            add *= 10;
        ans += add;
        cur += add - 1;
        cur = revNum(cur);

        add = 1;
        for (int i = half; i < digs; i++)
            add *= 10;
        ans += add - 1;
        cur += add - 1;
        digs++;
    }
    
    long long mostSig = n;
    while (mostSig >= 10)
        mostSig /= 10;
    
    long long best = ans + n - cur;
    for (int add = 0; add <= 10000000; add++) {
        if ((cur + add) % 10 != mostSig && (cur + add) % 10 != mostSig - 1)
            continue;

        long long tmp = cur + add;
        long long tans = ans + add;
        tmp = revNum(tmp); tans++;
        if (tmp <= n) {
            tans += n - tmp;
            best = min(best, tans);
        }
    }
    return best;
}


string toString(long long num) {
    if (num == 0)
        return "0";
    string sign = "";
    if (num < 0)
        sign = "-", num = -num;
    
    string ret;
    while (num)
        ret += (char)(num % 10 + '0'), num /= 10;
    reverse(ret.begin(), ret.end());
    return sign + ret;
}

long long scanLong(FILE* fp = stdin) {
    char buff[32];
    fscanf(fp, "%s", buff);
    int start = 0, len = (int)strlen(buff);
    bool sign = true;
    if (buff[0] == '-')
        sign = false, start = 1;
    long long val = 0;
    for (int i = start; i < len; i++)
        val = val * 10 + buff[i] - '0';
    return sign ? val : -val;
}
void solveTest() {
    long long n = scanLong(in);
    fprintf(out, "%s\n", toString(eval(n)).c_str());
//    fprintf(out, "%d\n", dist[n]);
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("CounterCulture.in", "rt");
	out = fopen("CounterCulture.out", "wt");
	
	bfs();
	
	int numTests;
	fscanf(in, "%d", &numTests);
	for (int test = 1; test <= numTests; test++) {
		fprintf(stderr, "Currently executing testcase %d...\n", test);
		fprintf(out, "Case #%d: ", test);
		solveTest();
	}
	
	fprintf(stderr, "Total execution time %.3lf seconds.\n",
        (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
	return 0;
}
