#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main(void){
	priority_queue<long long, deque<long long, allocator<long long> >, greater<long long> > q;
	int n;
	scanf("%d", &n);
	while(n--){
		long long t;
		scanf("%lld", &t);
		q.push(t);
	}
	if(q.size() == 1){
		printf("%lld\n", q.top());
		return 0;
	}

	long long sum = 0;
	while(q.size() > 1){
		int t1, t2;
		t1 = q.top();
		q.pop();
		t2 = q.top();
		q.pop();
		sum += t1 + t2;
		q.push(t1 + t2);
	}
	printf("%lld\n", sum);
	return 0;
}
