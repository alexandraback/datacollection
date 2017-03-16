#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
    out << "[";
    size_t last = v.size() - 1;
    for(size_t i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != last) 
            out << ", ";
    }
    out << "]";
    return out;
}

vector<long int> speicher;

long int flip(long int n){
	long int neu = 0;
	long int stelle = 0;
	long int faktor = 1;
	while(faktor*10 <= n){
		faktor *= 10;
		stelle ++;
	}
	
	
	/*std::cout << "flip(" << n << ") :: ";
	std::cout << " faktor="<< faktor;*/
	while(n != 0){
		neu += faktor * (n%10);
		n = n / 10;
		faktor = faktor / 10;
	}
	//std::cout << ", erg="<< neu << ";\n";
	return neu;
}


long int solve(long int n){
	//std::cout << "sovle(" << n << "), "<< speicher <<";\n";

	speicher.reserve(n+1);
	
	if(speicher[n] == 0){
		long int f = flip(n);
		if(f < n and n % 10 != 0)
			speicher[n] = 1 + std::min(solve(n-1), solve(f));
		else
			speicher[n] = 1 + solve(n-1);
	}

	return speicher[n];
}

int main (int argn, char** args){
	if(argn != 3){
		std::cout << "Parameter falsch\n";
		return -1;
	}
	std::string in = args[1];
	std::string out = args[2];

	std::fstream input(in, std::ios_base::in);
	std::fstream output(out, std::ios_base::out);
	
	speicher = vector<long int>(1000000, 0);
	speicher[1] = 1;
	
	unsigned int cases;
	input >> cases;
	for(unsigned i=0; i<cases; i++){
		unsigned int N;
		input >> N;
		
		output << "Case #" << (i+1) << ": " << solve(N) << "\n";
	}


	return 0;
}