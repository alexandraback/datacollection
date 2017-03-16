#include <bits/stdc++.h>

using namespace std;

struct kcs {
	long long K, C, S;
};

kcs make_kcs(long long k, long long c, long long s) {
	kcs res;
	res.K = k;
	res.C = c;
	res.S = s;
	return res;
}

vector<kcs> inputs;
int T;
vector<vector<long long> > outputs;

vector<long long> res(kcs input) {
	vector<long long> v;
	long long c = input.C, k = input.K, s = input.S;
	if (c*s < k) return v; // IMPOSSIBLE
	for (long long i = 0; i < (k / c); ++i) { // from i*c to i*c + c-1
		long long current = 0;
		for (long long j = i*c; j < (i+1)*c; ++j) {
			current *= k;
			current += j;
		}
		v.push_back(current + 1);
	}
	if (k % c) {
		long long current = 0;
		for (long long j = (k/c)*c; j < k; ++j) {
			current *= k;
			current += j;
		}
		v.push_back(current + 1);
	}
	return v;
}

void print(int i) {
	cout << "Case #" << (i+1) << ": ";
	if (outputs[i].size() > 0) {
		for (int j = 0; j < outputs[i].size(); ++j) {
			cout << outputs[i][j];
			if (j != outputs[i].size() - 1) cout << " ";
		}
	} 
	else cout << "IMPOSSIBLE";
}

int main() {
	freopen("D.txt", "r", stdin);
	freopen("D.out.txt", "w", stdout);
	cin >> T;
	for (int i = 0; i < T; ++i) {
		long long k, c, s;
		cin >> k >> c >> s;
		inputs.push_back(make_kcs(k, c, s));
	}
	outputs.resize(T);
	for (int i = 0; i < T; ++i) {
		outputs[i] = res(inputs[i]);
	}
	
	for (int i = 0; i < T - 1; ++i) {
		print(i);
		cout << endl;
	}
	
	print(T-1);
}