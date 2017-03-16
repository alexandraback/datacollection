#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

using namespace std;

int main()
{
	int N=0;
	cin >> N;
	for(int n=1;n<=N;n++) {
		vector<string> board;
		int result = 2; // draw
		for(int i=0;i<4;i++) {
			string s;
			cin >> s;
			board.push_back(s);
		}
		
		vector<string> need_judge;
		for(int i=0;i<4;i++) {
			need_judge.push_back(board[i]);
		}
		for(int i=0;i<4;i++) {
			string t;
			for(int j=0;j<4;j++) {
				if(board[j][i] == '.') {
					result = 3; //not completed
				}
				t += board[j][i];
			}
			need_judge.push_back(t);
		}
		string leftcross;
		string rightcross;
		leftcross += board[0][0];
		leftcross += board[1][1];
		leftcross += board[2][2];
		leftcross += board[3][3];
		
		rightcross += board[0][3];
		rightcross += board[1][2];
		rightcross += board[2][1];
		rightcross += board[3][0];
		
		need_judge.push_back(leftcross);
		need_judge.push_back(rightcross);
		
		int not_done = true;
		for(int i=0;i<need_judge.size() && not_done;i++) {
			string s = need_judge[i];
			string sx = need_judge[i];
			string so = need_judge[i];
			for(int j=0;j<s.length();j++) {
				if(s[j] == 'T') {
					s[j] = 'X';
					sx = s;	
					s[j] = 'O';
					so = s;	
					break;
				}
			}
			if(sx == "XXXX" && so == "OOOO") {
				result = 2;
				not_done = false;
			}else if(sx == "XXXX") {
				result = 0;
				not_done = false;
			}else if(so == "OOOO") {
				result = 1;
				not_done = false;
			}
		}
		switch(result) {
			case 0:
				cout << "Case #" << n << ": X won" << endl; break;
			case 1:
				cout << "Case #" << n << ": O won" << endl; break;
			case 2:
				cout << "Case #" << n << ": Draw" << endl; break;
			case 3:
				cout << "Case #" << n << ": Game has not completed" << endl; break;
			default:
				cout << "Case #" << n << ": Error" << endl;
		}
	}
	return 0;
}


/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
