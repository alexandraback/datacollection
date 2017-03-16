#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <assert.h>
#include <chrono>
#include <string>


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

long int C, D, V;
vector<long int> Ds;


long int rec(vector<bool> poss, vector<long int> &new_Ds, long int level){
	long int first_false = 0;
	for(long int i = 0; i<=V; i++)
		if(not poss[i]){
			first_false = i;
			break;
		}
	if(first_false == 0)
		return 0;	// es gibt kein false, alle sind darstellbar.
	
	
	new_Ds.resize(level+1);
	
	long int min_anwser = V;
	long int best_d = 0;
	for(long int new_d = 1; true; new_d++){
		next: 
		if(new_d > first_false)
			break;
		for(long int d = 0; d < D; d++)
			if(new_d == Ds[d]){
				new_d++;
				goto next;	// die münze wäre doppelt
			}
		for(long int d = 0; d < level; d++)
			if(new_d == new_Ds[d]){
				new_d++;
				goto next;	// die münze wäre doppelt
			}
				

		vector<bool> t_poss = poss;
		for(long int c = 1; c<=C; c++)
			for(long int j = V; j>=0; j--){
				if(t_poss[j] and (j+c*new_d <= V))
					t_poss[j+c*new_d] = true;
				}
				
		new_Ds[level] = new_d;
		long int this_answer = rec(t_poss, new_Ds, level+1);
		if(this_answer < min_anwser){
			//cout << "best_coin: " << new_d << "\n";
			min_anwser = this_answer;
			best_d = new_d;
		}
	}
	new_Ds[level] = best_d;
	//cout << "best : " << new_Ds << "\n";
	return 1 + min_anwser;
}


long int solve(){
	vector<bool> poss(V+1, false);
	poss[0] = true;
	//cout << "Test " << C << ", " << Ds << ", " << V << " => " << poss << "\n";
	for(long int d = 0; d<D; d++){
		for(long int c = 1; c<=C; c++){
			for(long int j = V; j>=0; j--){
			if(poss[j] and (j+c*Ds[d] <= V))
					poss[j+c*Ds[d]] = true;
			}
		}
	}
	
	//cout << "Test " << C << ", " << Ds << ", " << V << " => " << poss << "\n";
	
	vector<long int> new_Ds(0);
	return rec(poss, new_Ds, 0);
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
		input >> C >> D >> V;
		Ds = vector<long int>(D, 0);
		for(long int i=0; i<D; i++)
			input >> Ds[i];
		
		output << "Case #" << (i+1) << ": " << solve() << "\n";
		auto dur = std::chrono::high_resolution_clock::now() - start_time;
		std::chrono::minutes m = std::chrono::duration_cast<std::chrono::minutes>( dur );
		std::chrono::seconds s = std::chrono::duration_cast<std::chrono::seconds>( dur );
		cout << "Case: (" << (i+1) << " / " << cases << "), Zeit: " << s.count() << " Sekunden, " << m.count() << " Minuten\n";
	}


	return 0;
}