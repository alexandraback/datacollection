#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <string>
#include <cassert>
#include <sstream>
#include <iostream>
using namespace std;
typedef long long LL;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }


typedef tuple<char, char, char> Outfit;
typedef tuple<char, char> Combination;

void Go() {
	int J, P, S, K;
	cin >> J >> P >> S >> K;

	vector<Outfit> allOutfits;
	for (int j = 1; j <= J; j++) {
		for (int p = 1; p <= P; p++) {
			for (int s = 1; s <= S; s++) {
				auto outfit = make_tuple(j, p, s);
				allOutfits.push_back(outfit);
			}
		}
	}

	auto tryGet = [&]() {
		set<Outfit> usedOutfits;
		map<Combination, int> JP, JS, PS;
		vector<Outfit> bestOutfits;
		random_shuffle(allOutfits.begin(), allOutfits.end());
		auto canWear = [&](const Outfit& outfit) {
			if (usedOutfits.count(outfit) > 0) {
				return false;
			}
			auto jp = make_tuple(get<0>(outfit), get<1>(outfit));
			auto js = make_tuple(get<0>(outfit), get<2>(outfit));
			auto ps = make_tuple(get<1>(outfit), get<2>(outfit));
			if (JP[jp] >= K) {
				return false;
			}
			if (JS[js] >= K) {
				return false;
			}
			if (PS[ps] >= K) {
				return false;
			}
			return true;
		};
		for (auto outfit : allOutfits) {
			if (!canWear(outfit)) {
				continue;
			}
			auto jp = make_tuple(get<0>(outfit), get<1>(outfit));
			auto js = make_tuple(get<0>(outfit), get<2>(outfit));
			auto ps = make_tuple(get<1>(outfit), get<2>(outfit));
			usedOutfits.insert(outfit);
			JP[jp] += 1;
			JS[js] += 1;
			PS[ps] += 1;
			bestOutfits.push_back(outfit);
		}
		return bestOutfits;
	};
	vector<Outfit> bestOutfits;
	for (int i = 0; i < 1000; i++) {
		auto outfits = tryGet();
		if (outfits.size() > bestOutfits.size()) {
			bestOutfits = outfits;
		}
	}
	sort(bestOutfits.begin(), bestOutfits.end());
	cout << bestOutfits.size() << endl;
	for (size_t i = 0; i < bestOutfits.size(); i++) {
		auto outfit = bestOutfits[i];
		cout << (int)get<0>(outfit) << ' ' << (int)get<1>(outfit) << ' ' << (int)get<2>(outfit) << endl;
	}
}

int main() {
	const string task = "C";
	const string folder = "gcj/2016/1C";
	const int attempt = 1;
	const bool dbg = false;

	if (dbg) {
		freopen("inp.txt", "r", stdin);
	}
	else {
		stringstream ss;
		ss << folder << '/' << task;
		if (attempt < 0)
			ss << "-large";
		else
			ss << "-small-attempt" << attempt;
		freopen((ss.str() + ".in").c_str(), "r", stdin);
		freopen((ss.str() + ".out").c_str(), "w", stdout);
	}


	static char tt[128];
	gets(tt);
	int t;
	sscanf(tt, "%d", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%d: ", i + 1);
		Go();
	}
	return 0;
}
