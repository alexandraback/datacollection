#include <bits/stdc++.h>
using namespace std;

#define rREP(i,n) for(int i = (n)-1; i >= 0; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define rFOR(i,a,b) for(int i = (a); i >= (b); i--)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define itr iterator

typedef long long lint;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

char cand[10];
int k, l, s;
string board;
string tgt;
int worse;
int testa(){
	int tot = 0;
	int ts = tgt.size();
	if(ts > s)
		return 0;
	REP(ini, s-tgt.size()+1){
		bool ok = true;
		REP(k, ts){
			if(cand[ini+k] != tgt[k])
				ok = false;
		}
		if(ok)
			tot++;
	}
	worse = max(worse, tot);
	return tot;
}

int forma(int passo){
	if(passo == s)
		return testa();
	else{
		int tot = 0;
		REP(i, k){
			cand[passo] = board[i];
			tot += forma(passo+1);
		}
		return tot;
	}
}

int main(){

	int t;
	cin >> t;
	REP(caso, t){
		double ans = 0;
		cin >> k >> l >> s;
		cin >> board;
		cin >> tgt;
		worse = 0;

		double mkv = forma(0);
		int nways = 1;
		REP(i, s)
			nways *= k;
		mkv /= nways;
		ans = worse - mkv;

		cout << "Case #" << caso+1 << ": " << fixed << setprecision(10) << ans << endl;
	}
	return 0;
}