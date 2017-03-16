#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init() {
}

// 変数を書く

ll N;
vector<ll> D;
vector<ll> H;
vector<ll> M;

void input() {
  cin >> N;
  D.clear();
  H.clear();
  M.clear();
  for (auto i=0; i<N; i++) {
    ll d;
    ll h;
    ll m;
    cin >> d >> h >> m;
    D.push_back(d);
    H.push_back(h);
    M.push_back(m);
  }
}

void output() {
  ll tot = 0;
  for (auto i=0; i<N; i++) {
    tot += H[i];
  }
  if (tot <= 1) {
    cout << 0 << endl;
    return;
  }
  vector< pair<ll, ll> > people; // degree, time/round
  for (auto i=0; i<N; i++) {
    for (auto j=0; j<H[i]; j++) {
      people.push_back(make_pair(360-D[i], M[i]+j));
    }
  }
  if (people[0].second > people[1].second) {
    swap(people[0].first, people[1].first);
    swap(people[0].second, people[1].second);
  }
  // people[0]のほうが早い
  people[0].first += 360;
  // cerr << people[0].first << " " << people[0].second << endl;
  // cerr << people[1].first << " " << people[1].second << endl;
  if (people[1].first*people[1].second >= people[0].first*people[0].second) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
}

int main() {
  init();
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    cout << "Case #" << t << ": "; 
    input();
    output();
  }
}
