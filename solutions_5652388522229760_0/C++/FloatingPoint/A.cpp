#include <bits/stdc++.h>

using namespace std;

const int FULL_BM = (1 << 10) - 1;
vector<int> inputs;
int T;
vector<long long> outputs;

int getBM(long long n) {
	int bm = 0;
	while (n != 0) {
		int front = n % 10;
		n /= 10;
		bm |= (1 << front);
	}
	return bm;
}

long long res(long long input) {
	if (input == 0) return -1;
	int bitmask;
	long fac = 0;
	while (bitmask != FULL_BM) {
		++fac;
		bitmask |= getBM(input*fac);
	}
	return input*fac;
}

void print(int i) {
	cout << "Case #" << (i+1) << ": ";
	if (outputs[i] >= 0) cout << outputs[i];
	else cout << "INSOMNIA";
}

int main() {
	freopen("A.txt", "r", stdin);
	freopen("A.out.txt", "w", stdout);
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int y;
		cin >> y;
		inputs.push_back(y);
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