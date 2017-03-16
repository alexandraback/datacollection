#include <iostream>
#include <fstream>
#include <string.h>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;
#define re return
#define ll  long long

const ll MOD=1E9+7;

int main(){
	freopen("B-small-attempt0.in","rt",stdin);
	//freopen("input.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	ll i,j,n,k=0,T,t;
	cin>>T;
	cout.precision(20);
	for(t=0;t<T;++t){
		double C,F,X;
		cin>>C>>F>>X;

		double sum=0,speed=2;
		double res=0;
		bool bFoo=false;
		for(i=0;!bFoo;++i){
			double estimateX = X/speed;
			double estimateC = C/speed;
			double estimateX2 = estimateC+X/(speed+F);
			if(estimateX2 < estimateX){
				speed+=F;
				res+=estimateC;
			}else {
				bFoo = true;
				res+=estimateX;
			}
		}
		cout<<"Case #"<<t+1<<": "<<res<<endl;
	}
	re 0;
}