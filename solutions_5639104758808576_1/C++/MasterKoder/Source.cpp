#include <fstream>
#include <queue>
#include <utility>
#include <string>

void readData(std::fstream& in, int& numTests,
    std::queue<std::pair<int, std::string>>& testData);
void solveAndWrite(std::fstream& out, int numTests,
    std::queue<std::pair<int, std::string>>& testData);

int main() {
  int numTests;
  std::queue<std::pair<int, std::string>> testData;
  std::fstream in("input.txt", std::ios::in);
  std::fstream out("output.txt", std::ios::out);

  readData(in, numTests, testData);
  solveAndWrite(out, numTests, testData);

  return 0;
}

void readData(std::fstream& in, int& numTests,
    std::queue<std::pair<int, std::string>>& testData) {
  int shynessMax;
  std::string shynessList;
  std::pair<int, std::string> tempData;

  in >> numTests;
  
  for (auto i = 0; i < numTests; ++i) {
    in >> shynessMax;
    std::getline(in, shynessList);
    tempData = std::make_pair(shynessMax, shynessList);
    testData.push(tempData);
  }

  in.close();
}

void solveAndWrite(std::fstream& out, int numTests,
    std::queue<std::pair<int, std::string>>& testData) {
  int result;
  int partialSum;
  std::string shynessList;

  for (auto i = 0; i < numTests; ++i) {
    result = 0;
    partialSum = 0;
    shynessList = testData.front().second;
    testData.pop();

    for (auto j = 1; j < shynessList.length(); ++j) {
      if (shynessList.at(j) != '0' && (j - 1) > partialSum) {
        int temp = (j - 1) - partialSum;
        partialSum += temp;
        result += temp;        
      }

      partialSum += (shynessList.at(j) - '0');
    }

    out << "Case #" << (i + 1) << ": " << result << "\n";
  }
    
  out.close();
}
