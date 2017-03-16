#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i=1;i<=T;i++) {
    long long E, R, N;
    //scanf("%d %d %d\n",&E,&R,&N);
    cin >> E >> R >> N;
    if (R>E) R=E;
    vector<long long> w;
    for (int j=0;j<N;j++) {
      int v;
      cin >> v;
      w.push_back(v);
    }
    long long value = 0;
    deque<pair<long long,int> > q; // value, amount
    for (int j=N-1;j>=0;j--) {
      //clog << "processing " << j << endl;
      long long e = R;
      if (j==0) e=E;
      while ((!q.empty()) && q.front().first > w[j] && e>0) {
	//clog << "use " << q.front().second << " of e=" << e << " on " << q.front().first << endl;
	long long use = min((int)q.front().second,(int)e);
	q.front().second -= use;
	e-=use;
	value += use*q.front().first;
	if (q.front().second==0) q.pop_front();
	//clog << "after value " << value << endl;
      }
      if (e>0) value += e*w[j];
      long long passable = E-R;

      for (int k=0;k<q.size();k++) {
	if (q[k].first <= w[j]) {
	  q.resize(k);
	  break;
	}
	if (passable<q[k].second) {
	  q[k].second=passable;
	  q.resize(k+1);
	  passable=0;
	  break;
	}
	passable -= q[k].second;
      }
      q.push_back(make_pair(w[j], passable));
      //clog << "value = " << value << endl;
    }
    printf("Case #%d: %lld\n", i, value);
  }
  return 0;
}


