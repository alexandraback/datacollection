#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

void work()
{
	int n;
	string st;
	cin >> n >> st;
	int s = 0, ans = 0;
	for (int i = 0; i <= n; ++i) {		
		if (i - s > ans)
			ans = i - s;
		s += int(st[i] - '0');
	}
	cout << ans;
}

int main()
{
    freopen("a2.in", "r", stdin);
    freopen("a2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        work();
        printf("\n");
    }
    
    return 0;
}

