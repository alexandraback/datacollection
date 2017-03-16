#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll exp(int K, int C){
    if (C == 0) return 1;
    if (C & 1){
	return (ll) K * exp(K, C - 1);
    }
    ll tmp = exp(K, C/2);
    return tmp * tmp;
}

bool check(int K, int C, const vector<ll> &ans){
    ll sz = exp(K, C);
    if (sz > (int) 1e7) return true;
    for (int mask = 1; mask < (1 << K); mask++){
	string str = ""; 
	for (int i = 0; i < K; i++){
	    if ((1 << i) & mask) str += '1';
	    else str += '0';
	}
	string cur = str;
	for (int depth = 1; depth < C; depth++){
	    string nw = "";
	    for (char c : cur){
		if (c == '1') nw += string(K, '1');
		else nw += str;
	    }
	    cur = nw;
	}
	int g = 0;
	for (auto x : ans) 
	    if (cur[x-1] == '1')
		g++;
	if (g == 0) {
	    cout << str << ' ' << cur << endl;
	    return false;
	}
    }
    return true;
}

void solve(){
    int K, C, S; cin >> K >> C >> S;
    
    int nd = (K + C - 1) / C;
    if (nd > S) {
	cout << " IMPOSSIBLE" << endl;
	return;
    }
    ll totlen = exp(K, C);
    int tk = min(K, C);
    vector<ll> ans;
    for (int i = 0; i < nd; i++){
	ll ch = 0;
	for (int j = 0; j < tk; j++){
	    if (tk * i + j == K) break;
	    ch += (tk * i + j) * exp(K, C - 1 - j);
	}
	ans.push_back(min(totlen, ch + 1));
    }
    for (auto x : ans)
	cout << ' ' << x;
    cout << endl;
//    assert(check(K, C, ans));
}

int main(){
    int tc; cin >> tc;
    for (int cs = 1; cs <= tc; cs++){
	cout << "Case #" << cs << ":";
	solve();
    }

    return 0;
}
