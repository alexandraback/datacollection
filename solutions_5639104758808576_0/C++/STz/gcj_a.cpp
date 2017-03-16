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
		int n, cnt = 0, sum = 0;
		char m[1111];
		fscanf(f, "%d%s",&n,&m);
		for(int i=0;i<=n;i++){
			if(sum < i && m[i]>'0'){
				cnt += i-sum;
				sum += i-sum;
			}
			sum += m[i]-'0';
		}
		fprintf(g, "Case #%d: %d\n", s, cnt);
	}
	fclose(f);
	fclose(g);
	return 0;
}