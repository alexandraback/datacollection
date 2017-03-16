#pragma comment(linker, "/STACK:216000000")
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
#include <set>
const int MAX = 1000001;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


void main() {
	//ios_base::sync_with_stdio(false);
	ifstream cin{ "in.txt" };
	ofstream cout{ "out.txt" };
	int t;
	cin >> t; 
	for (int qqq = 0; qqq < t; ++qqq) {
		cout << "Case #" << qqq + 1 << ": ";
		int A, B, C, k;
		cin >> A >> B >> C >> k;
		int X = min(A, k), Y = min(B, k), Z = min(C, k);
		cout << X * Y * Z << endl;
		for (int a = 0; a < X; ++a) {
			for (int b = a; b < a + Y; ++b) {
				for (int c = b; c < b + Z; ++c) {
					cout << a % A + 1 << " " << b % B + 1 << " " << c % C + 1 << endl;
				}
			}
		}
	}
	cin.close();
	cout.close();
}