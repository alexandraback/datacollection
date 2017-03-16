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

int tc, cse = 1;
int n, pos;
int freq[3000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("output.txt", "w", stdout);
  
  cin >> tc;
  while(tc--){
    cin >> n;
    fill(freq, 0);
    FOR(i, 0, 2*n-1){
      FOR(j, 0, n){
        int x;
        cin >> x;
        freq[x]++;
      }
    }
    vi all;
    FOR(i, 0, 3000){
      if(freq[i] % 2 == 1){
        all.push_back(i);
      }
    }
    sort(ALL(all));
  	cout << "Case #" << cse++ << ":";
    FOR(i, 0, n){
      cout << " " << all[i];
    }
    cout << endl;
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