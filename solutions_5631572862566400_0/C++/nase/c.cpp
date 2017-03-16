#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

using namespace std;

#define ll          long long
#define VI          vector<int>
#define ALL(a)      (a).begin(), (a).end()
#define SORT(a)     sort( ALL(a) )
#define PB          push_back
#define FOR(i,a,b)  for( int i = (a); i < (int)(b); i++ )
#define dump_(x)     cerr << #x << " = " << (x) << " ";
#define dump(x)     cerr << #x << " = " << (x) << endl
#define dump_vec(x) FOR(zZz,0,x.size()) cout << x[zZz] << " "; cout << endl


template< typename type > type readOne()
{
  type res;
  char inp[5000];
  char* dum = fgets( inp, sizeof( inp ), stdin );
  stringstream ss( dum );
  ss >> res;
  return res;
}

template< typename type > vector<type> readMulti()
{
  vector<type> res;
  char inp[5000];
  char* dum = fgets( inp, sizeof( inp ), stdin );
  stringstream ss( dum );
  for ( type t; ss >> t; )
    res.push_back( t );
  return res;
}

//
//
// LET'S START
//
//
int dis[1001][1001];
int memo[1001];
void calcDis(vector<int> &F, int start) {
    memset(memo, 0, sizeof(memo));
    int cur = start;
    for (int i = 0; i < 1005; i++) {
	if (memo[cur]) break;
	memo[cur] = 1;
	dis[start][cur] = i;
	//	cerr << start << " => " << cur << " = " << i << endl;
	cur = F[cur];
	if (cur == -1) break;
    }
}

int line(int N, vector<int> &F, int start) {
    int len = 0;
    for (int i = 0; i < N; i++) {
	if (i == start) continue;
	len = max(len, dis[i][start]);
    }
    return len;
}

int circle(int N, vector<int> &F, int start) {
    int len = 1;
    for (int i = 0; i < N; i++) {
	if (i == start) continue;
	if (dis[start][i] > 0 && dis[i][start] > 0) {
	    len = max(len, dis[start][i] + dis[i][start]);
	}
    }
    return len;
}

int doit(int N, vector<int> F) {
    int a = 0;
    int b = 0;
    int recip[2000] = {0};
    for (int i = 0; i < N; i++) {
	int f = F[i];
	if (F[f] == i) {
	    //cerr << f << " is recip of " << i << endl;
	    recip[i] = 1;
	}
    }
    for (int i = 0; i < N; i++) {
	if (recip[i]) F[i] = -1;
    }
    memset(dis, -1, sizeof(dis));
    for (int i = 0; i < N; i++) {
	calcDis(F, i);
    }
#if 0
    printf("--\n");
    for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
	    printf("%d ", dis[i][j]);
	}
	printf("\n");
    }
    printf(">>\n");
#endif
    for (int i = 0; i < N; i++) {
	int f = F[i];
	// recip
	if (recip[i]) {
	    //cerr << i << " is recip" << endl;
	    a += (line(N, F, i) + 1);
	    //cerr << "add line => a = " << a << " start at " << i << endl;
	}
	else {
	    b = max(b, circle(N, F, i));
	    //cerr << "circle b = " << b << " start at " << i << endl;
	}
    }
    return max(a, b);
}

int doCase()
{
  //
  // DOIT!
  //
  int N = readOne<int>();
  vector<int> F = readMulti<int>();
  for (int i = 0; i < N; i++) {
      F[i]--;
  }
  return doit(N, F);
}

int main()
{
  int cases = readOne<int>();
  for (int caseno = 1; caseno <= cases; caseno++)
    cout << "Case #" << caseno << ": " << doCase() << endl;
  return 0;
}

