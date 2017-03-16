#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

typedef long long     LL;

#define For(i,a,b)    for(int i=(a);i<(b);++i)
#define rep(i,n)      For(i,0,(n))

int prime[15000000] = {};
int num_prime;

LL precalc[15][50] = {};

void init_prime(int N)
{
	num_prime = 0;
	prime[num_prime++] = 2;
	prime[num_prime++] = 3;

	for(int i = 5 ; i < int(2e8 + 1000) ; i += 2) {
		bool flag = false;
		for(int j = 0 ; prime[j] * prime[j] <= i ; ++j) {
			if(i % prime[j] == 0) {
				flag = true;
				break;
			}
		}
		if(!flag)
			prime[num_prime++] = i;
	}
}

void init_calc()
{
	For(i, 2, 13) {
		LL calc = 1;
		rep(j, 40) {
			precalc[i][j] = calc;
			calc *= i;
		}
	}
}

string to_bin(LL i)
{
	string result;
	do {
		result += '0' + (i & 0x01);
		i >>= 1;
	} while(i);

	reverse(result.begin(), result.end());
	return result;
}

LL create_cand(int N)
{
	LL cand = (1 << (N - 1)) | 0x01;

	rep(i, N)
		cand |= (LL(1) << ((rand() % (N - 2)) + 1));
	return cand;
}

map<LL, vector<LL>> solve(int N, int J)
{
	map<LL, vector<LL>> result;
	set<LL> checked;

	while(result.size() < J) {
		LL cand = create_cand(N);
		if(checked.find(cand) != checked.end())
			continue;

		checked.insert(cand);

		vector<LL> divisor;
		For(i, 2, 11) {
			LL calc = 0;
			rep(j, N) {
				if(cand & (LL(1) << j))
					calc += precalc[i][j];
			}

			bool flag = false;
			for(int j = 0 ; LL(prime[j]) * prime[j] <= calc ; ++j) {
				if(calc % prime[j] == 0) {
					flag = true;
					divisor.push_back(prime[j]);
					break;
				}
			}
			if(!flag)
				break;
		}
		if(divisor.size() == 9)
			result[cand] = divisor;
	}
	return result;
}

int main()
{
	int T;
	int N, J;
	map<LL, vector<LL>> result;

	cin >> T;			// 1
	cin >> N >> J;		// (16, 50) or (32, 500)

	init_prime(N);
	init_calc();

	result = solve(N, J);
	cout << "Case #1:" << endl;
	for(const auto &p : result) {
		cout << to_bin(p.first);
		for(auto d : p.second)
			cout << " " << d;
		cout << endl;
	}
}
