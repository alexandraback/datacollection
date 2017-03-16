#include <iostream>
#include <string>

using namespace std;

enum Trends {
	ASCENDING,
	DESCENDING
};

bool check(int **l, int rows, int cols){
	for(int row = 0; row < rows; row++ ) {
		for(int col= 0; col< cols; col++ ) {
			int checkVal = l[row][col];
			if(checkVal>100) {
				return false;
			}
			bool check = true;
			for(int i = 0; i < rows; i++ ) {
				if(l[i][col]>checkVal) {
					check = false;
				}
			}
			if(check) {
				continue;
			}
			for(int i = 0; i < cols; i++ ) {
				if(l[row][i]>checkVal) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	int numCases;
	cin>>numCases;
	for(int currTest = 1; currTest <= numCases; currTest++ ) {
		int rows, cols;
		cin>>rows;
		cin.clear();
		cin.ignore(1);
		cin>>cols;
		int **l = new int*[rows];
		for(int i = 0; i < rows; i++ ) {
			l[i] = new int[cols];
		}
		for(int i = 0; i < rows; i++ ) {
			for(int j = 0; j < cols; j++ ) {
				cin>>l[i][j];
				cin.clear();
				cin.ignore(1);
			}
		}
		cout<<"Case #"<<currTest<<": "
				<<((check(l,rows,cols))?"YES":"NO")
				<<endl;
	}
	return 0;
}
