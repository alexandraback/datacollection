#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

long long solve(long long a, long long b, long long k, int h){
	if(a > b){
		long long tmp=a;
		a=b;
		b=tmp;
	}
	if((1LL<<h) > a)
		return solve(a, b, k, h-1);
	long long ans=0;
	long long p=(1LL<<h);
	if(k >= p){
		ans += p*p;
		return ans+solve(a-p, b-p, k-p, h-1);
	}
	else{
		return solve(a-p, b-p, k, h-1);
	}
}

map<pair<pair<int, int>, int>, long long> memo;

long long dp(long long a, long long b, long long k){
	if(!a || !b){
		return (a+b+1);
	}
	if(memo.find(make_pair(make_pair(a, b), k)) != memo.end())
		return memo[make_pair(make_pair(a, b), k)];
	long long ans=0;
	int A=a&1, B=b&1, K=k&1;
	ans += dp(a/2, b/2, k/2);
	if(k)ans += dp((a-1)/2, (b-1)/2, (k-1)/2);
	ans += dp((a-1)/2, b/2, k/2);
	ans += dp(a/2, (b-1)/2, k/2);
	memo[make_pair(make_pair(a, b), k)] = ans;
	return ans;
}

int main(){
	FILE *fin = fopen("input.in", "r");
	FILE *fout = fopen("output.out", "w");
	int T;
	fscanf(fin, "%d", &T);
	for(int t=1; t <= T; ++t){
		long long A, B, K;
		fscanf(fin, "%lld%lld%lld", &A, &B, &K);
		--A;--B;--K;
		memo.clear();
		fprintf(fout, "Case #%d: %lld\n", t, dp(A, B, K));
		/*for(auto it = memo.begin(); it != memo.end(); ++it){
			printf("(%d, %d, %d)=%lld\n", it->first.first.first, it->first.first.second, it->first.second, it->second);
		}*/
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
