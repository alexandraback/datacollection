#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;

int main()
{
	int numCase, modifications;
	cin >> numCase;
	long long int myMote, numberOfMotes,temp, ans;

	ofstream myfile;
  	myfile.open ("output.txt");

	for (int num = 0; num < numCase; num++)
	{

		// Read dimensions
		cin >> myMote;
		cin >> numberOfMotes;
		
		// Read motes
		vector<long long int> motes;
		for(int i=0;i<numberOfMotes;i++) {
			cin >> temp;
			motes.push_back(temp);
		}
		
		// Sort the vector with motes
		sort (motes.begin(), motes.end());
		
		// Absorb motes or make operations
		int bestSoFar=motes.size(); // By deleting all of them at once
		int numberOfAdds=0;
		while(motes.size()>0) {
			// Try to absorb the smallest mode
			if(motes.at(0)<myMote) {
				myMote+=motes.at(0);
				motes.erase(motes.begin());
			}
			else { // Make an operation
				if(bestSoFar>numberOfAdds+motes.size()) { // If deleting all now would be better than before
					bestSoFar=numberOfAdds+motes.size();
				} 
				// Try to add the best possible mote
				myMote+=myMote-1; // Best way to add
				numberOfAdds++;
				if(myMote==1) {
					break;				
				}
				if(numberOfAdds>bestSoFar) {
					break;
				}
			}
		}
		
		// last fix
		if(bestSoFar>numberOfAdds+motes.size()) { // If deleting all now would be better than before
			bestSoFar=numberOfAdds+motes.size();
		}

		// Print outcome
		myfile << "Case #" << (num+1) << ": " << bestSoFar << endl;
	}

  	myfile.close();
	return 0;
}
