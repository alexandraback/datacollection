#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <strings.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <climits>
#include <assert.h>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> int2;
typedef pair<float, float> float2;
typedef pair<ull, ull> ull2;

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(s,i) for ( __typeof((s).begin()) i = ((s).begin())   ; i != (s).end(); ++i)  
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mp(a,b) make_pair(a,b)
#define del(s,x) if(s.find(x)!=s.end()) s.erase(s.find(x))

#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

bool comp(pair<int,int> a,pair<int,int> b) {return a.first < b.first; }

#define ok(a,b) (((a)>=0)&&((b)>=0)&&((a)<h)&&((b)<w))
#define okok(a,b) (ok(a,b)&&sol[a][b]=='*')
#define add(a,b) if (ok(a,b) && (!vis[a][b]) && (sol[a][b] != '*')) {vis[a][b] = true; q.push(mp(a,b));}

int main() {
  int T, h, w, m;
  scanf("%d", &T);
  FOR(test,1,T+1) {
    printf("Case #%d:\n", test);
    scanf("%d %d %d", &h, &w, &m);

    vector<vector<char> > sol(h, vector<char>(w,'*'));
    bool ok = true;
    int rem = h * w - m;
    int sq = 0; while(sq*sq < rem) sq++;
    if (sq*sq > rem) sq --;
    sq = min(sq, min(h,w));
    rem -= sq*sq;
    FOR(i,0,sq) FOR(j,0,sq) sol[i][j] = '.';
    if (sq == h) {
      int q = rem / h;
      for (int j = sq; j < sq + q; j++)
	for (int i = 0; i < h; i++)
	  sol[i][j] = '.';
      rem -= q*h;
      sq += q;
    } else if (sq == w) {
      int q = rem / w;
      for (int i = sq; i < sq + q; i++)
	for (int j = 0; j < w; j++)
	  sol[i][j] = '.';
      sq += q;
      rem -= q*w;
    }
    if ((sq == 1) && (m != w*h - 1) && (m != 0)) {
      printf("Impossible\n");
      continue;
    }
    sol[0][0] = 'c';
    int lasti = min(sq,h)-1;
    int lastj = min(sq,w)-1;
    if (sq < h) {
      int i;
      for (i = 0; rem > 0 && i < sq; i++, rem--)
	sol[sq][i] = '.';
      if (i == 1 && w >= 2) {
	if (min(sq,w) == 2) {
	  printf("Impossible\n");
	  continue;
	}
	else {
	  sol[sq-1][min(sq,w)-1] = '*';
	  sol[sq][i] = '.';
	}
      }
      if (i >= 1) {
	lasti = sq;
	lastj = i-1;
      }
    }
    if (sq < w) {
      int i;
      for (i = 0; rem > 0 && i < sq; i++, rem--)
	sol[i][sq] = '.';
      if (i == 1 && h >= 2) {
	if (min(sq,h) == 2) {
	  printf("Impossible\n");
	  continue;
	}
	else {
	  assert(sol[lasti][lastj]=='.');
	  sol[lasti][lastj] = '*';
	  sol[i][sq] = '.';
	}
      }
    }
    sol[0][0] = 'c';
    FOR(i,0,h) {
      FOR(j,0,w)
	printf("%c", sol[i][j]);
      printf("\n");
    }
    vector<vector<int> > nb(h, vector<int>(w,0));
    vector<vector<bool> > vis(h, vector<bool>(w,false));
    FOR(i,0,h) {
      FOR(j,0,w) {
	int cpt = 0;
	if(okok(i-1,j-1)) cpt++;
	if(okok(i-1,j))   cpt++;
	if(okok(i-1,j+1)) cpt++;
	if(okok(i,j-1))   cpt++;
	if(okok(i,j+1))   cpt++;
	if(okok(i+1,j-1)) cpt++;
	if(okok(i+1,j))   cpt++;
	if(okok(i+1,j+1)) cpt++;
        nb[i][j] = cpt;
      } 
    }
    stack<pair<int,int> > q;
    vis[0][0]=true;
    q.push(mp(0,0));
    while(!q.empty()) {
      pair<int,int> t = q.top();
      q.pop();
      int i = t.first;
      int j = t.second;
      if (nb[i][j] != 0) continue;
      add(i-1,j-1);
      add(i-1,j);
      add(i-1,j+1);
      add(i,j-1);
      add(i,j+1);
      add(i+1,j-1);
      add(i+1,j);
      add(i+1,j+1);
    }
    FOR(i,0,h) FOR(j,0,w) {
      if ((sol[i][j]!='*') && (!vis[i][j])) {
	cout << "oups " << h << " " << w << " " << m << endl;
	assert(0);
      }
    }
  }
  
  return 0;
}
