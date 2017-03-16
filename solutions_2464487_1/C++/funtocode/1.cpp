#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
typedef long long LL;

LL binary(double a,double sum){
	double start,end;
	LL mid;
	start = 1.0;end=sum;
	mid=(start+end)/2;
	while(start<end-1){
		mid=(start+end)/2;
		if( ((mid/2.0)*(2.0*a+(1.0*mid-1)*4.0)) <=sum)
			start=mid;
		else
			end = mid;
	}
	mid=end;
	if( ((mid/2.0)*(2.0*a+(1.0*mid-1)*4.0)) <=sum)
		return mid;
	else return (mid-1);
}
int main(){ 
LL test,o=0;
cin>>test;
while(o++<test){
printf("Case #%lld: ",o);
LL r,t;
	cin>>r>>t;
	double a = (r+1)*(r+1)-r*r;//note the overflow
	LL ans = binary(a,t);
	printf("%lld\n",ans);
}
return 0;
}
