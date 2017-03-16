#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;

long long diff(const string & A, const string & B) {
	string::size_type ss;
	long long a = stoll(A, &ss);
	long long b = stoll(B, &ss);
	return abs(a - b);
}

void test(char pA, char pB, string & rA, string & rB, long long & best, string & oA, string & oB) {
	rA = pA + rA;
	rB = pB + rB;
	long long l = diff(rA, rB);
	if (l < best || (l == best && rA < oA) || (l == best && rA == oA && rB < oB)) {
		oA = rA, oB = rB;
		best = l;
	}
}

void solve(string A, string B, int status, int i, string & oA, string & oB) {
	oA = "", oB = "";
	if (i >= A.size()) return;
	string rA, rB;
	if (status != 0) {
		solve(A, B, status, i+1, rA, rB);
		if (A[i] == '?') {
			if (status < 0) {
				A[i] = '9';
			} else {
				A[i] = '0';
			}
		} 
		if (B[i] == '?') {
			if (status < 0) {
				B[i] = '0';
			} else {
				B[i] = '9';
			}
		}
		oA = A[i] + rA;
		oB = B[i] + rB;
		return;
	}
	long long best = 1000000000000000000ll;
	long long l;
	// status == 0
	if (A[i] == '?' && B[i] == '?') {
		A[i] = '0';
		B[i] = '0';
		solve(A, B, 0, i+1, rA, rB);
		test(A[i], B[i], rA, rB, best, oA, oB);

		A[i] = '0';
		B[i] = '1';
		solve(A, B, -1, i+1, rA, rB);
		test(A[i], B[i], rA, rB, best, oA, oB);

		A[i] = '1';
		B[i] = '0';
		solve(A, B, 1, i+1, rA, rB);
		test(A[i], B[i], rA, rB, best, oA, oB);
		return;
	}

	if (A[i] == '?') {
		string rA, rB;
		if (B[i] > '0') {
			A[i] = B[i]-1;
			solve(A, B, -1, i+1, rA, rB);
			test(A[i], B[i], rA, rB, best, oA, oB);
		}
		A[i] = B[i];
		solve(A, B, 0, i+1, rA, rB);
		test(A[i], B[i], rA, rB, best, oA, oB);
		if (B[i] < '9') {
			A[i] = B[i]+1;
			solve(A, B, 1, i+1, rA, rB);
			test(A[i], B[i], rA, rB, best, oA, oB);
		}
		return;
	}
	if (B[i] == '?') {
		string rA, rB;
		if (A[i] > '0') {
			B[i] = A[i]-1;
			solve(A, B, 1, i+1, rA, rB);
			test(A[i], B[i], rA, rB, best, oA, oB);
		}
		B[i] = A[i];
		solve(A, B, 0, i+1, rA, rB);
		test(A[i], B[i], rA, rB, best, oA, oB);
		if (B[i] < '9') {
			B[i] = A[i]+1;
			solve(A, B, -1, i+1, rA, rB);
			test(A[i], B[i], rA, rB, best, oA, oB);
		}
		return;
	}
	int x;
	if (A[i] == B[i]) x = 0;
	else if (A[i] > B[i]) x = 1;
	else x = -1;
	solve(A, B, x, i+1, rA, rB);
	oA = A[i] + rA, oB = B[i] + rB;
	return;
}

int main(){
	int tcase;
	cin >> tcase;
	string a, b;

	for(size_t casen = 0; casen < tcase; ++casen)
	{
		cout << "Case #" << casen + 1 << ": ";

		cin >> a >> b;
		string rA, rB;
		solve(a, b, 0, 0, rA, rB);
		cout << rA << " " << rB << endl;
	}


	return 0;
}
