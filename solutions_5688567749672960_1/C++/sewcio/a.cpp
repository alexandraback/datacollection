#include<bits/stdc++.h>
using namespace std;
#define FWD(i, a, b) for(int i = (a); i < (b); i++)
typedef pair<int, int> PII;
typedef long long LL;
#define st first
#define nd second
const int N = 1e6+1;
int a[N];
LL p10[18];
int revi(int x){
  string s = to_string(x);
  string r = string(s.rbegin(), s.rend());
  return stoi(r);
}
#define VAR(x) #x << " " << x << " "
LL heura(LL x){
  if(x < 10) return x;
  if(x % 10 == 0) return heura(x-1)+1;

  string s = to_string(x);
  int n = s.size();
  LL h = heura(p10[n-1]-1);
  LL rev0 = x-(p10[n-1]-1) + h;
  LL c1 = stoi(s.substr(n-n/2, n/2));
  LL c2 = stoi(string(s.rbegin() + n/2, s.rend()));
    LL rev1 = c1 + c2 + h + 1;
    //    cout << VAR(x) << VAR(rev0) << VAR(rev1) << VAR(c1) << VAR(c2) << endl;
  return min(rev1, rev0);
}
int main(){
  p10[0] = 1;
  FWD(i, 0, 17) p10[i+1] = 10 * p10[i];
  iota(a+1,a+N,1);
  FWD(i, 1, N){
    int r = revi(i);
    if(r < N)
      a[r] = min(a[r], a[i] + 1);
    if(i+1 < N)
      a[i+1] = min(a[i+1], a[i] + 1);
    //    if(a[i] != heura(i))
    // cout << "heura" << i << " " << heura(i) << " " << a[i] << endl;
  }
  int T;
  ios_base::sync_with_stdio(0);
  cin >> T;
  FWD(t, 1, T+1){
    LL x;
    cin >> x;
    cout << "Case #" << t << ": " << heura(x) << endl;
  }

}
