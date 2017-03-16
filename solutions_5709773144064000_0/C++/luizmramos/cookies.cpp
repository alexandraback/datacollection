#include <stdio.h>
#define INF 1.0e30


int t;
int main(){
	scanf("%d",&t);
	for(int xxx=0;xxx<t;xxx++){
		double  c,f,x;
		scanf("%lf %lf %lf",&c,&f,&x);
		double tempo = 0;
		double taxa = 2;
		double ans = INF;
		while(true){
			double nestaIteracao = tempo + x/taxa;
			if(nestaIteracao>=ans){
				break;
			}
			ans = nestaIteracao;
			tempo += c/taxa;
			taxa+=f;
		}
		printf("Case #%d: %.7lf\n",xxx+1,ans);
	}
}