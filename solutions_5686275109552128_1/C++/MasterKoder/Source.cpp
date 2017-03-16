#include <fstream>
#include <vector>
#include <queue>

void readData(std::fstream& in, int& numTests,
    std::queue<std::pair<int, std::vector<int>>>& testData);
void solveAndWrite(std::fstream& out, int numTests,
    std::queue<std::pair<int, std::vector<int>>>& testData);
int getMax(std::vector<int> data);
void improveResult(std::vector<int>& data, int max, int& special);

int main() {
  int numTests;
  std::queue<std::pair<int, std::vector<int>>> testData;
  std::fstream in("input.txt", std::ios::in);
  std::fstream out("output.txt", std::ios::out);

  readData(in, numTests, testData);
  solveAndWrite(out, numTests, testData);

  return 0;
}

void readData(std::fstream& in, int& numTests,
    std::queue<std::pair<int, std::vector<int>>>& testData) {
  int numDiners, tempPancakes;
  std::vector<int> pancakesDistr;
  std::pair<int, std::vector<int>> tempData;

  in >> numTests;

  for (auto i = 0; i < numTests; ++i) {
    if (!pancakesDistr.empty())
      pancakesDistr.clear();

    in >> numDiners;

    for (auto j = 0; j < numDiners; ++j) {
      in >> tempPancakes;
      pancakesDistr.push_back(tempPancakes);
    }

    tempData = std::make_pair(numDiners, pancakesDistr);
    testData.push(tempData);
  }

  in.close();
}

void solveAndWrite(std::fstream& out, int numTests,
    std::queue<std::pair<int, std::vector<int>>>& testData) {
  int max, result;
  std::vector<int> tempData;
  std::vector<int>::iterator it;

  for (auto i = 0; i < numTests; ++i) {
    tempData = testData.front().second;
    testData.pop();

    int k = 2;
    int sum = 0;
    result = max = getMax(tempData);

    while (k < max) {
      sum = 0;
      for (it = tempData.begin(); it != tempData.end(); ++it) {
        sum += ((*it - 1) / k);
      }
      result = std::min(result, sum + k);
      k++;
    }

    out << "Case #" << (i + 1) << ": " << result << "\n";
  }

  out.close();
}

int getMax(std::vector<int> data) {
  int max = INT_MIN;
  std::vector<int>::iterator it;

  for (it = data.begin(); it != data.end(); ++it) {
    if (max < *it)
      max = *it;
  }

  return max;
}