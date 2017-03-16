#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

class Data
{
public:
	int state,sum;
	friend bool operator <(Data A, Data B)
	{
		return (A.sum < B.sum);
	}
};

Data D[1050000];

int main(){
	int T,N;
	int a,b;
	int i,j,k;
	int A[25];
	bool flag;
	Data d;
	
	k = 1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(i=0;i<N;i++)
			scanf("%d",&A[i]);
		
		for(i=0;i<(1<<N);i++){
			D[i].state = i; D[i].sum = 0;
			for(j=0;j<N;j++){
				if((i&(1<<j)) != 0)
					D[i].sum += A[j];
			}
		}
		sort(D,D+(1<<N));
		
		a = b = -1;
		for(i=1;i<(1<<N);i++){
			if(D[i].sum == D[i-1].sum){
				a = D[i-1].state;
				b = D[i].state;
				break;
			}
		}
		printf("Case #%d:\n",k);
		k++;
		if(a == -1) printf("Impossible\n");
		
		
		for(flag=false,i=0;i<N;i++){
			if((a&(1<<i)) != 0){
				if(flag)
					printf(" ");
				
				printf("%d",A[i]);
				flag = true;
			}
		}
		printf("\n");
		
		for(flag=false,i=0;i<N;i++){
			if((b&(1<<i)) != 0){
				if(flag)
					printf(" ");
				
				printf("%d",A[i]);
				flag = true;
			}
		}
		printf("\n");
	}
}
				
			