#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

const int sg[4][4] = { {0,0,0,0},{0,1,0,1},{0,1,1,0},{0,0,1,1} };
const int pr[4][4] = {{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0} };

char str[10010];

int mem[200010][4][2][4];
int N,X;

int pos(int i, int p, int s, int k){
	if(i >= X*N) return (k >= 4);
	if(k >= 4) return 0;

	int &val = mem[i][p][s][k];

	if(val >= 0) return val;

	int p1,s1,c;
	c = str[i%N];

	p1 = pr[p][c];
	s1 = sg[p][c]^s;

	val = pos(i+1,p1,s1,k);


	if(!s1 && p1==k) val |= pos(i+1,0,0,k+1);

	return val;
}

int main(){

	int t,T,i;
	long long x;

	scanf("%d",&T);

	for(t = 1; t <= T; ++t){
		scanf("%d%lld",&N,&x);
		scanf("%s",str);
		for(i = 0; i < N; ++i){
			str[i] -= 'h';
		}
		memset(mem,-1,sizeof(mem));

		X = x < 20 ? x : 16+(x%4);
		printf("Case #%d: %s\n",t,pos(0,0,0,1) ? "YES" : "NO");
	}


	return 0;
}
