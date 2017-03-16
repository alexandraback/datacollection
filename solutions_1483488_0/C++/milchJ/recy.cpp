#include <cstdio>
#include <set>

using namespace std;


int A,B;

set<int> v;

int ron(int x) {
	int sum=0;
	
	int ten=1;
	int num=0;
	int tmp = x;
	while(tmp>0) {
		tmp/=10;
		num++;
		ten*=10;
	}
	ten/=10;
	num--;
	
	//printf("%d -- %d %d\n", x, ten, num); 
	v.clear();
	tmp=x;
	for(int i=0; i<num; i++) {
		tmp = tmp/10 + (tmp%10)*ten;
		if(tmp>=A && tmp<=B && x<tmp && v.count(tmp)==0 ) {
			sum++;
			v.insert(tmp);
		}
	}

	return sum;
}
int main() {

	int N;
	scanf("%d ", &N);
	
	for(int t=0; t<N; ++t) {
		printf("Case #%d: ", t+1);
		scanf("%d %d", &A, &B);
		int sum=0;
		for(int i=A; i<=B; ++i) {
			int tp = ron(i);
			//if(tp>0)
			//	printf("%d -> %d\n", i, tp);
			sum += tp;
		}
		
		printf("%d\n", sum);
	}


	return 0;
};
