#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define INF 1000000000000000000LL
 
char linha[1000010], linha2[1000010];
ll L, X;
int T;
int regra_letra[11][11]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
int regra_sinal[11][11]={{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};

struct complexo{
	int sinal, letra;
	complexo(int s_=0, int l_=0){sinal=s_; letra=l_;}
};

complexo Pt;

complexo to_complexo(char c){
	if(c=='i') return complexo(1, 1);
	if(c=='j') return complexo(1, 2);
	return complexo(1, 3);
}

complexo multiplica(complexo a, complexo b){
	complexo c(1, 0);
	c.sinal = a.sinal*b.sinal;
	c.sinal *= regra_sinal[a.letra][b.letra];
	c.letra = regra_letra[a.letra][b.letra];
	return c;
}

ll find_K(complexo A, complexo B){
	if(B.sinal==1 && B.letra==0) return 0;
	if(B.sinal==A.sinal && B.letra==A.letra) return 1;
	complexo C = multiplica(A, A);
	if(C.sinal==B.sinal && C.letra==B.letra) return 2;
	C = multiplica(C, A);
	if(C.sinal==B.sinal && C.letra==B.letra) return 3;
	return INF;
}

ll comp_min(char s[], complexo b){
	Pt = complexo(1, 0);	
	ll tam = strlen(s);	
	for(ll i=0; i<tam; i++){
		complexo atu = to_complexo(s[i]);
		Pt = multiplica(Pt, atu);
	}
	ll respmin=INF;
	complexo ac(1, 0);
	//cout << Pt.sinal<<" "<<Pt.letra<<endl;
	for(ll i=0; i<tam; i++){
		complexo atu = to_complexo(s[i]);
		ac = multiplica(ac, atu);
		complexo B = multiplica(b, ac);
		B.sinal *= -1;
		ll K = find_K(Pt, B);
		//cout << ac.sinal << " "<<ac.letra<<" "<<B.sinal << " "<<B.letra<<" "<<K<<endl;
		if(K<INF) respmin = min(respmin, i+K*tam);
	}
	return respmin;
}

ll comp_min2(char s[], complexo b){
	ll tam = strlen(s);	
	ll respmin=INF;
	complexo ac(1, 0);
	for(ll i=0; i<tam; i++){
		complexo atu = to_complexo(s[i]);
		ac = multiplica(atu, ac);
		complexo B = multiplica(ac, b);
		B.sinal *= -1;
		ll K = find_K(Pt, B);
		//cout << ac.sinal << " "<<ac.letra<<" "<<B.sinal << " "<<B.letra<<" "<<K<<endl;
		if(K<INF) respmin = min(respmin, i+K*tam);
	}
	return respmin;
}

int main(){
	scanf("%d", &T);
	for(int caso=1; caso<=T; caso++){
		scanf("%lld %lld\n", &L, &X);
		
		gets(linha);
		
		ll tam = strlen(linha);
		for(ll i=tam-1; i>=0; i--){
			linha2[tam-i-1] = linha[i];
		}
		linha2[tam]='\0';
			
		ll left = comp_min(linha, complexo(1, 1));
		ll right = comp_min2(linha2, complexo(1, 3));
		
		right = L*X - right -1;
		
		int exp = X%4;
		complexo Ptotal(1, 0);
		for(int i=0; i<exp; i++){
			Ptotal = multiplica(Ptotal, Pt);
		}
		bool end = (Ptotal.sinal==-1 && Ptotal.letra==0);
		
		//printf("%lld %lld\n", left, right);
		printf("Case #%d: %s\n", caso, ((right-left>=2) && end)?"YES":"NO");	
	}		
	return 0;
}

