
#include <stdio.h>
#include <time.h>

#include <vector>
#include <list>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <map>
#include <iomanip>
#include <sstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stack>
#include <numeric>
#include <complex>

using namespace std;


typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL> VL;
#define FORE(it, c, T) for(T::iterator it = c.begin(); it != c.end(); it++)
#define FORI(i, n) for(int i = 0; i < (n); i++)
#define FORIS(i, s, n) for(int i = (s); i < (n); i++)
#define CLEAR(a, n) memset(a, n, sizeof(a))
#define PB(n) push_back(n)
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(), (c).end()

#define NUM 101

int T, N;

int main(int argc, char* argv[])
{
#define TASK_NAME(file) "A"file
#define FOLDER(file) "c:\\Projects\\coding\\cj\\2013\\QualificationRound\\"TASK_NAME("")"\\"file
//	ifstream in(FOLDER(TASK_NAME("-test.in")));
//	ofstream out(FOLDER(TASK_NAME("-test.out")));
	ifstream in(FOLDER(TASK_NAME("-small-attempt0.in")));
	ofstream out(FOLDER(TASK_NAME("-small-attempt0.out")));
//	ifstream in(FOLDER(TASK_NAME("-large.in")));
//	ofstream out(FOLDER(TASK_NAME("-large.out")));

	in >> T;
	char board[5][5];
	FORI(ncase, T) {
		in >> board[0] >> board[1] >> board[2] >> board[3];
		string res = "";
		int o, x, t;
		FORI(i, 4) {
			o=0, x=0, t=0;
			FORI(j, 4) {
				if(board[i][j] == 'O') o++;
				if(board[i][j] == 'X') x++;
				if(board[i][j] == 'T') t++;
			}
			if((o+t) == 4) {
				res = "O won";
				break;
			}
			if((x+t) == 4) {
				res = "X won";
				break;
			}
			o=0, x=0, t=0;
			FORI(j, 4) {
				if(board[j][i] == 'O') o++;
				if(board[j][i] == 'X') x++;
				if(board[j][i] == 'T') t++;
			}
			if((o+t) == 4) {
				res = "O won";
				break;
			}
			if((x+t) == 4) {
				res = "X won";
				break;
			}
		}
		if(!res.length()) {
			o=0, x=0, t=0;
			FORI(j, 4) {
				if(board[j][j] == 'O') o++;
				if(board[j][j] == 'X') x++;
				if(board[j][j] == 'T') t++;
			}
			if((o+t) == 4) {
				res = "O won";
			}
			if((x+t) == 4) {
				res = "X won";
			}
		}
		if(!res.length()) {
			o=0, x=0, t=0;
			FORI(j, 4) {
				if(board[j][3-j] == 'O') o++;
				if(board[j][3-j] == 'X') x++;
				if(board[j][3-j] == 'T') t++;
			}
			if((o+t) == 4) {
				res = "O won";
			}
			if((x+t) == 4) {
				res = "X won";
			}
		}
		if(!res.length()) {
			int d = 0;
			FORI(i, 4) FORI(j, 4) {
				if(board[i][j] == '.') d++;
			}
			if(d)
				res = "Game has not completed";
			else 
				res = "Draw";
		}
		out << "Case #" << (ncase+1) << ": " << res << endl;
	}
	return 0;
}
