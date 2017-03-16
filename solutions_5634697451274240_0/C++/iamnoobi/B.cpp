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
string s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
freopen("output.txt", "w", stdout);
  cin >> tc;
  while(tc--){
  	cin >> s;
  	vi cakes;
  	cakes.assign(SZ(s), 0);
  	FOR(i, 0, SZ(s)){
  		if(s[i] == '+') cakes[i] = 1;
  	}
  	int ans = 0;
  	for(int i = SZ(s)-1; i >= 0; i--){
  		if(cakes[i] == 1) continue;
  		else {
  			ans++;
  			for(int j = 0; j < i; j++){
  				cakes[j] ^= 1;
  			}
  		}
  	}
  	cout << "Case #" << cse++ << ": " << ans << endl;
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