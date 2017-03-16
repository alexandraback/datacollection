//
//  2013-1c-A.cpp
//  GCJ
//
//  Created by Roman Dzięcioł on 12.05.2013.
//  Copyright (c) 2013 Roman Dzięcioł. All rights reserved.
//

#include <istream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>

using namespace std;

typedef unsigned long long uint64;

#define LOG(text) (cout << text << endl)


// - Helpers ------------------------------------------------------------------

template<class T> inline T toNum(const string& str)
{
	stringstream ss(str);
	T value;
	ss >> value;
	return value;
}

template<class T> inline string toStr(const T& value)
{
	stringstream ss;
	ss << value;
	return ss.str();
}


// - InputData ----------------------------------------------------------------

class InputData
{
public:
	string name;
    uint64 ccount;
	
public:
	friend istream& operator >> (istream& stream, InputData& input);
};

inline istream& operator >> (istream& stream, InputData& input)
{
	string line;
    getline(stream, line);
    istringstream is(line);
    is >> input.name;
    is >> input.ccount;
	return stream;
}


// - OutputData ---------------------------------------------------------------

class OutputData
{
public:
	string result;
    
public:
	friend ostream& operator << (ostream& stream, OutputData& outputData);
};

inline ostream& operator << (ostream& stream, OutputData& outputData)
{
	stream << outputData.result;
	return stream;
}


// - Input --------------------------------------------------------------------

class Input
{
public:
	vector<InputData> data;
    
public:
	friend istream& operator >> (istream& stream, Input& input);
};

inline istream& operator >> (istream& stream, Input& input)
{
	string line;
	getline(stream, line);
	size_t count = toNum<size_t>(line);
    
	for(size_t i=0; i<count; ++i) {
		LOG("parsing " << i << "/" << count);
		InputData inputData;
		stream >> inputData;
		input.data.push_back(inputData);
	}
    
	return stream;
}


// - Output -------------------------------------------------------------------

struct Output
{
public:
	vector<OutputData> data;
    
public:
	friend ostream& operator << (ostream& stream, Output& output);
};

inline ostream& operator << (ostream& stream, Output& output)
{
	for(size_t i=0; i!=output.data.size(); ++i) {
		LOG("outputting " << i << "/" << output.data.size());
		stream << "Case #" << (i+1) << ": " << output.data.at(i) << std::endl;
	}
	return stream;
}



// - Solution -----------------------------------------------------------------

struct Solution
{
public:
	void solve(const Input& input, Output& output);
	OutputData solve(const InputData& input);
};

void Solution::solve(const Input& input, Output& output)
{
	for(size_t i=0; i!=input.data.size(); ++i) {
		LOG("solving " << i << "/" << input.data.size());
		OutputData outputData = solve(input.data.at(i));
		output.data.push_back(outputData);
	}
}


/*
 tsetse
 
 tsets
 tset
 tse
 ts
 
 setse
 etse
 tse
 
-tsets
 sets
 ets
 ts
 
 */

/*
 tsetse
 
 tsets
 tset
 tse
 ts
 
 tse
 ts
 
 etse
 ets
 
 setse
 sets
 
 */


/*
 tsetse
 
 tsetse
 tsets
 tset
 tse
 ts
 
 setse
 etse
 tse
 
 sets
 ets
 ts
 
 */

/*
 etsetse
 
 etsets
 etset
 etse
 ets
 
 tsetse
 tsets
 tset
 tse
 ts
 
 -etsetse
 -tsetse
 setse
 etse
 tse
 
 -etsets
 -tsets
 sets
 ets
 ts
 
 */


/*
 etsetse
 
 tsetse
 tsets
 tset
 tse
 ts
 
 
*etsetse
 etsets
 etset
 etse
 ets
 
 tse
 ts
 
 etse
 ets
 
 setse
 sets
-
 tsetse
 tsets
 
 etsetse
 etsets
 
 */


/*
 straight
 
 straigh
 straig
 strai
 stra
 str
 
 traight
 raight
 aight
 ight
 ght
 
 */


static inline bool isConsonant(char c)
{
    if (c >= 'a') {
        c -= 'a' - 'A';
    }
    
    if (c >= 'B' && c <= 'Z') {
        return c != 'E' && c != 'I' && c != 'O' && c != 'U';
    }
    
    return false;
}

//static inline unsigned int isConsonantSubstr(char*c )


OutputData Solution::solve(const InputData& input)
{
	OutputData output;
    
    uint64 result = 0;
    
    const char* name = input.name.c_str();
    const uint64 nameSize = input.name.size();
    const uint64 ccount = input.ccount;
    size_t from = 0;
    for (size_t i=0; i<nameSize; ++i) {
        
        if (isConsonant(name[i])) {
            
            size_t skip = 0;
            if (i+ccount <= nameSize) {
                if (ccount > 1) {
                    for (size_t j=i+1; j!=i+ccount; ++j) {
                        if (!isConsonant(name[j])) {
                            skip = j;
                            break;
                        }
                    }
                }
                
                if (skip) {
                    i = skip;
                } else {
                    cout << input.name.substr(i,ccount) << endl;
                    
                    size_t after = nameSize - (i + ccount);
                    size_t before = i-from;
                    result += (after + 1) * (before + 1);
                    
                    from = i+1;
                    //i += 1;
                }
            }
        }
        
        
    }
    
    output.result = toStr(result);
    
	return output;
}

// - main ---------------------------------------------------------------------

int main(int argc, char* argv[])
{
	string inputFileName = "1cAs2.in";
	string outputFileName = "1cAs2.out";
	if(argc == 2) {
		inputFileName = argv[1];
	}
    
	// Input
	LOG("parsing: " << inputFileName);
	ifstream inputFile(inputFileName);
	if(!inputFile) {
		LOG("Could not open " << inputFileName);
		return 1;
	}
    
	Input input;
	inputFile >> input;
	
	// Solve
	Output output;
	Solution solution;
	solution.solve(input,output);
	
	// Output
	LOG("outputting: " << outputFileName);
	ofstream outputFile(outputFileName);
	if(!outputFile) {
		LOG("Could not open " << outputFileName);
		return 1;
	}
	
	outputFile << output;
	cout << output;
    
	//LOG(output);
	
	LOG("Completed");
	return 0;
}

