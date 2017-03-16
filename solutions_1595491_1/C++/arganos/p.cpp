/*
ID: enggi231
LANG: C++
PROG: 
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long

using namespace std;

fstream out;

int g[31][4][4]; //g[score][#][field]
int cnt[31];

int main()
{
	fstream in("in.txt", ios_base::in);
	
	
	for (int i = 0; i <= 30; i++)
		for (int c = 0; c <= 10; c++)
			for (int b = c; b <= 10; b++) {
				int a = i-b-c;
				if ((a > 10) || (a < 0) || (a < b) || (a-c > 2))
					continue;
				g[i][cnt[i]][0] = a;
				g[i][cnt[i]][1] = b;
				g[i][cnt[i]][2] = c;
				g[i][cnt[i]][3] = (a-c == 2);
				cnt[i]++;
			}
	/*for (int i = 0; i < 31; i++)
		for (int j = 0; j < cnt[i]; j++) {
			cout << i << " " << j << "   ";
			for (int l = 0; l < 4; l++)
				cout << g[i][j][l] << " ";
			cout << endl;
		}*/
	int t, n, s,p,  d[201];
	in >> t;
	
	for (int v = 1; v <= t; v++ ) {
		in >> n >> s >> p;
		memset(d, 0, 400);
		int j = 0;
		for (int i = 0; i < n; i++) {
			in >> d[j];
			if ((g[d[j]][0][0] >= p) || (g[d[j]][0][1] >= p))
				j++;
		}
		int sure = 0, unsure = 0;
		for (int i = 0; i < j; i++) {
			if (((g[d[i]][0][0] >= p) && (g[d[i]][0][3] == 0)) ||
				((g[d[i]][1][0] >= p) && (g[d[i]][1][3] == 0)))
				sure++;
			else
				unsure++;
		}
		cout << "Case #"<< v<< ": " << sure +min(s, unsure) << endl;
	}

	return 0;
}

