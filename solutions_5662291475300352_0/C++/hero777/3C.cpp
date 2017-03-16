#include <iostream>
#include <algorithm>
#include <vector>
#include<fstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
	int T;
	ifstream input;
	ofstream output;
	input.open("a.txt");
	output.open("output.txt");
	input >> T;
	forn (i, T){
		int N;
		input >> N;
		int D[N], H[N];
		long long M[N];
		forn (j, N){
			input >> D[j];
			input >> H[j];
			input >> M[j];
		}
		if (N==1){

			output << "Case #"<< i+1 <<": " << 0	 << endl;	
			continue;
		}
		
			
				
		long long a, b;
		a = (360-D[0])*M[0];
		b = (360-D[1])*M[1];
		int c = (a<b) ? 0 :1;
		if (a==b) {
			output << "Case #"<< i+1 <<": " << 0	 << endl;	
			continue;
		}
		long long d = (720-D[c])*M[c];
		if (d > max(a,b)){
			output << "Case #"<< i+1 <<": " << 0	 << endl;	
			continue;
		}
		else
			output << "Case #"<< i+1 <<": " << 1	 << endl;
	}	
}


