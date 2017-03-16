#include <fstream>
#include <queue>
#include <utility>

void readData(std::fstream& in, int& numTests,
    std::queue<std::pair<int, std::pair<int, int>>>& testData);
void solveAndWrite(std::fstream& out, int numTests,
    std::queue<std::pair<int, std::pair<int, int>>>& testData);

int main() {
  int numTests;
  std::queue<std::pair<int, std::pair<int, int>>> testData;
  std::fstream in("input.txt", std::ios::in);
  std::fstream out("output.txt", std::ios::out);

  readData(in, numTests, testData);
  solveAndWrite(out, numTests, testData);

  return 0;
}

void readData(std::fstream& in, int& numTests,
    std::queue<std::pair<int, std::pair<int, int>>>& testData) {
  int cells, rows, cols;
  std::pair<int, int> tempPartialData;
  std::pair<int, std::pair<int, int>> tempData;

  in >> numTests;

  for (auto i = 0; i < numTests; ++i) {
    in >> cells >> rows >> cols;
    tempPartialData = std::make_pair(rows, cols);
    tempData = std::make_pair(cells, tempPartialData);
    testData.push(tempData);
  }

  in.close();
}

void solveAndWrite(std::fstream& out, int numTests,
    std::queue<std::pair<int, std::pair<int, int>>>& testData) {
  int cells, rows, cols;
  std::pair<int, int> tempPartialData;
  std::pair<int, std::pair<int, int>> tempData;

  for (auto i = 0; i < numTests; ++i) {
    tempData = testData.front();
    tempPartialData = tempData.second;
    cells = tempData.first;
    rows = tempPartialData.first;
    cols = tempPartialData.second;
    testData.pop();

    out << "Case #" << (i + 1) << ": ";

    if (((rows * cols) % cells != 0) || (rows == 2 && cols == 2 && cells == 4) ||
        (rows == 4 && cols == 2 && cells == 4) ||
        (rows == 2 && cols == 4 && cells == 4) ||
        (rows > 2 && cols < 2 && cells > 2) ||
        (rows < 2 && cols > 2 && cells > 2)) {
      out << "RICHARD" << "\n";
    }
    else {
      out << "GABRIEL" << "\n";
    }
  }

  out.close();
}