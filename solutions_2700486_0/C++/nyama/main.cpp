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

//==================================================================================//
//     nの階乗
//==================================================================================//
template<typename INT> INT factorial(const INT n){
    return factorial(n, (INT)1);
}

//==================================================================================//
//     n〜mまでの階乗
//==================================================================================//
template<typename INT> INT factorial(const INT n, const INT m){
    // n! / m!
    INT result = 1;
    for(INT i=m+1; i<=n; ++i){
        result *= i;
    }
    return result;
}

//==================================================================================//
//     組み合わせ数(nCm)の計算
//==================================================================================//
template<typename INT> INT CountCombination(const INT n, const INT m){
    // n! / (m!(n-m)!)
    if((m < n-m)){
        return factorial(n, n-m) / factorial(m);
    }
    else{
        return factorial(n, m) / factorial(n-m);
    }
}

//=========================================================================//
//     Problem Class
//=========================================================================//
class Problem{
private:
	const int _problem_index_;
	// input
	int N, X, Y;
	// tmp
	// result
	double result;
public:
	//--------------------------------------------------------------------//
	//     Constructor
	//--------------------------------------------------------------------//
	Problem(const uint index): _problem_index_(index){}

	//--------------------------------------------------------------------//
	//     Get Input
	//--------------------------------------------------------------------//
	void GetInput(istream& in){
		in >> N >> X >> Y;
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
		int n = (abs(X) + abs(Y)) / 2;
		if(n == 0 && N >= 1){
			result = 1.0f;
		}
		else if(N <= num(n-1)){
			result = 0.0f;
		}
		else if(num(n) <= N){
			result = 1.0f;
		}
		else{
			int t = N - num(n-1);
			int a = Y + 1;
			int side_max = min(t, n*2);
			int side_min = max(0, t - side_max);

			result = 0;
			for(int i=max(a, side_min); i<=side_max; ++i){
				result += CountCombination(t, i);
			}
			double r = 0;
			for(int i=side_min; i<=side_max; ++i){
				r += CountCombination(t, i);
			}
			result /= r;
			assert(result <= 1.0);
		}
	}

	int num(const int n){
#if 0
		if(n == 0){
			return 1;
		}
		else{
			return (n*2-1)*2+3 + num(n-1);
		}
#else
		int r = 1;
		for(int i=0; i<n; ++i){
			r += ((i+1)*2-1)*2+3;
		}
		return r;
#endif
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