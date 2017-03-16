#include "bits/stdc++.h"
using namespace std;
int t;
int n , j;
int tc = 0;
long long l , r;
const int primes[5] = {2 , 3 , 5 , 7 , 11};
bool check(long long num){
	vector < int > v;
	v.clear();
	for(int base = 2 ; base <= 10 ; ++base){
		int cur[5];
		int val[5];
		for(int j = 0 ; j < 5 ; ++j){
			cur[j] = 1;
			val[j] = 0;
		}
		for(int j = 0 ; j <= 32 ; ++j){
			if(num & (1LL << j)){
				for(int k = 0 ; k < 5 ; ++k){
					val[k] += cur[k];
					val[k] %= primes[k];
				}
			}
			for(int k = 0 ; k < 5 ; ++k){
				cur[k] *= base;
				cur[k] %= primes[k];
			}
		}
		bool ok = 0;
		for(int j = 0 ; j < 5 ; ++j){
			if(val[j] % primes[j] == 0){
				ok = 1;
				v.emplace_back(primes[j]);
				break;
			}
		}
		if(!ok){
			return 0;
		}
	}
	bool ok = 0;
	for(int i = 32 ; i >= 0 ; --i){
		if(num & (1LL << i)){
			ok = 1;
			printf("1");
		}
		else if(ok){
			printf("0");
		}
	}
	for(int x : v){
		printf(" %d" , x);
	}
	printf("\n");
	return 1;
}
int main(){
	cin >> t;
	while(t--){
		printf("Case #%d:\n" , ++tc);
		cin >> n >> j;
		l = (1LL << (n - 1)) + 1LL;
		r = (1LL << n) - 1LL;
		for(long long i = l ; i <= r && j ; i += 2){
			if(check(i)){
				--j;
			}
		}
	}
}