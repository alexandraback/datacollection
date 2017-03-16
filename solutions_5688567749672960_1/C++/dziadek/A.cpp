#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define f first
#define s second

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

const int MAX = 1000005;

long long dp[MAX];

vector<long long> pivots;

long long make_number(VI v){
	long long value = 0;

	REP(i,v.size()){
		value *= 10;
		value += v[i];
	}

	return value;
}

void generate(){
	pivots.PB(19);
	pivots.PB(199);

	int zeroes = 1;
	int nines = 2;

	while(zeroes+nines <= 14){
		VI t;
		t.PB(1);
		REP(i,zeroes) t.PB(0);
		REP(i,nines) t.PB(9);
		pivots.PB(make_number(t));
		t.PB(9);
		pivots.PB(make_number(t));
		++nines;
		++zeroes;
	}
}

long long rev(long long x){
	VI v;

	while(x){
		v.PB(x % 10);
		x /= 10;
	}

	return make_number(v);
}

long long bruteforce(long long N){
	dp[N] = 1;

	FORD(n,N-1,1){
		dp[n] = dp[n+1] + 1;
		if(rev(n) > n && rev(n) <= N) dp[n] = min(dp[n], dp[rev(n)] + 1);
	}

	return dp[1];
}

const int MAGIC = 100000;

void testcase(long long N){
	long long n = 0;
	long long cost = 0;

	if(N <= 10000){
		cout << bruteforce(N) << endl;
		return;
	}

	REP(i,pivots.size()){
		if(rev(pivots[i]) <= N){
			cost += (pivots[i] - n) + 1;
			n = rev(pivots[i]);
		}
	}
	
	long long result = N - n;

	for(long long i = n; i <= N; ++i){
		if(i - n > MAGIC) break;
		if(rev(i) <= N)
			result = min(result, i - n + (N - rev(i)) + 1);
	}

	for(long long i = N; i >= n; --i){
		if(N - i > MAGIC) break;
		if(rev(i) >= n){
			result = min(result, rev(i) - n + (N - i) + 1);
		}
	}

	cout << (cost + result) << endl;
}

int main(){
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;

	generate();

	FOR(i,1,t){
		long long N;
		cin >> N;
		cout << "Case #" << i << ": ";
		testcase(N);
	}

	return 0;
}
