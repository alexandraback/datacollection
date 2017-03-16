#include <stdio.h>
#include <map>
using namespace std;
long long int vec[30];
long long int calcsum(int n){
	long long int sum = 0;
	for(int i=0;i<20;i++){
		sum+=(n&(1<<i))?vec[i]:0;
	}
	return sum;
}
void print(int n){
	for(int i=0;i<20;i++){
		if(n&(1<<i)){
			printf("%lld ",vec[i]);
		}
	}
	printf("\n");
}

int main(){
	int C;
	scanf("%d",&C);
	map<long long int,int> m;
	for(int c = 1;c<=C;c++){
		scanf("%*d");
		for(int i = 0;i<20;i++)
			scanf("%lld",vec+i);
		m.clear();
		int found1 = -1;
		int found2 = -1;
		for(int i = 1;i<(1<<20)-1;i++){
			map<long long int,int>::iterator it;
			int s = calcsum(i);
			it = m.find(s);
			if(it != m.end()){
				found1 = i;
				found2 = (*it).second;
				break;
			}
			m[s] = i;
		}
		
		printf("Case #%d:\n",c);
		if(found1 == -1){
			printf("Impossible\n");
		}else{
			print(found2);
			print(found1);
		}

	}
	return 0;
}
