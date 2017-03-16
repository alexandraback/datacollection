#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

int main(){
	int T;
	cin >> T;

	std::cout.setf(std::ios::fixed);
   	std::cout.precision(6);

	for(int t=1; t<=T; t++){
	/*
	Code per test goes here
	*/	

	int A, B;
	cin >> A >> B;

	vector<double> probs(A);
	for(int i=0; i<A; i++){
		cin >> probs[i];
	}

	vector<double> scales(A+1);
	for(int i=0; i<=A; i++){
		double prod = 1;
		for(int j=0; j<i; j++){
			prod *= probs[j];		
		}	
		scales[i] = prod;
	}

	/*
	Strat 1: Keep typing
	Prob okay = scales[A], strokes = B-A+1
	Else penalty = strokes = B-A+1+B
	*/
	double score = scales[A]*(B-A+1) + (1-scales[A])*(2*B-A+2);	
	double minscore = score;	

	/*
	Strat 2: Enter now
	*/
	score = B + 2;
	if(score < minscore) minscore = score;

		/*
	Strat 3: Go back k steps
	Prob okay = Prob first error after A-k steps =  scales[A-k]; penalty = k + B - (A-k) + 1
	If not   k + B - (A-k) + 1 + B + 1;
	*/
	for(int k=1; k<A; k++){
		score = scales[A-k]*(k + B - (A-k) + 1) + (1-scales[A-k])*( k + B - (A-k) + 1 + B + 1);		
		if(score < minscore) minscore = score;
	}

	cout << "Case #" << t <<  ": " << minscore << endl;
	}
}
