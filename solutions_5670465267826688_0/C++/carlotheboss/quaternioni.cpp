#include <bits/stdc++.h>
using namespace std;

#define MAXL 10010

#define I 2
#define J 3
#define K 4

typedef long long ll;
int T, L;
ll X;
char S[ MAXL ];
int tab[5][5] = { {0,0,0,0,0}, {0, 1, I, J, K}, {0, I, -1, K, -J}, {0, J, -K, -1, I}, {0, K, J, -I, -1} };

int potenze_stringa[ 5 ];

//Ciclo di x : {x, -1, -x, 1}  sempre lungo 4
//             {1,  2,  3, 0}

inline int Prodotto(int a, int b) {
	if(a < 0 && b < 0) return tab[ -a ][ -b ];
	else if(a < 0) return -tab[ -a ][ b ];
	else if(b < 0) return -tab[a][ -b ];
	else return tab[ a ][ b ];
}
inline int Potenza(int b, int e) { 
	if(e==0) return 1;
	int v[ 5 ];
	v[ 0 ] = b;
	for(int i=1;i<4;i++) v[i] = Prodotto(v[i-1], b);
	e %= 4;
	if(e == 0) return v[ 3 ];
	else if(e==1) return v[0];
	else if(e==2) return v[1];
	else return v[2];
}

inline int Converti(char p) {
	if(p == 'i') return I;
	else if(p=='j') return J;
	else return K;
}
int main() {
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for(int i=1;i<=T;i++) {
		cin >> L >> X >> S;
		int sz = int( strlen(S) );
		if(X*sz < 3) { cout<<"Case #"<<i<<": NO\n"; continue; }
		int prod_stringa = 1;
		for(int j=0;j<sz;j++) prod_stringa = Prodotto(prod_stringa, Converti(S[j]));
		potenze_stringa[ 0 ] = 1;
		potenze_stringa[ 1 ] = prod_stringa;
		for(int j=2;j<5;j++) potenze_stringa[ j ] = Prodotto(potenze_stringa[j-1], prod_stringa);
		
		int totale = Potenza(prod_stringa, X);
		int pattern = Prodotto(I, Prodotto(J, K) );
		//cout<<"Totale: "<<totale<<" Pattern: "<<pattern<<endl;
		if(totale != pattern) { cout<<"Case #"<<i<<": NO\n"; continue; }
		
		int len_i=0, len_k=0;
		int tmp1=1, tmp2=1;
		for(int j=0;j<sz;j++) {
			tmp1 = Prodotto(tmp1, Converti(S[j]));
			int e=-1, appo=tmp1;
			for(int k=0;k<5 && k < X && e==-1;k++) {
				appo = Prodotto(appo, potenze_stringa[k]);
				if(appo == I) e=k;
			}
			if(e>=0) len_i = (len_i==0) ? j+1+sz*e : min(len_i, j+1+sz*e);
		}
		
		for(int j=sz-1;j>=0;j--) {
			tmp2 = Prodotto(tmp2, Converti(S[j]));
			int e=-1, appo=tmp2;
			for(int k=0;k<5 && k < X && e==-1;k++) {
				appo = Prodotto(appo, potenze_stringa[k]);
				if(appo == K) e=k;
			}
			if(e>=0) len_k = (len_k==0) ? (sz-j)+sz*e : min(len_k, (sz-j)+sz*e);
		}
		//cout<<"Len_i: "<<len_i<<" Len_k: "<<len_k<<endl;
		cout<<"Case #"<<i<<": ";
		if(len_i > 0 && len_k>0 && len_i+len_k < X*sz) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}

