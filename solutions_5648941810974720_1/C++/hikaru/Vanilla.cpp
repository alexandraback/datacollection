#include <iostream>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <bitset>
#include <assert.h>
using namespace std;

int A[26] = {};
int result[10];

void test(const string& s, int num)
{
	size_t len = s.length();

	int B[26] = {};
	for (char c : s) {
		B[c - 'A']++;
	}

	for (;;) {
		for (char c : s) {
			if (A[c - 'A'] < B[c - 'A']) return;
		}
		for (char c : s) {
			A[c - 'A']--;
		}
		result[num]++;
	}
}

void check()
{
	for (int a : A) {
		if (a != 0) {
			cerr << a << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc >= 2) {
		FILE* fp = freopen(argv[1], "r", stdin);
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(A, 0, sizeof(A));
		memset(result, 0, sizeof(result));
		string s;
		cin >> s;
		for (char c : s) {
			A[c - 'A']++;
		}
		test("ZERO", 0);//Z
		test("TWO", 2);//W
		test("SIX", 6);//X
		test("EIGHT", 8);//G
		test("SEVEN", 7);//S
		test("FIVE", 5);//V
		test("FOUR", 4);//F
		test("ONE", 1);//O
		test("THREE", 3);//R
		test("NINE", 9);
		cout << "Case #" << i + 1 << ": ";
		for (int i = 0; i < 10; i++) {
			for (;;) {
				if (result[i]-- > 0) {
					cout << i;
				} else {
					break;
				}
			}
		}
		cout << endl;
		check();
	}

	return 0;
}
