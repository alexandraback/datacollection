#include<bits/stdc++.h>
using namespace std;
#define FWD(i, a, b) for(int i = (a); i < (b); i++)

const int N = 1e6+1;
int a[N];
int revi(int x){
  string s = to_string(x);
  string r = string(s.rbegin(), s.rend());
  return stoi(r);
}
int main(){
  iota(a + 1, a + N, 1);
  FWD(i, 1, N){
    int r = revi(i);
    a[r] = min(a[r], a[i] + 1);
    if(i+1 < N)a[i+1] = min(a[i+1], a[i] + 1);
  }
  int T;
  ios_base::sync_with_stdio(0);
  cin >> T;
  FWD(t, 1, T+1){
    int x;
    cin >> x;
    cout << "Case #" << t << ": " << a[x] << endl;
  }

}
