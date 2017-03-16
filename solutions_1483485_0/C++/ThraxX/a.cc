#include <vector>

#include <string>
#include <cstdio>

#include <algorithm>
#include <utility>
#include <cstring>

#include <map>
#include <set>

#include <cassert>

#include <numeric>
#include <bitset>

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <cmath>
#include <complex>
#include <cstdlib>

#include <list>
#include <deque>
#include <queue>
#include <stack>

#include <functional>
#include <cctype>
#include <ctime>

using namespace std;
typedef long long ll;

#define fill(f, a) memset(f, a, sizeof(f))
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define for_each(s,container) for (typeof((container).begin()) s = (container).begin(); s != (container).end(); s++)

char ln[100001];

char mp[30] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main() {
	int t, tCtr;
	scanf("%d\n", &t);
    mp['y'] = 'a';
    mp['e'] = 'o';
    mp['q'] = 'z';
	for (tCtr = 0; tCtr < t; ++tCtr) {
        cin.getline(ln, 100001);	
        int n = strlen(ln);
		printf("Case #%d: ", tCtr + 1);
        for (int i = 0; i < n; ++i) {
            if (ln[i] != ' ')
                printf("%c", mp[ln[i] - 'a']);
            else
                printf(" ");
        }
        puts("");
	}
	return 0;
}

