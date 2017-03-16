#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

void print_map(vector<string> m);

int main(){
	int T;
	cin >> T;
	for (int t=1;t<=T;++t){
		int R,C,M;
		cin >> R >> C >> M;
		
		//Generate the minesweeper map
		vector<string> map;
		//generate zero map
		for (int i=0;i<R;++i){
			string s = "";
			for (int j=0;j<C;++j){
				s += ".";
			}
			map.push_back(s);
		}
		
		//Generate the mines position
		int cur_mine = 0;
		int cur_row = 0;
		int cur_col = 0;
		while (cur_mine < M){
			int h_left = C - cur_col;
			int v_left = R - cur_row;
			int mine_left = M - cur_mine;
			//We go to direction that is smaller
			if (h_left > v_left){
				//Go vertical
				if (mine_left >= v_left){
					for (int i=cur_row; i<R;++i) {
						map[i][cur_col] = '*';
					}
					cur_col++;
					cur_mine += v_left;
				}
				else if (mine_left == v_left - 1){
					for (int i=cur_row; i<R-2;++i) {
						map[i][cur_col] = '*';
					}
					map[cur_row][cur_col+1] = '*';
					cur_col++;
					cur_mine += mine_left;
					break;
				}
				else {
					for (int i=cur_row; i<cur_row+mine_left;++i){
						map[i][cur_col] = '*';
					}
					cur_mine += mine_left;
					break;
				}
			}
			else{
				//Go horizontal
				if (mine_left > h_left){
					for (int j=cur_col; j<C;++j) {
						map[cur_row][j] = '*';
					}
					cur_row++;
					cur_mine += h_left;
				}
				else if (mine_left == h_left-1){
					for (int j=cur_col; j<C-2;++j) {
						map[cur_row][j] = '*';
					}
					cur_row++;
					cur_mine += mine_left;
					break;
				}
				else {
					for (int j=cur_col; j<cur_col+mine_left;++j){
						map[cur_row][j] = '*';
					}
					cur_mine += mine_left;
					break;
				}
			}
		
		} //while
		
		map[R-1][C-1] = 'c';
		
		int safe = R*C - M;
		cout << "Case #" << t << ":" << endl;
		if (R >= 3 && C >= 3) {
			if (safe >= 8) {
				print_map(map);
			}
			else if (safe >=3 && safe%2 == 0){
				print_map(map);
			}
			else if (safe == 1) {
				print_map(map);
			}
			else cout << "Impossible" << endl;
		}
		else if (R >= 2 && C >= 2) {
			if (safe >= 3 && safe%2 == 0){
				print_map(map);
			}
			else if (safe == 1) {
				print_map(map);
			}
			else cout << "Impossible" << endl;
		}
		else {
			if (safe >= 0) {
				print_map(map);
			}
			else cout << "Impossible" << endl;
		}	
	}
	
	return 0;
}


void print_map(vector<string> m){
	for (int i=0;i<m.size();++i){
		cout << m[i] << endl;
	}
}