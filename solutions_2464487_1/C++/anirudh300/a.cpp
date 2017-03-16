#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf(" %d",&T);
	for(int k=1;k<=T;k++){
		long long r,t;
		scanf(" %lld %lld",&r,&t);
    long long first = 0LL;
		long long last;
		if (r > 2000000000){
			last = 2000000000000000000/r;
		}
		else{
			last = 2000000000;
		}
		long long middle = (first + last)/2;
		while(first <= last){
			if (middle*(2LL*(r+middle)-1LL) < t){
				first = middle+1LL;
			}
			else if (middle*(2LL*(r+middle)-1LL) == t){
				break;
			}
			else{
				last = middle - 1LL;
			}
			middle = (last+first)/2LL;
		}
		printf("Case #%d: %lld\n",k,middle);
	}
}
