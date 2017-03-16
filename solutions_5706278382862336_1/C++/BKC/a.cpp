#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
using namespace std;

bool isValidCombo(unsigned long long q){
	while(q > 2){
		if(q & 1) return false;
		else q = q >> 1;
	}
	return true;
}

unsigned long long gcd(unsigned long long a, unsigned long long b){
	if(a > b) return gcd(b, a);
	if(!a) return b;
	return gcd(b % a, a);
}

int main(){
	int testcases;
	scanf("%d\n", &testcases);
	for (int testcase = 1; testcase <= testcases; ++testcase){
		unsigned long long p, q, tmp;
		scanf("%lld/%lld", &p, &q);
		tmp = gcd(p, q);
		p /= tmp;
		q /= tmp;
		if(!isValidCombo(q))
			printf("Case #%d: impossible\n", testcase);
		else{
			while(!(p & 1)){
				p = p >> 1;
				q = q >> 1;
			}
			int count = 0;
			while(p < q){
				q = q >> 1;
				count++;
			}
			printf("Case #%d: %d\n", testcase, count);
		}
	}
	return 0;
}
