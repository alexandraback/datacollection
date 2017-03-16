#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int T;

int main()
{
    fstream fin("A-small-attempt0.in",ifstream::in);
    fstream fout("A-small-attempt0.out",ofstream::out);
    fin >> T;
	vector<string> board(4);
    for(int tc=1;tc<=T;tc++)
    {
        rep(i,4) fin >> board[i];
		int result = 0;
		int countdot = 0;
		rep(i,4)
		{
			int countx = 0;
			int counto = 0;
			int countt = 0;
			rep(j, 4)
				if (board[i][j]=='X') countx++;
				else if (board[i][j]=='O') counto++;
				else if (board[i][j]=='T') countt++;
				else countdot++;
			if (countx==4 || (countx==3 && countt==1)) result = 1;
			if (counto==4 || (counto==3 && countt==1)) result = 2;
		}

		rep(i,4)
		{
			int countx = 0;
			int counto = 0;
			int countt = 0;
			rep(j, 4)
				if (board[j][i]=='X') countx++;
				else if (board[j][i]=='O') counto++;
				else if (board[j][i]=='T') countt++;
			if (countx==4 || (countx==3 && countt==1)) result = 1;
			if (counto==4 || (counto==3 && countt==1)) result = 2;
		}

		int countx = 0;
		int counto = 0;
		int countt = 0;
		rep(i,4)
			if (board[i][i]=='X') countx++;
				else if (board[i][i]=='O') counto++;
				else if (board[i][i]=='T') countt++;
		if (countx==4 || (countx==3 && countt==1)) result = 1;
		if (counto==4 || (counto==3 && countt==1)) result = 2;

		countx = 0;
		counto = 0;
		countt = 0;
		rep(i,4)
			if (board[i][3-i]=='X') countx++;
				else if (board[i][3-i]=='O') counto++;
				else if (board[i][3-i]=='T') countt++;
		if (countx==4 || (countx==3 && countt==1)) result = 1;
		if (counto==4 || (counto==3 && countt==1)) result = 2;

		if (countdot==0 && result==0) result = 3;

        if (result==0) fout << "Case #" << tc << ": Game has not completed\n";
		else if (result==1) fout << "Case #" << tc << ": X won\n";
		else if (result==2) fout << "Case #" << tc << ": O won\n";
		else fout << "Case #" << tc << ": Draw\n";
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC << "\n";
    system("PAUSE");
    return 0;
}
