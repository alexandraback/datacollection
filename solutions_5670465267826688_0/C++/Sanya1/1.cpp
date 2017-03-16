#include <bits/stdc++.h>
#include <unordered_map>
#include <initializer_list>
#include <memory>
#include <vector>
#define mp make_pair
#define pb push_back
#define lo int
#define li long long int
#define db double

#define sz(a) (lo)(a).size()
#define FOR(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
#define DEB(...) fprintf(stderr, __VA_ARGS__)

//=======================
//#define pi 3.14159265358979323
#define eps 1e-9
#define INF 2e9
#define MN 1010
#define SM 2000
//=====================================================

int sign(int a){
	if(a > 0)
		return 1;
	return -1;
}
int q(int a, int b){
	static int ma[4][4] ={
			{
		        1, 2, 3, 4
			},
			{
				2, -1, 4, -3
			},
			{
				3, -4, -1, 2
			},
			{
			    4, 3, -2, -1
			}
	};
	return sign(a) * sign(b) * ma[abs(a) - 1][abs(b) - 1];
}

int binpow(int a, li b){
	if(!b)
		return 1;
	if(b & 1){
		return q(binpow(a, b - 1), a);
	}
	int res = binpow(a, b/  2);
	return q(res, res);
}

int tr(char a){
	static map<char, int> mp= {
			{'i', 2},
			{'j', 3},
			{'k', 4}
	};
	return mp[a];
}

int rev(int a){
	if(abs(a)== 1)
		return a;
	return -a;
}

bool stupid(vector<int> &with, li x){
	int now = 1;
	bool ii = false;
	bool kk = false;
	FOR(i, x){
		FOR(j, sz(with)){
			now = q(now, with[j]);
			if(now == 2){
				ii = true;
			}
			if(now == 4 && ii){
				kk = true;
			}
		}
	}
	return now == -1 && kk;
}

int main()
{
#ifdef MYLOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("matan.in", "r", stdin);
//    freopen("matan.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T;i++){
    	int L;
    	li x;
    	cin >> L >>x ;
    	string s;
    	cin >> s;
    	vector<int> with;
    	for_each(all(s), [&with](char c){ with.pb(tr(c));});
    	/*vector<vector<int> > have(L);
    	int now = 1;
    	int nm = 0;
    	int pos = 0;
    	int pos2 = 0;
    	int pos3 = 0;
     	vector<int> kk,
     				ii;
    	for(int j = 0, k = 0 ; nm < x; nm += (j == L - 1), j = ( j + 1 ) % L, k++){
    		now = q(now, with[j]);
    		auto it = have[0].begin();
    		if((it = find(all(have[j]), now)) != have[j].end()){
    			pos = j;
    			pos2 = it - have[j].begin();
    			pos3 = k;
    			break;
    		}
    		if(now == 4){
				kk.pb(k);
			}
			if(now == 2){
				ii.pb(k);
			}
    		have[j].push_back(now);
    	}

    	string res= "NO";
    	int fin = binpow(have.back()[0], x);
    	if(fin == -1){
    		if(!ii.empty() && !kk.empty()){
    			if(kk.back() > ii.front()) {
    				res = "YES";
    			}
    			int T_begin = pos2 * L + pos;
    			auto it = lower_bound(all(kk), T_begin);
    			if(it != kk.end()){
    				int to = pos3 + (*it - T_begin);
    				if(to < L * x){
    					res = "YES";
    				}
    			}
    		}
    	}
    	*/
    	string res = (stupid(with, x) ? "YES" : "NO");
    	printf("Case #%d: ", i);
    	cout << res << endl;
    }
}
