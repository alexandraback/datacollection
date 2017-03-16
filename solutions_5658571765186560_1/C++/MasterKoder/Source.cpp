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

    if (((rows * cols) % cells != 0) || cells >= 7 ||
        (cells > rows && cells > cols) ||
        ((cells + 1) / 2 > std::min(rows, cols))) {
      out << "RICHARD" << "\n";
    }
    else if (cells == 1 || cells == 2 || cells == 3) {
      out << "GABRIEL" << "\n";
    }
    else if (cells == 4) {
      out << (std::min(rows, cols) > 2 ? "GABRIEL" : "RICHARD") << "\n";
    }
    else if (cells == 5) {
      out << (std::min(rows, cols) == 3 && std::max(rows, cols) == 5 ? "RICHARD" : "GABRIEL") << "\n";
    }
    else if (cells == 6) {
      out << (std::min(rows, cols) > 3 ? "GABRIEL" : "RICHARD") << "\n";
    }
  }

  out.close();
}