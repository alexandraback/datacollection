#include <cstdio>

using namespace std;

int main(){
	int t,i;
	int r,c,w,wynik;
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%d%d%d", &r,&c,&w);
		if(c%w == 0) wynik = (c-1)/w+w;
		else wynik = wynik = c/w+w;
		wynik += (r-1)*(c/w);
		printf("Case #%d: %d\n", i+1,wynik);
	}
	return 0;
}
