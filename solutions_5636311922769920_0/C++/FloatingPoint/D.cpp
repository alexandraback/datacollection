#include <bits/stdc++.h>

using namespace std;

struct kcs {
	int K, C, S;
};

kcs make_kcs(int k, int c, int s) {
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
	for (int i = 0; i < input.K; ++i) {
		v.push_back(i+1);
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
		int k, c, s;
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