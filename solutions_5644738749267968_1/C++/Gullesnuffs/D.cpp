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

double a[1005], b[1005];
int N;

int war(){
	int bPos=0;
	int ans=0;
	for(int i=0; i < N; ++i){
		while(bPos < N &&b[bPos] < a[i])
			++bPos;
		if(bPos < N){
			++bPos;
		}
		else
			++ans;
	}
	return ans;
}

int deceitfulWar(){
	for(int i=0; i < N; ++i){
		double tmp=a[i];
		a[i]=b[i];
		b[i]=tmp;
	}
	return N-war();
}

int main(){
	FILE *fin = fopen("input.in", "r");
	FILE *fout = fopen("output.txt", "w");
	int T;
	fscanf(fin, "%d", &T);
	for(int t=1; t <= T; ++t){
		fscanf(fin, "%d", &N);
		for(int i=0; i < N; ++i)
			fscanf(fin, "%lf", a+i);
		for(int i=0; i < N; ++i)
			fscanf(fin, "%lf", b+i);
		sort(a, a+N);
		sort(b, b+N);
		int ans2=war();
		int ans1=deceitfulWar();
		fprintf(fout, "Case #%d: %d %d\n", t, ans1, ans2);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
