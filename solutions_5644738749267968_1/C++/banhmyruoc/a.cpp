#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int i,j,N,TC,cno,re,start;
double nao[1100],ken[1100];
int main(){
	//freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
	scanf("%d",&TC);
	for (cno = 1;cno <= TC;cno++){
		scanf("%d",&N);
		for (i=0;i<N;i++) scanf("%lf",&nao[i]);
		for (i=0;i<N;i++) scanf("%lf",&ken[i]);
		
		sort(nao,nao+N);
		sort(ken,ken+N);
		
		re = 0;
		start = N-1;
		for (i=N-1;i>=0;i--){
			while (ken[start] > nao[i] && start > 0 ) start--;
			if (start == 0){
				if (nao[i] > ken[0] ) re ++;	
				break;
			}
			re ++;
			start --;
		}
		printf("Case #%d: %d ",cno,re);
		
		re = 0; start = N-1;
		for (i=N-1;i>=0;i--){
			if (nao[i] > ken[start]) re++;
			else start--;
		}
		printf("%d\n",re);
	}
	
}
