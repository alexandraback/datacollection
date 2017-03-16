#include <algorithm>
#include <iterator>
#include <iostream>
#include <sstream>
#include <cstring>
#include <numeric>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <random>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>

using namespace std;

#define RA(x) (x).begin(), (x).end()
#define SZ(x) ((int) (x).size())

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair<int,int> ii;

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
#define nmax 501
#define max 100

map<ii, char> mov;
map<ii, int> visit;
map<ii, int> num;

void bfs()
{
  queue<pair<ii, int>> que;
  int vx, vy, tvx, tvy, n;
  pair<ii,int> vp;
  que.push(make_pair(make_pair(0,0), 0));
  while (!que.empty() && n < nmax) {
    vp = que.front(); 
    que.pop();
    tvx = vp.first.first; 
    tvy = vp.first.second; 
    n = vp.second;
    n++;
    vx = tvx + n;
    ii vxy = make_pair(vx, tvy);
    if (abs(vx) <= max && visit.count(vxy) == 0) {
      visit[vxy] = 1;
      num[vxy] = n;
      mov[vxy] = 'E';
      que.push(make_pair(vxy,n));
    }
    vx = tvx - n;
    vxy = make_pair(vx, tvy);
    if (abs(vx) <= max && visit.count(vxy) == 0) {
      visit[vxy] = 1;
      num[vxy] = n;
      mov[vxy] = 'W';
      que.push(make_pair(vxy,n));
    }
    vy = tvy + n;
    vxy = make_pair(tvx, vy);
    if (abs(vy) <= max && visit.count(vxy) == 0) {
      visit[vxy] = 1;
      num[vxy] = n;
      mov[vxy] = 'N';
      que.push(make_pair(vxy,n));
    }
    vy = tvy - n;
    vxy = make_pair(tvx, vy);
    if (abs(vy) <= max && visit.count(vxy) == 0) {
      visit[vxy] = 1;
      num[vxy] = n;
      mov[vxy] = 'S';
      que.push(make_pair(vxy,n));
    }
  }
}
void solve(int x, int y)
{
  int n = num[make_pair(x,y)];
  int t = n;
  vector<char> ans(n);
  while (n > 0 ) {
    ans[n-1] = mov[make_pair(x,y)];
    switch(ans[n-1]) {
      case 'S': y+= n;
                break;
      case 'N': y-= n;
                break;
      case 'E': x-= n;
                break;
      case 'W': x+= n;
                break;
    }
    n--;
  }
  for (int i=0; i<t; i++) {
    cout << ans[i];
  }
}

int main()
{
  int cases;
  cin >> cases;

  bfs();
  for (int cas = 1; cas < cases+1; cas++) {
    printf("Case #%d: ", cas);
    int x, y;
    cin >> x >> y;
    solve(x, y);
    printf("\n");
  }

  return 0;
}
