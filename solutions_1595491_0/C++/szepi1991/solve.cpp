#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	
	unsigned cases;
	cin >> cases;
	
	unsigned num, surps, p;
	unsigned total;
	unsigned base;
	
	for (unsigned i = 0; i < cases; ++i) {
		
		if (i > 0)
			cout << endl;
		
		cin >> num >> surps >> p;
		unsigned above = 0;
		unsigned surpAbove = 0;
		
		for (int g = 0; g < num; ++g) {
			cin >> total;
			base = total/3;
			// consider not surprising case first..
				// make note if we achieve p.
				// If not, make extra note if by 
				// having this surprising we can achieve it
			
			// special case
			if (total == 0) {
				if (p == 0) {
					above++;
				} // suprising can't help here
				continue; // move on to next participant
			}
			
			switch (total % 3) {
				case 0:
					if (base >= p) {
						above++;
					} else if (base + 1 == p) {
							surpAbove++;
					}
				break;
				case 1:
					if (base+1 >= p) {
						above++;
					} // suprising can't help here
				break;
				case 2:
					if (base + 1 >= p) {
						above++;
					} else if (base + 2 == p) {
							surpAbove++;
					}
				break;
			}
			
		}
		
		// answer is above + min(surpAbove, surps)
		cout << "Case #" << i+1 << ": " << above + min(surpAbove, surps);
		
	}
	
	return 0;
}
