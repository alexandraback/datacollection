#include <bits/stdc++.h>

using namespace std;
int used[1000002], vis = 1;
long long obj;
char str[1000001];

int solve(){
	queue < pair<long long,int> > fila;
	fila.push(make_pair(1LL,1));
	used[1] = vis;
	while( !fila.empty() ){
		pair < long long, int > at = fila.front();
		fila.pop();
		if( at.first == obj ) return at.second;
		sprintf(str,"%lu",at.first);
		long long nv = 0;
		reverse(str,str+strlen(str));
		sscanf(str,"%lu",&nv);
		if( at.first+1 <= obj && used[at.first+1] != vis ){
			used[at.first+1] = vis;
			fila.push(make_pair(at.first+1LL,at.second+1));
		}
		if( nv > 0 && nv <= obj && used[nv] != vis ){
			used[nv] = vis;
			fila.push(make_pair(nv,at.second+1));
		}
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	int t, k = 1;
	cin >> t;
	while( t-- ){
		cin >> obj;
		cout << "Case #" << k++ << ": " << solve() << '\n';
		vis++;
	}
	return 0;
}