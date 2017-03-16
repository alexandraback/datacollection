#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
using namespace std;

int main (int argc, char * const argv[]) {
    //ifstream in("..//..//sample.in.txt");
	ifstream in("..//..//C-small-attempt0.in.txt");
	
	if(!in) {
		cout << "Input file cannot be opened";
		return 1;
	}
	
	ofstream out("output.txt");
	if (!out) {
		cout << "Output file cannot be opened";
		in.close();
		return 1;
	}
	
	int T;	// number of test cases
	int A, B;	// A <= n < m <= B
	
	in >> T;
	for (int t = 0; t < T; t++) {
		cout << "Case#" << (t + 1) << ": " << endl;
		
		int answer = 0;
		
		in >> A;
		in >> B;
		
		char N[7];
		
		for (int n = A; n <= B; n++) {
			sprintf(N, "%i", n);
			
			// re-order the integer to see how many formation is available
			int lengthN = strlen(N);
			if (lengthN <= 1)
				continue;
			
			cout << "N = " << N << "(" << lengthN << ") M: ";					
			
			vector<int> ms(0);
			
			// find each of the formation
			for (int i = 1; i < lengthN; i++) {
				char M[lengthN];
				for (int l = 0; l < lengthN; l++) {
					M[l] = N[(l + i) % lengthN];
				}
				if (M[0] == '0')
					continue;
				int m = atoi(M);
				if (m <= n || m > B)
					continue;
				
				bool isDuplicated = false;
				// check for duplicates
				for (int j = 0; j < ms.size(); j++) {
					if (m == ms[j])
						isDuplicated = true;
				}
				if (isDuplicated)
					continue;
				
				cout << M << " ";
				answer++;
				ms.push_back(m);
			}
			
			cout << endl;
		}		
		cout << endl;
		
		out << "Case #" << (t + 1) << ": " << answer << endl;
	}
	
	in.close();
	out.close();
	
    return 0;
}
