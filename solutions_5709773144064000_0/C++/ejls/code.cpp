#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <iomanip>

double C, F, X;

double cost(int B){
	double r=X/(2+B*F);
	for(int i=0; i<B; ++i)
		r+=C/(2+i*F);
	return r;
}

double trichotomy(int b, int e){
	int t1=(2*b+e)/3, t2=(b+2*e)/3;
	double bc=cost(b), t1c=cost(t1), t2c=cost(t2), ec=cost(e);
	bool bm = bc<=t1c && bc<=t2c && bc<=ec;
	bool t1m = t1c<=bc && t1c<=t2c && t1c<=ec;
	bool t2m = t2c<=bc && t2c<=t1c && t2c<=ec;
	bool em = ec<=bc && ec<=t1c && ec<=t2c;
	if(e-b<4)
		return bm?bc:t1m?t1c:t2m?t2c:ec;

	if(bm)
		return trichotomy(b, t1);
	if(t1m)
		return trichotomy(b, t2);
	if(t2m)
		return trichotomy(t1, e);
	if(em)
		return trichotomy(t2, e);
	return -1; // error
}

int main(){
	int T;
	std::cin >> T;
	std::cout << std::setprecision(7) << std::fixed;
	for(int t=1; t<=T; ++t){
		std::cout << "Case #" << t << ": ";
		std::cin >> C >> F >> X;
		std::cout << trichotomy(0, X+1) << "\n";
	}
}
