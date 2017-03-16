#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	
	scanf("%d", &t);
	
	for(int time = 1; time <= t; ++time) {
		
		int n;
		vector<int> a, b;
		vector<int> c;
		
		int start = -1;
		int ans = 0;
		
		scanf("%d", &n);
		a.resize(n);
		b.resize(n);
		c.resize(2002);
		for(int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
			c[b[i]] += 1;
			if(a[i] == 0 && (start == -1 || b[start] < b[i]))
				start = i;
		}
		for(int i = 1; i < c.size(); ++i)
			c[i] += c[i - 1];
		
		if(c[0] == 0 && start == -1) {
			printf("Case #%d: Too Bad\n", time);
			continue;
		}
		if(c[0] > 0)
			start = -1;
		
		int cur = 0;
		int finish = 0;
		
		while(finish < n) {
			
			if(c[cur] - finish > 0) {
				
				int get = c[cur] - finish;
				
				if(start != -1 && cur >= b[start])
					cur -= 1, start = -1;
				cur += get * 2;
				ans += get;
				finish += get;
				//printf("[%d]get\n", cur);
				
			} else {
				
				cur += 1;
				ans += 1;
				//printf("[%d]use\n", cur);
			}
		}
		
		printf("Case #%d: %d\n", time, ans);
	}
	
	return 0;
}