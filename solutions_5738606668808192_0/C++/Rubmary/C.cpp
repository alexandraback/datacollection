#include <bits/stdc++.h>
using namespace std;

#define FOR(i, to, from) for(int i=to; i<from; i++)
#define ri(n) scanf("%d", &n)
#define rii(n, m) scanf("%d %d", &n, &m);

typedef long long ll;
int T, N, J;

string num(int i){
	string n;
	n.resize(N, '0');
	n[0]='1';
	int k = 0;
	for (; i>>k; k++) if ((i>>k)&1) n[k+1] = '1';
	for (k=0; k<N/2; k++) n[N-1-k] = n[k];
	return n;
}

int main(){
	cin >>T;
	FOR(t, 1, T+1){
		cout <<"Case #"<< t << ":\n";
		rii(N, J);
		FOR(i, 0, J) cout << num(i) << " 3 4 5 6 7 8 9 10 11" << endl;
	}
}
