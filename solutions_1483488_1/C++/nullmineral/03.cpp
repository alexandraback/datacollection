#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int numlen(int num)
{
	int ret = 0, mul = 1;
	
	while(mul <= num) {
		mul *= 10;
		ret += 1;
	}
	
	return ret;
}

int pow(int x, int y)
{
	int ret = 1;
	
	for(int i = 0; i < y; ++i)
		ret *= x;
		
	return ret;
}

int main()
{
	int t;
	
	scanf("%d", &t);
	
	for(int time = 0; time < t; ++time) {
		
		int a, b;
		long long ans = 0;
		
		scanf("%d%d", &a, &b);
		
		for(int n = a; n < b; ++n) {
			
			int len = numlen(n);
			int mul1 = 1;
			set<int> count;
			
			for(int cut = 0; cut <= len; ++cut, mul1 *= 10) {
				
				int hi = n % mul1;
				int lo = n / mul1;
				
				if(mul1 > 1 && (hi == (hi % (mul1 / 10))))
					continue;
				
				int mul2 = pow(10, numlen(lo));
				
				while(hi * mul2 + lo <= b) {
					
					int m = hi * mul2 + lo;
					
					if(n < m)
						count.insert(m);
						
					mul2 *= 10;
					
					if(hi == 0)
						break;
				}
				
			}
			
			ans = ans + count.size();
			
			//for(set<int>::iterator it = count.begin(); it != count.end(); ++it)
			//	printf("[Debug] %d %d\n", n, *it);
		}
		
		printf("Case #%d: %lld\n", time + 1, ans);
	}
	
	return 0;
}