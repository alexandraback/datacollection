#include <cstdio>
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) fr(i,0,b)

using namespace std;

int main(){
	int cas;
	scanf("%d",&cas);
	rep(i,cas){
		double c, f, x;
		scanf("%lf %lf %lf",&c,&f,&x);
		double rsp = x/2.0;
		
		double v=2.0, t=0.0;
		int q=1;
		while(q<1000000){
			double t2 = t + c/v;
			v += f;
			double tmp = t2 + x/v;
			if(tmp<rsp) rsp=tmp;
			else break;
			t=t2;
			q++;
		}
		//printf(">>> %d\n",q);
		
		printf("Case #%d: %.10lf\n",i+1,rsp);
	}
	
	return 0;
}

