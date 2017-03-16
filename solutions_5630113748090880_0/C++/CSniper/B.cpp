#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <cmath>
#include <iostream>
#define INF (1<<30)
using namespace std;

int main(){
	int t=0, c=0;
	scanf("%d", &t);
	while(t--){
		c++;
		int count[3000];
		memset(count, 0, sizeof(count));
		int N=0;
		scanf("%d", &N);
		for(int i=0; i<2*N-1; i++){
			for(int j=0; j<N; j++){
				int tmp=0;
				scanf("%d", &tmp);
				count[tmp]++;
			}
		}
		printf("Case #%d: ", c);
		for(int i=1; i<=2500; i++)
			if(count[i]%2)printf("%d ", i);
		printf("\n");
	}
	return 0;
}

