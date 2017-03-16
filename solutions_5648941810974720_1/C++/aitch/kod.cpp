#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;

int main(){
	srand(5);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	rep(t,1,T+1){
		cout << "Case #" << t << ": ";
		string s;
		cin >> s;
		int cnt[26] = {};
		rep(i,0,26) cnt[i] = count(allof(s),'A'+i);
		vi ans(10);
		int perm[] = {0,6,8,3,2,4,7,5,1,9};
		string cc = "ZXGHWUSVOE";
		string namn[] = {"ZERO","ONE","TWO","THREE","FOUR","FVE","SIX","SEVEN","EIGHT","NINE"};
		rep(i,0,10){
			int d = perm[i];
			char c = cc[i];
			ans[d] = cnt[c-'A'];
			for(char cc : namn[d])
				cnt[cc-'A'] -= ans[d];
		}
		rep(i,0,10){
			rep(_,0,ans[i]) cout << char('0'+i);
		}
		cout << endl;
	}
}