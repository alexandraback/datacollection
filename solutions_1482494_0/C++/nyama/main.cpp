#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>

using namespace std;

// typedef
typedef __int64 int64;
typedef unsigned __int64 uint64;
typedef unsigned int uint;

// define
#ifdef _DEBUG
#	define CHECK_DATA 1
#else
#	define CHECK_DATA 0
#endif

#ifdef    WIN32
#	define DIRECTORY_SEPARATOR '\\'
#else
#	define DIRECTORY_SEPARATOR '/'
#endif

#define DEFAULT_INPUT "test.txt"
#define DEFAULT_OUTPUT "result.txt"
#define DEFAULT_ANSWER "answer.txt"

//=========================================================================//
//     Problem Class
//=========================================================================//
class Problem{
private:
	// input
	uint N;
	vector<pair<uint, uint> > AB;
	// tmp
	
	// result
	uint64 result;
public:
	//--------------------------------------------------------------------//
	//     Get Input
	//--------------------------------------------------------------------//
	void GetInput(istream& in){
		in >> N;
		for(uint i=0; i<N; ++i){
			int a, b;
			in >> a >> b;
			AB.push_back(make_pair(a,b));
		}
	}
	//--------------------------------------------------------------------//
	//     Output for Debug
	//--------------------------------------------------------------------//
	void DebugOutput(ostream& out) const{

	}
	//--------------------------------------------------------------------//
	//     Solve
	//--------------------------------------------------------------------//
	void Solve(){
		vector<uint> clear(N, 0);
		result = 0;
		uint stars = 0;
		uint c = 0;
		while(c < N){
			uint best_index = -1, best_stars = 0, large_second = 0;
			bool second_flag = false;
			for(uint i=0; i<N; ++i){
				if((clear[i] != 2) && (AB[i].second <= stars) && (best_stars <= 2 - clear[i])){
					best_stars = 2 - clear[i];
					best_index = i;
					second_flag = true;
				}
				else if((clear[i] == 0) && (AB[i].first <= stars) && best_stars <= 1){
					if(best_stars == 0 || (large_second < AB[i].second && !second_flag)){
						best_stars = 1;
						best_index = i;
						large_second = AB[i].second;
						second_flag = false;
					}
				}
			}
			if(best_stars == 0){
				result = -1;
				return;
			}
			else{
				stars += best_stars;
				clear[best_index] += best_stars;
				c += (clear[best_index] == 2)? 1: 0;
				++result;
			}
		}
		if(result != N){
			int x = 10;
		}
	}

	//--------------------------------------------------------------------//
	//     Output Result
	//--------------------------------------------------------------------//
	void OutputResult(ostream& out) const{
		out << " ";
		if(result != -1){
			out << result << endl;
		}
		else{
			out << "Too Bad" << endl;
		}
	}
};

//=========================================================================//
//     Open Files
//=========================================================================//
int OpenFiles(const int argc, const char *argv[], ifstream *in_file, fstream *out_file, ifstream *answer_file){
	string input_file_name = (argc > 1)? argv[1]: DEFAULT_INPUT;
	uint index = input_file_name.find_last_of(DIRECTORY_SEPARATOR);
	string dir = (index+1 < input_file_name.size())? input_file_name.substr(0, index+1): "",
		        output_file_name = dir + DEFAULT_OUTPUT;
	string answer_file_name = (argc > 1)? argv[2]: DEFAULT_ANSWER;

	in_file->open(input_file_name.c_str());
	if(!in_file->is_open()){
		cout << "Input File Open Error: [" << input_file_name << "]" << endl;
		return -1;
	}

	out_file->open(output_file_name.c_str(), ios::in | ios::out | ios::trunc);
	if(!out_file->is_open()){
		cout << "Output File Open Error: [" << output_file_name << "]" << endl;
		return -1;
	}

	answer_file->open(answer_file_name.c_str());
	if(!answer_file->is_open()){
	}

	return 0;
}

//=========================================================================//
//     Main
//=========================================================================//
int main(const int argc, const char *argv[]){
	// Get File Name
	ifstream in_file, answer_file;
	fstream out_file;
	if(OpenFiles(argc, argv, &in_file, &out_file, &answer_file) != 0){
		return -1;
	}

	// Get Start Time
	clock_t start, end;
	start = clock();

	// Get number of problems
	uint number_of_problems;
	in_file >> number_of_problems;
	getline(in_file, string());
	
	cout << "=====[Result]===============" << endl;
	Problem problem;
	for(uint i=0; i<number_of_problems; ++i){
		problem = Problem();
		// Get Input
		problem.GetInput(in_file);
		// Solve
		problem.Solve();
		// Output
		out_file << "Case #" << (i+1) << ":";
		cout << "Case #" << (i+1) << ":";
		problem.OutputResult(cout);
		problem.OutputResult(out_file);
#if CHECK_DATA
		problem.DebugOutput(cout);
#endif
	}

	// Get End Time
	end = clock();

	// Output Result
	char buf[256 * 1024];
	out_file.seekg(0);
	out_file.clear();
	string result = "";
	/*while(!out_file.eof()){
		out_file.get(buf, sizeof(buf));
		result += buf;
	}*/

	string answer = "";
	if(answer_file.is_open()){
		/*while(!answer_file.eof()){
			answer_file.get(buf, sizeof(buf));
			answer += buf;
		}*/
	}

	cout << endl;
	cout << "=====[Info]=================" << endl;
	cout << "time: "
	     << setprecision(2) << setiosflags(ios::fixed)
	     << (end - start) << "sec" << endl;
	if(answer.size() > 0){
		cout << ((result == answer)? "Correct": "Incorrect") << endl;
	}
	cout << endl;

	// File Close
	in_file.close();
	out_file.close();

	return 0;
}