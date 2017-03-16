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

int N, M, K;
int anK[10];

int vectToResult(const vector<int> &vect) {
	int nResult = 0;
	each(vect, it) nResult = nResult * 10 + *it;
	return nResult;
}

void insertState(list< pair< vector<int>, set<int> > > &vectStates, const vector<int> &vectState) {
	set<int> stTmp;
	for (int i = 0; i < (1 << N); i += 1) {
		int nMul = 1;
		for (int j = 0; j < N; j += 1) {
			if (i & (1 << j)) nMul *= vectState[j];
		}
		stTmp.insert(nMul);
	}
	vectStates.push_back(make_pair(vectState, stTmp));
}

void prune(list< pair< vector<int>, set<int> > > &vectStates) {
	for (int i = 0; i < K; i += 1) {
		for (list< pair< vector<int>, set<int> > >::iterator it = vectStates.begin(); it != vectStates.end();) {
			if (it->second.count(anK[i])) ++it;
			else it = vectStates.erase(it);
		}
	}
}

int solve() {
	for (int i = 0; i < K; i += 1) cin >> anK[i];
	if (N == 1) return *max_element(anK, anK + K);
	list< pair< vector<int>, set<int> > > vectStates;
	for (int i = 2; i <= M; i += 1) {
		vector<int> vectCurState;
		vectCurState.push_back(i);
		for (int j = 2; j <= M; j += 1) {
			vectCurState.push_back(j);
			if (N == 2) {
				insertState(vectStates, vectCurState);
			} else {
				for (int k = 2; k <= M; k += 1) {
					vectCurState.push_back(k);
					insertState(vectStates, vectCurState);
					vectCurState.pop_back();
				}
			}
			vectCurState.pop_back();
		}
	}
	prune(vectStates);
	if (vectStates.empty()) {
		cerr << "empty state" << endl;
		return N == 2 ? 11 : 111;
	}
	list< pair< vector<int>, set<int> > >::iterator it = vectStates.begin(); advance(it, rand() % vectStates.size());
	return vectToResult(it->first);
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T >> T >> N >> M >> K;

	cout << "Case #1:" << endl;
	for (int t = 1; t <= T; t += 1) {
		cout << solve() << endl;
	}

	return 0;
}
