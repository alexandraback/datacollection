#include <iostream>
#include <vector>

//Technically this doesn't generate enough primes to be certain on the big input, but hopefully we get lucky...
std::vector<int> getPrimes(){
	std::vector<int> ret;
	ret.push_back(2);
	ret.push_back(3);
	for(int i=5; i<10000; i+=2){
		bool prime=true;
		for(size_t j=0; j<ret.size(); j++){
			if(i%ret[j]==0){
				prime=false;
				break;
			}
		}
		if(prime){
			ret.push_back(i);
		}
	}
	return ret;
}

int reverse(unsigned int n){
	int ret=0;
	while(n!=0){
		ret*=2;
		ret+=n%2;
		n/=2;
	}
	return ret;
}

void output(unsigned int n){
	n = reverse(n);
	while(n!=0){
		std::cout << (n%2);
		n/=2;
	}
}

bool divides(unsigned int n, int d, int base){
	n = reverse(n);
	int current = 0;
	while(n>0){
		current*=base;
		current+=(n%2);
		n/=2;
		current-= d*(current/d);
	}
	return (current%d)==0;
}

int check(unsigned int current, std::vector<int> primes){
	int divisors[11]={0};
	for(size_t base=2; base<=10; base++){
		for(size_t j=0; j<primes.size(); j++){
			if(!divides(current, primes[j], base)){
				continue;
			}
			divisors[base]=primes[j];
		}
		if(!divisors[base]){
			return 0;
		}
	}
	
	output(current);
	for(int base=2; base<=10; base++){
		std::cout << " " << divisors[base];
	}
	std::cout << std::endl;
	return 1;
}

int main(){
	std::cout << "Case #1:" << std::endl;
	std::vector<int> primes = getPrimes();

	int temp,length,n;
	std::cin >> temp >> length >> n;

	unsigned int current = 1 << (length-1);
	current++;

	int found=0;

	while(found < n){
		found+=check(current, primes);
		current+=2;
	}

	return 0;
}
