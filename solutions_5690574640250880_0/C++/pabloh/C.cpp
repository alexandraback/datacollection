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

const string Impossible("Impossible");
const char click = 'c';
const char empty = '.';
const char mine = '*';

ostream& operator<< (ostream& os, const vector<string> & v)
{
	FOR(i,v.size()) os << v[i] << (i == v.size()-1 ? "" : "\n");
	return os;
}

vector<string> transpose(const vector<string> & v)
{
	const size_t R = v.size();
	const size_t C = v[0].size();
	vector<string> result(C,string(R,' '));
	FOR(i,R) FOR(j,C) result[j][i] = v[i][j];
	return result;
}
vector<string> solve_case(int R, int C, int M)
{
	int F = R*C-M;
	if (F == 0) return vector<string>(1,Impossible);
	if (F == 1) {
		vector<string> result(R,string(C,mine));
		result[0][0] = click;
		return result;
	}
	if (M == 0) {
		vector<string> result(R,string(C,empty));
		result[0][0] = click;
		return result;
	}
	if (min(R,C) == 1) {
		int k = max(R,C);
		string s; s += click + string(k-M-1,empty) + string(M,mine);
		assert(s.size() == k);
		vector<string> result(1,s);
		if (R==1)
			return result;
		else
			return assert(C==1),transpose(result);
	}
	if (F == 2) return vector<string>(1,Impossible);
	if (min(R,C) == 2) {
		if (M % 2 == 0) {
			int k = max(R,C);
			string s = string(k-M/2,empty) + string(M/2,mine);
			assert(s.size() == k);
			vector<string> result(2,s);
			result[0][0] = click;
			if (R==2)
				return result;
			else
				return assert(C==2),transpose(result);
		}
		else
			return vector<string>(1,Impossible);
	}
	assert(R >= 3 && C >= 3);
	if (F == 3) return vector<string>(1,Impossible);
	if (F == 4) {
		vector<string> result(R,string(C,mine));
		result[0][0] = click;
		result[0][1] = empty;
		result[1][0] = empty;
		result[1][1] = empty;
		return result;
	}
	if (F == 5) return vector<string>(1,Impossible);
	if (F == 6) {
		vector<string> result(R,string(C,mine));
		result[0][0] = click;
		result[0][1] = empty;
		result[1][0] = empty;
		result[1][1] = empty;
		result[2][0] = empty;
		result[2][1] = empty;
		return result;
	}
	if (F == 7) return vector<string>(1,Impossible);
	if (min(R,C) == 3) {
		int k = max(R,C);
		string s = string(F/3,empty) + string(k-F/3,mine);
		assert(s.size() == k);
		vector<string> result(3,s);
		result[0][0] = click;
		if (F % 3 == 0) {
			//skip;
		} else if (F % 3 == 2) {
			result[0][F/3] = empty;
			result[1][F/3] = empty;
		} else {
			result[0][F/3] = empty;
			result[2][F/3-1] = mine;
			result[1][F/3] = empty;
		}
		if (R==3)
			return result;
		else
			return assert(C==3),transpose(result);
	}
	assert(F >= 8 && R >= 4 && C >= 4);
	if (F <= 2*min(R,C)) {
		int r = min(R,C);
		int k = max(R,C);
		vector<string> result(r,string(k,mine));
		FOR(i,F/2-1) {
			result[i][0] = empty;
			result[i][1] = empty;
		}
		if (F % 2 == 0) {
			result[F/2-1][0] = empty;
			result[F/2-1][1] = empty;
		} else {
			result[0][2] = empty;
			result[1][2] = empty;
			result[2][2] = empty;
		}
		result[0][0] = click;
		if (R==r)
			return result;
		else
			return assert(C==r),transpose(result);
	} else if (F <= 3*min(R,C)) {
		int r = min(R,C);
		int k = max(R,C);
		int c = F/r;
		string s = string(c,empty) + string(k-c,mine);
		vector<string> result(r,s);
		assert(c >= 2);
		if (F % r == 1) {
			result[r-1][c-2] = mine;
			result[r-1][c-1] = mine;
			result[0][c] = empty;
			result[1][c] = empty;
			result[2][c] = empty;
		} else {
			FOR(i,F%r) result[i][c] = empty;
		}
		result[0][0] = click;
		if (R==r)
			return result;
		else
			return assert(C==r),transpose(result);
	} else {
		int r = min(R,C);
		int k = max(R,C);
		int c = F/r;
		string s = string(c,empty) + string(k-c,mine);
		vector<string> result(r,s);
		assert(c >= 2);
		if (F % r == 1) {
//			result[r-1][c-2] = mine;
			result[r-1][c-1] = mine;
			result[0][c] = empty;
			result[1][c] = empty;
//			result[2][c] = empty;
		} else {
			FOR(i,F%r) result[i][c] = empty;
		}
		result[0][0] = click;
		if (R==r)
			return result;
		else
			return assert(C==r),transpose(result);
	}
}



void solve(istream & in, ostream & out)
{
	int TC_NCases;
	in >> TC_NCases;
	out.precision(18);
	out.setf(std::ios_base::fixed, std::ios_base::floatfield);
	for (int t = 1; t <= TC_NCases; ++t)
	{
		int R, C, M;
		in >> R >> C >> M;

		vector<string> result = solve_case(R,C,M);
		assert(result.size() == 1 && result[0] == Impossible || result.size() == R);
		out << "Case #" << t << ":\n" << result << endl;
	}
}


int main()
{
	//ifstream in("C-sample.in");
	//ofstream out("C-sample-out.txt");

	//ifstream in("C-small-attempt0.in");
	ifstream in("C-small-attempt1.in");
	ofstream out("C-small-out.txt");

	//ifstream in("C-large.in");
	//ofstream out("C-large-out.txt");

	solve(in,out);


	return 0;
}
