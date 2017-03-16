#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

bool doing = true;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		cout << "Case #" << testNum++ << ": ";
		solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

void precalc() {
}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//#define int li

struct Hiker {
	int start;
	ld velocity;
	Hiker(int start, int period):start(start) {
		velocity = 360.0 / period;
	}
	bool operator < (const Hiker& other) const {
		return mp(start, velocity) < mp(other.start, other.velocity);
	}
};

ld eps = 1e-11;

struct State {
	int nextHiker;
	ld curTime;
	State() {}
	State(int nextHiker, ld curTime) :nextHiker(nextHiker), curTime(curTime) {}
	bool operator < (const State&) const ;
};

map<State, ld> dp;

bool State::operator < (const State& other) const {
	if (nextHiker != other.nextHiker)
		return nextHiker < other.nextHiker;
	return curTime + eps < other.curTime;
}

int n;
vector<Hiker> hikers;


void solve() {
	hikers.clear();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int d, h, m;
		cin >> d >> h >> m;
		for (int cur = m; cur < m + h; ++cur) {
			hikers.push_back(Hiker(d, cur));
		}
	}

	n = hikers.size();

	if (n == 1) {
		cout << "0\n";
		return;
	}

	if (hikers[1] < hikers[0]) {
		swap(hikers[0], hikers[1]);
	}

	vector<ld> endTime(2);
	for (int i = 0; i < 2; ++i) {
		endTime[i] = (360.0 - hikers[i].start) / hikers[i].velocity;
	}

	int res = 2;
	if (endTime[0] + eps > endTime[1] && endTime[0] * (hikers[1].velocity - hikers[0].velocity) + eps < 360 - hikers[1].start + hikers[0].start) {
		cout << "0\n";
		return;
	}

	if (endTime[1] > endTime[0] && endTime[1] * (hikers[0].velocity - hikers[1].velocity) + eps < hikers[1].start - hikers[0].start + 360) {
		cout << "0\n";
		return;
	}

	if (endTime[1] * (hikers[0].velocity - hikers[1].velocity) + eps < hikers[1].start - hikers[0].start + 360 * 2) {
		cout << "1\n";
		return;
	}

	if (endTime[0] * (hikers[1].velocity - hikers[0].velocity) + eps < 360 - hikers[1].start + hikers[0].start + 360) {
		cout << "1\n";
		return;
	}

	cout << "2\n";
	return;

	/*ld L = 0, R = 1e12;
	for (int w = 0; w < 200; ++w) {
		ld M1 = (2 * L + R) / 3;
		ld M2 = (L + 2 * R) / 3;
		if (getFunc(M1) > getFunc(M2)) {
			L = M1;
		}
		else {
			R = M2;
		}
	}

	cout << getFunc(L) << "\n";*/

	//State startState(0, 0.0);
	
	/*for (int i = 0; i < n; ++i) {
		if (hikers[i].start + eps < hikers[startState.nextHiker].start || fabs((ld)hikers[i].start - hikers[startState.nextHiker].start) < eps && hikers[i].velocity < hikers[startState.nextHiker].velocity) {
			startState.nextHiker = i;
		}
	}

	dp[startState] = 0;
	set<pair<ld, State>> currentStates;
	currentStates.insert(mp(0, startState));

	while (!currentStates.empty()) {
		auto item = *currentStates.begin();
		currentStates.erase(currentStates.begin());
		State curState = item.second;

		int curHiker = curState.nextHiker;
		ld curTime = curState.curTime;

		int nextEncounter = -1;
		ld nextTime = 0;
		for (int i = 0; i < n; ++i) {
			if (hikers[i].velocity > hikers[curHiker].velocity) {
				ld nextTime = getEncounterTime(hikers[curHiker], hikers[i], curTime);

			}
		}

	}*/




}


