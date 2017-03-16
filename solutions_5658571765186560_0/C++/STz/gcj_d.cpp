#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define ll long long
using namespace std;

int main(void){
	FILE *f, *g;
	f = fopen("d.in", "r");
	g = fopen("d.out", "w");
	int t;
	fscanf(f,"%d",&t);
	for(int s=1;s<=t;s++){
		bool q;
		int x, r, c;
		fscanf(f,"%d%d%d",&x,&r,&c);
		if(r*c % x != 0 || x >= 7) q = false;
		else if(x <= 2) q = true;
		else if(r <= x/2 || c <= x/2) q = false;
		else q = true;
		fprintf(g, "Case #%d: ",s);
		if(q) fprintf(g, "GABRIEL\n"); else fprintf(g, "RICHARD\n");
	}
	return 0;
}