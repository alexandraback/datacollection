#include <iostream>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <queue>

#define var(x) #x
#define forn(i, n) for (int i = 0; i < ((int) n); ++i)
#define foreach(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define sqr(x) (x)*(x)
#define all(x) x.begin(), x.end()
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define endl '\n'
#define sp ' '
#define elif else if
#define len(x) ((int) (x).size())
#define last(x) ((x)[(len(x))-1])
#define plast(x) ((x)[(len(x))-2])

using namespace std;

typedef long long int64;
typedef unsigned long long lint;
typedef long double ld;

template<typename type>
inline static void _cutedebug(const type &a){
	cerr << a;
}
template<typename type1, typename type2>
inline static void _cutedebug(const pair<type1, type2> &a){
	cerr << "("; _cutedebug(a.fs); cerr << ", "; _cutedebug(a.sc); cerr << ")";
}
template<typename type>
inline static void _cutedebug(const vector<type> &a){
	cerr << "[";
	bool flag = true;
	for (typename vector<type>::const_iterator i = a.begin(); i != a.end(); i++){
		if (flag)
			flag = false;
		else
			cerr << ", ";
		_cutedebug(*i);
	}
	cerr << "]";
}
template<typename type>
inline static void _cutedebug(const set<type> &a){
	cerr << "{";
	bool flag = true;
	for (typename set<type>::const_iterator i = a.begin(); i != a.end(); i++){
		if (flag)
			flag = false;
		else
			cerr << ", ";
		_cutedebug(*i);
	}
	cerr << "}";
}
template<typename type1, typename type2>
inline static void _cutedebug(const map<type1, type2> &a){
	cerr << "{";
	bool flag = true;
	for (typename map<type1, type2>::const_iterator i = a.begin(); i != a.end(); i++){
		if (flag)
			flag = false;
		else
			cerr << ", ";
		cerr << "(";
		_cutedebug((*i).fs);
		cerr << ": ";
		_cutedebug((*i).sc);
		cerr << ")";
	}
	cerr << "}";
}
#ifdef CUTEBMAING
template<typename type>
inline static void _cutedebug_(const type &a, string name, int ln = __LINE__){
	cerr << "Line " << ln << " : " << name << " = "; _cutedebug(a); cerr << ";" << endl;
}
#define debug(x) _cutedebug_(x, var(x), __LINE__)
#endif
#ifndef CUTEBMAING
#define debug(x) ({})
#endif

const char* fin = "input.txt";
const char* fout = "output.txt";

const int inf = (1 << 30);
const int64 linf = (int64(1) << 61);
const ld eps = 1e-12;
const int cmax = 101;
const int hmax = 10001;
const int cx[] = {1, 0, -1, 0};
const int cy[] = {0, -1, 0, 1};

typedef set<pair<ld, pair<int, pair<int, int> > > >::iterator iter;

int h, n, m;
int c[cmax][cmax], f[cmax][cmax];
set<pair<ld, pair<int, pair<int, int> > > > q;
bool used[cmax][cmax];
ld dist[hmax][cmax][cmax];

bool cango(int x, int y, int nx, int ny, int h){
    if (h > c[nx][ny]-50)
        return false;
    if (f[x][y] > c[nx][ny]-50)
        return false;
    if (f[nx][ny] > c[nx][ny]-50)
        return false;
    if (f[nx][ny] > c[x][y]-50)
        return false;
    return true;
}

void dfs(int x, int y){
    if (used[x][y])
        return;
    used[x][y] = true;
    for (int i = 0; i < 4; i++){
        int nx = x + cx[i], ny = y + cy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (cango(x, y, nx, ny, h))
            dfs(nx, ny);
    }
}

int mt = 0;

void bfs(){
    for (int i = 0; i <= mt; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                dist[i][j][k] = INFINITY;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (used[i][j])
                dist[h][i][j] = 0, q.insert(mp(0, mp(h, mp(i, j))));
    while (q.size() > 0){
        int t = (*q.begin()).sc.fs, x = (*q.begin()).sc.sc.fs, y = (*q.begin()).sc.sc.sc;
        q.erase(q.begin());
        for (int i = 0; i < 4; i++){
            int nx = x + cx[i], ny = y + cy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (cango(x, y, nx, ny, t)){
                int cost = 0;
                if (t >= f[x][y] + 20)
                    cost = 1;
                else
                    cost = 10;
                int nt = max(0, t-cost*10);
                if (dist[nt][nx][ny] > dist[t][x][y] + cost){
                    iter it = q.find(mp(dist[nt][nx][ny], mp(nt, mp(nx, ny))));
                    if (it != q.end())
                        q.erase(it);
                    dist[nt][nx][ny] = dist[t][x][y] + cost;
                    q.insert(mp(dist[nt][nx][ny], mp(nt, mp(nx, ny))));
                }
            }
        }
        for (int i = t-1; i >= 0 && i >= t-1; i--)
            if (dist[i][x][y] > dist[t][x][y] + 1.0*(t-i)/10){
                iter it = q.find(mp(dist[i][x][y], mp(i, mp(x, y))));
                if (it != q.end())
                    q.erase(it);
                dist[i][x][y] = dist[t][x][y] + 1.0*(t-i)/10;
                q.insert(mp(dist[i][x][y], mp(i, mp(x, y))));
            }
    }
}

void run(int x){
    cout << "Case #" << x << ": ";
    cin >> h >> n >> m;
    mt = h;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> f[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            used[i][j] = false;
    dfs(0, 0);
    bfs();
    ld ans = INFINITY;
    for (int i = 0; i <= h; i++)
        ans = min(ans, dist[i][n-1][m-1]);
    cout.precision(20);
    cout << fixed << ans << endl;
}

int main(){
    #ifdef CUTEBMAING
    assert(freopen(fin, "r", stdin));
    assert(freopen(fout, "w", stdout));
    #endif
	int t; cin >> t;
	for (int i = 1; i <= t; i++)
		run(i);
    return 0;
}

