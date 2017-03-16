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
#include <queue>
using namespace std;

const int maxn = 1000 + 5;

int a[maxn];

void work()
{
	int n;	
	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> a[i];
	int ans = 1000;
	for (int L = 1; L <= 1000; ++L) {
		int s = 0;
		for (int i = 0; i < n; ++i)
			s += (a[i] + L - 1) / L - 1;
		if (s + L < ans)
			ans = s + L;
	}
	cout << ans;
}

int main()
{
    freopen("b2.in", "r", stdin);
    freopen("b2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        work();
        printf("\n");
    }
    
    return 0;
}

