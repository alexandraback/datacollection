#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MAX_E = 10;
const ll MAX_N = 21;
long long enegies[MAX_E][MAX_N];

ll solve(ll E, ll R, ll N, vector<ll> enegy){
  for(int i = 0; i <= E; i++){
    enegies[E-i][0] = i * enegy[0];
  }
  for(int i = 1; i < N; i++){
    ll n = enegy[i];
    // j is now enegy
    for(int j = 0; j <= E; j++){
      for(int k = E; k >= max(0,j-(int)R); k--){
        int e = min(E, k + R);
        enegies[j][i] = max(enegies[j][i], enegies[k][i-1] + (e-j) * n);
      }
    }
  }
  ll max_enegy = 0;
  for(int i = 0; i <= E; i++){
    max_enegy = max(max_enegy, enegies[i][N-1]);
  }
  return max_enegy;
}

int main(){
  vector<int> answer;
  int n;
  ll E, R, N;
  cin >> n;
  for(int i = 0; i < n; i++){
    memset(enegies, 0, sizeof(enegies));
    cin >> E >> R >> N;

    vector<ll> enegy(N);

    for(int j = 0; j < N; j++){
      cin >> enegy[j];
    }

    answer.push_back(solve(E, R, N, enegy));
  }

  for(int i = 0; i < n; i++){
    cout << "Case #" << i+1 << ": " << answer[i] << endl;
  }
  return 0;
}
