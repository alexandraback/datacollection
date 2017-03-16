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

string CaseName = "B-small-attempt0";

int Solve(string data) {
  
  int N = data.size();
  
  int npos = 0;
  int flip = 0;
  for (int i = 0; i < N; i++) {
    if (data[i] == '+') npos++;  
  }
  
  string local = data;
  
  while (npos < N) {
    
    int endind = 0;
    char start = local[0];
    npos = 0;
    
    for (int i = 0; i < N; i++) {
      if (local[i] != start) {
        break;
      } else {
        local[i] = (local[i] == '+') ? '-' :'+';
        endind++;

      } 
    }
    
    for (int i = 0; i < N; i++) {
      if (local[i] == '+') npos++;
    }
    
    flip++;
  
  }
  
  
  return flip;
}

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
		
		string data;
		In >> data;
		
		int ret = Solve(data);

		Out << "Case #" << i << ": " << ret << endl;
		cout << "Case #" << i << ": "<< ret << endl;		

	}
	// Close Input and Output Files //
	In.close();
	Out.close();

	return 0;

}
