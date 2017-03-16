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
#include <bitset>
#include <algorithm>
#include <assert.h>

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
	const int _problem_index_;
	// input
	string L;
	int64 n;
	// tmp
	// result
	int result;
public:
	//--------------------------------------------------------------------//
	//     Constructor
	//--------------------------------------------------------------------//
	Problem(const uint index): _problem_index_(index){}

	//--------------------------------------------------------------------//
	//     Get Input
	//--------------------------------------------------------------------//
	void GetInput(istream& in){
		in >> L >> n;
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
		enum{
			MAX_SIZE = 300,
		};
		vector<vector<int> > D(MAX_SIZE, vector<int>(MAX_SIZE, 0));
		for(int i=0; i<L.size(); ++i){
			for(int j=0; j<=i; ++j){
				int r = 0;
				if(i-1 >= 0){
					r += D[i-1][j];
					if(j+1 <= i){
						//r += D[i-1][j+1];
					}
				}
				if(test(L, i, j)){
					r += 1;
				}
				D[i][j] = r;
			}
		}
		
		result = 0;
		for(int i=0; i<L.size(); ++i){
			result += D[L.size()-1][i];
		}
	}

	bool test(const string &str, int j, int i){
		int cons = 0;
		int r = 0;
		for(int x=i; x<=j; ++x){
			if(test2(str[x])){
				cons++;
			}
			else{
				r = max(cons, r);
				cons = 0;
			}
		}
		r = max(cons, r);
		return r >= n;
	}

	bool test2(char c){
		if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
			return false;
		}
		else{
			return true;
		}
	}

	//--------------------------------------------------------------------//
	//     Output Result
	//--------------------------------------------------------------------//
	void OutputResult(ostream& out) const{
		out << " " << setprecision(20) << result << endl;
	}
};

//=========================================================================//
//     Open Files
//=========================================================================//
int OpenFiles(const int argc, const char *argv[], ifstream *in_file, fstream *out_file){
	string input_file_name = (argc > 1)? argv[1]: DEFAULT_INPUT;
	uint index = input_file_name.find_last_of(DIRECTORY_SEPARATOR);
	string dir = (index+1 < input_file_name.size())? input_file_name.substr(0, index+1): "",
		        output_file_name = dir + DEFAULT_OUTPUT;

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

	return 0;
}

int OpenFiles(const int argc, const char *argv[], ifstream *result_file, ifstream *answer_file){
	string input_file_name = (argc > 1)? argv[1]: DEFAULT_INPUT;
	uint index = input_file_name.find_last_of(DIRECTORY_SEPARATOR);
	string dir = (index+1 < input_file_name.size())? input_file_name.substr(0, index+1): "",
		        output_file_name = dir + DEFAULT_OUTPUT;
	string answer_file_name = (argc > 1)? argv[2]: DEFAULT_ANSWER;

	result_file->open(output_file_name.c_str());
	if(!result_file->is_open()){
		cout << "Result File Open Error: [" << input_file_name << "]" << endl;
		return -1;
	}

	answer_file->open(answer_file_name.c_str());
	if(!answer_file->is_open()){
		//cout << "Result File Open Error: [" << input_file_name << "]" << endl;
		//return -1;
	}

	return 0;
}

//=========================================================================//
//     Compare Result
//=========================================================================//
void CompareResult(ifstream *result, ifstream *answer){
	if(!answer->is_open()){
		return;
	}

	string line1, line2;
	uint count = 0;
	bool ok = true;
	while(!result->eof() || !answer->eof()){
		++count;

		if(result->eof() && !answer->eof()){
			cout << "Answerには" << count << "行目がありません。" << endl;
			ok = false;
			break;
		}
		else if(!result->eof() && answer->eof()){
			cout << "Resultには" << count << "行目がありません。" << endl;
			ok = false;
			break;
		}

		getline(*result, line1);
		getline(*answer, line2);

		if(line1 != line2){
			cout << count << "行目が異なります。" << endl
				<< "	" << line1 << endl
				<< "	" << line2 << endl;
			ok = false;
		}
	}

	if(ok){
		cout << "Correct" << endl;
	}
	else{
		cout << "InCorrect" << endl;
	}
}

//=========================================================================//
//     Get All Stream Content
//=========================================================================//
template<typename Stream>
void GetAll(string *buf, Stream *stream){
	char c;
	while(!stream->eof()){
		*stream >> c;
		*buf += c;
	}
}

//=========================================================================//
//     Main
//=========================================================================//
int main(const int argc, const char *argv[]){
	// Get File Name
	ifstream in_file;
	fstream out_file;
	if(OpenFiles(argc, argv, &in_file, &out_file) != 0){
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
	for(uint i=0; i<number_of_problems; ++i){
		Problem problem(i+1);
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

	// File Close
	in_file.close();
	out_file.close();

	// Result Open
	ifstream result_file, answer_file;
	OpenFiles(argc, argv, &result_file, &answer_file);

	cout << endl;
	cout << "=====[Info]=================" << endl;
	cout << "time: "
	     << setprecision(2) << setiosflags(ios::fixed)
	     << (end - start) << "sec" << endl;
	CompareResult(&result_file, &answer_file);
	cout << endl;

	

	return 0;
}