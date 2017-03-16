#pragma comment (linker,"/STACK:16000000")
#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <deque> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector> 
#include <functional>

using namespace std; 

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const double pi = 3.1415926;
const ld eps = 1e-9;
const int N = (int)1e5+5;
const int INF = (int)1e9+10;

const double EPS = 0.00001;

pair<int,int> pos;

int k;
string s;

string dfs(int x, int y, int d, string s) {
	if(d > 500) 
		return "";
	if(x == pos.first && y == pos.second) return s;
	k++;
	if(dfs(x + k, y, d+1,s+'W') != "") return s;
	if(dfs(x - k, y, d+1,s+'E')!="") return s;
	if(dfs(x, y+k, d+1,s+'N')!="") return s;
	if(dfs(x, y-k, d+1,s+'S')!="") return s;
	k--;
	return "";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    int t;

	cin >> t;
	for(int o = 0; o < t; o++) {
		k = 1; s = "";
		cin >> pos.first >> pos.second;
		pos.first += 500;
		pos.second += 500;
		queue<pair<int,int> > q;
		q.push (make_pair(500,500));
		bool used[1000][1000];
		int kk[1000][1000];
		for(int i = 0; i < 1000; i++)
			for(int j = 0; j < 1000; j++)
				used[i][j] = false;
		pair<int,int> p[1000][1000];
		used[500][500] = true;
		kk[500][500] = 1;
		vector<pair<int,int>> path;
		while (!q.empty()) {
			pair<int,int> v = q.front();
			q.pop();
			int tox = v.first + kk[v.first][v.second];
			int toy = v.second;
			if(tox == pos.first && toy == pos.second) {
				p[tox][toy] = v;
				for (pair<int,int> ppos = make_pair(tox, toy); ppos != make_pair(500,500); ppos = p[ppos.first][ppos.second])
					path.push_back (ppos);
				reverse (path.begin(), path.end());
				break;
			}
			if (!used[tox][toy]) {
				used[tox][toy] = true;
				q.push (make_pair(tox,toy));
				p[tox][toy] = v;
				kk[tox][toy] = kk[v.first][v.second] + 1;
			}
			tox = v.first - kk[v.first][v.second];
			toy = v.second;
			if(tox == pos.first && toy == pos.second) {
				p[tox][toy] = v;
				for (pair<int,int> ppos = make_pair(tox, toy); ppos != make_pair(500,500); ppos = p[ppos.first][ppos.second])
					path.push_back (ppos);
				reverse (path.begin(), path.end());
				break;
			}
			if (!used[tox][toy]) {
				used[tox][toy] = true;
				q.push (make_pair(tox,toy));
				p[tox][toy] = v;
				kk[tox][toy] = kk[v.first][v.second] + 1;
			}
			tox = v.first;
			toy = v.second+kk[v.first][v.second];
			if(tox == pos.first && toy == pos.second) {
				p[tox][toy] = v;
				for (pair<int,int> ppos = make_pair(tox, toy); ppos != make_pair(500,500); ppos = p[ppos.first][ppos.second])
					path.push_back (ppos);
				reverse (path.begin(), path.end());
				break;
			}
			if (!used[tox][toy]) {
				used[tox][toy] = true;
				q.push (make_pair(tox,toy));
				p[tox][toy] = v;
				kk[tox][toy] = kk[v.first][v.second] + 1;
			}
			tox = v.first;
			toy = v.second-kk[v.first][v.second];
			if(tox == pos.first && toy == pos.second) {
				p[tox][toy] = v;
				for (pair<int,int> ppos = make_pair(tox, toy); ppos != make_pair(500,500); ppos = p[ppos.first][ppos.second])
					path.push_back (ppos);
				reverse (path.begin(), path.end());
				break;
			}
			if (!used[tox][toy]) {
				used[tox][toy] = true;
				q.push (make_pair(tox,toy));
				p[tox][toy] = v;
				kk[tox][toy] = kk[v.first][v.second] + 1;
			}
		}
		cout << "Case #" << o+1 << ": ";
		int px = 500, py = 500;
		for(int i = 0; i < path.size(); i++) {
			if(path[i].first > px) cout << 'E';
			else if(path[i].first < px) cout << 'W';
			else if(path[i].second > py) cout << 'N';
			else cout << 'S';
			px = path[i].first;
			py = path[i].second;
		}
		cout << endl;
	}	
}