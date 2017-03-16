#pragma comment(linker, "/STACK:160777216")
#define _CRT_SECURE_NO_WARNINGS
#include <queue>
#include <cassert>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
//typedef long long LL;
typedef int LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }
#define FOR(i, n) for(int i = 0; i < (int)(n); ++i)

vector<LL> mem;
LL rev(LL x) {
	if (x % 10 == 0) {
		return -1;
	}
	LL rx = 0;
	while (x > 0) {
		rx = rx * 10 + x % 10;
		x /= 10;
	}
	return rx;
}
LL get(LL x);
LL _get(LL x) {
	if (x == 1) {
		return 1;
	}
	LL res = get(x - 1) + 1;
	LL rx = rev(x);
	if (rx != -1 && rx < x) {
		LL nr = get(rx - 1) + 2;
		res = min(res, nr);
	}
	return res;
}
LL get(LL x) {
	if (x < mem.size()){
		if (mem[x] == -1) {
			mem[x] = _get(x);
		}
	}
	else {
		mem.resize(x + 1, -1);
		mem[x] = _get(x);
	}
	return mem[x];	
}

void Go(){
	LL n;
	cin >> n;
	cout << get(n);
}

int main(){	
	const string task = "A";
	const string folder = "gcj/2015/1B";
	const int attempt = 0;
	const bool dbg = false;


	if (dbg){
		freopen("inp.txt", "r", stdin);
	}
	else{
		stringstream ss;
		if (attempt < 0)
			ss << folder << '/' << task << "-large";
		else
			ss << folder << '/' << task << "-small-attempt" << attempt;
		freopen((ss.str() + ".in").c_str(), "r", stdin);
		freopen((ss.str() + ".out").c_str(), "w", stdout);
	}


	static char tt[128];
	gets(tt);
	int t;
	sscanf(tt, "%d", &t);
	FOR(i, t){
		printf("Case #%d: ", i + 1);
		Go();
		printf("\n");
	}
	return 0;
}