#include <bits/stdc++.h>
using namespace std;
set<int> s;
void digs(long long x) {
	while (x > 0){
	    s.insert(x % 10);
	    x /= 10;
	}
} 
int main(){
	int test;
	scanf("%d", &test);
	for (int w = 1; w <= test; w++) { 
		int i;
		scanf("%d", &i);   
		if(i == 0) {
			printf("Case #%d: INSOMNIA\n", w);
			continue;
		}
		s.clear();
		for (long long j = 1; ; j++) {
			digs(i * j);
			if(int(s.size()) == 10) {
				printf("Case #%d: %lld\n", w, i * j);
				break;
			}
		}
	}
}