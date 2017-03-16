#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#define FOR(i, b, e) for (typeof(b) i = (b); i != (e); ++i)
#define VAR(a,b) typeof(b) a=b
#define dout cout
using namespace std;
typedef long long LL;


void run(int Case)
{
	string r[10];
	int c=4;
	int d=8;
	int rd=9;
	FOR(i,0,4){
		cin >> r[i];
		FOR(j,0,4){
			r[c+j]+=r[i][j];
		}
		r[d]+=r[i][i];
		r[rd]+=r[i][3-i];
	}


	cout << "Case #" << Case << ": ";
	int dot=0;
	FOR(i,0,10){
		int x=0;
		int o=0;
		int t=0;
		FOR(j,0,4){
			switch(r[i][j]){
				case 'X':
					x++;
					break;
				case 'O':
					o++;
					break;
				case 'T':
					t++;
					break;
				case '.':
					dot++;
					break;
			}
		}
		if (x+t==4){
			cout << "X won" << endl;
			return;
		}
		if (o+t==4){
			cout << "O won" << endl;
			return;
		}
	}

	if (dot==0){
		cout << "Draw" << endl;
		return;
	}

	cout << "Game has not completed" << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t=1;t<=T;t++) {
		run(t);
	}
}
