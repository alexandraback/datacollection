#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;



int table[4][4] = { { 0, 1, 2, 3 }, { 1, 4, 3, 6 }, { 2, 7, 4, 1 }, { 3, 2, 5, 4 } };

inline int calc(int x,int y){
	int e = 1;
	if (x > 3) e *= -1, x -= 4;
	if (y > 3) e *= -1, y -= 4;
	if (e > 0) return table[x][y];
	return table[x][y] > 3 ? table[x][y] - 4 : table[x][y] + 4;
}

int main(){
	int n;
	ifstream inf("C-large.in");
	ofstream outf("C-large.out");
	inf >> n;
	for (int i = 1; i <= n; i++){
		bool test1 = false, test2 = false, test3 = false; // 1: i 2: k after i 3: final value = -1
		long long L, X;
		int *result;
		inf >> L >> X;
		result = new int[L];
		char c;
		inf >> c;
		result[0] = c - 'i' + 1;
		if (result[0] == 1) test1 = true;
		for (int j = 1; j < L; j++){
			inf >> c;
			c = c - 'i' + 1;
			result[j] = calc(result[j-1],c);
			if (result[j] == 1) test1 = true;
			if (test1 && result[j] == 3) test2 = true;
		}
		int t = result[L - 1];
		int fin = 0;
		for (int j = 0; j < (X % 4); j++) fin = calc(fin, t);
		if (fin == 4){
			test3 = true;
			for (int j = 1; j < 8 && j < X; j++){
				for (int k = 0; k < L; k++){
					result[k] = calc(t,result[k]);
					if (result[k] == 1) test1 = true;
					if (test1 && result[k] == 3) test2 = true;
				}
			}
		}
		outf << "Case #" << i << ": " << (test1 && test2 && test3?"YES":"NO") << "\n";
		delete[] result;
	}
	return 0;
}