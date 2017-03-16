#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

const long long max_prime = 1000;

long long
change_base(unsigned int v, int nw_base)
{
	long long res = 0;
	long long pow = 1;
	while (v) {
		res += (v % 2) * pow;
		pow *= nw_base;
		v /= 2;
	}
	return res;
}

pair<bool, vector<long long> >
check_jamcoin(unsigned int v, vector<long long> &primes)
{
	vector<long long> out(11);
	for (int i = 2; i <= 10; ++i) {
		long long v2 = change_base(v, i);
		out[i] = 0;
		for (int j = 0; j < primes.size(); ++j) {
			if (v2 % primes[j] == 0 && v2 != primes[j]) {
				out[i] = primes[j];
				break;
			}
		}
		if (out[i] == 0) {
			return make_pair(false, vector<long long>());
		}
	}
	return make_pair(true, out);
}

string
get_string_representation(unsigned int v)
{
	string s = "", s2 = "0";
	while (v != 0) {
		s2[0] = '0' + v % 2;
		s = s2 + s;
		v /= 2;
	}
	return s;
}

vector<long long>
generate_primes(long long max_prime)
{
	vector<long long> res;
	for (long long i = 2; i <= max_prime; ++i) {
		bool is_prime = true;
		for (int j = 0; j < res.size(); ++j) {
			if (i % res[j] == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			res.push_back(i);
		}
	}
	return res;
}

unsigned int
generate_random_number(int n)
{
	unsigned int res = (rand() << 16 + rand());
	res %= (1LL << (long long)(n));
	res |= 1;
	res |= 1LL << (long long)(n - 1);
	return res;
}

void
solve(int n, int jamcoins_num)
{
	vector<long long> primes = generate_primes(max_prime);

	set<unsigned int> was;
	vector<pair<unsigned int, vector<long long> > > res;
	
	while (res.size() < jamcoins_num) {
		unsigned int cur = generate_random_number(n);
		pair<bool, vector<long long> > lres;
		if (was.find(cur) == was.end() && (lres = check_jamcoin(cur, primes)).first) {
			was.insert(cur);
			res.push_back(make_pair(cur, lres.second));
			cout << get_string_representation(cur);
			for (int i = 2; i <= 10; ++i) {
				cout << " " << lres.second[i];
			}
			cout << endl;
		}
	}
}

int
main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ":\n";
        int n, j;
        cin >> n >> j;
        solve(n, j);
    }
}
