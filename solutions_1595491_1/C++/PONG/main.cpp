#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char * const argv[]) {
	//ifstream in("..//..//sample.in.txt");
	//ifstream in("..//..//B-small-attempt0.in.txt");
	ifstream in("..//..//B-large.in.txt");
	
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
	int N;	// number of Googlers
	int	S;	// number of surprising triplets
	int p;	// lowest best result
	
	in >> T;
	
	for (int i = 0; i < T; i++) {
		in >> N;
		in >> S;
		in >> p;
		int t[N];
		
		for (int n = 0; n < N; n++) {
			in >> t[n];
		}
		
		// compute the answer
		int answer = 0;
		int s = 0;
				
		for (int n = 0; n < N; n++) {
			int minimumNoSurprise = p * 3 - 2;
			int minimumSurprise = minimumNoSurprise - 2;
			if (minimumNoSurprise < 0)
				minimumNoSurprise = 0;
			if (minimumSurprise < 0)
				minimumSurprise = 0;
			cout << n << ": " << minimumNoSurprise << " " << minimumSurprise << endl;
			
			if (t[n] == 0) {
				if (p == 0)
					answer++;				
			}
			else if (t[n] >= minimumNoSurprise) {
				answer++;
			}
			else if (s < S && t[n] >= minimumSurprise) {
				s++;
				answer++;
			}
		}
		
		out << "Case #" << (i + 1) << ": " << answer << endl;
	}
	
	in.close();
	out.close();
    return 0;
}
