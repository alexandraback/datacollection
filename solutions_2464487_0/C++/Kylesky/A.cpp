#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int cases;
	scanf("%d", &cases);
	
	for(int z=1; z<=cases; z++){
		long long r, t;
		scanf("%lld %lld", &r, &t);
		
		r++;
		long long n = 0;
		while(true){
			long long temp = 2*r-1;
			if(t >= temp){
				t-=temp;
				n++;
				r+=2;
			}else{
				break;
			}
		}
		printf("Case #%d: %lld\n", z, n);
	}
	return 0;
}