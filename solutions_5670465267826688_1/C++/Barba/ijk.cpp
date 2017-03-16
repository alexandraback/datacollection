#include <bits/stdc++.h>
using namespace std;

#define rREP(i,n) for(int i = (n)-1; i >= 0; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define rFOR(i,a,b) for(int i = (b); i > (a); i--)
#define FOR(i,a,b) for(int i = (a); i < (b); i++)

typedef long long lint;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

int v[100000];

int mult(int a, int b){

	if(a == 1)
		return b;
	if(a == -1)
		return -b;
	if(a == b)
		return -1;
	if(a == -b)
		return 1;

	int ret;

	if(a == 'i' || a == -'i'){
		if(b == 'j' || b == -'j')
			ret = 'k';
		else ret = -'j';
	}
	else if(a == 'j' || a == -'j'){
		if(b == 'i' || b == -'i')
			ret = -'k';
		else ret = 'i';
	}
	else if(a == 'k' || a == -'k'){
		if(b == 'i' || b == -'i')
			ret = 'j';
		else ret = -'i';
	}
	if(a*b < 0)
		ret *= -1;
	return ret;
}

int main(){
	int t,d;
	int tot, num;
	cin >> t;
	REP(cas, t){
		lint l, x;
		cin >> l >> x;
		bool poss = false;
		string mono;
		cin >> mono;
		int totb = min(4LL, x);
		v[0] = mono[0];
		int fi = -1;
		int fk = -1;
		int lk = -1;
		if(v[0] == 'i')
			fi = 0;
		if(v[0] == 'k')
			fk = lk = 0;
		REP(nb, totb){
			FOR(i, (nb == 0 ? 1:0), l){
				v[i+nb*l] = mult(v[i+nb*l-1], mono[i]);
				if(v[i+nb*l] == 'i'){
					if(fi == -1)
						fi = i+nb*l;
				}
				else if(v[i+nb*l] == 'k'){
					if(fk == -1)
						fk = i+nb*l;
					lk = i+nb*l;
				}
			}
		}
		int fim = 1;
		REP(i, x%4)
			fim = mult(fim, v[l-1]);
		if(fim == -1 && fi >= 0 && fk >= 0){
			poss = (fi < lk) || (fk + 4*l < l*x);
		}
		cout << "Case #" << cas+1 << ": " << (poss ? "YES" : "NO") << endl;
	}
	return 0;
}