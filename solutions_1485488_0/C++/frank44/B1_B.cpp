#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef long long Long;
typedef unsigned long long uLong;

const double PI = acos(-1.0);
const double EPS = 1e-12;

#define FOR(i,a,b) for (int i=(int)(a); i<(int)(b); ++i)
#define DEBUG false

const int MAX = 1024;
int H, N, M ;
int C[MAX][MAX];
int F[MAX][MAX];
bool mark[MAX][MAX];

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

struct State
{
	int i, j;
	double time;

	State(int I, int J, double TIME)
	{ i = I; j = J; time = TIME; }

	bool operator<(const State & b) const
	{ return time > b.time; } //invert

	string toStr()
	{
		stringstream ss;
		ss << "(" << i << ", " << j << ") :: " << time;
		return ss.str();
	}
};

bool isValid(int i, int j)
{ return i >= 0 && i < N && j >= 0 && j < M; }

bool can(int si, int sj, int ei, int ej, double time) //can go rigth this instant
{
	double sC = C[si][sj];
	double eC = C[ei][ej];
	
	double sF = F[si][sj];
	double eF = F[ei][ej];

	double waterLevel = H - time*10;

	bool ok1 = waterLevel + 50 <= eC;
	bool ok2 = sF + 50 <= eC;
	bool ok3 = eF + 50 <= eC;
	bool ok4 = eF + 50 <= sC;

	return ok1 && ok2 && ok3 && ok4;
}

bool when(int si, int sj, int ei, int ej, double & time, double curWL) //when can I go?
{
	double sC = C[si][sj];
	double eC = C[ei][ej];
	
	double sF = F[si][sj];
	double eF = F[ei][ej];

	bool ok2 = sF + 50 <= eC;
	bool ok3 = eF + 50 <= eC;
	bool ok4 = eF + 50 <= sC;
	
	if (!ok2 || !ok3 || !ok4) return false;

	time = (curWL - eC + 50)/10;
	time = max(time, 0.0);

	return true;
}

void fill_mark() //BFS
{
	fill(*mark, *mark + MAX*MAX, false);
	
	queue< pair<int, int> > q;
	q.push( make_pair(0, 0) );
	mark[0][0] = true;

	while (!q.empty())
	{
		pair<int, int> c = q.front();
		q.pop();

		for (int k=0; k<4; k++)
		{
			int ni = c.first + di[k];
			int nj = c.second + dj[k];
			if (isValid(ni, nj) && !mark[ni][nj] && can(c.first, c.second, ni, nj, 0))
			{
				mark[ni][nj] = true;
				q.push(make_pair(ni, nj));
			}
		}
	}
}

double solve() //Dijkstra's
{
	cin >> H >> N >> M;

	FOR(i,0,N) FOR(j,0,M) cin >> C[i][j];
	FOR(i,0,N) FOR(j,0,M) cin >> F[i][j];

	fill_mark();

	priority_queue< State > pq;

	if (DEBUG) cout << "Initial states:\n";
	FOR(i,0,N)
		FOR(j,0,M)
		{
			if (mark[i][j]) pq.push(State(i,j,0));
			if (DEBUG) cout << i << "-" << j << endl;
		}

	fill(*mark, *mark + MAX*MAX, false); //reset seen

	while (!pq.empty())
	{
		State c = pq.top();
		pq.pop();

		if (mark[c.i][c.j]) continue;
		else mark[c.i][c.j] = true;

		if (DEBUG) cout << c.toStr() << endl;

		if (c.i == N-1 && c.j == M-1) return c.time;

		for (int k=0; k<4; k++)
		{
			int ni = c.i + di[k];
			int nj = c.j + dj[k];
			double deltaT = 0;
			if (isValid(ni, nj) && !mark[ni][nj] && when(c.i, c.j, ni, nj, deltaT, H-10*c.time))
			{
				double cost = (H-10*(c.time + deltaT) >= 20 + F[c.i][c.j]) ? 1 : 10;
				pq.push( State(ni, nj, c.time + deltaT + cost) );
			}
		}
	}

	return -1.0;
}

int main()
{
	freopen("data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;
	for (int x=1; x<=T; x++) 
		printf("Case #%d: %.10llf\n", x, solve());

	return 0;
}
