#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct MyPair {
	int x, y;
	MyPair(int n1, int n2) { x = n1, y = n2; }
};

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		int N, X, Y;
		fin >> N >> X >> Y;
		vector<vector<MyPair> > states;
		vector<MyPair> iState;
		iState.push_back(MyPair(0, 0));
		states.push_back(iState);
		for (int n = 1; n < N; n++) {
			vector<vector<MyPair> > newStates;
			for (int s = 0; s < states.size(); s++) {
				int collideD = -1;
				for (int d = states[s].size()-1; collideD == -1; d--) {
					if (states[s][d].x == 0) collideD = d;
				}


				int closestRightD = -1;
				bool rightBlocked = 0;
				for (int curY = states[s][collideD].y + 1, curX = states[s][collideD].x+1; curY >= 0 && closestRightD == -1; curY--, curX++) {
					for (int d = states[s].size()-1; d >= 0 && closestRightD == -1; d--) {
						if (curY == states[s][d].y && curX == states[s][d].x) closestRightD = d;
					}
				}
				if (closestRightD != -1 && states[s][closestRightD].y > states[s][collideD].y) rightBlocked = 1;


				int closestLeftD = -1;
				bool leftBlocked = 0;
				for (int curY = states[s][collideD].y + 1, curX = states[s][collideD].x-1; curY >= 0 && closestLeftD == -1; curY--, curX--) {
					for (int d = states[s].size()-1; d >= 0 && closestLeftD == -1; d--) {
						if (curY == states[s][d].y && curX == states[s][d].x) closestLeftD = d;
					}
				}
				if (closestLeftD != -1 && states[s][closestLeftD].y > states[s][collideD].y) leftBlocked = 1;


				if (leftBlocked && rightBlocked) {
					states[s].push_back(MyPair(0, states[s][collideD].y+2));
					newStates.push_back(states[s]);
				}
				else if (leftBlocked) {
					if (closestRightD == -1) states[s].push_back(MyPair(states[s][collideD].y+2, 0));
					else states[s].push_back(MyPair(states[s][closestRightD].x-1, states[s][closestRightD].y+1));
					newStates.push_back(states[s]);
				}
				else if (rightBlocked) {
					if (closestLeftD == -1) states[s].push_back(MyPair(-states[s][collideD].y-2, 0));
					else states[s].push_back(MyPair(states[s][closestLeftD].x+1, states[s][closestLeftD].y+1));
					newStates.push_back(states[s]);
				}
				else {
					vector<MyPair> temp = states[s];
					if (closestRightD == -1) states[s].push_back(MyPair(states[s][collideD].y+2, 0));
					else states[s].push_back(MyPair(states[s][closestRightD].x-1, states[s][closestRightD].y+1));
					newStates.push_back(states[s]);
					if (closestLeftD == -1) temp.push_back(MyPair(-states[s][collideD].y-2, 0));
					else temp.push_back(MyPair(states[s][closestLeftD].x+1, states[s][closestLeftD].y+1));
					newStates.push_back(temp);
				}
			}
			states = newStates;
		}
		double total = 0;
		for (int s = 0; s < states.size(); s++) {
			for (int d = 0; d < states[s].size(); d++) {
				if (states[s][d].x == X && states[s][d].y == Y) {
					total++;
					break;
				}
			}
		}
		double res = total / states.size();
		fout.setf(ios::fixed);
		fout.precision(8);
		cout << t << endl;
		fout << "Case #" << t << ": " << res << endl;
	}
}