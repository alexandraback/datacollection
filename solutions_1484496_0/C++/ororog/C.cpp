#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define REP(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long LL;

int nextInt() {
  char c;
  int res = 0;
  while (!isdigit(c = getchar())){};
  do {
    res = res * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return res;
}

vector<int> vl, vr;
int ls, rs;
int N;
int v[555];
void dfs(int pos) {
  if (pos != 0 && ls == rs) throw 0;
  if (pos == N) return;
  vl.push_back(v[pos]);
  ls += v[pos];
  dfs(pos + 1);
  ls -= v[pos];
  vl.pop_back();

  vr.push_back(v[pos]);
  rs += v[pos];
  dfs(pos + 1);
  rs -= v[pos];
  vr.pop_back();

  dfs(pos+1);
}


int main(){
	int TestCase = nextInt();

	for(int caseCnt=1; caseCnt <= TestCase; caseCnt++){
    N = nextInt();
    REP(i, N) v[i] = nextInt();
    vl.clear();
    vr.clear();
    try {
      dfs(0);
    } catch (int e) {

    }

		printf("Case #%d:\n", caseCnt);
    int sl = 0, sr = 0;
    REP(i, vl.size()) {
      if (i != 0) cout << ' ';
      cout << vl[i];
      sl += vl[i];
    }cout << endl;

    REP(i, vr.size()) {
      if (i != 0) cout << ' ';
      cout << vr[i];
      sr += vr[i];
    }cout << endl;
    //fprintf(stderr, "Case %d\n", caseCnt);
	}
	return 0;
}
