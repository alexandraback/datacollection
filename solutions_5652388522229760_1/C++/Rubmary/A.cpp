#include <bits/stdc++.h>
using namespace std;

#define FOR(i, to, from) for(int i=to; i<from; i++)
#define ri(n) scanf("%d", &n)
#define rii(n, m) scanf("%d %d", &n, &m);
#define ms(obj,val) memset(obj, val, sizeof(obj))

typedef long long ll;
typedef vector<int> vi;

bool used[10];
int cant, T;
void digitos(ll N){
	while(N){
		if(!used[N%10]){
			used[N%10]=true;
			cant++;
		}
		N/=10;
	}
}
int main(){
	cin >>T;
	FOR(t, 1, T+1){
		cout <<"Case #"<< t << ": ";
		ms(used, false);
		ll N, M=0;
		cin >> N;
		if(N==0){
			cout << "INSOMNIA" << endl;
			continue;
		}
		bool cont=true;
		cant = 0;
		while(cont){
			M += N;
			digitos(M);
			if(cant==10) cont = false;
		}
		cout << M << endl;
	}	
}
