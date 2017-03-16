#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <math.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define loop(i,n) for(int i=0; i<(n); i++)
#define tr(it,c) for(it=(c).begin(); it!=(c).end(); it++)
#define tr2(it1,c,it2,d) for(it1=(c).begin(),it2=(d).begin(); it1!=(c).end(); it1++,it2++)

bool getResult(int R, int C, int E, vvi &X)
{
	X.resize(R, vi(C, 1));
	if (E == 1) {
		X[0][0] = 0;
		return true;

	} else if (C == 1) {
		for (int i = 0; i < R; i++) {
			if (i < E) {
				X[i][0] = 0;
			}
		}
		return true;

	} else if (C == 2) {
		if (E ==2 || E % 2 == 1) {
			return false;
		} else {
			for (int i = 0; i < R; i++) {
				if (i < E/2) {
					X[i][0] = X[i][1] = 0;
				}
			}
			return true;
		}

	} else {
		if (E == 2 || E == 3 || E == 5 || E == 7) {
			return false;

		} else {
			if (E <= 2*C+1) {
				int firstTwoRow, thirdRow;
				if (E % 2 == 1) {
					firstTwoRow = (E - 3) / 2;
					thirdRow = 3;
				} else {
					firstTwoRow = E / 2;
					thirdRow = 0;
				}
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < firstTwoRow; j++) {
						X[i][j] = 0;
					}
				}
				for (int j = 0; j < thirdRow; j++) {
					X[2][j] = 0;
				}

			} else {
				int rowCount = E / C;
				int lastRow = E % C;
				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < C; j++) {
						X[i][j] = 0;
					}
				}
				if (lastRow == 1) {
					X[rowCount-1][C-1] = 1;
					lastRow = 2;
				}
				for (int j = 0; j < lastRow; j++) {
					X[rowCount][j] = 0;
				}
			}

			return true;
		}
	}
}

vs solve(int R, int C, int M)
{
	int vR = R, vC = C;
	if (R < C) {
		swap(vR, vC);
	}
	vvi X;
	bool result = getResult(vR, vC, R*C-M, X);
	vs answer(1, string());
	if (!result) {
		answer.push_back("Impossible");
	} else {
		for (int i = 0; i < R; i++) {
			string newLine;
			newLine.resize(C);
			for (int j = 0; j < C; j++) {
				int mine = R>=C ? X[i][j] : X[j][i];
				newLine[j] = mine==1 ? '*' : '.';
			}
			answer.push_back(newLine);
		}
		answer[1][0] = 'c';
	}
	return answer;
}

void preprocess(){}

void readinput(int &R, int &C, int &M)
{
	cin>>R>>C>>M;
}

vs getoutput()
{
	int R, C, M;
	readinput(R, C, M);
	return solve(R, C, M);
}

void main()
{
//	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
//	freopen("test\\C-small-attempt0.in", "r", stdin);freopen("test\\C-small-attempt0.out", "w", stdout);
	freopen("test\\C-large.in", "r", stdin);freopen("test\\C-large.out", "w", stdout);
	int testcase;
	cin>>testcase;
	preprocess();
	for(int i=1; i<=testcase; i++)
	{
		cout<<"Case #"<<i<<": ";
		vs answer = getoutput();
		loop(j, sz(answer))
			cout<<answer[j]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}