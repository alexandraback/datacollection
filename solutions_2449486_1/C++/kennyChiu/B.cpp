#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int T;
	cin >> T;

	int i,j,k;

	for (i=1;i<=T;i++){
		int N, M;
		cin >> N >> M;
		vector<vector<int> > board(N);

		vector<int> row_max;

		int h;
		for (j=0;j<N ;j++){
			int r=0;
			for (k=0;k< M;k++){
				cin >> h;
				board[j].push_back(h);
				if (h > r){
					r = h;
				}
			}
			row_max.push_back(r);
		}

		vector<int> col_max;
		for (k=0; k< M;k++){
			int c= 0;
			for (j=0;j<N;j++){
				if (board[j][k] > c){
					c = board[j][k];
				}
			}
			col_max.push_back(c);
		}

		bool yes = true;
		for (j=0;j<N;j++){
			for (k=0;k<M;k++){
				if (board[j][k] < row_max[j] && board[j][k] < col_max[k]){
					yes = false;
					break;
				}
			}
			if (!yes){
				break;
			}
		}

		if (yes){
			cout <<"Case #" << i <<": YES" <<endl;
		}else{
			cout << "Case #" << i << ": NO" <<endl;
		}
	}

	return 0;
}
