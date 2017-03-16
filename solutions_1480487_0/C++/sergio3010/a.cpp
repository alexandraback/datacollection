#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define F first
#define S second
#define MP make_pair
#define Fr(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;


int x=0;
int n, ju[1000], t;

bool f(double d, double val, int ind){
	double resto = 1.0-d;
/*	Fr(i,0,n){
		if(i == ind) continue;
		if(ju[i] > val) return false;
	}*/
	Fr(i,0,n){
		if(i == ind) continue;
		resto = resto - max(0.0,(val-ju[i])/double(x));
	}
	if(resto < 0) return true;
	if(fabs(resto) <= EPS) return true;
	return false;
}





int main(){
	scanf("%d",&t);
	Fr(cas,0,t){
		printf("Case #%d:",cas+1);
		scanf("%d",&n);
		x = 0;
		Fr(i,0,n){
			scanf("%d",&ju[i]);
			x += ju[i];
		}
		Fr(i,0,n){
			double ini=0.0, fim=1.0,meio;
			while(fim-ini > EPS){
				meio = (ini+fim)/2.0;
				if(f(meio, ju[i] + meio*x,i)){
					fim = meio;
				}
				else{
					ini = meio;
				}
			}
			printf(" %.6lf",100*ini);
		}
		printf("\n");
	}	
	return 0;
}
