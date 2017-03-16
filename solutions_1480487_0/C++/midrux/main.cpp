#include <iomanip>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
using namespace std;

#define MAX(a,b) (a)>(b)?(a):(b)

int main(){
	ifstream in("A.in");
	ofstream out("result.txt");
	int TESTS; 
	in >> TESTS;
	cout.precision(6);
	cout.setf(ios::fixed,ios::floatfield);   // floatfield set to fixed
	
	out.precision(6);
	out.setf(ios::fixed,ios::floatfield);   // floatfield set to fixed
	int N;
	for(int test = 0; test<TESTS; test++){
		out << "Case #" << test+1 << ": ";
		cout << "Case #" << test+1 << ": ";
			in >> N;
		vector<int> s(N+1);
		double x = 0;
		for(int i =0;i<N;i++){
			in >> s[i];
			x += s[i];
		}

		for(int i = 0;i<N; i++){
			double low = 0, high = 1;
			double mid;
			for(int j = 0; j<100; j++){
				mid = (low+high)/2.0;
				double score = s[i] + x*mid;
				double totx = 1 - mid;
				for(int k = 0; k<N; k++){
					if(k==i) continue;
					double scorek = (double)s[k];
					totx -= MAX(0, ((score-scorek)/x));
					//scorek + x*porc > score;
					//<=> x*porc > score-scorek <=> porc > (score-scorek)/x
				}
				if(totx > 0) low = mid;
				else high = mid;
			}
			out << mid*100;
			if(i!=N-1) out << " ";
			cout << mid*100;
			if(i!=N-1) cout << " ";
		}
		out << endl;
		cout << endl;
	}
	return 0;
}