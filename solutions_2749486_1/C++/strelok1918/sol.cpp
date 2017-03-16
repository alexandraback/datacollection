#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;
 
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define sz size()
#define sqr(x) (x) * (x)
#define all(x) (x).begin(), (x).end()




int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char dest[] = {'W', 'N', 'E', 'S'};

string go(pair<int,int> to) {
	set<pair<int,int> > u;
	map<pair<int,int>, string > path;
	map<pair<int,int>, int> pt;
	pair<int,int> from = mp(0, 0), now;
	queue<pair<int,int> > q;
	int xn, yn, len;
	char p;
	q.push(from);
	pt[from] = 0;
	while(!q.empty()) {
		now = q.front();
		
		q.pop();
		if(now == to) return path[now];
		for(int i = 0; i < 4; i++) {
			len = pt[now] + 1;
			xn = now.X + dx[i] * len;
			yn = now.Y + dy[i] * len;
			if(u.count(mp(xn, yn))) continue;
			p = dest[i];
			path[mp(xn, yn)] = path[now] + p;
			q.push(mp(xn, yn));
			pt[mp(xn, yn)] = len ;
			u.insert(mp(xn, yn));
			if(to == mp(xn, yn)) return path[to];
		}
	}
}
struct heap {
	vector<int> h;
	int last;
	
	heap() {
		last = 0;
	}
	heap(int size) {
		last = 0;
		h.resize(size, 0);
	}
	
	int PeekMin() {
		if(last <= 0) return -1;
		return h[0];
	}
	
	int ExtractMin() {
		if(last <= 0) return -1;
		int ans = h[0];
		h[0] = h[--last];
		siftDown(0);
		return ans;
	}
	
	void Add(int p) {
		if(last >=  (int)h.sz - 1) h.pb(0);
		h[last++] = p;
		siftUp(last - 1);
	}

	void siftUp(int pos) {
		int p = pos;
		while(p > 0) {
			if(h[p / 2] > h[p]) swap(h[p], h[p / 2]);
			else break;
			p /= 2;
		}
	}

	void siftDown(int pos) {
		int p1, p2, mn;
		int ps = pos - 1;
		while(pos < last) {
			mn = h[pos]; ps = pos;
			p1 = pos * 2 + 2;
			p2 = pos * 2 + 1;
			if(p1 <= last && h[p1] < mn) {
				ps = p1, mn = h[p1];
			}
			if(p2 <= last && h[p2] < mn) {
				ps = p2, mn = h[p2];
			}
			if(pos == ps) break;
			swap(h[pos], h[ps]);
			pos = ps;
		}
	}
};
int phi(int n) {
	int ans = n;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			while(n % i == 0) n /= i;
			ans -= ans / i;
		}
	}
	if(n > 1)
		ans -= ans / n;

	return ans;
}
vector<int> InsertionSort(vector<int> a) {
	vector<int> ans;
	for(int i = 0; i < a.sz; i++) {
		int j = 0;
		for(; j < ans.sz && ans[j] < a[i]; j++);
		ans.insert(ans.begin() + j, a[i]);
	}
	return ans;
}
void solve() {
	int x, y;
	scanf("%d%d", &x, &y);
	puts(go(mp(x, y)).c_str());
}
void OJ() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
        solve();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    OJ();
    //solve();
    return 0;
}