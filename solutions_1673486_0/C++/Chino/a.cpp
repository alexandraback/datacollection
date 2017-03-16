#include <cstdlib>
#include <cstdio>

double prob[101000];
int typed, size;
double res[4];
double probC[101000];

void calculate(){
	probC[0]=1.0;
	for(int i=1; i<=typed;i++){
		probC[i] = probC[i-1]*prob[i-1];
	}
}

double keepTyping(){
	int r, w;
	r = size-typed+1;
	w = r+size+1;
	double p=1.0;
	for(int i=0;i<typed;i++){
		p*=prob[i];
	}
	double res;
	res = r*p + w*(1-p);
	return res;
}

double pressRightAway(){
	return 1 + size + 1;
}

double backspaced(int n){
	int r,w;
	r = 2*n + size-typed + 1;
	w = r + size + 1;
	double res = r*probC[typed-n] + w*(1-probC[typed-n]);
	//printf("%d %d %d - %lf(%lf)\n",n,r,w,res,probC[typed-n]);
	
	return res;
}

int main(){
	int T,cases;
	scanf("%d\n",&T);
	cases = 0;
	double aux;
	double min;
	while(cases < T){
		scanf("%d %d\n",&typed, &size);
		for(int i=0; i<typed; i++){
			scanf("%lf\n",&prob[i]);
		}
		calculate();
		min = pressRightAway();
		aux = keepTyping();
		if(min > aux) {
			min = aux;
		}
		for(int i=1;i<=typed;i++){
			aux = backspaced(i);
			if(min > aux) {
				min = aux;
			}
		}
		printf("Case #%d: %lf\n",++cases ,min);
	}
}
