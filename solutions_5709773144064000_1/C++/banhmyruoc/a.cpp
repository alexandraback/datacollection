#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
ll i,j,TC,cno;
double C,F,X,sum;
int main(){
//	freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
	
	scanf("%lld",&TC);
	for (cno = 1;cno <= TC;cno++){
		scanf("%lf %lf %lf",&C,&F,&X);
		sum = 0;
		for (i=0;i<=100000;i++){
			double de = 2 + (i*F);
			if (X/de < ( C/de + X/(de + F)) ){
				printf("Case #%lld: %.7lf\n",cno,sum + X/de);
				break;
			}
			sum += C/de;
		}
	}
}
