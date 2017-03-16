#include <bits/stdc++.h>

using namespace std;

vector<vector<char> > inputs;
int T;
vector<int> outputs;

int res(vector<char> input) {
	int N = input.size();
	int c = 0;
	for (int i = 0; i < N - 1; ++i) {
		c += input[i] != input[i+1] ? 1 : 0;
	}
	return c;
}

void print(int i) {
	cout << "Case #" << (i+1) << ": " << outputs[i];
}

int main() {
	freopen("B.txt", "r", stdin);
	freopen("B.out.txt", "w", stdout);
	cin >> T;
	for (int i = 0; i < T; ++i) {
		string y;
		cin >> y;
		vector<char> v;
		for (int j = 0; j < y.size(); ++j) v.push_back(y[j]);
		v.push_back('+');
		inputs.push_back(v);
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