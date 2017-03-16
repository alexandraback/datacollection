#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iostream>

using namespace std;

FILE *fin;
FILE *fout;

int solve(int a,int b,int k){
	int ret = 0;
	for(int i = 0;i < a;++i)
		for(int j = 0;j < b;++j){
			int t = i & j;
			if(t < k)
				++ret;	
		}
	return ret;
}

int main(){
	fin = fopen("B-small-attempt0.in","r");
	fout = fopen("out.txt","w");
	int T;
	fscanf(fin,"%d",&T);
	for(int cas = 1;cas <= T;++cas){
		int a,b,k;
		fscanf(fin,"%d%d%d",&a,&b,&k);
		int ans = solve(a,b,k);
		fprintf(fout,"Case #%d: %d\n",cas,ans);
	
	}
	fclose(fin);
	fclose(fout);
	system("pause");
	return 0;
}

