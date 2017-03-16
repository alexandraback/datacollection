// Google Code Jam 2012 
// Problem A 

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <list> 
using namespace std; 

int main(int argc, char *argv[]) 
{ 
	if (argc < 3) 
	{ 
		cout << "[Usage] ProblemA input_file output_file" << endl; 
		return -1; 
	} 

	// Initialize problem variables 
	int numcases = 0; 
	int numppl = 0; 
	int numsurprising = 0; 
	int minbestscore = 0; 
	list<int> scorelist; 

	// Open the input and outputfile  
	ifstream inputfile; 
	ofstream outfile; 
	string line; 
	inputfile.open(argv[1]); 
	outfile.open(argv[2]); 

	// Get the number of cases 
	inputfile >> numcases; 
	getline(inputfile, line); 

	// Read through the input 
	int count = 0; 
	while (inputfile.good()) 
	{ 
		count++; 

		// Get the number of of chars already typed and number of chars in password 
		int numtyped = 0; 
		int numcharinpwd = 0; 
		inputfile >> numtyped; 
		inputfile >> numcharinpwd; 
		getline(inputfile, line); 
		cout << "Numtyped : " << numtyped << " NumCharInPwd: " << numcharinpwd << endl; 

		// Get the probability of mistyping each character 
		double *prob = new double[numtyped]; 

		for (int k = 0; k < numtyped; k++) 
		{ 
			inputfile >> prob[k]; 
		} 

		getline(inputfile, line); 
		if (!inputfile.good()) break; 

		// Compute the expected number of keystrokes 
		double expnum = 0; 

		// Compute the probability that the password will be correct 
		double pcorrect = 1.0; 
		//cout << "Probabilities: "; 
		for (int k = 0; k < numtyped; k++) 
		{ 
			pcorrect *= prob[k]; 
			//cout << prob[k] << " "; 
		} 
		//cout << endl; 
		//cout << "Probability of correct: " << pcorrect << endl; 

		double bestcase; 

		// Case 1: Press Enter 
		double case1 = 0; 
		if (numtyped == numcharinpwd) 
			case1 = pcorrect * 1 + (1.0 - pcorrect) * (numcharinpwd + 2); 
		else 
			case1 = numcharinpwd + 2; 
		bestcase = case1; 
		//cout << "Pressing Enter: " << case1 << " Best Case: " << bestcase << endl; 

		// Case 2:  Continue typing 
		double case2 = 0; 
		case2 = pcorrect * (numcharinpwd - numtyped + 1) + (1 - pcorrect) * (numcharinpwd - numtyped + 1 + numcharinpwd + 1); 
		if (case2 <= bestcase) bestcase = case2; 
		//cout << "Continue typing: " << case2 << " Best Case: " << bestcase << endl; 

		// Case 3: Pressing backspace 
		// Compute for each time the backspace is computed 
		for (int k = 0; k < numtyped; k++) 
		{ 
			double case3 = 0.0; 
			double pcorrect = 1.0; // Probability that after backspace it is correct 

			for (int p = 0; p < numtyped - k - 1; p++) 
			{ 
				pcorrect *= prob[p]; 
			} 

			//cout << "Probability of backspacing " << k + 1 << " is correct : " << pcorrect << endl; 

			if (k != numtyped - 1) 
				case3 = pcorrect * (k + 1 + numcharinpwd - (numtyped - k - 1) + 1) + (1 - pcorrect) * (k + 1 + numcharinpwd - (numtyped - k - 1) + 1 + numcharinpwd + 1); 
			else 
				case3 = k + 1 + numcharinpwd + 1; 

			if (case3 <= bestcase) bestcase = case3; 

			//cout << "Backspace #" << k + 1 << " : " << case3 << " Best Case: " << bestcase << endl; 
		} 

		stringstream s; 
		s.setf(ios::fixed, ios::floatfield); 
		s << "Case #" << count << ": " << bestcase; 
		cout << "Case #" << count << ": " << bestcase << endl; 
		
		outfile << s.str() << endl; 

		// Release any variables 
		if (prob) { 
			delete[] prob; 
			prob = NULL; 
		} 

	} 

	// Closes the file 
	inputfile.close(); 
	outfile.close(); 

	// Successful run 
	return 0; 
}


