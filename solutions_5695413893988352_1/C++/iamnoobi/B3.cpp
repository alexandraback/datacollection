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
pair<string, string> largest[20], smallest[20];
string s1, s2;

void solve(int k){
	if(k == n) smallest[k] = make_pair("", ""), largest[k] = make_pair("", "");
	else {
		solve(k+1);
		vi pos1, pos2;
		if(s1[k] != '?') pos1.push_back(s1[k] - '0');
		else FOR(i, 0, 10) pos1.push_back(i);
		if(s2[k] != '?') pos2.push_back(s2[k] - '0');
		else FOR(i, 0, 10) pos2.push_back(i);

		ll maxi = -1;
		ll mini = 1000000000000000000ll;

		for(int i : pos1) for(int j : pos2){
			string combi1 = to_string(i) + largest[k+1].first;
			string combi2 = to_string(j) + largest[k+1].second;
			string combi3 = to_string(i) + smallest[k+1].first;
			string combi4 = to_string(j) + smallest[k+1].second;
			ll diff1 = abs(stoll(combi1) - stoll(combi2));
			ll diff2 = abs(stoll(combi3) - stoll(combi4));
			//cout << diff1 << " " << diff2 << endl;
			if(diff2 < mini){
				mini = diff2;
				smallest[k] = make_pair(combi3, combi4);
			}
			if(diff1 < mini){
				mini = diff1;
				smallest[k] = make_pair(combi1, combi2);
			}
			if(diff1 > maxi){
				maxi = diff1;
				largest[k] = make_pair(combi1, combi2);
			}
			if(diff2 > maxi){
				maxi = diff2;
				largest[k] = make_pair(combi3, combi4);
			}
		} 
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("output.txt", "w", stdout);
  cin >> tc;
  while(tc--){
  	cin >> s1 >> s2;
  	n = SZ(s1);
  	solve(0);
  	cout << "Case #" << cse++ << ": ";
  	cout << smallest[0].first << " " << smallest[0].second << endl;
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