#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


#define Fr(i,a,b) for(int i=a;i<b;++i)
int t,a,b,n_digits;
int p10[10];



bool match(int a, int b){
	int b2 = 0;
	Fr(i,1,n_digits){
		int tmp1 = b % p10[i];
		b2 = b / p10[i];
		b2 += tmp1*p10[n_digits-i];
		if(a == b2) return true;
	}
	return false;
}




int main(){
	p10[0] = 1;
	Fr(i,1,10) p10[i] = p10[i-1]*10;
	scanf("%d",&t);
	Fr(cas,1,t+1){
		scanf("%d %d",&a,&b);
		int resp = 0;
		n_digits = 0;
		int tmp = b;
		while(tmp){
			n_digits++;
			tmp /= 10;
		}
		Fr(i,a,b+1){
			Fr(j,i+1,b+1){
				if(match(i,j)){
					resp++;
				}
			}
		}
		printf("Case #%d: %d\n",cas,resp);
	}
	return 0;
}
