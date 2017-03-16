#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
using namespace std;

const int INF = 1 << 30;
const double EPS = 1e-10;

int main()
{
  int T;
  cin >> T;
  for (int Testcase = 1; Testcase <= T; ++Testcase) {
    int N;
    cin >> N;

    int X = 0;
    vector<long long int> s(N);
    for (int i = 0; i < N; ++i) {
      cin >> s[i];
      X += s[i];
    }

    double sum = 0.0;
    vector<double> ans(N, 0.0);
    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > que;
    for (int i = 0; i < N; ++i)
      que.push(make_pair(s[i], i));

    while (que.size() >= 2) {
      pair<double, int> t = que.top();
      que.pop();

      vector<int> index;
      while (!que.empty() && que.top().first - t.first < EPS) {
	index.push_back(que.top().second);
	que.pop();
      }

      if (que.empty())
	break;

      double diff = que.top().first - t.first;
      double p = diff / X;
      if (p*(index.size()+1) + sum >= 1.0) {
	p = (1.0 - sum) / (index.size()+1);
	ans[t.second] += p;
	for (int i = 0; i < index.size(); ++i)
	  ans[index[i]] += p;
	sum = 1.0;
      } else {
	ans[t.second] += p;
	t.first = que.top().first;
	que.push(t);
	for (int i = 0; i < index.size(); ++i) {
	  t.second = index[i];
	  ans[t.second] += p;
	  que.push(t);
	}
	sum += p * (index.size()+1);
      }
    }

    cout << "Case #" << Testcase << ":";
    for (int i = 0; i < N; ++i)
      printf(" %.6f", ((1.0 - sum) / N +ans[i] )*100);
    puts("");
  }
  return 0;
}
