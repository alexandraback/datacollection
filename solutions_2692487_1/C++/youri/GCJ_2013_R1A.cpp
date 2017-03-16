/* A */


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long LL;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second

#define DEBUG 0

void solve(int c, FILE * fin, FILE * fout)
{
	int A, n;
	int mots[110];
	fscanf(fin, "%d %d", &A, &n);
	REP(i, n)
	{
		fscanf(fin, "%d ",&mots[i]);
	}
	vector<int> moty(mots, mots + n);
	sort(moty.begin(), moty.end(), greater<int>());

	int min = 1000000000;
	int cur_add = 0;

	if(A == 1)
	{
		cur_add = moty.size();
	}
	else
	{
		while(!moty.empty())
		{
			int rs = cur_add + moty.size();
			//printf("%d\n",  rs);
			min = MIN(min, rs);

			int cand = moty.back();

			while(A <= cand)
			{
				int addon = A-1;
				A += addon;
				cur_add++;
			}

			A += cand;

			moty.pop_back();
		}
	}
	//printf("or %d\n",  cur_add);
	min = MIN(min, cur_add);

	fprintf(fout, "Case #%d: %d\n", c, min);

}

int main() {

	FILE *fin, *fout;

	fin = fopen("temp.in", "r");
	fout = fopen("temp.out", "w");

	int cases;
	fscanf(fin, "%d", &cases);
	REP(i, cases)
	{
		solve(i + 1, fin, fout);
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
