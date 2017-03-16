#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;

int t, r, c, w;
FILE *inp, *out;

int main(){
	inp = fopen("a.in", "r");
	out = fopen("b.out", "w");
	fscanf(inp, "%d", &t);
	//scanf("%d", &t);
	for(int ti = 1; ti <= t; ++ti){
		int ans = 0;
		fscanf(inp, "%d%d%d", &r, &c, &w);
		//scanf("%d%d%d", &r, &c, &w);
		ans = c/w;
		ans *= r;
		ans += w - 1;
		if(c%w != 0) ++ans;
		fprintf(out, "Case #%d: %d\n", ti, ans);
		//printf("Case #%d: %d\n", ti, ans);
	}
	fclose(inp);
	fclose(out);
	return 0;
}
