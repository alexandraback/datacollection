#include<bits/stdc++.h>
#include <unistd.h>

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define EPS (double)(1e-9)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 1000006

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }
//to increase stack size : -Wl,--stack,1677721600

int k, l, s, ctt, tot;
string let, tar;

bool chk(int idx, string temp){
	int ll = s-idx;
	if(ll < l) return false;
	int j = idx;
	for(int i = 0;i<l;i++){
		//if(idx == 1) cout << temp[i] << tar[j] << i << j << temp.size() << tar.size() << endl;
		//if(temp[i] != tar[j]){ LOG(i);LOG(idx);LOG(temp[i]);LOG(tar[j]);return false; }
		if(tar[i] != temp[j]) return false;
		j++;
	}
	return true;
}

bool chk1(){
	for(int i = 0;i<l;i++){
		bool found = false;
		for(int j = 0;j<k;j++){
			if(tar[i] == let[j]) found = true;
		}
		if(found == false) return false;
	}
	return true;
}

void solve(int idx, string tt){
	if(idx >= s){
		ctt++;
		//cout << tt << endl;
		for(int i = 0;i<s;i++){
			bool cc = chk(i, tt);
			if(cc) tot++;
		}
		//cout << tot << endl;
		return;
		//return 0.0;
	}
	string temp = tt;
	for(int i = 0;i<k;i++){
		temp = tt;
		solve(idx+1, temp+let[i]);
	}
	//return 0.0;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T, casee = 1;
	cin >> T;
	for(casee=1;casee<=T;casee++){
		cin >> k >> l >> s;
		cin >> let >> tar;
		ctt = 0;
		tot = 0;
		cout << "Case #" << casee << ": " ;
		if(chk1() == false){
			cout << 0.0 << endl;
			continue;
		}
		double need = s-l+1;
		solve(0, "");

		double pp = (double)1.0/(double)ctt;
		double expt = (double)pp * (double)tot;
		double ans = (double)need - (double)expt;
		//LOG(pp);
		//LOG(tot);
		//LOG(ctt);
		//LOG(expt);
		//LOG(need);
		//LOG(ans);
		
		cout << setprecision(7) << ans << endl;
	}
	//fclose(stdin);
	//fclose(stdout);
return 0;	
}

