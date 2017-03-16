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

template<typename T1, typename T2> ostream& operator<<(ostream &o, const pair<T1, T2> &p) {return o << '(' << p.first << ", " << p.second << ')';}
template<typename I> ostream& print(ostream &o, I s, I e, int w = 5, int prec = 2, const string &sep = ", ", const string &lhs = "", const string &rhs = "") {
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

ll A;
int N;

int nTest(int nStart, ll &Atmp, vector<ll> &vect, ll nNew) {
	while (nStart < (int)vect.size() && vect[nStart] < Atmp) {
		Atmp += vect[nStart];
		if (nNew != -1) vect[nStart] = nNew;
		nStart += 1;
	}
	return nStart;
}

ll solve() {
	vector<ll> vectOther;
	vectOther.resize(N);
	for (int i = 0; i < N; i += 1) cin >> vectOther[i];
	sort(vectOther.begin(), vectOther.end());

	int nSteps = 0;
	int nCurrent = 0;
	while (true) {
		nCurrent = nTest(nCurrent, A, vectOther, 0);
		if (nCurrent == (int) vectOther.size()) break;

		int nNeedLeft = 0;
		if (A != 1) {
			ll Atmp = A;
			while (Atmp <= vectOther[nCurrent]) Atmp += Atmp - 1, nNeedLeft += 1;
		} else {
			nNeedLeft = 100000;
		}

		if (nNeedLeft < (int) vectOther.size() - nCurrent) {
			A += A - 1;
		} else {
			vectOther.pop_back();
		}
		nSteps += 1;

		// nCurrent = nTest(nCurrent, A, vectOther, 0);
		// if (nCurrent == (int) vectOther.size()) break;

		// ll nSavedLeft = 0;
		// {
		// 	ll ATmp = A + A - 1;
		// 	nTest(nCurrent, ATmp, vectOther, -1);
		// 	nSavedLeft = ATmp - A;
		// }

		// ll nSavedRight = vectOther[vectOther.size() - 1];
		// if (vectOther.size() > 2) nSavedRight -= vectOther[vectOther.size() - 2];

		// if (nSavedLeft < nSavedRight || nSavedLeft == 0) {
		// 	vectOther.pop_back();
		// 	// cout << "remove " << vectOther << endl;
		// } else {
		// 	// cout << "add " << A - 1 << endl;
		// 	A += A - 1;
		// 	nCurrent = nTest(nCurrent, A, vectOther, 0);
		// }

		// nSteps += 1;
	}

	return nSteps;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		cin >> A >> N;
		cout << "Case #" << t << ": " << solve() << endl;
	}
	return 0;
}
