#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <set>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <queue>

#define ST first
#define ND second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int ID     = 0;
const int I      = 1;
const int J      = 2;
const int K      = 3;
const int NOT_ID = 4;
const int NOT_I  = 5;
const int NOT_J  = 6;
const int NOT_K  = 7;

const int mult[8][8] = 
{
	{ ID, I, J, K, NOT_ID, NOT_I, NOT_J, NOT_K },
	{ I, NOT_ID, K, NOT_J, NOT_I, ID, NOT_K, J },
	{ J, NOT_K, NOT_ID, I, NOT_J, K, ID, NOT_I },
	{ K, J, NOT_I, NOT_ID, NOT_K, NOT_J, I, ID },
	{ NOT_ID, NOT_I, NOT_J, NOT_K, ID, I, J, K },
	{ NOT_I, ID, NOT_K, J, I, NOT_ID, K, NOT_J },
	{ NOT_J, K, ID, NOT_I, J, NOT_K, NOT_ID, I },
	{ NOT_K, NOT_J, I, ID, K, K, NOT_I, NOT_ID }
};

const int maxl = 10000 + 100;

int range(int *s, int l, int r) {
	if (l == 0) return s[r];
	int a = s[r];
	int b = s[l - 1];
	for (int i = ID; i <= NOT_K; i++) {
		if (mult[b][i] == a) return i; 
	}

	return -1; 
}

int main()
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int l, x;
		string ss, s;
		int ll[maxl]; 

		cin >> l >> x;
		cin >> ss;

		s = "";
		for (int j = 0; j < x; j++) {
			s += ss;
		}

		int sum = ID;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'i') ll[j] = mult[sum][I];
			if (s[j] == 'j') ll[j] = mult[sum][J];
			if (s[j] == 'k') ll[j] = mult[sum][K];
			sum = ll[j];
		}

		if (sum != NOT_ID) {
			cout << "Case #" << i + 1 << ": NO" << endl;
			continue;
		}

		bool success = false;
		for (int j = 0; !success && (j < s.length() - 2); j++) {
			if (range(ll, 0, j) != I) continue;

			for (int k = j + 1; k < s.length() - 1; k++) {
				if (range(ll, j + 1, k) == J && range(ll, k + 1, s.length() - 1) == K) {
					cout << "Case #" << i + 1 << ": YES" << endl;
					success = true;
					break;
				}
			}
		}

		if (!success) {
			cout << "Case #" << i + 1 << ": NO" << endl;
		}
	}

	return 0;
}

