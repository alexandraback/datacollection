#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
using namespace std;

int nao[55],ken[55];
void responde(int& dec,int& nor){
	dec=nor=0;
	int n;
	double aux;
	set<double> N,K;
	set<double>::iterator it;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {scanf("%f",&nao[i]); N.insert(nao[i]);}
	for(int i=0;i<n;i++) {scanf("%f",&ken[i]); K.insert(ken[i]);}
	for(int i=0;i<n;i++){
		it=N.end();
		it--;
		aux=(*it);
		if(aux>(*K.rbegin())){
			nor++;

			N.erase(it);
			K.erase(K.begin());
		}
		else{
			K.erase(K.upper_bound(aux));
			N.erase(it);
		}
	}
	for(int i=0;i<n;i++){
		N.insert(nao[i]);
		K.insert(ken[i]);
	}
	for(int i=0;i<n;i++){
		if((*N.begin())>(*K.begin())){
			N.erase(N.begin());
			K.erase(K.begin());
			dec++;
		}
		else{
			N.erase(N.begin());
			it=K.end();
			it--;
			K.erase(it);
		}
	}
}

int main(){
	int T,t=0,dec,nor;
	scanf("%d",&T);
	while(T--){
		t++;
		responde(dec,nor);
		printf("Case #%d: %d %d\n",t,dec,nor);
	}
}
