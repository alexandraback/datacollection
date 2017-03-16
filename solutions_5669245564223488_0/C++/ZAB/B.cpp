#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <bitset>
#include <string.h>
using namespace std;

int N;
vector<string> src;

void readCase()
{
	cin >> N;
	src.clear();
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		src.push_back(s);
	}
}

const int MOD = 1000000007;

long long fact(int v)
{
	long long res = 1;
	for(int i = 1; i <= v; i++) {
		res *= i;
		res %= MOD;
	}
	return res;
}

vector<string> cars;
map<char, int> freecnt;
vector< pair< set<char>, long long > > trains;

set<char> used;

bool build_train(char first, long long cnt, int len = 0)
{
	used.insert(first);

	if(freecnt.count(first)) {
		len += freecnt[first];
		cnt *= fact(freecnt[first]);
		cnt %= MOD;
		freecnt.erase(first);
	}

	int i = 0;
	while(i < cars.size() && cars[i][0] != first) i++;

	if(i == cars.size()) {
		if(len > 0) trains.push_back(make_pair(used, cnt));
		return true;
	}

	string car = cars[i];
	cars.erase(cars.begin() + i);
	for(int j = 1; j < car.size(); j++) {
		char cur = car[j];
		if(cur != car[j-1]) {
			if(used.count(cur)) return false;
			used.insert(cur);
		}
	}

	return build_train(*car.rbegin(), cnt, len + 1);
}

void stupidsolve()
{
	long long cnt = 0;

	if(src.size() > 7) return;

	vector<int> perm;
	for(int i = 0; i < N; i++) perm.push_back(i);
	do {
		bool bad = false;

		string s;
		for(int i = 0; i < N; i++) {
			s += src[perm[i]];
		}
		set<char> m;
		char pred = -1;
		for(int i = 0; i < s.size(); i++) {
			char cur = s[i];
			if(cur != pred) {
				if(m.count(cur)) {
					bad = true;
					continue;
				}
				m.insert(cur);
			}
			pred = cur;
		}

		if(bad) continue;

		cnt++;
	} while(next_permutation(perm.begin(), perm.end()));

	cout << cnt;
}

void solve()
{
	//stupidsolve(); cout << " ";

	freecnt.clear();
	cars.clear();

	set<char> ends;

	for(int i = 0; i < N; i++) {
		set<char> m;
		string car = src[i];
		for(int j = 0; j < car.size(); j++) {
			m.insert(car[j]);
		}
		if(m.size() == 1) {
			freecnt[car[0]]++;
		} else {
			cars.push_back(car);
			ends.insert(car[car.size()-1]);
		}
	}

	trains.clear();

	for(char f = 'a'; f <= 'z'; f++) {
		if(ends.count(f)) continue;
		used.clear();
		if(!build_train(f, 1)) {
			cout << 0;
			return;
		}
	}

	for(char f = 'a'; f <= 'z'; f++) {
		if(ends.count(f)) continue;
		used.clear();
		if(!build_train(f, 1)) {
			cout << 0;
			return;
		}
	}

	if(cars.size() > 0 || freecnt.size() > 0) {
		cout << 0;
		return;
	}

	used.clear();

	long long cnt = 1;

	for(int i = 0; i < trains.size(); i++) {
		for(set<char>::iterator it = trains[i].first.begin(); it != trains[i].first.end(); it++) {
			if(used.count(*it)) {
				cout << 0;
				return;
			}
			used.insert(*it);
		}
		cnt *= trains[i].second;
		cnt %= MOD;
	}

	cnt *= fact(trains.size());
	cnt %= MOD;


	cout << cnt;
}

int main()
{
	//string fname = "./test/B-example.in";
	//string fname = "./test/B-small-attempt0.in";
	string fname = "./test/B-small-attempt1.in";
	//string fname = "./test/B-small-practice.in";
	//string fname = "./test/B-large-practice.in";
	//string fname = "./test/B-large.in";
	
	freopen(fname.c_str(),"r",stdin);freopen((fname+".out").c_str(),"w",stdout);

	int analizeCase = -1;
	
	int T;
	scanf("%d", &T);
	for(int tCase = 1; tCase <= T; tCase++) {
		printf("Case #%d: ", tCase);
		readCase();
		if(analizeCase < 0 || analizeCase == tCase) solve();
		printf("\n");
		fflush(stdout);
		fprintf(stderr, "Done %d %%     \r", 100 * tCase / T );
	}
	return 0;
}

