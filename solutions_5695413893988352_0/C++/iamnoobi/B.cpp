#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;

template <typename Type> void print_array(Type* array, int start, int end);
template <typename Type> void print_vector(vector<Type> v);

#define FOR(i,a,b) for (int i = (a),_b = (b); i < _b; i++)
#define DOW(i,b,a) for (int i = (b),_a = (a); i >= _a; i--)
#define fill(a,v) memset(a, v, sizeof a)
#define checkbit(n,b) ((n >> b) & 1)
#define pb(a) push_back(a)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()

#define INF 1e9
#define PI acos(-1.0)

#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

int tc, cse = 1, n;

int intpow(int b, int k){
  if(k == 0) return 1;
  else return pow(b, k-1) * b;
}

bool can(string s1, int k){
  FOR(i, 0, SZ(s1)){
    if(s1[i] != '?' && (k / intpow(10, n - 1 - i)) % 10 != s1[i] - '0'){
      return false;
    }
  }
  return true;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> tc;
  while(tc--){
    string s1, s2;
    cin >> s1 >> s2;
    n = SZ(s1);
    int diff = 1000000;
    int ans1 = 0, ans2 = 0;
    FOR(i, 0, pow(10, n)) FOR(j, 0, pow(10, n)){
      if(can(s1, i) && can(s2, j)){
        if(abs(i-j) < diff){
          diff = abs(i-j);
          ans1 = i, ans2 = j;
        }
      }
    }
    cout << "Case #" << cse++ << ": ";
    if(n == 1) printf("%d %d\n", ans1, ans2);
    if(n == 2) printf("%02d %02d\n", ans1, ans2);
    if(n == 3) printf("%03d %03d\n", ans1, ans2);

  }

  return 0;
}

template <typename Type>
void print_array(Type* array, int start, int end){
  cout << "[";
  FOR(i, start, end){
    cout << array[i] << " ";
  }
  cout << "]\n";
}

template <typename Type>
void print_vector(vector<Type> v){
  cout << "[";
  FOR(i, 0, SZ(v)){
    cout << v[i] << " ";
  }
  cout << "]\n";
}