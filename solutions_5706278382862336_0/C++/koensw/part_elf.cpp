#include <iostream>
#include <cmath>
#include <cstdlib>

long long gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b, a%b);
}

int N;
long long p, q;
int main(){
	std::cin >> N;

	for(int i=0; i<N; ++i){
		std::string s;
		std::cin >> s;
		
		int d = s.find('/');
		std::string s1 = s.substr(0, d);
		std::string s2 = s.substr(d+1);
		p = atoi(s1.c_str()); q = atoi(s2.c_str());
		
		long long chk = std::pow(2, 12);
		
		long long c = gcd(p,q);
		p/=c; q/=c;
		
		if((chk % q) != 0){
			std::cout << "Case #" << (i+1) << ": impossible" << std::endl; 
			continue;
		}
		
		long long total = 0;
		while(p/q < 1){
			q/=2;
			total+=1;
		}
		
		std::cout << "Case #" << (i+1) << ": " << total << std::endl; 
	}
}