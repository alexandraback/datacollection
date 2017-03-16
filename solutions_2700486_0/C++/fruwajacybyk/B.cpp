#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define pb push_back

int t(int k){
	return k*(k+1)/2;
}

int ab(int u){
	return max(u,-u);
}

int poziom(int u,int v){
	return max(ab(u-v),ab(u+v))/2;
}

double binomial(int n,int k){
	double res=1.0;
	FOR(i,0,k){
		res*=(n-i)*1.0/((i+1)*1.0);
		res/=2.;
	}
	FOR(i,k,n) res/=2.;
	return res;
}

double pstwo(int n,int k){
	double a=0.;
	FOR(i,0,k){
		a+=binomial(n,i);
		
	}
	return 1.-a;
}

int main(){
	int z; scanf("%d",&z);
	FOR(test,1,z+1){
		int N,X,Y;
	        scanf("%d%d%d",&N,&X,&Y);
		int poz=1;
		while(1){
			if(N>=t(2*poz-1) && N<t(2*poz+1)) break;
			poz++;
		}
		int zostalo = N-t(2*poz-1);
		double res=0.0;
		int dupa = poziom(X,Y); 
		if(dupa<poz) res=1.0;
		else if(dupa>poz) res=0.0;
		else{
				int wys = (Y+1); 
				if(wys==2*poz+1) res = 0.0;
				else{
					if(zostalo>=2*poz+wys ) { res=1.0;}
					else{
						if(zostalo<wys) res = 0.0;
						else res = pstwo(zostalo, wys);
					}
				}
		}
		
		 	
			
		printf("Case #%d: %.9lf\n",test,res);	
		

	}
	return 0;
}
