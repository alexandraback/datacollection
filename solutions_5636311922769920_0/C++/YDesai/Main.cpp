# include <iostream>
# include <cmath>
# include <vector>
# include <string>
# include <algorithm>
# include <ostream>
# include <fstream>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vii;

string CaseName = "D-small-attempt1";



int main() {

	int NCases; 
	ifstream In;
	In.open(CaseName+".in");
	
	// Reads Number of cases //
	In >> NCases;
	
	// Opens output stream //
	ofstream Out;
	Out.open(CaseName+".out");

	
	int i,j;



	for (i = 1; i <= NCases; i++) {
		int K, C, S;
		
		In >> K >> C >> S;
    
		Out << "Case #" << i << ": ";
		cout << "Case #" << i << ": ";		
    
    
    for (int i = 1; i <= S; i++) {
      
      if (i != S) {
        Out << i << " ";
        cout << i << " ";
      } else {
        Out << i << endl;
        cout << i << endl;
      } 
    }
//    Out << endl;
//    cout << endl;
	}
	// Close Input and Output Files //
	In.close();
	Out.close();

	return 0;

}
