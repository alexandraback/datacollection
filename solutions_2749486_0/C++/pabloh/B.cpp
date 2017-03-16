#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
//download TTMath from http://www.ttmath.org/
//#include <ttmath/ttmath.h>
#undef max
#undef min

using namespace std;
//using namespace ttmath;

#define metafor(iter,container) \
	for ((iter) = (container).begin(); (iter) != (container).end(); ++(iter))
#define FOR(i,n) for (size_t i = 0; i < (n); ++i)
#define FORi(i,n) for (int i = 0; i < (n); ++i)
template<class C>
void show(const C & v) { FOR(i,v.size()) cout << v[i] << ' '; cout << endl; }

typedef int dir;
const char let[] = { '?', 'N', 'S', 'E', 'W' };
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };
const dir move[] = { 1, 2, 3, 4 };
const dir move2revdir[] = { -1, 1, 0, 3, 2 };

const int N = 1000;
vector< vector< pair<dir,int> > > lastmove(2*N+1, vector< pair<dir,int> >(2*N+1));
inline ostream & operator<<(ostream & os, const pair<dir,int> & p) { os << let[p.first]; return os; } 
typedef pair<int,int> pos;
void comp()
{
	queue< pair<pos,int> > q; //jump size
	q.push( make_pair(pos(0,0), 1) );
	while(!q.empty()) {
		pair<pos,int> pp = q.front(); q.pop();
		pos p = pp.first;
		int jmp = pp.second;
		for (int d = 0; d < 4; ++d) {
			pos r = pos(p.first + jmp*dx[d], p.second + jmp*dy[d]);
			int x = r.first+N;
			int y = r.second+N;
			if (0 <= x && x <= 2*N && 0 <= y && y <= 2*N) {
				if (lastmove[y][x].first == 0) {
					lastmove[y][x] = make_pair(move[d],jmp);
					q.push( make_pair(r,jmp+1) );
				}
			}
		}
	}
}

string solve_case(const int X, const int Y)
{
	int x = X+N, y = Y+N;
	string res;
	while ( !(x==N && y == N) ) {
		dir d = lastmove[y][x].first; 
		int jmp = lastmove[y][x].second;
		res += let[d];
		assert(move2revdir[d] != -1);
		x += dx[move2revdir[d]]*jmp;
		y += dy[move2revdir[d]]*jmp;
		assert(0 <= x && x <= 2*N && 0 <= y && y <= 2*N);
	}
	reverse(res.begin(), res.end());
	return res;
}

void solve(istream & in, ostream & out)
{
	comp();
	//FOR(i,lastmove.size())
	//	show(lastmove[i]);



	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		int X, Y;
		in >> X >> Y;

		string result = solve_case(X,Y);
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//ifstream in("B-sample.in");
	//ofstream out("B-sample-out.txt");

	ifstream in("B-small-attempt0.in");
	ofstream out("B-small-out.txt");

	//ifstream in("B-large.in");
	//ofstream out("B-large-out.txt");

	solve(in,out);

	return 0;
}
