#include "main.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Not enough arguments" << endl;
    return -1;
  }
  ifstream inputFile(argv[1]);

  if (!inputFile.is_open()) {
    cout << "Could not open file" << endl;
    return -1;
  }

  string line;
  // Read the number of cases
  getline(inputFile, line);
  int caseCount = atoi(line.c_str());

  ofstream outputFile("q2.out");
  if (!outputFile.is_open()) {
    cout << "Could not create file" << endl;
    return -1;
  }
  
  int N, S, p;
  string s;
  //vector<int> t;
  int t;
  int o = 0;
  for (int i = 1; i <= caseCount; i++) {
    // Read data from line
    getline(inputFile, line);
    stringstream stream(line);
    stream >> s;
    N = atoi(s.c_str());
    stream >> s;
    S = atoi(s.c_str());
    stream >> s;
    p = atoi(s.c_str());

    for (int j = 0; j < N; j++) {
      stream >> s;
      t = atoi(s.c_str());
      if (t > 3*p - 3)
        o++;
      else if (S > 0 && ((t == 3*p - 4 && p - 2 >= 0) || (t == 3*p - 3 && p - 2 >= 0))) {
        S--;
        o++;
      }
    } 
    
    // We maximize the number of users that have a score of at least p by finding those
    // with a score of:
    //  (p-1, p-1, p-2) => (p, p-2, p-2)
    //  (p-1, p-1, p-1) => (p, p-1, p-2)

    outputFile << "Case #" << i << ": " << o << endl;
    o = 0;
  }

  inputFile.close();
  outputFile.close();

  return 0;
}
