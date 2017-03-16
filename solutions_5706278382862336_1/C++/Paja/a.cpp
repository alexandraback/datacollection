#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

const int MAXN = 1010;

long long gcd(long long a, long long b){
	return (b == 0 ? a : gcd(b, a%b));
	}

void lower(long long & n, long long & m){
	long long g = gcd(n, m);
	n/=g;
	m/=g;
	}

void solve(int test){
	long long n, m;
	scanf("%lld/%lld", &n, &m);
	
	lower(n, m);
	
	long long tmp = m;
	for(int j = 0; j < 40 && tmp%2 == 0; j++)
		tmp/=2;
		
	if(tmp > 1){
		printf("Case #%d: impossible\n", test);
		return;
		}
	
	int i;
	for(i = 0; i < 40 && n < m; i++)
		n*=2, lower(n, m);
	//~ cout << i << endl;

	printf("Case #%d: %d\n", test, i);
	//~ printf("Case #%d: \n", test);
	}

int main(){	
	int testcases;
	scanf("%d", &testcases);
	
	for(int test = 0; test < testcases; test++)
		solve(test+1);
	
	return 0;
}
