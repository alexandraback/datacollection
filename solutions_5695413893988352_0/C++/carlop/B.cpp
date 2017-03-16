#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <set>

using namespace std;

int number_of_inversion(const string & S) {
	int c=0;
	for (int i=1; i<S.size(); i++) if (S[i] != S[i-1]) c++;
	return c;
}

void fill_it_greedily(vector <string> in, vector <string> & best, unsigned long long & best_diff) {
	vector <string> res(2);
	
	int steps = 0;
	for (string::iterator it0 = in[0].begin(), it1 = in[1].begin(); it0<in[0].end(); it0++, it1++, steps++) {
		char C[2] = {'0', '0'};
		
		if (isdigit(*it0)) C[0]=*it0;
		if (isdigit(*it1)) C[1]=*it1;
		
		if (res[0] == res[1]) {
			if (!isdigit(*it0)) C[0] = C[1];
			if (!isdigit(*it1)) C[1] = C[0];
			
			
			//copy-paste!!!
			if (!isdigit(*it0)) {
				if (C[0] != '0') {
					vector <string> recurrence(in);
					recurrence[0][steps] = (char)((int)C[0]-1);
					recurrence[1][steps] = C[1];
					fill_it_greedily(recurrence, best, best_diff);
				}
				if (C[0] != '9') {
					vector <string> recurrence(in);
					recurrence[0][steps] = (char)((int)C[0]+1);
					recurrence[1][steps] = C[1];
					fill_it_greedily(recurrence, best, best_diff);
				}
			}
			if (!isdigit(*it1)) {
				if (C[1] != '0') {
					vector <string> recurrence(in);
					recurrence[1][steps] = (char)((int)C[1]-1);
					recurrence[0][steps] = C[0];
					fill_it_greedily(recurrence, best, best_diff);
				}
				if (C[1] != '9') {
					vector <string> recurrence(in);
					recurrence[1][steps] = (char)((int)C[1]+1);
					recurrence[0][steps] = C[0];
					fill_it_greedily(recurrence, best, best_diff);
				}
			}
		}
		else if (res[0] < res[1]) {
			if (!isdigit(*it0)) C[0] = '9';
			if (!isdigit(*it1)) C[1] = '0';
		}
		else {
			if (!isdigit(*it0)) C[0] = '0';
			if (!isdigit(*it1)) C[1] = '9';
		}
		
		*it0 = C[0];
		*it1 = C[1];
		res[0] += C[0];
		res[1] += C[1];
	}
	

	vector <unsigned long long> V;
	V.push_back(stoull(res[0]));
	V.push_back(stoull(res[1]));
	
	
	unsigned long long diff;
	if (V[0] <= V[1]) diff = V[1]-V[0];
	else diff = V[0] - V[1];
	

	if (best.size() == 0) {
		best = res;
		best_diff = diff;
	}
//	std::cerr<<res[0] <<" "<< res[1] << "\t";
//	std::cerr<<best[0] <<" "<< best[1] << "\n";


	if (diff < best_diff) {
		best_diff = diff;
		best = res;
	}
	else if (diff == best_diff){
		if (res[0] < best[0]) best = res;
		else if (res[0] == best[0] && res[1] < best[1]) best = res;
	}
}

int main(void) {
	int num_test;
	cin>>num_test;
	
	for (int test=1; test<=num_test; test++) {
		vector<string> in(2);
		cin>>in[0]>>in[1];
		
		vector <string> res;
		unsigned long long diff = 0;
		fill_it_greedily(in, res, diff);
		
		cout<<"Case #"<<test<<": "<<res[0] << " " << res[1]<<"\n";
//		cerr << "-------------\n";
	}
	return 0;
}
