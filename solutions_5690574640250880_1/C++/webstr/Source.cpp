#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream fin;
	ofstream fout;
	int T;

	fin.open("input.txt");
	fout.open("output.txt");
	fin >> T;

	for (int k = 1; k <= T; k++){
		int R, C, M;
		fin >> R >> C >> M;

		int **mas = new int *[R];
		for (int i = 0; i < R; i++){
			mas[i] = new int [C];
		}

		for (int i = 0; i < R; i++){
			for (int j = 0; j < C; j++){
				mas[i][j] = 0;
			}
		}

		bool isPossible = true;
		int num = R * C - M;
		
		if (M == 0){
			mas[0][0] = 2;
		} else if (R == 1){
			mas[0][0] = 2;
			for (int i = C - 1; i > C - M - 1; i--){
				mas[0][i] = 1;
			}
		} else if (C == 1){
			mas[0][0] = 2;
			for (int i = R - 1; i > R - M - 1; i--){
				mas[i][0] = 1;
			}
		} else if (num == 1){
			for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					mas[i][j] = 1;
				}
			}
			mas[0][0] = 2;
		} else if (num == 2 || num == 3 || num == 5 || num == 7){
			isPossible = false;
		} else if (num == 4){
			for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					mas[i][j] = 1;
				}
			}
			mas[0][0] = 2; mas[0][1] = 0; mas[1][0] = 0; mas[1][1] = 0;
		} else if (R == 2){
			if (num % 2 == 1){
				isPossible = false;
			} else {
				mas[0][0] = 2;
				for (int j = C - 1; j > C - 1 - M / 2; j--){
					mas[0][j] = 1;
					mas[1][j] = 1;
				}
			}
		} else if (C == 2){
			if (num % 2 == 1){
				isPossible = false;
			} else {
				mas[0][0] = 2;
				for (int i = R - 1; i > R - 1 - M / 2; i--){
					mas[i][0] = 1;
					mas[i][1] = 1;
				}
			}
		} else if (num == 6){
			for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					mas[i][j] = 1;
				}
			}
			mas[0][0] = 2; mas[0][1] = 0; mas[1][0] = 0; mas[1][1] = 0; mas[0][2] = 0; mas[1][2] = 0;
		} else if (M <= (R - 2) * (C - 2)){
			int s = 0;
			mas[0][0] = 2;
			for (int i = R - 1; i > 1; i--){
				if (s < M){
					for (int j = C - 1; j > 1; j--){
						if (s < M){
							mas[i][j] = 1;
							s++;
						} else {
							break;
						}
					}
				} else {
					break;
				}
			}
		} else {
			mas[0][0] = 2;
			int s = 0;
			for (int i = R - 1; i > 1; i--){
				for (int j = C - 1; j > 1; j--){		
					mas[i][j] = 1;
					s++;
				}
			}

			int r = R - 1;
			int c = C - 1;
			while (s < M){
				if (r > 2){
				mas[r][0] = 1;
				mas[r][1] = 1;
				r--;
				s += 2;
				}
				if (s < M && c > 2){
					mas[0][c] = 1;
					mas[1][c] = 1;
					c--;
					s += 2;
				}
				if (r == 2 && c == 2){
					mas[2][2] = 0;
					s++;
				}
			}

			if (s > M){
				mas[2][2] = 0;
			}
		}

		if (isPossible){
			fout << "Case #" << k << ":" << endl;
			for (int i = 0; i < R; i++){
				for (int j = 0; j < C; j++){
					if (mas[i][j] == 2){
						fout << "c";
					} else if (mas[i][j] == 1){
						fout << "*";
					} else if (mas[i][j] == 0){
						fout << ".";
					}
				}
				fout << endl;
			}
		} else {
			fout << "Case #" << k << ":" << endl;
			fout << "Impossible" << endl;
		}
	}

	fin.close();
	fout.close();
}