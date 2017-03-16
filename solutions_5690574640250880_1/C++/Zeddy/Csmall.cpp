
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w+", stdout);
	int t;
    cin >> t;

	
	cout.precision(20);

	int map[2500];
	int transMap[2500];
	int R;
	int C;
	int M;
	int size;

	int rowFirst;
	int canDo;
	int sliverLength;
	int slivers;
	int notMine;

	int mapnum = 0;




	for(int ti = 0; ti < t; ti++){
		
		cout << "Case #" << (ti+1) << ": ";
		
		cin >> R;
		cin >> C;
		cin >> M;

		size = R*C;
		notMine = size-M;
		canDo = 0;

		if(R >= C){
			rowFirst = 1;
			sliverLength = C;
			slivers = R;
		}
		else{
			rowFirst = 0;
			sliverLength = R;
			slivers = C;
		}



		if(sliverLength == 1){
			canDo = 1;
		}

		if(sliverLength == 2){
			if((notMine%2 == 0)&&(notMine != 2)){
				canDo = 2;
			}
		}

		if(sliverLength >= 3){
			if(notMine%2 == 0){
				if(notMine != 2){
					canDo = 3;
				}
			}
			else{
				if((notMine == 1)||(notMine>=9)){
					canDo = 3;
				}
			}
		}

		if(notMine == 1){
			canDo = 1;
		}

		cout<<endl;

		if(canDo == 0){
			cout<<"Impossible"<<endl;
		}
		else{
			if(canDo == 3){
				for(int i = 0; i < slivers; i++){
					for(int j = 0; j < sliverLength; j++){
						map[i*sliverLength + j] = 1;
					}
				}

				int tempMine = M;
				int rowPos = 0;
				int colPos = 0;

				int rowsToLeave = 0;
				if(notMine%2 ==0){
					rowsToLeave = 1;
				}
				else{
					rowsToLeave = 2;
				}

				for(int i = (slivers-1); i > rowsToLeave;i--){
					if(tempMine >= sliverLength){
						for(int j = 0; j < sliverLength; j++){
							map[i*sliverLength + j] = 2;
						}
						tempMine = tempMine - sliverLength;
					}
					else{
						for(int j = 0; j < tempMine; j++){
							map[i*sliverLength + sliverLength - 1 -j] = 2;
						}
						if(sliverLength == (tempMine + 1)){
							map[i*sliverLength + 1] = 1;
							map[i*sliverLength-1] = 2;
						}
						tempMine = 0;
						break;
					}
				}

				if(tempMine > 0){
					if(notMine%2 == 0){
						for(int j = sliverLength - 1; j > sliverLength - 1 - tempMine/2; j--){
							map[j] = 2;
							map[sliverLength + j] = 2;
						}
						tempMine = 0;
					}
					else{
						colPos = sliverLength - 1;
						while(tempMine >= 3){
							map[colPos] = 2;
							map[sliverLength + colPos] = 2;
							map[2*sliverLength + colPos] = 2;
							tempMine = tempMine - 3;
							colPos--;
						}
						if(tempMine >= 1){
							map[2*sliverLength + colPos] = 2;
						}
						if(tempMine == 2){
							map[2*sliverLength] = 2;
						}
						tempMine = 0;
					}
				}

				map[0] = 0;
			}
			else{
				for(int i = 0; i < slivers; i++){
					for(int j = 0; j < sliverLength; j++){
						if((i == 0)&&(j==0)){
							map[i*sliverLength + j] = 0;
							notMine--;
						}
						else{
							if(notMine<1){
								map[i*sliverLength + j] = 2;
							}
							else{
								map[i*sliverLength + j] = 1;
								notMine--;
							}
						}
					}
				}
			}
		
			for(int i = 0; i < R; i++){
				for(int j = 0; j < C; j++){
					if(rowFirst){
						mapnum = map[i*C+j];
					}
					else{
						mapnum = map[j*R+i];
					}
					if(mapnum == 0){
						cout<< "c";
					}
					if(mapnum == 1){
						cout<< ".";
					}
					if(mapnum == 2){
						cout<< "*";
					}

				}
				cout<<endl;
			}

		}
	}

	fclose(stdout);
	fclose(stdin);
	return 0;
}

/*
void transposeMatrix(int *mat1, int *mat2, int rows, int columns){
	for(int i = 0; i < rows; i++){
		for(int j = 0; i < columns; j++){
			mat2[j*rows + i] = mat1[i*columns + rows];
		}
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; i < columns; j++){
			mat1[j*rows + i] = mat2[j*rows + i];
		}
	}
}
*/