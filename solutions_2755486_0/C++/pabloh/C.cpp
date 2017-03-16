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

struct tribe
{
	int d, n, w, e, s, dd, dp, ds;
};
inline istream & operator>>(istream & is, tribe & t) { 
	is >> t.d >> t.n >> t.w >> t.e >> t.s >> t.dd >> t.dp >> t.ds;
	return is;
}

long long solve_case(/*const*/ vector<tribe> & ts)
{
	priority_queue< pair<int, size_t> > q; //-day, tribe index
	const size_t n = ts.size();
	FOR(i, n) {
		tribe & t = ts[i];
		assert(t.n > 0);
		q.push(make_pair(-t.d,i));
	}
	vector<int> wall(20001);
	vector< pair<int,int> > changes; //pos, value
	long long result = 0;
	while(!q.empty()){
		int day = q.top().first;
		while (!q.empty() && q.top().first == day) {
			size_t idx = q.top().second; q.pop();
			tribe & t = ts[idx]; 
			assert(-t.d == day);
			bool suc = false;
//			for (int i = t.w; i <= t.e; ++i) {
			for (int i = t.w; i < t.e; ++i) {
				if (wall[i+10000] < t.s) {
					suc = true;
					changes.push_back(make_pair(i,t.s));
				}
			}
			t.n--;
			if (t.n) {
				t.d += t.dd;
				t.w += t.dp;
				t.e += t.dp;
				t.s += t.ds;
				q.push(make_pair(-t.d, idx));
			}
			if (suc) ++result;
		}
		while(!changes.empty()) {
			int i = changes.back().first;
			int s = changes.back().second;
			wall[i+10000] = max(wall[i+10000],s);
			changes.pop_back();
		}
	}
	return result;
}



void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		int N;
		in >> N;
		vector<tribe> ts(N);
		FOR(i,N) in >> ts[i];


		long long result = solve_case(ts);
		out << "Case #" << t << ": " << result << endl;
	}
}


int main()
{
	//ifstream in("C-sample.in");
	//ofstream out("C-sample-out.txt");

	ifstream in("C-small-attempt0.in");
	ofstream out("C-small-out.txt");

	//ifstream in("C-large.in");
	//ofstream out("C-large-out.txt");

	solve(in,out);


	return 0;
}
