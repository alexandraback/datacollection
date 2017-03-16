#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int N, M;
vector< pair<ll, int> > toy, box;

ll correct_toys(int t, int b, ll wt, ll wb) {
  ll cont = 0;
  while (t < N and b < M and toy[t].second == box[b].second) {
    ll n = min(toy[t].first - wt, box[b].first - wb);
    cont += n;
    wt += n;
    wb += n;
    //cerr << "Aparello " << n << " del tipus " << toy[b].second << endl;
    if (toy[t].first == wt) {
      t++;
      wt = 0;
    }
    if (box[b].first == wb) {
      b++;
      wb = 0;
    }
  }
  if (t >= N or b >= M) return cont;
  else return cont + max(correct_toys(t+1, b, 0, wb), correct_toys(t, b+1, wt, 0));
}

int main() {
  int T, cas;
  cin >> T;
  cas = 1;
  while (cas <= T) {
    cin >> N >> M;
    toy = vector< pair<ll, int> >(N);
    box = vector< pair<ll, int> >(M);
    for (int i = 0; i < N; ++i) cin >> toy[i].first >> toy[i].second;
    for (int i = 0; i < M; ++i) cin >> box[i].first >> box[i].second;
    cout << "Case #" << cas << ": " << correct_toys(0, 0, 0, 0) << endl;
    ++cas;
  }
}