#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int K,L,S,f[100];
char s1[101],s2[101];
bool have[26];
int go[101][26];
double memo[101][101];

double solve(int pos, int match){
	if(pos == S)
		return (match == L? 1.0 : 0.0);

	double &ret = memo[pos][match];

	if(!(ret == ret)){
		ret = (match == L? 1.0 : 0.0);

		for(int i = 0;i < K;++i){
			int to = go[match][ s1[i] - 'A' ];

			ret += (double)solve(pos + 1,to) / K;
		}
	}

	return ret;
}

int main(){
	ios::sync_with_stdio(0);

	int T;
	
	scanf("%d",&T);

	for(int tc = 1;tc <= T;++tc){
		scanf("%d %d %d %s %s",&K,&L,&S,s1,s2);

		memset(have,false,sizeof have);

		for(int i = 0;i < K;++i)
			have[ s1[i] - 'A' ] = true;

		f[0] = 0;

		for(int i = 1,k = 0;i < L;++i){
			while(k > 0 && s2[i] != s2[k])
				k = f[k - 1];

			if(s2[i] == s2[k])
				++k;

			f[i] = k;
			//printf("%d ",f[i]);
		}
		//printf("\n");

		int best = 0;
		bool ok = true;

		for(int i = 0;i < L && ok;++i)
			if(!have[ s2[i] - 'A' ])
				ok = false;

		if(ok && S >= L){
			int need = L - f[L - 1];
			//printf("%d, need = %d\n",f[L - 1],need);
			best = (S - f[L - 1]) / need;
		}

		//printf("best = %d\n",best);

		for(int i = 0;i <= L;++i){
			for(char c = 'A';c <= 'Z';++c){
				int k = (i < L? i : f[L - 1]);

				while(k > 0 && c != s2[k])
					k = f[k - 1];

				if(s2[k] == c)
					++k;

				go[i][c - 'A'] = k;
				//printf("%d %c : %d\n",i,c,k);
			}
		}

		memset(memo,-1,sizeof memo);
		printf("Case #%d: %.8f\n",tc,best - solve(0,0));
	}

	return 0;
}