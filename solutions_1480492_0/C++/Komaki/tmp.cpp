#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define li        long long int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second


#define MAX 5050
#define M 55
li n;
double s[MAX];
double p[MAX];
string L[MAX];
vector<double> exactly;
vector<double> t;
vector<li> masks;
map<li,li> dp[MAX];
double eps = 0.0001;
bool meet[M][M];
bool touch[M][M];

bool debug = false;

void make(li pos, li mask, li defined)
{
	rep(i, n){
		if(defined & bit(i)) continue;
		rep(j, i){
			if(defined & bit(j)) continue;
			if(!meet[i][j]) continue;
			li next0 = mask | bit(i);
			li next1 = mask | bit(j);
			li next_defined = defined | bit(i) | bit(j);
			rep(k, n){
				if(next_defined & bit(k)) continue;
				li check = 0;
				if(meet[i][k] || touch[i][k]){
					next1 |= bit(k);
					next_defined |= bit(k);
					check |= 1;
				}
				if(meet[j][k] || touch[j][k]){
					next0 |= bit(k);
					next_defined |= bit(k);
					check |= 2;
				}
				if(check == 3) return;
			}
			make(pos, next0, next_defined);
			make(pos, next1, next_defined);
			return;			
		}
	}
	masks.pb(mask);
}

void print_bit(li mask){
	rep(i, n) cout<<((mask >> i) & 1); cout<<endl;
}

inline li get(li mask, li digit){ return ((mask >> digit) & 1); }

li recur(li pos, li mask)
{
	if(debug){
		cout<<endl;
		cout<<"pos: "<<pos<<endl;
		print_bit(mask);
	}
	if(pos == sz(t)) return pos;
	if(dp[pos].find(mask) != dp[pos].end()) return dp[pos][mask];
	li lock_mask = 0;
	rep(i, n)rep(j, n){
		double d0 = p[i] + s[i] * t[pos];
		double d1 = p[j] + s[j] * t[pos];
		bool approach = (d0 < d1) ^ (s[i] < s[j]);
		touch[i][j] = (abs(d0 - d1) + eps < 5.0); 
		meet[i][j] = (abs(d0 - d1) < 5.0 + eps) && approach;
	}
	rep(i, n)rep(j, i)if(touch[i][j]){
		lock_mask |= bit(i) | bit(j);
		if(get(mask, i)	!= get(mask, j)) continue;
		return dp[pos][mask] = pos;
	}
	if(debug)	 cout<<"H"<<endl;
	
	masks.clear();
	li MASK = 0;
	li defined = 0;
	rep(i, n)rep(j, n)if(i != j && touch[i][j]){
		MASK |= (mask & bit(i));
		defined |= bit(i);
		rep(k, n)if(meet[i][k] || touch[i][k]){
			if(i == k) continue;
			if(get(defined, k) && get(MASK, i) == get(MASK, k)){
				if(debug) cout<<"A"<<i<<" "<<k<<endl;
				return dp[pos][mask] = pos;
			}
			defined |= bit(k);
			if(get(MASK, i) == 0) MASK |= bit(k);
		}
	}
	if(debug){
		cout<<"MASK *"; print_bit(MASK);
		cout<<"defined : "; print_bit(defined);
	}
	make(pos, MASK, defined);
	vector<li> candidates = masks;
	if(sz(candidates) == 0) return dp[pos][mask] = pos;
	li res = pos;
	rep(i, sz(candidates)) res = max(res, recur(pos + 1, candidates[i]));
	return dp[pos][mask] = res;
}

int main()
{
	li T;
	cin >> T;
	rep(turn, T){
		cin >> n;
		rep(i, n) cin >> L[i] >> s[i] >> p[i];
		rep(i, MAX) dp[i].clear();
		set<double> S;
		t.clear();
		rep(i, n)rep(j, n)if(s[i] != s[j]){
			if(p[j] < p[i]) continue;
			if(s[i] < s[j]) continue;
			S.insert((p[j] - p[i] - 5) / (s[i] - s[j]));
			S.insert((p[j] - p[i] + 5) / (s[i] - s[j]));
		}
		each(it, S) t.pb(*it);
		if(debug){
			rep(i, sz(t)) cout<<"t : "<<t[i]<<endl;
		}
		li mask = 0;
		rep(i, n)if(L[i] == "L") mask |= bit(i);
		li res = recur(0, mask);
		
		printf("Case #%lld: ", turn + 1);
		if(res == sz(t)) cout<<"Possible"<<endl;
		else printf("%0.20lf\n", t[res]);
	}
}
