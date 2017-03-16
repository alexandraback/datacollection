#include      <algorithm>
#include <queue>
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

struct SState{
	ll x, y;
	vector<char> path;
	int step;
};

string solve() {
	ll tx, ty;
	cin >> tx >> ty;

	set< pair<ll, ll> > setVisited;
	SState st;
	st.x = st.y = 0;
	st.step = 0;
	queue<SState> listStack;
	listStack.push(st);

	while (!listStack.empty()) {
		st = listStack.front();
		listStack.pop();

		if (setVisited.count(make_pair(st.x, st.y))) continue;

		if (st.x == tx && st.y == ty) {
			break;
		}

		if (st.x == tx) {
			queue<SState> listTmpStack;
			SState stTmp = st;
			listTmpStack.push(stTmp);
			int i = 0;
			bool bFound = false;
			while (i < 200 && !listTmpStack.empty()) {
				stTmp = listTmpStack.front();
				listTmpStack.pop();

				if (setVisited.count(make_pair(stTmp.x, stTmp.y))) continue;
				setVisited.insert(make_pair(stTmp.x, stTmp.y));

				if (stTmp.x == tx && stTmp.y == ty) {
					bFound = true;
					break;
				}

				stTmp.step += 1;

				stTmp.path.push_back('N');
				stTmp.y += stTmp.step; listTmpStack.push(stTmp); stTmp.y -= stTmp.step;
				stTmp.path.pop_back();
				stTmp.path.push_back('S');
				stTmp.y -= stTmp.step; listTmpStack.push(stTmp); stTmp.y += stTmp.step;
				stTmp.path.pop_back();
				i += 1;
			}
			if (bFound) {
				st = stTmp;
				break;
			 }
		}

		if (st.y == ty) {
			queue<SState> listTmpStack;
			SState stTmp = st;
			listTmpStack.push(stTmp);
			int i = 0;
			bool bFound = false;
			while (i < 200 && !listTmpStack.empty()) {
				stTmp = listTmpStack.front();
				listTmpStack.pop();

				if (setVisited.count(make_pair(stTmp.x, stTmp.y))) continue;
				setVisited.insert(make_pair(stTmp.x, stTmp.y));

				if (stTmp.x == tx && stTmp.y == ty) {
					bFound = true;
					break;
				}

				stTmp.step += 1;

				stTmp.path.push_back('E');
				stTmp.x += stTmp.step; listTmpStack.push(stTmp); stTmp.x -= stTmp.step;
				stTmp.path.pop_back();
				stTmp.path.push_back('W');
				stTmp.x -= stTmp.step; listTmpStack.push(stTmp); stTmp.x += stTmp.step;
				stTmp.path.pop_back();
				i += 1;
			}
			if (bFound) {
				st = stTmp;
				break;
			 }
		}

		setVisited.insert(make_pair(st.x, st.y));

		st.step += 1;

		st.path.push_back('N');
		st.y += st.step; listStack.push(st); st.y -= st.step;
		st.path.pop_back();

		st.path.push_back('S');
		st.y -= st.step; listStack.push(st); st.y += st.step;
		st.path.pop_back();

		st.path.push_back('E');
		st.x += st.step; listStack.push(st); st.x -= st.step;
		st.path.pop_back();

		st.path.push_back('W');
		st.x -= st.step; listStack.push(st); st.x += st.step;
		st.path.pop_back();
	}

	string strRtn;
	each(st.path, it) strRtn.push_back(*it);
	return strRtn;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		cout << "Case #" << t << ": " << solve() << endl;
	}
	return 0;
}
