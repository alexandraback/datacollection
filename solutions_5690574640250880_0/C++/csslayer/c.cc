#include <iostream>
#include <stdint.h>
#include <iomanip>
#include <algorithm>
using namespace std;

char output[50][50 + 1];

static void helper_1(int C, int M, bool transd)
{
	int i = 0;
	for (; i < M; i ++ ){
		cout << "*";
		if (transd) {
			cout << endl;
		}
	}
	for (;i < C - 1; i++ ) {
		cout << ".";
		if (transd) {
			cout << endl;
		}
	}
	
	if (i < C) {
		cout << "c" << endl;
	}
};

static void print_output(int R, int C)
{
	for (int i = 0; i < R; i++) {
		output[i][C] = '\0';
		cout << output[i] << endl;
	}
}

#define SET(V) \
	do { \
		if (!transd) { \
			output[i][j] = (V); \
		} else { \
			output[j][i] = (V); \
		} \
	} while(0)

static void helper_2(int R, int C, int M, bool transd)
{
	int count = 0;
	for (int j =0 ; j < C ; j++) {
		for (int i = 0 ; i < R ; i++) {
			if (i == 0 && j == 0) {
				SET('c');
			} else if (count < R * C - M) {
				SET('.');
			} else {
				SET('*');
			}
			count ++;
		}
	}
	
	if (transd) {
		swap(R, C);
	}
	print_output(R, C);
};

static void helper_one_safe(int R, int C)
{
	for (int i =0 ; i < R ; i++) {
		for (int j =0 ; j < C ; j++) {
			if (i == 0 && j == 0) {
				cout << "c";
			} else {
				cout << "*";
			}
		}
		cout << endl;
	}
}

static void helper_corner(int R, int C, int M, bool transd)
{
	if (transd) {
		swap(R, C);
		transd = false;
	}
	int count = 0;
	for (int i = 0 ; i < R ; i++) {
		for (int j =0 ; j < C ; j++) {
			if (i == R - 1 && j == C - 1) {
				SET('c');
			} else if (j < C - 2 && i < R - 2) {
				if (count < M) {
					SET('*');
				} else {
					SET('.');
				}
				count ++;
			} else {
				SET('.');
			}
		}
	}
	
	print_output(R, C);
};


static void helper_corner_2(int R, int C, int M, int S, bool transd)
{
	if (transd) {
		swap(R, C);
		transd = false;
	}
	for (int i = 0 ; i < R - 2 ; i++) {
		for (int j =0 ; j < C - 2 ; j++) {
			SET('*');
		}
	}
	
	int count = (R - 2) * (C - 2);
	if (S % 2 == 1) {
		output[R - 3][C -3] = '.';
		count -= 1;
	}
	
	for (int i = 0; i < R - 3; i ++) {
		for (int j = C - 2; j < C; j++) {
			if (count < M) {
				SET('*');
			} else {
				SET('.');
			}
			count ++;
		}
	}
	for (int j = 0; j < C - 3; j++) {
		for (int i = R - 2; i < R; i ++) {
			if (count < M) {
				SET('*');
			} else {
				SET('.');
			}
			count ++;
		}
	}
	
	
	// right down corner
	output[R - 3][C - 1] = '.';
	output[R - 3][C - 2] = '.';
	output[R - 1][C - 3] = '.';
	output[R - 2][C - 3] = '.';
	output[R - 2][C - 2] = '.';
	output[R - 1][C - 2] = '.';
	output[R - 2][C - 1] = '.';
	output[R - 1][C - 1] = 'c';
	
	print_output(R, C);
};

static void helper_46(int R, int C, int S, bool transd)
{
	if (transd) {
		swap(R, C);
		transd = false;
	}
	for (int i = 0 ; i < R ; i++) {
		for (int j =0 ; j < C ; j++) {
			if (i == 0 && j == 0) {
				SET('c');
			} else if (i < 2 && j < S / 2) {
				SET('.');
			} else {
				SET('*');
			}
		}
	}
	
	print_output(R, C);
}
	
int main()
{
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++) {
		int R, C, M;
		cin >> R >> C >> M;
		
		cout << "Case #" << t << ":" << endl;
		bool transd = false;
		if (R > C) {
			transd = true;
			swap(R, C);
		}
		
		int S = R * C - M;
		
		if (R == 1) {
			helper_1(C, M, transd);
		} else {
			// if we click on non zero, the only possibility is there is only one non-mine
			if (S == 1) {
				if (transd) {
					swap(R, C);
				}
				helper_one_safe(R, C);
			} else {
				if (R == 2) {
					// 2 is so special
					// it can only work like
					// .. ..*
					// .. ..*
					if (M % 2 == 1) {
						cout << "Impossible" << endl;
					} else if (S < 4){
						cout << "Impossible" << endl;
					} else {
						helper_2(R, C, M, transd);
					}
				} else {
					if (M <= (R - 2) * (C - 2)) {
						helper_corner(R, C, M, transd);
					} else if (S >= 8) {
						helper_corner_2(R, C, M, S, transd);
					} else {
						// this leave use 4 and 6
						if (S < 4 || S == 5 || S == 7) {
							cout << "Impossible" << endl;
						} else {
							helper_46(R, C, S, transd);
						}
					}
				}
			}
		}
	}
}