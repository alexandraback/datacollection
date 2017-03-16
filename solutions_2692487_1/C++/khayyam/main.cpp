#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define ABS(x) (((x)<0)?(-(x)):(x))
#define SQR(x) ((x)*(x))
#define LL long long
#define MAX_SIZE 1000001
int M[101];
int cache[100][MAX_SIZE+1];
int N;
int solve(int n, int s){
	if(n>=N){
		return 0;
	}
	int &sol=cache[n][s];
	if(sol>=0){
		return sol;
	}
	if(M[n]<s){
		int newSize=MIN(s+M[n], MAX_SIZE);
		return solve(n+1,newSize);
	}
	int op1=1+solve(n+1, s);
	if(s==1){
		return sol=op1;
	}
	int k=0;
	while(s<=M[n]){
		s=2*s-1;
		++k;
	}
	s=MIN(s+M[n], MAX_SIZE);
	int op2=k+solve(n+1, s);
	sol=MIN(op1, op2);
	return sol;
}

int main(int argc, char *argv[]){
	int T;
	scanf("%d", &T);
	for(int c=1;c<=T;++c){
		int A;
		scanf("%d%d", &A, &N);
		for(int i=0;i<N;++i){
			scanf("%d", &M[i]);
		}
		sort(M, M+N);
		memset(cache, -1, sizeof(cache));
		int sol=solve(0,A);
		printf("Case #%d: %d\n", c, sol);
	}
	return 0;
}

