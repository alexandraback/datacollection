#include <iostream>
#include <string>
using namespace std;

char board[51][51];
bool trans;

bool f(int row, int col, const int mines){
	trans = false;
	const int emp = row*col - mines;
	
	if(mines == 0){
		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++)
				board[i][j] = '.';
		board[0][0] = 'c';
		return true;
	}
	if(mines+1 == row*col){
		for(int i=0; i<row; i++){
			for(int j=0; j<col; j++)
				board[i][j] = '*';
		}
		board[0][0]='c';
		return true;
	}

	if(col == 1){ trans=!trans; swap(row, col); }
	if(row == 1){
		int k = 0;
		for(int j=0; j<col; j++){
			if(k < mines){
				board[0][j] = '*';
				k++;
			}
			else board[0][j] = '.';
		}
		board[0][col-1] = 'c';
		return true;
	}

	int fill = mines/col;
	if(mines % col != 0) fill++;
	if(fill+2 <= row && (col-(mines%col)) != 1){ trans=!trans; swap(row, col); }
	
	fill = mines/row;
	if(mines % row != 0) fill++;
	if(fill+2 <= col && (row-(mines%row) != 1)){ // ((r-(mines%r))%2 == 0
		int k = 0;
		for(int j=0; j<col; j++){
			for(int i=0; i<row; i++){
				if(k < mines){ 
					board[i][j] = '*';
					k++;
				}
				else board[i][j] = '.';
			}
		}
		board[row-1][col-1] = 'c';
		return true;
	}
	
	if(emp >= 4){
		int sq = 0;
		for(int i=2; i < min(row,col); i++){
			if(emp % i == 0){
				int temp = emp/i;
				if(temp < col && temp < row)
				{
					sq = i;
					break;
				}

			}
		}
		if(sq > 0){
			for(int i=0; i<row; i++)
				for(int j=0; j<col; j++)
					board[i][j] = '*';
			
			//assert(col >= sq && row >= sq);
			if(row >= sq){
				int k = 0;
				for(int j=0; k<emp; j++){
					for(int l=0; l<sq; l++)
						board[l][j] = '.';
					k+=sq;
				}
				board[0][0] = 'c';
				return true;
			}
		}
	}

	if(mines >= 3 && row > 3 && col > 3){
		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++)
				board[i][j] = '.';
		board[row-1][col-1] = 'c';
		board[0][0] = '*';
		int cnt = mines-1;
		for(int k=1; min(row,col)>k+2; k++){
			if(cnt == 0) return true;
			board[0][k] = '*'; cnt--;
			if(cnt == 0) return true;
			board[k][0] = '*'; cnt--;
			if(cnt == 0) return true;
			if(k == 1){
				board[k][k] = '*';
				cnt--;
				if(cnt == 0) return true;
			}
			else if(k == 2){
				board[1][k] = '*'; cnt--;
				if(cnt == 0) return true;
				board[k][1] = '*'; cnt--;
				if(cnt == 0) return true;
				board[k][k] = '*'; cnt--;
				if(cnt == 0) return true;
			}
		}
	}

	if(emp >= 4 && row > 2 && col > 2){
		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++)
				board[i][j] = '*';
		board[0][0] = 'c';
		board[0][1] = board[1][0] = board[1][1] = '.';
		int rem = emp-4;
		for(int k=2;k<5;k++){
			if(rem == 0) return true;
			if(rem == 1) break;
			board[0][k] = board[1][k] = '.'; rem-=2;
			if(rem == 0) return true;
			if(rem == 1) break;
			board[k][0] = board[k][1] = '.'; rem-=2;
			if(rem == 0) return true;
			if(k == 2){
				board[k][k] = '.';
				if(rem == 1) return true;
				rem--;
			}
		}
	}

	return false;
}

void main(){
	//*
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	//*/
	
	int T;
	cin >> T;
	for(int tc=1; tc<=T; tc++){
		int r, c, m;
		cin >> r >> c >> m;
		//*
		cout << "Case #" << tc << ":\n";
		/*/
		//if(r*c == m+1 || m==0 || m+2 == r*c || m+3 == r*c || m+5 == r*c || m+7 == r*c) continue;
		cout << "Case #" << tc << ": r,c,m:\n" << r << ' ' << c << ' ' << m;
		cout << endl;//", emp: " << r*c-m << endl;
		//*/
		if(!f(r,c,m)) cout << "Impossible\n";
		else{
			if(trans){
				for(int i=0; i<r; i++){
					for(int j=0; j<c; j++){
						cout<<board[j][i];
					}
					cout << endl;
				}
			}
			else{
				for(int i=0; i<r; i++){
					for(int j=0; j<c; j++){
						cout<<board[i][j];
					}
					cout << endl;
				}
			}
		}
	}
}
/*
5 5 16
Possible
3 3 1
Possible
3 3 5
Possible
4 4 3
**..
*...
....
....
5 5 4
5 5 14
*****
*****
**...
*....
*....


3 3 2 ?
*..
...
..*

*/