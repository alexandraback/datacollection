#include <cstdio>

using namespace std;

long long Monety[1000*100];

int main(){
	int t,i,j;
	int c,d,ile;
	long long v,suma;
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%d%d%lld", &c,&d,&v);
		for(j=0; j<d; j++) scanf("%lld", &Monety[j]);
		suma = 0;
		ile = 0;
		j = 0;
		while(suma < v){
			if( j < d && suma+1 >= Monety[j]  ) {
				suma += (long long)c*Monety[j];
				j++;
			}
			else{
				ile++;
				suma += c*(suma+1);
			}
		}
		printf("Case #%d: %d\n", i+1,ile);
	}
	return 0;
}
