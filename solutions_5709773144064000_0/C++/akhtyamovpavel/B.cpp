#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
#define FILE "B"
int main(){
	freopen(FILE ".in","r",stdin);
	freopen(FILE ".out","w",stdout);
	int Tests;
	cin>>Tests;
	for(int numTest = 1; numTest <= Tests; ++numTest){
		double C,F,X;
		cin>>C>>F>>X;
		cout<<"Case #"<<numTest<<": ";
		if(C>=X){
			cout<<fixed;
			cout<<setprecision(8);
			cout<<X/2.0<<endl;
			continue;
		}
		int cnt = 0;
		int k = max(0.0001, ceil(X/C - 2.0/F - 1.0));
		//cout<<k<<endl;
		double curspeed = 2.0;
		double overall = 0;
		for(int curK = 0; curK < k; ++curK){
			overall += C/curspeed;
			curspeed += F;
		}
		overall += X/curspeed;
		cout<<fixed;
		cout<<setprecision(8);
		cout<<overall<<endl;
	}
	return 0;
}