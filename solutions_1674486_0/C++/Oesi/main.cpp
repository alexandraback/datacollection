#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

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
    unsigned int N = 0;
    unsigned int classData[1001][11];
    memset(classData, 0, sizeof(unsigned int) * 1001 * 11);

    getline(input, line);
    ss = std::stringstream(line);
    ss >> N;

    for (unsigned int j = 1;j <= N;j++) {
      unsigned int M = 0;
      getline(input, line);
      ss = std::stringstream(line);
      ss >> M;

      for (unsigned int k = 1;k <= M;k++) {
        ss >> classData[j][k];
      }
    }

      for (unsigned int j = 1;j <= N;j++) {
        bool inherited[1001];
        memset(inherited, 0, sizeof(bool) * 1001);
        std::queue<unsigned int> q;
        q.push(j);
        while(!q.empty()) {
          unsigned int next = q.front();
          q.pop();
          unsigned int index = 1;
          while(classData[next][index] != 0) {
            if (inherited[classData[next][index]]) {
              output << "Case #" << i+1 << ": Yes" << std::endl;
              goto next;
            }
            inherited[classData[next][index]] = true;
            q.push(classData[next][index]);
            index++;
          }
        }
      }


    output << "Case #" << i+1 << ": No" << std::endl;

next:
    ;
  }

  input.close();
  output.close();

  return 0;
}