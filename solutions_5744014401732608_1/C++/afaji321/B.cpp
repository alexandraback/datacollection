#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <iostream>
#include <map>
using namespace std;

pair <int,int> isi[1111];

int main() {

	int T = 0;
	int tt = 1;
	scanf("%d",&T);
	while (T--){
		printf("Case #%d: ",tt++);

		
		long long N;
		long long M;
		bool full = 0;
		scanf("%lld%lld",&N,&M);
		long long redux = (1LL<<(N-2));
		if (M > redux){
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n");
		if (redux == M)
			full = 1;

		//cout<<M<<endl;
		for (int i=0;i<N;i++){
			for (int j=0;j<N-1;j++){
				if (j <= i)
					printf("0");
				else
					printf("1");
			}
			if (i == 0 && full) {
				printf("1\n");
				M--;
				continue;
			}
			if (i == N-1 || (i == 0 && !full)){
				printf("0\n");
				continue;
			}
			if (M % 2)
				printf("1\n");
			else
				printf("0\n");
			M/=2;
		}
	}
}