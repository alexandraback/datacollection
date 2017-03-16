//Program: b
//Author: gary
//Date: 03/05/2014
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ( (int) (x).size() )
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> i2;
typedef long long ll;
const int INF = 1e9;


int solve(){
  int A, B, K, r = 0;
  cin >> A >> B >> K;
  for(int i = 0; i < A; i++)
    for(int j = 0; j < B; j++)
      if( (i & j) < K )
	r ++;
  return r;
}

int main(){
  ios::sync_with_stdio(0);
  int T;
  cin >> T;
  for(int caseno = 1; caseno <= T; caseno++){
    cout << "Case #" << caseno << ": " << solve() << endl;
  }
  return 0;
}
