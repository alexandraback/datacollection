#include<iostream>
#include<fstream>
using namespace std;

#define MAX 4
ofstream out;

void solve(char arr[][MAX], int total_filled) {
	int O_wins = 4, X_wins = 4;

	for(int i = 0; i < MAX; ++i) {
		for(int j = 0; j < MAX; ++j) {
			if(arr[i][j] == 'O') O_wins--;
			else if(arr[i][j] == 'X') X_wins--;
			else if(arr[i][j] == 'T') {
				O_wins--;
				X_wins--;
			}
		}
		if(O_wins == 0){
			out<<"O won"<<endl;
			return;
		}
		else if(X_wins == 0) {
			out<<"X won"<<endl;
			return;
		}
		O_wins = 4;
		X_wins = 4;
	}

	for(int i = 0; i < MAX; ++i) {
		for(int j = 0; j < MAX; ++j) {
			if(arr[j][i] == 'O') O_wins--;
			else if(arr[j][i] == 'X') X_wins--;
			else if(arr[j][i] == 'T') {
				O_wins--;
				X_wins--;
			}
		}
		if(O_wins == 0) {
			out<<"O won"<<endl;
			return;
		}
		else if(X_wins == 0) {
			out<<"X won"<<endl;
			return;
		}
		O_wins = 4;
		X_wins = 4;
	}


	for(int i = 0; i < MAX; ++i) {
		if(arr[i][i] == 'O') O_wins--;
		else if(arr[i][i] == 'X') X_wins--;
		else if(arr[i][i] == 'T') {
			O_wins--;
			X_wins--;
		}
	}

	if(O_wins == 0) {
		out<<"O won"<<endl;
		return;
	}
	else if(X_wins == 0) {
		out<<"X won"<<endl;
		return;
	}

	O_wins = 4;
	X_wins = 4;

	for(int i = 0; i < MAX; ++i) {
		if(arr[i][MAX - i -1] == 'O') O_wins--;
		else if(arr[i][MAX - i -1] == 'X') X_wins--;
		else if(arr[i][MAX - i -1] == 'T') {
			O_wins--;
			X_wins--;
		}
	}

	if(O_wins == 0) {
		out<<"O won"<<endl;
		return;
	}
	else if(X_wins == 0) {
		out<<"X won"<<endl;
		return;
	}
	if(total_filled < 16) {
		out<<"Game has not completed"<<endl;
		return;
	}
	else {
		out<<"Draw"<<endl;
		return;
	}
}

int main() {
	ifstream in;

	in.open("A-large.in");
	out.open("output.txt");
	int T;
	char arr[MAX][MAX];

	in>>T;
	int total_filled = 0;
	for(int k = 0; k < T; ++k) {
		total_filled = 16;
		out<<"Case #"<<k+1<<": ";

		for(int i = 0; i < MAX; ++i) {
			for(int j = 0; j < MAX; ++j) {
				in>>arr[i][j];
				if(arr[i][j] == '.')
					total_filled--;
			}
		}
		solve(arr, total_filled);
	}

	in.close();
	out.close();
	return 0;
}
