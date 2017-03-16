#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

int T, A, B, K;

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);
	
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
	    scanf("%d %d %d", &A, &B, &K);
        int ans = 0;
        for(int a = 0; a < A; a++)
            for(int b = 0; b < B; b++)
                if((a & b) < K)
                    ans++;
        printf("Case #%d: %d\n", t, ans);
	}
	
	return 0;
}
