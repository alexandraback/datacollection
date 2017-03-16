#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back

#define REP(i,n) for(int i=0; i < (n); ++i)

using namespace std;

typedef long long ll;

struct Value
{
	ll v; 
	int i;
	Value() {}
	Value(ll _v, int _i) { v = _v; i = _i;}

	bool operator<(const Value& ot) const {
		if(v == ot.v) return i < ot.i;
		return v > ot.v;
	}
};

int find_left(vector<pair<int,int> >& flow, int i, int r, int e)
{
	for(int ii = i-1; ii >= 0; --ii) {
		if (flow[ii].second != -1) {
			return flow[ii].second + r * (i - ii);
		}
	}
	return e;
}

int find_right(vector<pair<int,int> >& flow, int i, int r, int e)
{
	for(int ii = i+1; ii < flow.size(); ++ii) {
		if (flow[ii].first != -1) {
			return flow[ii].first - r * (ii-i);
		}
	}
	return 0;
}

void solve()
{ 
	int e,r,n;
	ll v[20000];
	vector<Value> vv;
	vector<pair<int,int> > flow;

	cin >> e >> r >> n;
	vv.resize(n);
	flow.resize(n);
	REP(i, n) {
		cin >> v[i];
		vv[i].i = i;
		vv[i].v = v[i];
	}
	sort(vv.begin(), vv.end());

	REP(i,n) {
		flow[i].first = -1;
		flow[i].second = -1;
	}

	ll sol = 0;

	REP(i,n) {
		Value& val = vv[i];
		int begin = find_left(flow, val.i, r, e);
		int end = find_right(flow, val.i, r, e);
		if(begin > e) begin = e;
		if(end < 0) end = 0;
		flow[val.i].first = begin;
		flow[val.i].second = end;
		//cout << vv[i].i << " " << begin << " " << end << endl;
		sol += (begin - end) * vv[i].v;
	}
	cout << sol << endl;
}

int main(int argc, char *argv[])
{
  int t;
  cin >> t;
  string ee;
  getline(cin,ee);

  for(int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}

