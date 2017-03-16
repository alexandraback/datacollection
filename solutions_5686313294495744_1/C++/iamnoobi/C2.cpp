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
string fw[1010], sw[1010];
int n;
map<string, int> leftwords, rightwords;
int L, R;
vvi graph;
vi vis, match, matched;

int aug(int l){
  if(vis[l]) return 0;
  vis[l] = 1;
  for(int r : graph[l]){
    if(match[r] == -1 || aug(match[r])){
      match[r] = l; return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("output.txt", "w", stdout);
  cin >> tc;
  while(tc--){
    cin >> n;
    leftwords.clear();
    rightwords.clear();
    L = R = 0;
    FOR(i, 0, n){
      cin >> fw[i] >> sw[i];
      if(leftwords.count(fw[i]) == 0){
      	leftwords[fw[i]] = L++;
      }
      if(rightwords.count(sw[i]) == 0){
      	rightwords[sw[i]] = R++;
      }
    }
    graph.assign(L+R, vi());
    FOR(i, 0, n){
    	graph[leftwords[fw[i]]].push_back(L+rightwords[sw[i]]);
    }
    int mcbm = 0;
	match.assign(L+R, -1);
	matched.assign(L+R, 0);
	vis.assign(L+R, 0);
	//FOR(i, 0, SZ(graph)) print_vector(graph[i]);
	FOR(i, 0, L){
		vi avail;	
  		for(int v : graph[i]){
  			if(match[v] == -1){
            	avail.push_back(v);
          	}
  		}
        if(SZ(avail) == 0) continue;
        int t = avail[rand() % SZ(avail)];
        match[t] = i;
        matched[i] = 1;
        mcbm++;
  	}

  	FOR(i, 0, L){
	    if(matched[i] != 1){
	      	vis.assign(n, 0);
	      	mcbm += aug(i);
	    }
  	}
  	//cout << mcbm << endl;
  	cout << "Case #" << cse++ << ": ";
    cout << n-(L+R-mcbm) << endl;
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