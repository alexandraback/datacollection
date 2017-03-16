#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define eps 1e-10
#define inf 0x3f3f3f3f

#define console cout
#define dbg(x) console << #x << " == " << x << endl
#define print(x) console << x << endl

double alpha[202];
int N;
double sum;

void read() {
    scanf("%d", &N);
    sum = 0;
    for(int i = 0; i < N; i++) {
        scanf("%lf", &alpha[i]);
        sum += alpha[i];
    }
}

void process() {
    double T = 2*sum/N;
    double newPercentage = 0.0;
    for(int i = 0; i < N; i++) {
        if (T > alpha[i]) {
            newPercentage += (T-alpha[i])/sum;
        }
    }
    for(int i = 0; i < N; i++) {
        if (T < alpha[i]) {
            printf(" 0.0");
        }else {
            printf(" %.9lf", (T-alpha[i])/sum * 100 / newPercentage);
        }
    }
    printf("\n");
}

// BEGIN CUT HERE
int main() {
//freopen("out.txt","w",stdout);
//freopen("out.txt","w",stderr);
	int casos;
	scanf("%d", &casos);
	for (int i = 1; i <= casos; i++) {
	    read();
	    printf("Case #%d:", i);
	    process();
	}
	return 0;
}
// END CUT HERE 
