#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <chrono>


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

long int solve(long int R, long int C, long int W){
	long int auffinden = R * (C / W);
	if(C % W == 0)
		return W - 1 + auffinden;
	else
		return W + auffinden;
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
	

	auto start_time = std::chrono::high_resolution_clock::now();

	
	unsigned int cases;
	input >> cases;
	for(unsigned i=0; i<cases; i++){
		unsigned int R, C, W;
		input >> R >> C >> W;
		
		output << "Case #" << (i+1) << ": " << solve(R, C, W) << "\n";
		auto dur = std::chrono::high_resolution_clock::now() - start_time;
		std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>( dur );
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>( dur );
		cout << "Case: (" << (i+1) << " / " << cases << "), Zeit: " << s.count() << " Sekunden, " << m.count() << " Minuten\n";
	}


	return 0;
}