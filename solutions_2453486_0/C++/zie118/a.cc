#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>
#include <sstream>
#include <bitset>

using namespace std;

#define inf (1<<29)
#define eps (1e-9)

#define flt(x,y) ((x)<(y)-eps)
#define fgt(x,y) flt(y,x)
#define fle(x,y) !fgt(x,y)
#define fge(x,y) !flt(x,y)
#define feq(x,y) (fabs((x)-(y))<eps)

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


int main()
{
	int T; scanf("%d", &T);
	char dump[1000], a[10][10];
	for (int cc = 1; cc <= T; cc++)
	{
		gets(dump);
		for (int i = 0; i < 4; i++) gets(a[i]);
		int status = 0, empty = 0, ti = -1, tj;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				if (a[i][j] == '.') empty++;
				else if (a[i][j] == 'T') { ti = i; tj = j; }
			if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][2] == a[i][3])
				if (a[i][0] == 'X') status = 1;
				else if (a[i][0] == 'O') status = 2;
			if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[2][i] == a[3][i])
				if (a[0][i] == 'X') status = 1;
				else if (a[0][i] == 'O') status = 2;
		}
		if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[2][2] == a[3][3])
			if (a[0][0] == 'X') status = 1;
			else if (a[0][0] == 'O') status = 2;
		if (a[0][3] == a[1][2] && a[1][2] == a[2][1] && a[2][1] == a[3][0])
			if (a[0][3] == 'X') status = 1;
			else if (a[0][3] == 'O') status = 2;

		if (ti != -1)
		{

			a[ti][tj] = 'X';
			if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[2][2] == a[3][3])
				if (a[0][0] == 'X') status = 1;
			if (a[0][3] == a[1][2] && a[1][2] == a[2][1] && a[2][1] == a[3][0])
				if (a[0][3] == 'X') status = 1;
			if (a[ti][0] == a[ti][1] && a[ti][1] == a[ti][2] && a[ti][2] == a[ti][3])
				if (a[ti][0] == 'X') status = 1;
			if (a[0][tj] == a[1][tj] && a[1][tj] == a[2][tj] && a[2][tj] == a[3][tj])
				if (a[0][tj] == 'X') status = 1;

			a[ti][tj] = 'O';
			if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[2][2] == a[3][3])
				if (a[0][0] == 'O') status = 2;
			if (a[0][3] == a[1][2] && a[1][2] == a[2][1] && a[2][1] == a[3][0])
				if (a[0][3] == 'O') status = 2;
			if (a[ti][0] == a[ti][1] && a[ti][1] == a[ti][2] && a[ti][2] == a[ti][3])
				if (a[ti][0] == 'O') status = 2;
			if (a[0][tj] == a[1][tj] && a[1][tj] == a[2][tj] && a[2][tj] == a[3][tj])
				if (a[0][tj] == 'O') status = 2;
		}

		if (status == 1) printf ("Case #%d: X won\n", cc);
		else  if (status == 2) printf("Case #%d: O won\n", cc);
		else if (status == 0 && empty) printf("Case #%d: Game has not completed\n", cc);
		else if (status == 0 && empty == 0) printf("Case #%d: Draw\n", cc);
	}
	return 0;
}
