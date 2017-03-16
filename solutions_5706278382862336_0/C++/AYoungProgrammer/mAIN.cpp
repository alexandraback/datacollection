#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;


int gcd(int p,int q){
	if(q==0)return p;
	return gcd(q,p%q);
}

int main(void){

	freopen("A-small-attempt0.in","r",stdin);
	freopen("as.out","w",stdout);

	int t;
	cin>>t;
	char input[100];
	for(int test=0;test<t;test++){
		
		cin>>input;
		int n = 0;
		int p,q;
		sscanf(input,"%d/%d",&p,&q);
		
		int g = gcd(p,q);
		p/=g;
		q/=g;
		int kq = q;
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