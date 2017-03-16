#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

char str[110];
int N;

int main(){
	int T,t,i,cur,sol;

	scanf("%d",&T);

	for(t = 1; t<=T; ++t){
		scanf("%d",&N);
		scanf("%s",str);

		for(i = 0; i <= N; ++i){
			str[i] -= '0';
		}

		cur = 0;
		sol = 0;

		for(i = 0; i <= N; ++i){
			if(!str[i]) continue;
			if(cur < i){
				sol += i-cur;
				cur = i;
			}
			cur += str[i];
		}

		printf("Case #%d: %d\n",t,sol);
	}

	return 0;
}
