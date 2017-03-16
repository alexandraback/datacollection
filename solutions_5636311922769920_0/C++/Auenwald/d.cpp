#include <bits/stdc++.h>

using namespace std;

#define INTMAX 0x7FFFFFFF
#define INTMIN -0x80000000
#define LONGMAX 0x7FFFFFFFFFFFFFFF
#define LONGMIN -0x8000000000000000

int main(){
	ios_base::sync_with_stdio(false);
	
	int T;
	cin>>T;
	for(int case_nr=1; case_nr<=T; case_nr++){
		cout<<"Case #"<<case_nr<<": ";
		int K,C,S;
		cin>>K>>C>>S;
		long long Kto[C];
		Kto[0] = 1;
		for(int i=1; i<C; i++){
			Kto[i] = K*Kto[i-1];
		}
		int f = K/C;
		if(K%C!=0)
			f++;
		if(S<f){
			cout<<"IMPOSSIBLE";
		}
		else{
			int ind = 0;
			while(ind<K){
				long long ch = 1;
				for(int i=1; i<=C; i++){
					if(ind>=K)
						continue;
					ch +=ind*Kto[C-i];
					ind++;
				}
				cout<<ch<<" ";
			}
		}
		cout<<"\n";
	}
}