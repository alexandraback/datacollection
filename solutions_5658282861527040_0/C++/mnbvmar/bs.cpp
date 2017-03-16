#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#define MP make_pair
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define ALL(container) (container).begin(), (container).end()
#define FORI(i,from,to) for(int i = (from); i <= (to); i++)
#define FORD(i,from,to) for(int i = (from); i >= (to); i--)
#define REP(i,num) for(int i = 0; i < (num); i++)


using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
const LD Eps = 1e-8;
inline bool is_zero(LD x){ return (x >= -Eps) && (x <= Eps); }



/**********************************************************************/
/**********************************************************************/

int A, B, K;

void cleanup(){
	
}

void input(){
	scanf("%d%d%d", &A, &B, &K);
}

void output(int num){
	printf("%d\n", num);

}


void process_test(){
	cleanup();
	input();
	
	int z = 0;
	for(int i = 0; i < A; i++)
		for(int j = 0; j < B; j++)
			if((i & j) < K)
				z++;
	
	output(z);
}


int main(){
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		process_test();
	}
}
