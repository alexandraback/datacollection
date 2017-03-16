#include <bits/stdc++.h>
using namespace std;

#define FOR(i, to, from) for(int i=to; i<from; i++)
#define ri(n) scanf("%d", &n)
#define rii(n, m) scanf("%d %d", &n, &m);

typedef long long ll;
typedef vector<int> vi;

int N;
int T;
string S;

char cambiar(char x){
	if(x=='+') return '-';
	else       return '+';
}
int main(){
	cin >>T;
	FOR(t, 1, T+1){
		cout <<"Case #"<< t << ": ";
		cin >> S;
		N = S.length();
		char ac = '+';
		int res=0;
		FOR(i, 0, N) if(ac!=S[N-1-i]){
			res++;
			ac = cambiar(ac);
		}
		cout << res << endl;
	}
}
