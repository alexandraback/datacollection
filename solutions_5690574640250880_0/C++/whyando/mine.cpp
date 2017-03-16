#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <set>

using namespace std;

int r, c, m;
ofstream fout("mine.out");
ifstream fin("mine.in");

void printVec(vector<vector<char>> *vec){
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cout << (*vec)[i][j];
			fout << (*vec)[i][j];
		}
		cout << endl;
		fout << endl;
	}
}

int main() {	

	int t;
	fin >> t;

	for (int caseNo = 1; caseNo <= t; caseNo++){
		fout << "Case #" << caseNo << ":" << endl;
		
		fin >> r >> c >> m;
		//r = 5; c = 3; m = 0;

		int spaces = r*c - m;

		if (r >= 3 && c >= 3 && spaces>=6 && spaces!=7){
			
			//by this point should be r>=3 c>=3 spaces>=4
			cout << "normal problem " << r << " by " << c << " spaces: " << spaces << endl;

			vector<vector<char>> vec;
			for (int i = 0; i < r; i++){
				vec.emplace_back();
				for (int j = 0; j < c; j++){
					vec[i].push_back('*');
				}
			}

			vec[0][0] = 'c';
			vec[0][1] = '.';
			vec[1][0] = '.';
			vec[1][1] = '.';
			vec[0][2] = '.';
			vec[1][2] = '.';
			int used = 6;
			
			int right = 2;
			int down = 1;
						
			while (used != spaces && used!= spaces-1){
				//expand down
				down++;
				vec[down][0] = '.';
				vec[down][1] = '.';
				used += 2;
				if (down+1 == r)
					break;
			}

			while ((right+1!=c) && used != spaces && used != spaces - 1){
				//expand right
				right++;
				vec[0][right] = '.';
				vec[1][right] = '.';
				used += 2;
				//if (right + 1 == c)
				//	break;
			}
			//at this point vec[2+][2+] can be added as a space for +1
			//printVec(&vec);


			right = 2; down = 2;//current editing square
			while (used != spaces){
				//expand diagonal
				//cout << down << "," << right<< endl;
				vec[down][right] = '.';
				used++;
				right++;
				if (right == c){
					right = 2;
					down++;
				}
				if (down == r){					
					cout << "full" << endl;
					//return 10;
				}
			}
			printVec(&vec);


		}
		else{
			if (c >= 3 && r >= 3 && spaces != 1 && spaces != 4){//2,3,5,7
				cout << "impossible 2357" << endl;
				fout << "Impossible" << endl;
			}
			
			else if (c == 1){//several lines
				fout << "c" << endl;
				spaces--;
				for (int i = 1; i < r; i++){
					if (spaces>0){
						fout << "." << endl;
						spaces--;
					}
					else
						fout << "*" << endl;
				}
			}
			else if (r == 1){//one line
				fout << "c";
				spaces--;
				for (int i = 1; i < c; i++){
					if (spaces>0){
						fout << ".";
						spaces--;
					}
					else
						fout << "*";
				}
				fout << endl;
			}
			else if (spaces == 1){
				//just c				
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						if (i == 0 && j == 0)
							fout << "c";
						else
							fout << "*";
					}
					fout << endl;
				}
			}
			else if (spaces == 4){
				//just c... (in square)				
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						if (i == 0 && j == 0)
							fout << "c";
						else if ((i == 1 && j == 0) || (i == 0 && j == 1) || (i == 1 && j == 1))
							fout << ".";
						else
							fout << "*";
					}
					fout << endl;
				}
			}
			else if (r == 2){
				if (spaces % 2 == 1 || spaces == 2){
					cout << "impossible odd in 2 wide" << endl;
					fout << "Impossible" << endl;
				}
				else{
					int length = spaces / 2;
					for (int i = 0; i < c; i++){
						if (i == 0){
							fout << "c";
							length--;
						}
						else if (length>0){
							length--;
							fout << ".";
						}
						else
							fout << "*";
					}
					fout << endl;
					length = spaces / 2;
					for (int i = 0; i < c; i++){
						if (length>0){
							length--;
							fout << ".";
						}
						else
							fout << "*";
					}
					fout << endl;
				}
			}
			else if (c == 2){
				if (spaces % 2 == 1 || spaces == 2){
					cout << "impossible odd in 2 wide" << endl;
					fout << "Impossible" << endl;
				}
				else{
					int length = spaces / 2;
					for (int i = 0; i < r; i++){
						if (i == 0){
							fout << "c." << endl;
							length--;
						}
						else if (length>0){
							length--;
							fout << ".." << endl;
						}
						else
							fout << "**" << endl;
					}
				}
			}
			else{
				cout << "IHAVENOIDEA" << endl;
				cout <<"\t" <<  r << " by " << c << " spaces: " << spaces << endl;
			}
		}
	}
	return 0;
}