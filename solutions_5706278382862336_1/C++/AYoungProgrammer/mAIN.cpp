#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;


unsigned long long gcd(unsigned long long p,unsigned long long q){
	if(q==0)return p;
	return gcd(q,p%q);
}

int main(void){

	freopen("A-large.in","r",stdin);
	freopen("al.out","w",stdout);

	int t;
	cin>>t;
	char input[100];
	for(int test=0;test<t;test++){
		
		cin>>input;
		int n = 0;
		unsigned long long p,q;
		sscanf(input,"%llu/%llu",&p,&q);

		//printf("%llu %llu",p,q);
		
		unsigned long long g = gcd(p,q);
		p/=g;
		q/=g;
		unsigned long long kq = q;
		while(kq%2==0){
			kq/=2;
		}
		if(kq!=1){
			printf("Case #%d: impossible\n",test+1);
		}
		else {
			int count = 0;
			while(p<q){
				p*=2;
				count++;
			}
			printf("Case #%d: %d\n",test+1,count);
		}
	}


}