#include <cstdio>
#include <cstdlib>
using namespace std;

int main(void){
	FILE *f, *g;
	f = fopen("a.in", "r");
	g = fopen("a.out", "w");
	int t;
	fscanf(f,"%d",&t);
	for(int s=1; s<=t; s++){
		int n, additional = 0, stood = 0;
		char m[1111];
		fscanf(f, "%d%s",&n,&m);
		for(int i=0;i<=n;i++){
			if(stood < i && m[i] > '0'){
				additional += i - stood;
				stood = i;
			}
			stood += m[i] - '0';
		}
		fprintf(g, "Case #%d: %d\n", s, additional);
	}
	fclose(f);
	fclose(g);
	return 0;
}