#include <bits/stdc++.h>
using namespace std;
#define M_PI        3.14159265358979323846

typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

void solve(){
    string s;
    int cnum;
    cin >> s;
    map<char, int> vv;
    for(auto x : s){
    	vv[x]++;
    }
    map<int, int> nums;
    cnum = vv['Z'];
    nums[0] += cnum;
    for(auto x : string("ZERO")){
    	vv[x] -= cnum;
    }
    cnum = vv['X'];
    nums[6] += cnum;
    for(auto x : string("SIX")){
    	vv[x] -= cnum;
    }
    cnum = vv['W'];
    nums[2] += cnum;
    for(auto x : string("TWO")){
    	vv[x] -= cnum;
    }
    cnum = vv['U'];
    nums[4] += cnum;
    for(auto x : string("FOUR")){
    	vv[x] -= cnum;
    }
    cnum = vv['S'];
    nums[7] += cnum;
    for(auto x : string("SEVEN")){
    	vv[x] -= cnum;
    }
    cnum = vv['G'];
    nums[8] += cnum;
    for(auto x : string("EIGHT")){
    	vv[x] -= cnum;
    }
    cnum = vv['V'];
    nums[5] += cnum;
    for(auto x : string("FIVE")){
    	vv[x] -= cnum;
    }
    cnum = vv['O'];
    nums[1] += cnum;
    for(auto x : string("ONE")){
    	vv[x] -= cnum;
    }
    cnum = vv['R'];
    nums[3] += cnum;
    for(auto x : string("THREE")){
    	vv[x] -= cnum;
    }
    cnum = vv['I'];
    nums[9] += cnum;
    for(auto x : string("NINE")){
    	vv[x] -= cnum;
    }
    for(auto x : vv){
    	if(isalpha(x.first)){
    		assert(x.second == 0);
    	}
    }
    for(auto x : nums){
    	for(int i = 0; i < x.second; i++){
    		cout << x.first;
    	}
    }
}

int main() {
    ios_base::sync_with_stdio(false);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("nextpartition.in", "r", stdin);
//    freopen("nextpartition.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
    	cout << "Case #" << i << ": ";
    	solve();
    	cout << "\n";
    }
    return 0;
}
