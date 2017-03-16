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
	int D;
	long long C, V;
	cin >> C >> D >> V;
	long long T = 0;
	int ans = 0;
	for (int i = 1; i <= D; ++i) {
		long long x;
		cin >> x;		
		while (x > T + 1) {
			T = C * (T + 1) + T;
			++ans;
		}
		T = C * x + T;
	}
	while (V > T) {
		T = C * (T + 1) + T;
		++ans;
	}	
	cout << ans;		
}

int main()
{
    freopen("c2.in", "r", stdin);
    freopen("c2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);
        work();
        printf("\n");
    }
    
    return 0;
}

