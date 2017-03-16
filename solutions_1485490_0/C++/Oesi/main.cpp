#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

unsigned int numBox[100], typBox[100], numToy[100], typToy[100];

int match(unsigned int bi, unsigned int ti, unsigned int bl, unsigned int tl);

int waitForNext(unsigned int bi, unsigned int ti, unsigned int bl, unsigned int tl);
int skip(unsigned int bi, unsigned int ti, unsigned int bl, unsigned int tl) {
  // merge
  if (bi > 99 || typBox[bi] == 0 || ti > 99 || typToy[ti] == 0)
    return 0;

  if (typToy[ti] == typBox[bi]) {
    if (bl == tl) {
      int wfn = waitForNext(bi + 1, ti + 1, numBox[bi + 1], numToy[ti + 1]);
      int skp = skip(bi + 1, ti + 1, numBox[bi + 1], numToy[ti + 1]);

      return bl + std::max(wfn, skp);
    }
    else if (bl < tl) {
      int wfn = waitForNext(bi + 1, ti, numBox[bi + 1], tl - bl);
      int skp = skip(bi + 1, ti, numBox[bi + 1], tl - bl);

      return bl + std::max(wfn, skp);
    }
    else {
      int wfn = waitForNext(bi, ti + 1, bl - tl, numToy[ti + 1]);
      int skp = skip(bi, ti + 1, bl - tl, numToy[ti + 1]);

      return tl + std::max(wfn, skp);
    }
  }
  else {
    int wfn = waitForNext(bi + 1, ti, numBox[bi + 1], tl);
    int skp = skip(bi + 1, ti, numBox[bi + 1], tl);
    return std::max(wfn, skp);
  }
}

int waitForNext(unsigned int bi, unsigned int ti, unsigned int bl, unsigned int tl) {
  // merges following boxes matching type and toys
  while (bi < 100 && typBox[bi] != 0 && ti < 100 && typToy[ti] != 0) {
    if (typToy[ti] == typBox[bi]) {
      if (bl == tl) {
        int wfn = waitForNext(bi + 1, ti + 1, numBox[bi + 1], numToy[ti + 1]);
        int skp = skip(bi + 1, ti + 1, numBox[bi + 1], numToy[ti + 1]);

        return bl + std::max(wfn, skp);
      }
      else if (bl < tl) {
        int wfn = waitForNext(bi + 1, ti, numBox[bi + 1], tl - bl);
        int skp = skip(bi + 1, ti, numBox[bi + 1], tl - bl);

        return bl + std::max(wfn, skp);
      }
      else {
        int wfn = waitForNext(bi, ti + 1, bl - tl, numToy[ti + 1]);
        int skp = skip(bi, ti + 1, bl - tl, numToy[ti + 1]);

        return tl + std::max(wfn, skp);
      }
    }
    else {
      ti++;
      tl = numToy[ti];
    }
  }

  return 0;
}

int main (int argc, const char **argv) {
  unsigned int numCases;

  if (argc != 2) {
    std::cout << "syntax: C file" << std::endl;
    return 1;
  }

  std::ifstream input;
  input.open(argv[1]);
  if (!input.is_open()) {
    std::cout << "file not found" << std::endl;
    return 1;
  }

  std::string line;
  getline(input, line);
  std::stringstream ss(line);

  ss >> numCases;

  if (numCases > 100) {
    std::cout << "numCases exceeds 100" << std::endl;
  }

  std::ofstream output;
  output.open("result.txt");

  for (unsigned int i = 0;i<numCases;i++) {
    unsigned int N, M;
    getline(input, line);
    std::stringstream ss(line);
    ss >> N;
    ss >> M;

    memset(numBox, 0, sizeof(unsigned int) * 100);
    memset(typBox, 0, sizeof(unsigned int) * 100);
    memset(numToy, 0, sizeof(unsigned int) * 100);
    memset(typToy, 0, sizeof(unsigned int) * 100);

    getline(input, line);
    ss = std::stringstream(line);
    for (unsigned int n = 0;n < N;n++) {
      ss >> numBox[n];
      ss >> typBox[n];
    }

    getline(input, line);
    ss = std::stringstream(line);
    for (unsigned int m = 0;m < M;m++) {
      ss >> numToy[m];
      ss >> typToy[m];
    }

    int wfn = waitForNext(0, 0, numBox[0], numToy[0]);
    int skp = skip(0, 0, numBox[0], numToy[0]);

    output << "Case #" << i+1 << ": " << std::max(wfn, skp) << std::endl;
  }

  input.close();
  output.close();

  return 0;
}