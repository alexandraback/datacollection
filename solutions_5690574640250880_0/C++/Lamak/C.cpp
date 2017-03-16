#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

int R,C,M; 

bool inside_grid (int i, int j) {
	if (i>=0 && i<R && j>=0 && j<C) return true;
	else return false;
}

int openable (int** grid, int i, int j) {
	int count = 0;
	for (int m=i-1; m <=i+1; m++) {
		for (int n=j-1; n <=j+1; n++) {
			if (inside_grid(m,n)) {
				if (grid[m][n]==0) count++;
			}
		}
	}
	return count;
}

void open (int** grid, int i, int j) {
	for (int m=i-1; m<=i+1; m++) {
		for (int n=j-1; n<=j+1; n++) {
			if (inside_grid(m,n)) {
				grid[m][n]=1;
			}
		}
	}
}

void print_grid (int** grid) {
	int count = 0;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			if (i==0 && j==0) cout<<"c";
			else if (grid[i][j]==1) cout<<".";
			else {cout<<"*";count++;}
		}
		cout<<"\n";
	}
	/*if (M!=count) {
		cout<<"BUG! R:"<<R<<", C:"<<C<<", M:"<<M;
		cin.get();
	}*/
}

void explode_grid (int** grid, int to_open) {
	grid[0][0]=1;
	to_open--;
	for (int i=0; i<R && to_open>0; i++) {
		for (int j=0; j<C && to_open>0; j++) {
			
			//print_grid(grid); cout<<endl;
			
			int openable_n = openable(grid,i,j);
			//cout<<"["<<i<<"]["<<j<<"] to_open: "<<to_open<<", openable:"<<openable_n<<endl<<endl;
			//cin.get();
			if (grid[i][j]==0) break;
			if (to_open > 3 || R == 1 || C == 1  || to_open == openable_n || to_open - openable_n != 1) {
				open(grid, i, j);
				to_open-=openable_n;
			}
			
		}
	}
}

int main () {
	
	ifstream in ("C-small-attempt4.in");
    freopen("small.out","w",stdout);
	
	int* arr[4][4];
	arr[1][1]=new int[2] {1,1};
	arr[1][2]=arr[2][1]=new int[3] {2,1,2};
	arr[1][3]=arr[3][1]=new int[4] {3,1,2,3};
	arr[2][2]=new int[3] {2,1,4};
	arr[2][3]=arr[3][2]=new int[4] {3,1,4,6};
	arr[3][3]=new int[6] {5,1,4,6,8,9};
	
	int T; in>>T;
	
	for (int t=0; t<T; t++) {
		in>>R>>C>>M;
		cout<<"Case #"<<t+1<<":\n";
		
		int** grid = new int*[R];
		for (int i=0; i<R; i++) grid[i]=new int[C]();
		
		int* arr_t = arr[min(3,R)][min(3,C)];
		int to_open = R*C-M;
		if ( (R!=2 && C!=2 && to_open > arr_t[arr_t[0]]) || ((R==2 || C==2) && to_open>2 && to_open%2==0)
			|| find(arr_t+1, arr_t+1+arr_t[0], to_open) != arr_t+1+arr_t[0]) {
			
			explode_grid(grid,to_open);
			print_grid(grid);
			
		} else cout<<"Impossible\n";
		
	//	cin.get();
	}
	
	return 0;
}

