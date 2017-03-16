#include "main.hpp"

using namespace std;

int int2array(int n, char *arr) {
  int j = 0;
  while (n != 0) {
    arr[j] = n%10;
    n = n/10;
    j++;
  }
  arr[j] = '\0';
  return j;
}

int array2int(char *arr, int size) {
  int r = 0;
  for (int i = size - 1; i >= 0; i--) {
    r *= 10;
    r += arr[i];
  }
  return r;
}

void cpy(char* dest, char* src, int size) {
  for (int i = 0; i < size - 1; i++) {
    dest[i] = src[i];
  }
}

bool isrotation(char *a1, char *a2, int size) {
  bool b;
  for (int i = 0; i < size - 1; i++) {
    b = true;
    for (int j = 0; j < size - 1; j++) {
      if (a1[i%size] != a2[j%size]) {
        b = false;
        break;
      }
    }
    if (b == true)
      return true;
  }
  return false;
}

typedef struct {
  int x, y;
} pair;

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
  
  int o = 0;
  int n, m;
  char T1[12];
  char T2[12];
  int perm;
  string s;
  int exp;
  bool b;
  vector<int> rot;

  for (int i = 1; i <= caseCount; i++) {
    // Read data from line
    getline(inputFile, line);
    stringstream stream(line);
    stream >> s;
    n = atoi(s.c_str());
    stream >> s;
    m = atoi(s.c_str());

    // Enumerate through all integers between n and m
    for (int t = n; t <= m; t++) {
      int2array(t, T1);

      exp = (int)log10(t) + 1;
      rot.clear();
      for (int j = 0; j < exp; j++) {
        b = false;
        for (int k = 0; k < exp; k++) {
          T2[k] = T1[(j + k)%exp];
        }
        perm = array2int(T2, exp);
        
        for (vector<int>::iterator k = rot.begin(); k != rot.end(); k++) {
          if (perm == *k) {
            b = true;
            break;
          }
        }
        
        if (!b && perm > t && perm <= m) {
          rot.push_back(perm);
          o++;
        }
      }
    }

    outputFile << "Case #" << i << ": " << o << endl;
    o = 0;
  }

  inputFile.close();
  outputFile.close();

  return 0;
}
