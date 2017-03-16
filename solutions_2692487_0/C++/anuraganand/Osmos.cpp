#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T;
	int mote[1000005];
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++){
		int A,N;
		scanf("%d %d",&A,&N);
		for(int i=0;i<N;i++)
			scanf("%d",&mote[i]);
		sort(mote,mote+N);
		int count=0;
		for(int i=0;i<N;i++){
			if(A <= mote[i]){
				int temp=0;
				while(A <= mote[i]){
					//fprintf(stderr, "A = %d mote[i] = %d\n", A,mote[i]);
					temp++;
					A += A-1;
					if(A == 1)
						break;
					//fprintf(stderr, "A = %d mote[i] = %d\n", A,mote[i]);
				}
				if(temp > N-i){
					count += N-i;
					break;
				}
				else
					count += temp;
			}
			if(A > mote[i])
				A +=mote[i];
		}
		count = min(count,N);
		printf("Case #%d: %d\n",tt,count);
	}
	return 0;
}