#include <bits/stdc++.h>
using namespace std;

FILE *in = fopen("f.in", "r");
FILE *out = fopen("f.out", "w");

int D, a[1111];
priority_queue<int> heap;

int doit(int maxV, int maxIter){
	while(!heap.empty()){
		heap.pop();
	}
	for(int q = 0; q < D; q++){
		heap.push(a[q]);
	}
	int result = heap.top();
	for(int q = 1; q <= maxIter && heap.top() > maxV; q++){
		int first = heap.top();
		heap.pop();
		heap.push(maxV);
		heap.push(first - maxV);
		result = min(result, q + heap.top());
	}
	return result;
}

int solve2(){
	fscanf(in, "%d", &D);
	int maxV = 0;
	for(int q = 0; q < D; q++){
		fscanf(in, "%d", &a[q]);
		maxV = max(maxV, a[q]);
	}
	int result = maxV;
	for(int q = 1; q <= maxV; q++){
		result = min(result, doit(q, maxV));
	}
	return result;
}

int main(){
	int ntest;
	fscanf(in, "%d", &ntest);
	for(int test = 1; test <= ntest; test++){
		int result = solve2();
		fprintf(out, "Case #%d: %d\n", test, result);
		printf("Case #%d: %d\n", test, result);
	}
	return 0;
}