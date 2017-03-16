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
int n;
int freq[30];

string all[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string order = "ZXGWHUFVIO";
int nums[10] = {0, 6, 8, 2, 3, 4, 5, 7, 9, 1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("output.txt", "w", stdout);
  cin >> tc;
  while(tc--){
    string s;
    cin >> s;
    fill(freq, 0);
    FOR(i, 0, SZ(s)){
      freq[s[i]-'A']++;
    }
    vi digs(10);
    FOR(i, 0, 10){
      //print_array(freq, 0, 26);
      int cnt = freq[order[i] - 'A'];
      string curr = all[nums[i]];
      //cout << curr << endl;
      for(char c : curr){
        freq[c - 'A'] -= cnt;
      }
      digs[nums[i]] = cnt;
    }
  	cout << "Case #" << cse++ << ": ";
    FOR(i, 0, 10){
      FOR(j, 0, digs[i]){
        cout << i;
      }
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