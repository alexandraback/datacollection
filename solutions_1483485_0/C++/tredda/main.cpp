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

  ofstream outputFile("q1.out");
  if (!outputFile.is_open()) {
    cout << "Could not create file" << endl;
    return -1;
  }

  char cstr[100];
  for (int i = 1; i <= caseCount; i++) {
    getline(inputFile, line);
    strcpy(cstr, line.c_str());
    for (int j = 0; j < strlen(cstr); j++) {
      if (cstr[j] != ' ')
        cstr[j] = map[cstr[j] - 'a'];
    }
    outputFile << "Case #" << i << ": " << string(cstr) << endl;
  }

  inputFile.close();
  outputFile.close();

  return 0;
}
