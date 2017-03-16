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
	cin >> t;
	REP(cas, t){
		int x, r, c;
		cin >> x >> r >> c;
		if(r > c)
			swap(r, c);
		bool exists = false;
		if(x == 1)
			exists = false;
		else if(x == 2){
			if((c*r) % 2 != 0)
				exists = true;
			else exists = false;
		}
		else if(x == 3){
			if((r == 3 && c == 4) || (r == 2 && c == 3) || (r == 3 && c == 3))
				exists = false;
			else exists = true;
		}
		else if(x == 4){
			if((r == 3 && c == 4) || (r == 4 && c == 4))
				exists = false;
			else exists = true;
		}
		cout << "Case #" << cas+1 << ": " << (exists ? "RICHARD" : "GABRIEL") << endl;
	}
	return 0;
}