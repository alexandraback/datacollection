#include <iostream>
#include <cassert>

using namespace std;

char mines[64][64];

int r,c;

void print_mines(bool flipped){
	if (flipped){
		for (int j = 0; j < c; j++){
			for (int i = 0; i < r; i++)
				cout << mines[i][j];
			cout << endl;
		}
	}
	else{
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++)
				cout << mines[i][j];
			cout << endl;
		}
	}
}

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		int m;
		cin >> r >> c >> m;
		int f = r*c - m;
		bool flipped = false;
		if (r > c){
			int temp = r;
			r = c;
			c = temp;
			flipped = true;
		}
		for (int i = 0; i < 64; i++)
			for (int j = 0; j < 64; j++)
				mines[i][j] = '*';
				
		cout << "Case #" << zz << ":" << endl;
		//cout << "r = " << r << ", c = " << c << endl;
		if (r == 1){
			mines[0][0] = 'c';
			for (int i = 1; i < f; i++)
				mines[0][i] = '.';
			print_mines(flipped);
		}
		else if (r == 2){
			if (f == 1){
				mines[0][0] = 'c';
				print_mines(flipped);
			}
			else if (f <= 3) cout << "Impossible" << endl;
			else if (f % 2) cout << "Impossible" << endl;
			else {
				for (int i = 0; i < 2; i++){
					for (int j = 0; j < (f/2); j++)
						mines[i][j] = '.';
				}
				mines[0][0] = 'c';
				print_mines(flipped);
			}
		}
		else{
			if (f ==1){
				mines[0][0] = 'c';
				print_mines(flipped);
			}
			else if (f <= 3) cout << "Impossible" << endl;
			else if (f == 4 || f == 6){
				for (int i = 0; i < 2; i++){
					for (int j = 0; j < (f/2); j++)
						mines[i][j] = '.';
				}
				mines[0][0] = 'c';
				print_mines(flipped);
			}
			else if (f == 5 || f == 7) cout << "Impossible" << endl;
			else if (f == 8 || f == 9){
				for (int i = 0; i < 3; i++){
					for (int j = 0; j < 3; j++)
						mines[i][j] = '.';
				}
				mines[0][0] = 'c';
				if (f == 8) mines[2][2] = '*';
				print_mines(flipped);
			}
			else if (f < 2*c){
				//cerr << "here" << endl;
				if (f % 2){
					for (int i = 0; i < 2; i++)
						for (int j = 0; j < (f/2)-1; j++)
							mines[i][j] = '.';
					mines[2][0] = '.';
					mines[2][1] = '.';
					mines[2][2] = '.';
				}
				else{
					for (int i = 0; i < 2; i++)
						for (int j = 0; j < (f/2); j++)
							mines[i][j] = '.';
				}
				mines[0][0] = 'c';
				print_mines(flipped);
			}
			else if (f % c != 1){
				for (int i = 0; i < (f/c); i++)
					for (int j = 0; j < c; j++)
						mines[i][j] = '.';
				for (int j = 0; j < (f%c); j++)
					mines[f/c][j] = '.';
				mines[0][0] = 'c';
				print_mines(flipped);
			}
			else if (f == 2*c+1){
				for (int i = 0; i < 2; i++)
					for (int j = 0; j < c-1; j++)
						mines[i][j] = '.';
				mines[2][0] = '.';
				mines[2][1] = '.';
				mines[2][2] = '.';
				mines[0][0] = 'c';
				print_mines(flipped);
			}
			else{
				for (int i = 0; i < (f/c); i++)
					for (int j = 0; j < c; j++)
						mines[i][j] = '.';
				mines[(f/c)-1][c-1] = '*';
				mines[f/c][0] = '.';
				mines[f/c][1] = '.';
				mines[0][0] = 'c';
				print_mines(flipped);
			}
		}
		/*
		if (mines[0][0] != 'c')
			cerr << r << " " << c << " " << m << endl;
		
		else{
			int cnt = 0;
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++){
					if (mines[i][j] == '*')
						cnt++;
				}
			if (cnt != m){
				cerr << r << " " << c << " " << m << endl; 
				assert(cnt==m);
			}
		}
		*/
	}

	return 0;
}
