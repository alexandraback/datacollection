#include <cstdio>
#include <cmath>
using namespace std;
int n;
long long t, r;
const float pi = acos(0)*2;
long long drawc(long long paint, long long r){
	long long rs = (r+1)*(r+1)-(r*r);
	if(paint >= rs) return rs;
	return 0;
}
int main(){
	scanf("%i", &n);
	for(int tc=1;tc<=n;tc++){
		scanf("%lld%lld", &r, &t);
		long long cc = 0;
		while(long long res = drawc(t, r)){
			t -= res;
			cc++;
			r+=2;
		}
		printf("Case #%i: %lld\n", tc, cc);
	}
}