#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
vector<int> primes;
void init(int mx){
	bitset<1000000> isnp;
	for(int i = 2; i < mx; ++i) if(!isnp[i]){
		primes.push_back(i);
		for(int j = 2*i; j < mx; j += i) isnp[j] = 1;
	}
}
vector<int> test(bitset<16> b){
	vector<int> ret;
	for(int i = 2; i < 11; ++i){
		long long n = 0;
		for(int j = 16; j-->0;) n = n*i+b[j];
		for(int j = 0; primes[j]*primes[j] < n && j < primes.size(); ++j) if(n%primes[j] == 0){
			ret.push_back(primes[j]);
			break;
		}
	}
	return ret.size() == 9 ? ret : vector<int>();
}
int main(){
	int n,j;
	cin >> n >> n >> j;
	cout << "Case #1:\n";
	init(1e6);
	for(int i = 0; i < (1<<15) && j; ++i){
		bitset<16> b(32769|(i<<1));
		auto v = test(b);
		if(!v.size()) continue;
		cout << b;
		for(auto i:v) cout << " " << i;
		cout << endl;
		--j;
	}
}