#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
int A[2000];
int B[2000];
int cache[1<<11][1<<11];
int N;
int solve(int mask1, int mask2){
	if(mask2==0){
		return 0;
	}
	int &sol=cache[mask1][mask2];
	if(sol!=-1){
		return sol;
	}
	int stars=0;
	for(int i=0;i<N;++i){
		if(!(mask2&(1<<i))){
			stars+=2;
		}else if(!(mask1&(1<<i))){
			stars+=1;
		}
	}
	//----------------
	int best=-2;
	for(int i=0;i<N;++i){
		if(!(mask2&(1<<i))){
			continue;
		}
		if(stars>=B[i]){
			int m1=mask1&(~(1<<i));
			int m2=mask2&(~(1<<i));
			int opc=solve(m1, m2);
			if(opc>=0){
				if((best<0) || (opc+1<best)){
					best=opc+1;
				}
			}
		}else{
			if((mask1&(1<<i)) && (stars>=A[i])){
				int m1=mask1&(~(1<<i));
				int m2=mask2;
				int opc=solve(m1, m2);
				if(opc>=0){
					if((best<0) || (opc+1<best)){
						best=opc+1;
					}
				}
			}
		}
	}
	sol=best;
	return sol;
}
int main(int argc, char *argv[]){
	int T;
	cin>>T;
	for(int c=1;c<=T;++c){
		cin>>N;
		for(int i=0;i<N;++i){
			cin>>A[i]>>B[i];
		}
		int mask1=(1<<N)-1;
		int mask2=(1<<N)-1;
		memset(cache, -1, sizeof(cache));
		int sol=solve(mask1, mask2);
		if(sol<0){
			printf("Case #%d: Too Bad\n",c);
		}else{
			printf("Case #%d: %d\n",c,sol);
		}
		
	}
	return 0;
}

