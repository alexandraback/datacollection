#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long r,t,lim=1;
long long search(long long s, long long e){
	if(s==e) return s;
	long long m=(s+e)/2+1;
	long long ans=2*m*m+(2*r-1)*m;
	if(ans<t) return search(m,e);
	else if(ans>t) return search(s,m-1);
	return m;
}
int main(){
	int c,cnt=0;
	for(int x=0;x<9;x++) lim*=10;
	scanf("%d",&c);
	while(c--){
		cnt++;
		scanf("%lld %lld",&r,&t);
		printf("Case #%d: %lld\n",cnt,search(0,min(t/(2*r-1),lim)));
	}
	return 0;
}
