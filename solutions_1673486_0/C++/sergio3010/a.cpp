#include <bits/stdc++.h>
using namespace std;


#define Fr(i,a,b) for(int i=a;i<b;++i)


int t,a,b;
double vet[100];
double esps[100010];
double esp;



double calculaProb(int n){
	double prob = 1;
	Fr(i,0,a){
		if(((1<<i)&n)){
			prob *= vet[i];
		}
		else{
			prob *= (1-vet[i]);
		}
	}
	return prob;
}




void solve(int x, int y){
	if(y != a){
		solve(x|(1<<y),y+1);
		solve(x,y+1);
	}
	else{
		double p = calculaProb(x);
		esps[0] += p*(b+2);
		int esq = -1;
		Fr(i,0,a){
			if(esq == -1 && !((1<<i)&x)){
				esq = i;
				break;
			}
		}
		if(esq == -1) esq = a+1;
		for(int i = 1; i <= a; i++){
			if(a-esq > i){
				esps[i] += p*(2*i+(b-a)+b+2);
			}
			else{
				esps[i] += p*(2*i+(b-a)+1);
			}
		}
		esps[100000] += ((x == ((1<<a)-1)) ? (p*(b-a+1)) : (p*(b-a+b+2)));
	}
}





int main(){
	scanf("%d",&t);
	Fr(cas,1,t+1){
		esp = 100000000.0;
		scanf("%d %d",&a,&b);
		Fr(i,0,a){
			scanf("%lf",&vet[i]);
		}
		Fr(i,0,b+1){
			esps[i] = 0.0;
		}
		esps[100000] = 0.0;
		solve(0,0);
		double re = 100000000.0;
		Fr(i,0,a+1){
			re = min(re, esps[i]);
		}
		re = min(re, esps[100000]);
		printf("Case #%d: %.6lf\n",cas,re);
	}
	return 0;
}
