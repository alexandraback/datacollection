#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int T,res;
	long long x,y,tmp,temp;
	bool cek;
	double t;
	scanf("%d",&T);
	for(int z=1;z<=T;z++) {
		scanf("%lld/%lld",&x,&y);
		tmp = x;
		temp = y;
		while(temp) {
			tmp = tmp%temp;
			tmp = tmp+temp;
			temp = tmp-temp;
			tmp = tmp-temp;
		}
		x/= tmp;
		y/= tmp;
		temp = y;
		cek = true;
		while(temp>1) {
			if(temp&1) {
				cek = false;
				break;
			}
			temp/=2;
		}
		if(cek) {
			res = 1;
			t = double(x)/double(y);
			while(t<0.5) {
				t*=2;
				res++;
			}
		}
		else res=-1;
		printf("Case #%d: ",z);
		if(res==-1) printf("impossible\n");
		else printf("%d\n",res);
	}
	return 0;
}
				
					
