#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;


#define Fr(i,a,b) for(int i=a;i<b;++i)
int t,a,b,n_digits;
int p10[10];
int marcados[10];
int nmark;

int match(int num){
	int b2 = 0;
	int ret = 0;
	nmark = 0;
	Fr(i,1,n_digits){
		int tmp1 = num % p10[i];
		b2 = num / p10[i];
		b2 += tmp1*p10[n_digits-i];
		//printf("%d\n",b2);
		if(b2 > num && b2 <= b){
			bool pode = true;
			Fr(j,0,nmark){
				if(b2 == marcados[j]) pode = false;
			}
			if(pode){
				marcados[nmark++] = b2;
				ret++;
			}
		}
	}
	return ret;
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
		//printf(">>%d\n",match(a));
		Fr(i,a,b+1){
			resp += match(i);
			//printf("%d %d\n",i,match(i));
		}
		printf("Case #%d: %d\n",cas,resp);
	}
	return 0;
}
