#include <bits/stdc++.h>
using namespace std;

int glob[16];
int globmax = 0;
bool check(int arr[], int l) {
	if (l > 2) {
	
	for (int i = 1; i < l-1; i++) {
		if (!(glob[arr[i]] == arr[i-1] || glob[arr[i]] == arr[i+1])) {
			return false;
		}
	}
	}
	if (!(glob[arr[0]] == arr[l-1] || glob[arr[0]] == arr[1])) {
			return false;
	}
	if (!(glob[arr[l-1]] == arr[0] || glob[arr[l-1]] == arr[l-2])) {
		return false;
	}
/*	cout << "DEBUGX";
	for (int i = 0; i < l; i++) {
		cout << arr[i];
	}
	cout << endl;*/
	return true;
}

void generatepattern(bitset<15> bs) {
	int arr[16];
	int counter = 0;
	for (int i = 0; i < 15; i++) {
		if (bs[i]) {
			arr[counter] = i+1;
			counter++;
		}
	}
	do {
/*		cout << "DEBUG";
		for (int i = 0; i < counter; i++) {
			cout << arr[i];
		}
		cout << "C" << counter <<  endl;*/
		if (check(arr, counter)) {
			globmax = max(globmax, counter);
		}
	}
	while (next_permutation(arr, arr+counter));
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen ("C-small-out.txt","w",stdout);
	int tc;
	cin >> tc;
	for (int z = 1; z <= tc; z++) {
		int c;
		cin >> c;
		globmax = 0;
		for (int i = 1; i <= c; i++) {
			int temp;
			cin >> temp;
			glob[i] = temp;
		}
		int total = 1;
		for (int i = 0 ; i < c; i++) {
			total *= 2;
		}		
		for (int i = 1; i <= total; i++) {
			bitset<15> bs= i;
			generatepattern(bs);
		}
		printf("Case #%d: %d\n", z, globmax);

	}

	
	return 0;
}
