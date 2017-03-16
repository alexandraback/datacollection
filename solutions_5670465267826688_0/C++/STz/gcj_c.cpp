#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define ll long long
using namespace std;

int mul[3][8] = {1,4,7,2,5,0,3,6, 2,3,4,5,6,7,0,1, 3,6,1,4,7,2,5,0}, q[256];

int main(void){
	FILE *f, *g;
	f = fopen("c.in", "r");
	g = fopen("c.out", "w");
	int t;
	fscanf(f,"%d",&t);
	for(int s=1;s<=t;s++){
		int l, x, r, step = 0, prod = 0;
		ll xb;
		char m[11111];
		fscanf(f,"%d%lld%s",&l,&xb,&m);
		if(xb > 12) x = 12 + xb%4; else x = xb;
		r = l*x;
		for(int i=0;i<r;i++){
			prod = mul[m[i%l]-'i'][prod];
			if(prod == 1 && step == 0) step = 1;
			else if(prod == 3 && step == 1) step = 2;
		}
		if(prod == 4 && step == 2) step = 3;
		fprintf(g, "Case #%d: ",s);
		if(step == 3) fprintf(g, "YES\n"); else fprintf(g, "NO\n");
	}
	return 0;
}