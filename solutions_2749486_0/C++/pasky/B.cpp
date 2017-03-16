#define _HAS_CPP0X 0
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <queue>
#include <cassert>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }
#define FOR(i, n) for(int i = 0; i < (int)(n); ++i)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dt[] = {'W', 'E', 'S', 'N'};
const int dr[] = {1, 0, 3, 2};


struct State{
	int first;
	int second;
	int step;
	State(int first, int second, int step) : first(first), second(second), step(step) { }
	friend bool operator < (const State& a, const State& b){
		if (a.first < b.first){
			return true;
		}
		if (a.first > b.first){
			return false;
		}
		if (a.second < b.second){
			return true;
		}
		if (a.second > b.second){
			return false;
		}
		return a.step < b.step;
	}
};
string find_way(int x, int y){
	State start(0, 0, 0);
	map<State, int> pr;	
	queue<State> Q;
	Q.push(start);	
	int dist = -1;
	while (!Q.empty()){
		State u = Q.front();
		Q.pop();
		if (u.first == x && u.second == y){
			dist = u.step;
			break;
		}
		int step = u.step + 1;
		for (int i = 0; i < 4; i++){
			State v(u.first + dx[i] * step, u.second + dy[i] * step, step);
			if (pr.count(v) == 0){				
				pr[v] = i;
				Q.push(v);
			}
		}
	}
	if (dist == -1){
		throw 42;
	}
	string path;
	State p(x, y, dist);
	for (;;){
		if (pr.count(p) == 0){
			break;
		}
		int d = pr[p];
		path.push_back(dt[d]);
		p.first -= dx[d] * p.step;
		p.second -= dy[d] * p.step;
		p.step -= 1;
	}
	reverse(path.begin(), path.end());
	return path;
}

void Go(){
	int x, y;
	cin >> x >> y;
	cout << find_way(x, y);
}

int main(){
	const string task = "B";
	const string folder = "gcj/2013/1C";
	const int attempt = 0;
	const bool dbg = false;
	
	/*int b = 0;
	for (int i = -20; i <= 100; i++){
		for (int j = -20; j <= 2; j++){
			if (i == 0 && j == 0){
				continue;
			}
			b = max<int>(b, find_way(i, j).size());
		}
	}
	cout << b << endl;*/

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