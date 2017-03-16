#include <bits/stdc++.h>
using namespace std;
int tcs, mst[] = {0, 9};
char buf[10000], buf2[10000];
int ansa, ansb;
void nex(int i, int a, int b){
	//printf("%i, %i, %i\n", i, a, b);
	if(i == strlen(buf)){
		int da = abs(a - b), db = abs(ansa - ansb);
		//printf("%i vs %i\n", da, db);
		if(da < db) {
			//printf("setting\n");
			ansa = a; ansb = b;
		} else if(da == db){
			if(a < ansa) {
				ansa = a; ansb = b;
			} else if (a == ansa && b < ansb) ansb = b;
		}
		return;
	}
	a *= 10; b *= 10;
	if(buf[i] == '?' && buf2[i] == '?') {
		for(int j=0;j<10;j++){
			a += j;
			for(int k=0;k<10;k++){
				b += k;
				nex(i+1, a, b);
				b -= k;
			}
			a -= j;
		}
		return;
	}
	if(buf[i] != '?' && buf2[i] != '?') {
		a += buf[i] - '0'; b += buf2[i] - '0'; nex(i+1, a, b);
	}
	if(buf[i] == '?'){
		b += buf2[i] - '0';
		for(int g=0;g<10;g++){
			a += g;
			nex(i+1, a, b);
			a -= g;
		}
	}
	else if (buf2[i] == '?'){
		a += buf[i] - '0';
		for(int g=0;g<10;g++){
			b += g;
			nex(i+1, a, b);
			b -= g;
		}
	}
}
int main(){
	scanf("%i\n", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		scanf("%s%s", buf, buf2);
		//brute force haiz
		ansa = - (1<<10); ansb = 1<<10;
		//fill all ? with either k-1, k, k+1, 0, 9
		nex(0, 0, 0);
		char fmt[1000];
		sprintf(fmt, "Case #%i: %%0%ii %%0%ii \n", tc, strlen(buf), strlen(buf));
		printf(fmt, ansa, ansb);
	}
}