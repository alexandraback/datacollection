#include<sys/types.h>
#include<dirent.h>

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<fstream>
#include<map>
#include<set>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define lt(x, y)	((x) >= 0 && ((x) < (y) || (y) < 0))

#define SWAP(x, y) {(x) += (y); (y) = (x) - (y); (x) -= (y);}

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

int ncase, R, C;

int x[100][100];

int Rma[100], Cma[100];

string Ans[] = {"NO", "YES"};

int main()
{
	scanf("%d", &ncase);


	for(int caseidx = 1; caseidx <= ncase; caseidx++){

		scanf("%d %d", &R, &C);

		for(int r = 0; r < R; r++){
			Rma[r] = 0;

			for(int c = 0; c < C; c++){

				scanf("%d", &x[r][c]);
				Rma[r] = MAX(Rma[r], x[r][c]);
			}
		}

		for(int c = 0; c < C; c++){
			Cma[c] = 0;
			for(int r = 0; r < R; r++){
				Cma[c] = MAX(Cma[c], x[r][c]);
			}
		}

		int ans = 1;
		for(int r = 0; r < R; r++){
			for(int c = 0; c < C; c++){
				if(x[r][c] < MIN(Rma[r], Cma[c])){
					ans = 0;
					goto end;
				}
			}
		}

end:

		printf("Case #%d: %s\n", caseidx, Ans[ans].c_str());
	}

	return 0;
}

// vi: ts=2 sw=2
