#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

int main(int argc, const char **argv){
	ifstream input;
	ofstream output;
	input.open(argv[1]);
	output.open(argv[2]);
	if(!input.is_open() || !output.is_open()){
		exit(0);	
	}
	int numcase;
	input >> numcase;
	for(int i = 0; i < numcase; i ++){
		int M, N;
		input >> N >> M;
		short board[N][M];
		vector<short> emprow;
		vector<vector<short> > mapx(100, emprow);
		vector<vector<short> > mapy(100, emprow);
		bool isPoss = true;
		for(int j = 0; j < N; j ++){
			for(int k = 0; k < M; k ++){
				input >> board[j][k];
				mapx[board[j][k] - 1].push_back(j);
				mapy[board[j][k] - 1].push_back(k);
			}
		}
		for(int j = 0; j < mapx.size(); j ++){
			for(int k = 0; k < mapx[j].size(); k ++){
				if(board[mapx[j][k]][mapy[j][k]] != -1){
					
					bool isline = true;
					for(int l = 0; l < N; l ++){
						if(board[l][mapy[j][k]] > j + 1){
							isline = false;
						}
						else if(board[l][mapy[j][k]] != -1 && board[l][mapy[j][k]] < j + 1){
							isPoss = false;
						}
					}
					if(isline){
						for(int l = 0; l < N; l ++){
							if(board[l][mapy[j][k]] == j + 1){
								board[l][mapy[j][k]] = -1;
							}
						}
					}
					isline = true;
					for(int l = 0; l < M; l ++){
						if(board[mapx[j][k]][l] > j + 1){
							isline = false;
						}
						else if(board[mapx[j][k]][l] != -1 && board[mapx[j][k]][l] < j + 1){
							isPoss = false;
						}
					}
					if(isline){
						for(int l = 0; l < M; l ++){
							if(board[mapx[j][k]][l] == j + 1){
								board[mapx[j][k]][l] = -1;
							}
						}
					}
				}
			}	
		}
		if(isPoss){
			for(int j = 0; j < N; j ++){
				for(int k = 0; k < M; k ++){
					if(board[j][k] != -1){
						isPoss = false;
					}
				}
			}
		}
		string result;
		if(isPoss){
			result = "YES";		
		}
		else{
			result = "NO";
		}
		output << "Case #" << i + 1 << ": " << result << endl;
	}
	input.close();
	output.close();
	return 0;
}
