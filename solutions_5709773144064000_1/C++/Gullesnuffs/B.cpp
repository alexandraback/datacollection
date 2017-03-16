#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

int main(){
	FILE *fin = fopen("input.in", "r");
	FILE *fout = fopen("output.txt", "w");
	int T;
	fscanf(fin, "%d", &T);
	for(int t=1; t <= T; ++t){
		double C, F, X;
		fscanf(fin, "%lf%lf%lf", &C, &F, &X);
		double ans = X/2;
		double time = 0;
		for(int i=0; true; ++i){
			double timePrev=time+X/(2+F*i);
			ans=min(ans, timePrev);
			time += C/(2+F*i);
			if(X/(2+F*(i+1))+time > timePrev)
				break;
		}
		fprintf(fout, "Case #%d: %.7lf\n", t, ans);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
