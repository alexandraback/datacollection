# include <iostream>
# include <cmath>
# include <vector>
# include <string>
# include <algorithm>
# include <ostream>
# include <fstream>
# include <stdio.h>
# include <stdlib.h>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int> > vii;

string CaseName = "A-small-attempt0";
#define MAX_LOOPS 100000

int Solve(long long int N) {
  
  int nvisited = 0;
  
  vb visited(10, false);
  long long int local = N;
  int nloops = 0;
  int count = 0;
  while ((nvisited < 10) && (nloops < MAX_LOOPS)) {
    local = N*(count+1);
    string tmp = to_string(local);
    for (int i = 0; i < tmp.size(); i++) {
      int l = (int) (tmp[i]); 
      
      if (!visited[l]) {
        visited[l] = true;
        nvisited++;
      }
    }
    
    count++;    
    nloops++;
  }
  
  if (nloops == MAX_LOOPS) {
    return -1;
  } else {
    return local;
  }
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
	
	for (int i = 1; i <= NCases; i++) {
		
		long long int N;
		In >> N;
		
		int ret = Solve(N);
		
		if (ret < 0) {

		  Out << "Case #" << i << ": INSOMNIA" << endl;
//		  cout << "Case #" << i << ": INSOMNIA" << endl;	
		  	
    } else {
      Out << "Case #" << i << ": " << ret << endl;
//		  cout << "Case #" << i << ": " << ret << endl;
    }
	}
	// Close Input and Output Files //
	In.close();
	Out.close();

	return 0;

}
