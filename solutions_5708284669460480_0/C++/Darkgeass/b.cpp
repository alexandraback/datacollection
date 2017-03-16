#include <iostream>
#include <vector>
#include <map>
#include <set>
#define EPS 1e-8

using namespace std;

typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef vector<char> vc;
typedef vector<vc> vvc;

int k,l,s;
string kb,tg;
vi ktg;
int bant;
map<char,ld> prob;
map<char,ld>::iterator it;
bool flag;

bool pos(){
	for(int i = 0; i < l; ++i){
		bool enc = false;
		for(int j = 0; j < k; ++j){
			if(kb[j] == tg[i]){
				enc = true;
				break;
			}
		}
		if(!enc) return false;
	}
	return true;
}

void kmp(){
	ktg = vi(l,-1);
	int kk = 0;
	for(int i = 1; i < l; ++i){
		while(kk != 0 and tg[i] != tg[kk]) kk = ktg[kk-1]+1;
		if(kk == 0 and tg[i] != tg[kk]) kk = -1;
		ktg[i] = kk;
		++kk;
	}
}

vvd din;

ld dina(int a,int b){
	if(a == s and b == l) return 1.;
	if(a == s) return 0.;
	if(din[a][b] == -1){
		int kk = b;
		ld acum = 0.;
		set<char> g;
		if(kk == l){
			acum += 1.;
			kk = ktg[kk-1]+1;
		}
		while(kk != 0){
			if(g.find(tg[kk]) == g.end()){
// 				if(flag) cout << tg[kk] << " y se inserta " << a << ' ' << b << endl;
				acum += prob[tg[kk]]*dina(a+1,kk+1);
				g.insert(tg[kk]);
			}
			kk = ktg[kk-1]+1;
		}
		if(g.find(tg[0]) == g.end()){
			acum += prob[tg[0]]*dina(a+1,1);
			g.insert(tg[0]);
		}
// 		if(flag) cout << "acum " << acum << " a " << a << " b " << b << endl;
		ld probway = 0.;
		for(int i = 0; i < k; ++i){
			if(g.find(kb[i]) == g.end()){
// 				if(flag) cout << kb[i] << ' ' << probway << endl;
				probway += prob[kb[i]];
				g.insert(kb[i]);
			}
		}
		acum += probway*dina(a+1,0);
// 		if(flag) cout << "prob " << probway << endl;
// 		if(flag) cout << "acum " << acum << " a " << a << " b " << b << endl;
		din[a][b] = acum;
	}
// 	if(flag) cout << a << ' ' << b << ' ' << din[a][b] << endl;
	return din[a][b];
}

int main(){
	int t; cin >> t;
	cout.precision(8);
	cout.setf(ios::fixed);
	for(int cass = 1; cass <= t; ++cass){
// 		if(cass == 3) flag = true;
// 		else flag = false;
		prob.clear();
		cin >> k >> l >> s;
		cin >> kb >> tg;
		if(!pos() or s < l){
			cout << "Case #" << cass << ": " << 0.0 << endl;
			continue;
		}
		kmp();
// 		for(int i = 0; i < l; ++i){
// 			cout << ktg[i] << ' ';
// 		}
// 		cout << endl;
		int x = ktg[l-1]+1;
		bant = (s-l)/(l-x)+1;
		for(int i = 0; i < k; ++i) prob[kb[i]] += ld(1.)/ld(k);
// 		if(flag) for(int i = 0; i < k; ++i) cout << kb[i] << ' ' << prob[kb[i]] << ' ';
// 		if(flag) cout << endl;
// 		cout << s << ' ' << l << ' ' << x << endl;
// 		cout << "bananas " << bant << endl;
		din = vvd(s,vd(1+l,-1));
		cout << "Case #" << cass << ": " << ld(bant)-dina(0,0) << endl;
	}
}