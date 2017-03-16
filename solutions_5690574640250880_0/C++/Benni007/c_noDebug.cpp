/* BA 2014 */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <limits>
#include <limits.h>
#include <iomanip>


using namespace std;
#define pb push_back
#define EPS 0.00001
#define For(x,y) for ( int (x) = 0; (x) < (y); (x)++ )
#define MAX 1


int R,C,M;
vector<vector<int> > field;
// spots that we have revealed to be zero
vector<pair<int,int> > zeros;
// spots that are perimeter : need to iterate through it
vector<pair<int,int> > peri;
// N is the number of spots not mine
int N;
/******************************/
// Methods
//
void print(vector<pair<int,int> > v){
	For(i, v.size()){
		cout << "(" << v[i].first <<  "," << v[i].second << ")" << endl;
	}
}

void printMap(){
	bool clicked = false;
	For(row,R){
		For(col,C){
			
			if(field[row][col] ==0 and !clicked){
				cout << "c";
				clicked = true;
			} else if(field[row][col] >= 0){
				cout << ".";
			} else {
				cout << "*";
			}
		}
		cout << endl;
	}
}

void printMapLiteral(){
	For(row,R){
		For(col,C){
			if(field[row][col]>=0){
				cout << field[row][col];
			} else {
				cout << "4";
			}
		}
		cout <<endl;
	}
}

bool aux(int a){
	if(a == N){
		return true;
	} else if(a > N){
		return false;
	} else {
		//cout << "Begining of Aux for a = " << a << endl;
		//printMap();

		// 1. copy perimeter vector
		vector<pair<int,int> > _peri = vector<pair<int,int> >(peri.size(), pair<int,int>(-9,-9));
		For(i,peri.size()){
			_peri[i].first = peri[i].first;
			_peri[i].second = peri[i].second;
		}
		// 2. loop through the perimeter vector
		For(i,_peri.size()){
			int row = _peri[i].first;
			int col = _peri[i].second;
			bool possible;
			int newScores;
			/********/
			// 2.0 set the field to zero at the spot
			field[row][col] = 0;
			// 2.1 add zero to the list
			zeros.push_back(pair<int,int>(row,col));
			// 2.2 add perimeters to the list
			int count = 0; // for convenient of rolling back
			for(int _row = row-1; _row <= row+1 ; _row++){
				if(_row >= 0 and _row < R){
					for(int _col = col-1; _col <= col+1 ; _col++){
						if(_col >= 0 and _col < C ){
							if(field[_row][_col] == -1){
								count++;
								//cout << "Found" << endl;
								field[_row][_col] = 1;
								peri.push_back(pair<int,int>(_row,_col));
							}
							// else field[row][col] == 0 or 1 , which we'll skip
						}
					}
				}
			}
			if(count == 0) continue;
			/*******/
			//cout << "After adding 0. Count = "<< count << endl;
			//printMap();
			possible = aux(a + count);
			
			if(possible){
				return true;
			} else {
				//cout << "Reverting" << endl;
				// fix zeros
				field[row][col] = 1;
				zeros.pop_back();
				For(j,count){
					pair<int,int> p = peri[peri.size()-1];
					int _r = p.first;
					int _c = p.second;
					field[_r][_c] = -1;

					peri.pop_back();
				}
				// pop back peri too (count times)
				// fix the field
			}
		}

		return false; // if this route doesn't work at all - go back and return false
	}
}


bool findPerfectConfig(){
	//cout << "HERE" << endl; // debug
	//cout << "Number of non mines = " << N << endl;
	field = vector<vector<int> >(R, vector<int>(C,-1));
	zeros = vector<pair<int,int> >();
	peri = vector<pair<int,int> >();
	
	if(N == 0){
		return true;
	} else if(N == 1) {
		field[0][0] = 0;
		return true;
	} else {
		// vary x and y : do for loop
		//cout << "R,C, are" << R << "," << C << endl;
		For(y,R){
			For(x,C){
				field = vector<vector<int> >(R, vector<int>(C,-1));
				zeros = vector<pair<int,int> >();
				peri = vector<pair<int,int> >();
				
				//cout << "Center of O is row = " << y << " and col = " << x << endl;
				// 1. adding the middle
				zeros.push_back(pair<int,int>(x,y));
				field[y][x] = 0;
				// 2. add the perimeters
				int count = 1; // have the 0 already
				//cout << "x,y are:" << x << "," << y << endl;
				for(int row = y-1; row <= (y+1); row++){
					if(row >= 0 and row < R){
						//cout << "Going through row " << row << endl;
						for(int col = x-1; col <= (x+1) ; col++){
							if(col >=0 and col < C){
								// everything around it is -1 (except for (x,y))
								//cout << "Going through (row,col) ("<< row << ","<< col<<")"<< endl;
								if(field[row][col] < 0){
									field[row][col] = 1;
									// add it to the list
									peri.push_back(pair<int,int>(row,col));
									count++;
									//cout << "After setting" << endl;
									//printMap();
								}
							}
						}
					}
				}
				//cout << "The count at first is" << count << endl;
				bool possible =  aux(count);
				if(possible){
					return true;
				} 
				// else, continue
			}
		}
		// if not returning true yet, return false
		return false;
	}
	
}

int main(){
	int numCases;
	cin >> numCases;
	
	for(int caseN=1; caseN <= numCases; caseN++){
		cin >> R >> C >> M;
			N = R*C - M;
		/********************************/
		// DEBUG
		bool possible = findPerfectConfig();

		/********************************/
		//cout << "=------------------------------------------------------------------------------"<<endl;
		cout << "Case #" << caseN << ":" << endl; // DEBUG
		//cout << "R,C,M = " << R << "," << C <<","<< M << endl;
		//cout << "N = " << N << endl;
		if(!possible){
			cout << "Impossible\n";
		} else {
			printMap();
			//printMapLiteral();
		}
	}
	
	return 0;
}
