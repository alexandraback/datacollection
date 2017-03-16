#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

const double eps = 1e-9;
const int inf = 1e9 + 23;

const int MAX_PRIME = 50;

vector <int> primes;
vector < vector < vector <int> > > table;

int N;

vector < pair < vector <int>, vector <int> > > ans;

void generate_first_primes (int k) {
	int n = 2;
	while (k > (int) primes.size()) {
		bool prime = true;
		for (int i = 0; i < (int) primes.size(); i++) {
			if (n % primes[i] == 0) {
				prime = false;
				break;
			}
		}
		if (prime)
			primes.push_back(n);
		n++;
	}
	return;
}

void generate_prime_table (int k, int J) {
//	table.push_back(vector < vector <int> >);
	for (int i = 0; i < k; i++) {
		int p = primes[i];
		vector <vector <int> > prelast;
		for (int d = 2; d < 11; d++) {
			int a = 1;
			vector <int> last;
			for (int j = 0; j < J; j++) {
//				table[i].push_back(vector < vector <int> >);
//				table[i][d - 2][j] = a;
				last.push_back(a);
//				cout << "a = " << a << endl;
//				cout << "d = " << d << endl;
//				cout << "p = " << p << endl;
				a *= d;
				a %= p;
			}
			prelast.push_back(last);
		}
		table.push_back(prelast);
	}
	return;
}

bool check_prime (vector <int> &num, vector <int> &p, int J) {
	bool flag = true;
//	cerr << p.size();
	int len = (int) num.size();
	vector <int> div;
	for (int d = 2; d <= 10; d++) {
		bool is_prime = true;
		for (int p_num = 0; p_num < p.size(); p_num++) {
			int sum = 0;
			for (int j = 0; j < J; j++) {
				if (num[len - 1 - j] == 1) {
//					cout << "table[" << p[p_num] << "][" << d << "][" << j;
//					cout << "] = " << table[p_num][d - 2][j] << endl;
					sum += table[p_num][d - 2][j];
					sum %= p[p_num];
				}
			}
//			cout << "Num = ";
//			for (int i = 0; i < num.size(); i++) {
//				cout << num[i];
//			}
//			cout << endl;
//			cout << "prime = " << p[p_num] << endl;
//			cout << "digit = " << d << endl;
//			cout << "sum = " << sum;
//			cout << endl;
			if (sum == 0) {
				is_prime = false;
				div.push_back(p[p_num]);
				break;
			}
		}
		if (is_prime)
			return false;
	}
	ans.push_back(make_pair(num, div));
	return true;
}

bool gen_next (vector <int> &num) {
	int len = num.size();
	int k = 2;
	while (k < len && num[len - k] == 1) {
		num[len - k] = 0;
		k++;
	}
	if (k == len)
		return false;
	else {
		num[len - k] = 1;
		return true;
	}
}

int main (void){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	int t;
	int J;
	
	cin >> t;
	for (int it = 1; it <= t; it++) {
		cin >> N;
		cin >> J;
		
		cout << "Case #" << it << ": " << endl;
		generate_first_primes(MAX_PRIME);
		generate_prime_table(MAX_PRIME, N);
		vector <int> jamcoin;
		jamcoin.push_back(1);
		for (int i = 0; i < N - 2; i++)
			jamcoin.push_back(0);
		jamcoin.push_back(1);
//		cerr << "Max Prime = " << primes[primes.size() - 1] << endl;
		
		int JJ = J;
		while (JJ > 0) {
//			for (int i = 0; i < jamcoin.size(); i++) {
//				cerr << jamcoin[i];
//			}
//			cerr << endl;
			if (check_prime(jamcoin, primes, N)) {
				JJ--;
			}
			if (!gen_next(jamcoin)) {
				cout << "((((" << endl;
				return 0;
			}
		}
		for (int i = 0; i < J; i++) {
			for (int j = 0; j < N; j++) {
				cout << ans[i].first[j];
			}
			cout << " ";
			for (int d = 2; d <= 10; d++) {
				cout << ans[i].second[d - 2] << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}