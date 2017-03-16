#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;

int DP[1002];
int amigo[1002];
vector<int>inv[1002];

int T;
int N;
int act;
int res;

int listaG(int pos){
	int ret = 0,aux;
	if(DP[pos]!=-1)
		return DP[pos];
	if(inv[pos].size()==0){
		DP[pos] = 1;
		return 1;
	}	
	for(int i = 0 ; i < inv[pos].size() ; i++){
		if(inv[pos][i]!=amigo[pos]){
			aux = listaG(inv[pos][i]);
			if(aux > ret)
				ret = aux;
		}
	}
	ret += 1;
	DP[pos] = ret;
	return ret;
}

void busca(int pos){	
	if(DP[pos]==1){
		int aux = amigo[pos],cont = 1;
		DP[pos] = 2;
		while(aux!=pos){
			DP[aux] = 2;
			aux = amigo[aux];
			cont++;			
		}
		if(cont > res)		
			res = cont;		
		return;
	}
	if(DP[pos]==2){
		return;
	}
	DP[pos] = 1;
	busca(amigo[pos]);
	DP[pos] = 2;
}

int main(){
	optimizar_io(0);
	cin>>T;
	for(int caso =1 ; caso <= T; caso++){
		cin>>N;
		res = 0;
		act = 0;
		for(int i = 1; i <= N ; i++){
			inv[i] = vector<int>();
			DP[i] = -1;
		}
		for(int i =1 ; i <= N; i++){
			cin>>amigo[i];
			inv[amigo[i]].push_back(i);
		}			
		for(int i =1 ; i <= N; i++){
			if(DP[i]==-1){				
				if(amigo[amigo[i]]==i){										
					act += listaG(i)+listaG(amigo[i]);
					if(act > res)
						res = act;
				}
			}
		}
		if(act > res)
			res = act;		
		for(int i =1 ; i <= N; i++){
			if(DP[i]==-1){
				busca(i);				
			}
		}		
		cout<<"Case #"<<caso<<": "<<res<<"\n";		
	}
	return 0;
}