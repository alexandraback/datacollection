#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;	
	
	scanf("%d", &t);
	
	for(int time = 0; time < t; ++time) {
		
		int n, s, p;
		int div1 = 0, div2 = 0;
		
		scanf("%d%d%d", &n, &s, &p);
		
		for(int i = 0; i < n; ++i) {
			
			int t;
			
			scanf("%d", &t);
			
			if(t >= (p * 3 - 2))
				++div1;
			else if(p > 1 && t >= (p * 3 - 4))
				++div2;
		}
		
		int ans = div1 + min(s, div2);
		
		printf("Case #%d: %d\n", time + 1, ans);
	}
	
	return 0;
}