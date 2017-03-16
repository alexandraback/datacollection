#include <fstream>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

ifstream fin("B.in");
ofstream fout("B.out");

int T;

int main(){
	fin>>T;
	for(int z=1;z<=T;z++){
		
	double C, F, X;
		
	fin>>C>>F>>X;
	
	double min = X/C - 2/F - 1;
	
	int n;
	
	if(min<0)n = 0;
	else n = ceil(min);
	
	double ans=0;
	
	for(int i=0;i<=n-1;i++){
		ans += C /(2 + i*F);
	}
	
	ans += X/(2 + n*F);
		
	fout<<"Case #"<<z<<": "<<fixed<<setprecision(7)<<ans<<endl;
	
	}
	return 0;
}
