#include <iostream>
#include <iterator>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;



int main() {

  int nr = 0;
  int maxNr;
  cin >> maxNr;
  cin.ignore(10,'\n');
  cerr <<  "maxNr= " << maxNr << endl;


  string line;
  getline(cin,line);
  while(!cin.eof() && nr < maxNr) {

    // Process Line of test
    stringstream iss(line);

    int nrClasses;
    iss >> nrClasses;
    vector<vector<int> > matrix;
    for(int i = 0; i < nrClasses; ++i) {
      getline(cin,line);
      stringstream iss(line);
      vector<int> row;
      int nrSubs;
      iss >> nrSubs;
      istream_iterator<int> start(iss),end;
      
      copy(start,end,back_inserter(row));
      matrix.push_back(row);

    }
    bool diamant = false;
    cerr <<"Rows: " << matrix.size() << endl;
    for_each(matrix.begin(),matrix.end(),[&](vector<int> row) {
	
	vector<int> process = row;
	vector<int> parents;
	

	while(!process.empty()) {
	  int nr = process.back();
	  process.pop_back();
	  parents.push_back(nr);
	  vector<int> parent = matrix[nr-1];
	  for(int i = 0; i < parent.size() ; ++i) {
	    process.push_back(parent[i]);
	  }
	}
	
	sort(parents.begin(),parents.end());
	if(adjacent_find(parents.begin(),parents.end()) != parents.end()) {
	  // diamand structure
	  diamant = true;
	  return;
	}

    });

    string result = (diamant)?"Yes":"No";
    cout << "Case #" << ++nr << ": " << result << endl; 
    getline(cin,line);
  }
  if(nr != maxNr) {
    cerr << "unexpected end of stream..." << nr << " " << maxNr << endl;
  }

  return 0;
}
