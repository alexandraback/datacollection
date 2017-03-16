#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;



long long gcd(long long a,long long b){long long r;while((r=b%a)!=0){b=a;a=r;}return a;}
int solve(){
	
	long long p,q;
	scanf("%I64d/%I64d",&p,&q); 
	long long g=gcd(q,p);
	long long int a[41];
	for(int i=0;i<41;i++){
		a[i]=((long long)1)<<(long long)i;
	}
	p/=g;
	q/=g;
	//printf("%I64d %I64d\n",p,q);
	int c=0;
	for(int i=40;i>=0;i--){
		if(q==a[i]){
			c=i;
			break;
		}
	}
	if(c==0){ 
		if(q!=1)printf("impossible\n");
		else printf("0\n");
		return 0;
	}
	int ans=0;
	for(;;){
		if(q*2>a[40]){
			break;
		}
		p<<=1;
		q<<=1;
	}
	for(int i=40;i>=0;i--){
		if(p>=a[i]){
			printf("%d\n",40-i);
		    return 0;
		}
	}
	return 0;
}

int main(){
	 
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){ 
		printf("Case #%d: ",i);
		solve();
	}
	
	
	
	
	return 0;
}