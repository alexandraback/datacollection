/*!
 * \file     q1.cpp
 * \author   Cong Wang
 * \date     2012
 * \brief 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main (int argc, char const* argv[]){

	if(argc < 2){
		cout << "using: ./prog inputfile" << endl;
		exit(0);
	}

	string line;
	ifstream myfile (argv[1]);

	int numTests;
	myfile >> numTests;

    int A, B;
    double temp;
    vector<double> prob;
    vector<double> cases;

	for (unsigned int i = 0; i < numTests; i += 1){
		//hand each test case here
		prob.clear();
		cases.clear();
		
		myfile >> A >> B;
		
		for (unsigned int j = 0; j < A; j += 1){
		    myfile >> temp;
		    prob.push_back(temp);
		}
		
		//keep typing
		double probPerfect = 1.0;
		for (unsigned int j = 0; j < A; j += 1){
		    probPerfect = probPerfect * prob[j];
		}
		cases.push_back( probPerfect*(double)(B-A+1) + (1.0 - probPerfect)*(double)(B-A+1+B+1) );
		
		//backspace j = 1 to A times		
		int tempA = 0;
		for (unsigned int j = 1; j <= A; j += 1){
		    probPerfect = 1.0;
		    tempA = A - j;
		    
		    for (unsigned int k = 0; k < tempA; k += 1){
		        probPerfect = probPerfect * prob[k];
		    }
		    
		    cases.push_back( probPerfect*(double)(j+B-tempA+1) + (1.0 - probPerfect)*(double)(j+B-tempA+1+B+1) );
		    
		    probPerfect = 1.0;
		}
		
		//hit enter now
		cases.push_back(B + 2);
		
	    cout << "Case #" << i+1 << ": ";
		cout << fixed << setprecision(6) << *min_element(cases.begin(), cases.end()) << endl;
		
		/*
		cout << A << " " << B << endl;
		for (unsigned int i = 0; i < A; i += 1){
		    cout << prob[i] << " ";
		}
		cout << endl;
		*/
	}
	
	

	myfile.close();

	return 0;
}
