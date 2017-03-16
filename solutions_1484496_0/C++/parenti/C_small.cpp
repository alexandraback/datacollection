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

int a[22];
int N;
vector<pair<int,int> >sums;

void read() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)scanf("%d", &a[i]);
}
void process() {
    sums.clear();
    for (int i = 1; i < (1<<N); i++) {
        int val = 0;
        for (int j = 0; j < N; j++) if((i>>j)&1){
            val += a[j];
        }
        sums.push_back(make_pair(val, i));
    }
    sort(sums.begin(), sums.end());
    for (int i = 0; i < ((int)sums.size())-1; i++) {
        if (sums[i].first == sums[i+1].first) {
            int first = 1;
            for(int j = 0; j < N; j++) {
                if ((sums[i].second>>j)&1){
                    if(first)first = 0;
                    else printf(" ");
                    printf("%d", a[j]);
                }
            }
            printf("\n");
            first = 1;
            for(int j = 0; j < N; j++) {
                if ((sums[i+1].second>>j)&1){
                    if(first)first = 0;
                    else printf(" ");
                    printf("%d", a[j]);
                }
            }
            printf("\n");
            return;
        }
    }
    printf("Impossible\n");
}
// BEGIN CUT HERE
int main() {
//freopen("out.txt","w",stdout);
//freopen("out.txt","w",stderr);
	int casos;
	scanf("%d", &casos);
	for (int i = 1; i <= casos; i++) {
	    fprintf(stderr, "case %d\n", i);
	    read();
	    printf("Case #%d:\n", i);
	    process();
	}
	return 0;
}
// END CUT HERE 
