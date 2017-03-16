#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int main() {
	int _; cin >> _; 
	for (int __ = 1; __ <= _; __ ++) {
        printf ("Case #%d: ", __);
        int R, C, L;
        cin >> R >> C >> L;
        int n = 0;
        int r = C / L;
        n += (R - 1) * r;
        n += r + L - (C % L == 0);
        printf ("%d\n", n);
	}
	return 0; 
}
