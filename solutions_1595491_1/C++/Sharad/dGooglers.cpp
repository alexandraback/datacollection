#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	for(int i=0; i<T; ++i) {
		int n,s,p;
		cin >> n >> s >> p;	// dancers
		int score;//s = new int[n];
		int surely = 0;	// surely contains 1 p
		int may = 0;	// may contain p if they are surprising
		for(int j=0; j<n; ++j) {
			cin >> score;
			if(score > 3*(p-1)) {
				surely++;
			} else  if(score > 0 && (score+1 >= 3*(p-1))) {
				may++;
			}			
		}
		int max;
		if(p == 0)
			max = n;
		else
			max = (may >= s) ? surely+s : surely+may;
		cout << "Case #"<<i+1<< ": " << max << endl;
		
	//	delete []scores;
		
	}
	
	
	return 0;
}