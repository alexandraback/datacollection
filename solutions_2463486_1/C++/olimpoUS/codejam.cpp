#include<stdio.h>
#include<iostream>
using namespace std;
int t;
long long Reverse(long long x){
	long long y = 0;
	while(x){
		y = 10*y + (x%10);
		x/=10;
	}
	return y;
}
bool IsP(long long x){
	return (x == Reverse(x));
}
long long N[100];
long long a,b;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int tt = 1;
	int c = 0;
	for(long long i = 1; i < 10000000; i++)
	if(IsP(i) && IsP(i*i)){
		//cout << i*i << endl;
		N[c++] = i*i;
	}
	//cout << c << endl;
	cin >> t;
	
	while(t--){
		printf("Case #%d: ",tt++);
		scanf("%lld%lld",&a,&b);
		int r = 0;
		for(int i = 0 ; i < c ; i++)
			if(N[i] >=a && N[i]<=b)
				r++;
			
		printf("%d\n",r);
	}
	return 0;
}
