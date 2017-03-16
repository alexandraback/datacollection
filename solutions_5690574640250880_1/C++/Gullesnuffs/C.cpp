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
#define EMPTY vector<vector<char> >()
using namespace std;

vector<vector<char> > solve(int R, int C, int M){
	vector<vector<char> > ans;
	if(R == 1){
		ans.push_back(vector<char>());
		ans[0].push_back('c');
		for(int i=1; i < C-M; ++i)
			ans[0].push_back('.');
		for(int i=C-M; i < C; ++i)
			ans[0].push_back('*');
		return ans;	
	}
	else if(R == 2){
		if(M%2){
			if(R*C-M == 1){
				ans.push_back(vector<char>());
				ans.push_back(vector<char>());
				ans[0].push_back('c');
				ans[1].push_back('*');
				for(int i=1; 2*i < M; ++i){
					ans[0].push_back('*');
					ans[1].push_back('*');

				}
				return ans;
			}
			else
				return EMPTY;
		}
		else{
			if(R*C-M == 2 && C != 1)
				return EMPTY;
			ans.push_back(vector<char>());
			ans.push_back(vector<char>());
			ans[0].push_back('c');
			ans[1].push_back('.');
			for(int i=1; i < C-M/2; ++i){
				ans[0].push_back('.');
				ans[1].push_back('.');
			}
			for(int i=0; 2*i < M; ++i){
				ans[0].push_back('*');
				ans[1].push_back('*');
			}
			return ans;
		}
	}
	if(C == 1 || C == 2){
		vector<vector<char> > flipped = solve(C, R, M);
		if(flipped.empty())
			return EMPTY;
		for(int i=0; i < flipped[0].size(); ++i)
			ans.push_back(vector<char>());
		for(int i=0; i < flipped.size(); ++i)
			for(int j=0; j < flipped[i].size(); ++j)
				ans[j].push_back(flipped[i][j]);
		return ans;
	}
	for(int i=0; i < R; ++i){
		ans.push_back(vector<char>());
		for(int j=0; j < C; ++j)
			ans[i].push_back('*');
	}
	int L=R*C-M;
	if(L == 1){
		ans[0][0]='c';
		return ans;
	}
	if(L == 2 || L == 3 || L == 5 || L == 7){
		return EMPTY;
	}
	int r=1, c=1;
	while(r*c < L){
		if(r < R && (r < c || c == C))
			++r;
		else
			++c;
	}
	for(int k=0; k < r; ++k)
		for(int m=0; m < c; ++m)
			ans[k][m]='.';
	ans[0][0]='c';
	int i=r-1, j=c-1;
	int left=r*c-L;
	while(left){
		while(i < 2){
			i=r-1;
			--j;
		}
		ans[i][j]='*';
		--left;
		--i;
	}
	return ans;
}

int main(){
	FILE *fin = fopen("input.in", "r");
	FILE *fout = fopen("output.txt", "w");
	int T;
	fscanf(fin, "%d", &T);
	for(int t=1; t <= T; ++t){
		int R, C, M;
		fscanf(fin, "%d%d%d", &R, &C, &M);
		vector<vector<char> > ans = solve(R, C, M);
		fprintf(fout, "Case #%d:\n", t);
		if(ans.empty())
			fprintf(fout, "Impossible\n");
		else{
			for(int i=0; i < ans.size(); ++i){
				for(int j=0; j < ans[i].size(); ++j)
					fprintf(fout, "%c", ans[i][j]);
				fprintf(fout, "\n");
			}
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
