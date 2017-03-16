#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <list>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<(int)b; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair <int, int> pii;
#define debug(x) cerr << #x << " = " << (x) << \
" (L" << __LINE__ << ")" << " " << __FILE__ << endl;
template <class T> void debugall(T a, T b) { cerr << " (L" << __LINE__ << ") "; for(T i = a; i != b; i++) cerr << *i << ", "; cerr << endl; }

vector <bool> check;
int n;
vector <vector <int> > vec;

bool dfs(int i){
    if(check[i] == true) return true;
    check[i] = true;
    FOR(j, 0, vec[i].size()){
        if(dfs(vec[i][j])){
            return true;
        }
    }
    return false;
}

int main() {
	int zz;
	cin >> zz;
	FOR(z, 0, zz){
        cin >> n;
        vec.clear();
        vec.resize(n);
        fill(vec.begin(), vec.end(), vector <int>());
        FOR(i, 0, n){
            int m;
            cin >> m;
            FOR(j, 0, m){
                int tmp;
                cin >> tmp;
                vec[i].pb(tmp-1);
            }
        }

        string res = "No";
        FOR(i, 0, n){
            check.clear();
            check.resize(n);
            fill(check.begin(), check.end(), false);
            if(dfs(i)){
                res = "Yes";
                break;
            }
        }

		printf("Case #%d: ", z+1);
        cout << res << endl;
	}
}
