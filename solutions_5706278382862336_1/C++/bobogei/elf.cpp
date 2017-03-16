#include<bits/stdc++.h>

using namespace std;

typedef long long i64;

int T;
i64 P,Q;

int main(){
	cin >> T;
	for(int _T=0;_T<T;_T++){

		scanf("%I64d/%I64d",&P,&Q);
		i64 gc=__gcd(P,Q);

		P = P/gc;
		Q = Q/gc;

		int fg=0;

		if( Q&(Q-1) ){
			fg=-1;
		}else{
			while(P<Q){
				fg++;	
				P<<=1;
			}
		}
		cout << "Case #" << _T+1 << ": ";
		if(fg==-1||fg>40) cout << "impossible" << endl;
		else cout << fg << endl;
	}
}
