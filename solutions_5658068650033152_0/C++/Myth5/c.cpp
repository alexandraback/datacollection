#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int Cover(int x) { return x * (x + 1) / 2; }

int work()
{
	int W, H, K;
	cin >> W >> H >> K;
	if (W > H)
		swap(W, H);
	if (W <= 2)
		return K;
	int ans = K;
	for (int w = 1; w <= W; ++w)
		for (int h = 1; h <= H; ++h) 
			for (int a = 0; a <= min(w, h); ++a)
			for (int b = 0; b <= min(w - a, h); ++b)
			for (int c = 0; c <= min(w, h - a); ++c)
			for (int d = 0; d <= min(w - c, h - b); ++d) {
				int cover = w * h;
				int use = 2 * (w + h) - 4;
				cover -= Cover(a) + Cover(b) + Cover(c) + Cover(d);
				use -= a + b + c + d;
				if (cover >= K && use <= ans)
					ans = use;
			}
	return ans;
}

int main()
{
    freopen("c1.in", "r", stdin);
    freopen("c1.out", "w", stdout);
    
    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);				        
        printf("%d\n", work());
    }
    
    return 0;
}
