#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define double long double
#define LL long long
#define itn int

using namespace std;

int main(){

	int T;
	cin >> T;
	for (int _ = 0; _ < T; _++){
		cout << "Case #" << _ + 1 << ": ";
		int r, c, m;
		cin >> r >> c >> m;
		cout << "\n";
		if (m == r * c - 2 || m == r * c - 3){
			if (r == 1 || c == 1){
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						if (i * c + j < m) cout << "*"; else
						if (i == r - 1 && j == c - 1) cout << "c"; else
						cout << ".";
					}
					cout << "\n";
				}
			} else cout << "Impossible\n";
		} else 
		if (r == 1 || c == 1){
			for (int i = 0; i < r; i++){
				for (int j = 0; j < c; j++){
					if (i * c + j < m) cout << "*"; else
					if (i == r - 1 && j == c - 1) cout << "c"; else
					cout << ".";
				}
				cout << "\n";
			}
		} else
		if (r == 2 || c == 2){
			if (m == r * c - 1){
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						if (i == r - 1 && j == c - 1) cout << "c"; else cout << "*";
					}
					cout << "\n";
				}
			} else 
			if ((r * c - m) % 2 == 0){
				if (r == 2){
					for (int i = 0; i < c; i++) if (i < m / 2) cout << "*"; else cout << ".";
					cout << "\n";
					for (int i = 0; i < c - 1; i++) if (i < m / 2) cout << "*"; else cout << ".";
					cout << "c\n";
				} else {
					for (int i = 0; i < r - 1; i++) if (i < m / 2) cout << "**\n"; else cout << "..\n";
					cout << ".c\n";
				}
			} else cout << "Impossible\n";
		} else {
			if (m == r * c - 1){
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						if (i == r - 1 && j == c - 1) cout << "c"; else cout << "*";
					}
					cout << "\n";
				}
			} else
			if (m == r * c - 5 || m == r * c - 7){
				cout << "Impossible\n";
			} else {
				char ans[r][c];
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						ans[i][j] = '*';
					}
				}
				if (r * c - m <= r + r + c + c - 4){
					m = r * c - m;
					ans[r - 1][c - 1] = 'c';
					ans[r - 1][c - 2] = '.';
					ans[r - 2][c - 1] = '.';
					ans[r - 2][c - 2] = '.';
					m -= 4;
					if (m % 2 == 1) ans[r - 3][c - 3] = '.';
					m -= m % 2;
					if (m > 0){
						ans[r - 3][c - 2] = ans[r - 3][c - 1] = '.';
						m -= 2;
					}
					if (m > 0){
						ans[r - 2][c - 3] = ans[r - 1][c - 3] = '.';
						m -= 2;
					}
					for (int i = 4; i <= r && m > 0; i++){
						ans[r - i][c - 2] = ans[r - i][c - 1] = '.';
						m -= 2;
					}
					for (int i = 4; i <= c && m > 0; i++){
						ans[r - 2][c - i] = ans[r - 1][c - i] = '.';
						m -= 2;
					}
				} else {
					m = r * c - m;
					ans[r - 1][c - 1] = 'c';
					ans[r - 1][c - 2] = '.';
					ans[r - 2][c - 1] = '.';
					ans[r - 2][c - 2] = '.';
					m -= 4;
					ans[r - 3][c - 3] = '.';
					m -= 1;
					if (m > 0){
						ans[r - 3][c - 2] = ans[r - 3][c - 1] = '.';
						m -= 2;
					}
					if (m > 0){
						ans[r - 2][c - 3] = ans[r - 1][c - 3] = '.';
						m -= 2;
					}
					for (int i = 4; i <= r && m > 0; i++){
						ans[r - i][c - 2] = ans[r - i][c - 1] = '.';
						m -= 2;
					}
					for (int i = 4; i <= c && m > 0; i++){
						ans[r - 2][c - i] = ans[r - 1][c - i] = '.';
						m -= 2;
					}
					for (int k = 7; m > 0; k++){
						for (int i = max(3, k - c); i <= min(k - 3, r) && m > 0; i++){
							ans[r - i][c - k + i] = '.';
							m--;
						}
					}
				}
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++) cout << ans[i][j];
					cout << "\n";
				}
			}
		}
	}

	return 0;
	
}