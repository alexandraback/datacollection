#include <bits/stdc++.h>
#include <tr1/unordered_set>

using namespace std;
using namespace tr1;

int c, d, v;
int m[1000];
vector < pair < int, int > > vet;

struct tri{
	int sum, b, n, mask;
	tri( int sum = 0, int b = 0, int n = 0, int mask = 0 ) : sum(sum), b(b), n(n), mask(mask) { }
};

bool sumCheck(int M, int mask){
	memset(m,0,sizeof(m));
	m[0]=1;
	vector < int > moeda;
	for( int i = 0; i < vet.size(); i++ ){
		if( mask & (1 << i) ) moeda.push_back(vet[i].first);
	}
	for(int i = 0; i < moeda.size(); i++){
		for(int j = M; j >= moeda[i]; j--){
			m[j] |= m[j-moeda[i]];
		}
	}
	for( int i = 1; i <= v; i++ ) if( !m[i] ) return false;
}

int solve(){
	queue < tri > fila;
	fila.push(tri(0,0,0,0));
	while( !fila.empty() ){
		tri at = fila.front();
		fila.pop();
		if( sumCheck(at.sum,at.mask) ) return at.b;
		if( vet[at.n].second == 0 ){
			fila.push(tri(at.sum+vet[at.n].first, at.b, at.n+1, at.mask | (1 << at.n)));
		}
		else{
			fila.push(tri(at.sum+vet[at.n].first, at.b+1, at.n+1, at.mask | (1 << at.n)));
			fila.push(tri(at.sum+vet[at.n].first, at.b, at.n+1, at.mask));	
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	int t, k = 1, val;
	cin >> t;
	while( t-- ){
		cin >> c >> d >> v;
		map < int, int > mapa;
		for( int i = 0; i < d; i++ ){
			cin >> val;
			vet.push_back(make_pair(val,0));
			mapa[val]++;
		}
		for( int i = 1; i <= v; i++ ){
			if( mapa.count(i) ) continue;
			vet.push_back(make_pair(i,1));
		}
		cout << "Case #" << k++ << ": " << solve() << '\n';
		vet.clear();
	}
	return 0;
}