#include      <algorithm>
#include      <cmath>
#include      <cstdarg>
#include      <cstdio>
#include      <cstdlib>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <set>
#include      <vector>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
typedef long long ll;
using namespace std;

enum ECorners { NONE = 0, CORNER_L, CORNER_R };

template<typename T1, typename T2> ostream& operator<<(ostream &o, const pair<T1, T2> &p) {return o << '(' << p.first << ", " << p.second << ')';}
template<typename I> ostream& print(ostream &o, I s, I e, int w = 5, int prec = 5, const string &sep = ", ", const string &lhs = "", const string &rhs = "") {
	o << lhs;
	if (s != e) o << setw(w) << setprecision(prec) << *(s++);
	for (; s != e; ++s) o << sep << setw(w) << setprecision(prec) << *s;
	return o << rhs;
}
template<typename T, template<typename E, typename A=std::allocator<E> > class C>
ostream& operator<<(ostream &o, const C<T>& c) {return print(o, c.begin(), c.end(), 0, 2, ", ", "[", "]");}
template<typename T, template<typename E, typename Compare = less<E>, typename Alloc = allocator<E> > class C>
ostream& operator<<(ostream &o, const C<T>& c) {return print(o, c.begin(), c.end(), 0, 2, ", ", "{", "}");}
template<typename K, typename T, template<typename E1, typename E2, typename Compare = std::less<E1>, class Allocator = std::allocator<std::pair<const E1, E2> > > class C>
ostream& operator<<(ostream &o, const C<K, T>& c) {return print(o, c.begin(), c.end(), 0, 2, ", ", "{", "}");}

map< pair<int, int>, double > simulate(int N) {
	const int nCeter = 50;
	const int nTop = 50;
	const int nTests = 1000000;

	map< pair<int, int>, int > mapRes;

	for (int t = 0; t < nTests; t += 1) {
		ECorners aMap[100][100];
		for (int i = 0; i < 100; i += 1) for (int j = 0; j < 100; j += 1) aMap[i][j] = NONE;

		for (int i = 0; i < N; i += 1) {
			pair<int, int> ptCur(nCeter, nTop);
			while (ptCur.second != 5) {
				if (aMap[ptCur.first][ptCur.second - 1] == CORNER_R && aMap[ptCur.first + 1][ptCur.second - 1] == CORNER_L) break;
				else if (aMap[ptCur.first][ptCur.second - 1] == CORNER_R) ptCur.first += 1;
				else if (aMap[ptCur.first + 1][ptCur.second - 1] == CORNER_L) ptCur.first -= 1;
				else if (aMap[ptCur.first][ptCur.second - 2] == CORNER_L && aMap[ptCur.first + 1][ptCur.second - 2] == CORNER_R) ptCur.first += rand() % 2 == 0 ? -1 : 1;
				ptCur.second -= 1;
			}
			aMap[ptCur.first][ptCur.second] = CORNER_L;
			aMap[ptCur.first + 1][ptCur.second] = CORNER_R;

			mapRes[make_pair(ptCur.first, ptCur.second)] += 1;
		}
	}

	map< pair<int, int>, double > mapRtn;
	each(mapRes, it) mapRtn[make_pair(it->first.first - 50, it->first.second - 5)] = it->second / (double) nTests;
	return mapRtn;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	map< pair<int, int>, double > mapRes[21];
	for (int i = 1; i <= 20; i += 1) {
		cerr << "preparing " << i << endl;
		mapRes[i] = simulate(i);
	}
	int T;
	cerr << "start " << endl;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		int n, x, y;
		cin >> n >> x >> y;
		cout << "Case #" << t << ": " << setprecision(10) << mapRes[n][make_pair(x, y)] << endl;
	}
	return 0;
}
