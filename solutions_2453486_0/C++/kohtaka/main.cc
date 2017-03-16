#include <cstdlib>
#include <iostream>
#include <tr1/memory>
#include <vector>
#include <map>

typedef std::pair<unsigned int, unsigned int> Position;

class Line {
 private:
  unsigned int count_;
  const unsigned int MAX_COUNT;
 public:
  explicit Line (void) : count_(0), MAX_COUNT(4) {}
  Line (const Line& other) : count_(other.count_), MAX_COUNT(other.MAX_COUNT) {}
  ~Line (void) {}
  Line& operator= (const Line& other) {
    count_ = other.count_;
    return *this;
  }
  void incrementCount (void) { ++count_; }
  bool hasFullCount (void) const { return count_ == MAX_COUNT; }
};

class PositionToLineMap {
  typedef std::tr1::shared_ptr<Line> LinePtr;
 private:
  std::vector<LinePtr> lines_;
  std::map<Position, std::vector<LinePtr> > relation_;
 public:
  explicit PositionToLineMap (void) : lines_(), relation_() {
    for (unsigned int i = 0; i < 10; ++i) {
      lines_.push_back(LinePtr(new Line()));
    }
    for (unsigned int i = 0; i < 4; ++i) {
      for (unsigned int j = 0; j < 4; ++j) {
        relation_[Position(i, j)] = std::vector<LinePtr>();
        relation_[Position(i, j)].push_back(lines_[i]);
        relation_[Position(i, j)].push_back(lines_[j + 4]);
        if (i == j) {
          relation_[Position(i, j)].push_back(lines_[8]);
        }
        if ((3 - i) == j) {
          relation_[Position(i, j)].push_back(lines_[9]);
        }
      }
    }
  }
  ~PositionToLineMap (void) {}
  void incrementLineCount (const Position& position) {
    for (auto line : relation_.at(position)) {
      line.get()->incrementCount();
    }
  }
  bool hasFullCountedLine (void) const {
    for (auto line : lines_) {
      if (line.get()->hasFullCount()) {
        return true;
      }
    }
    return false;
  }
};

void fillSquare (
    PositionToLineMap& xMap,
    PositionToLineMap& oMap,
    unsigned int row,
    const std::string& buffer,
    bool* hasEmptySquare) {

  for (unsigned int col = 0, l = buffer.length(); col < l; ++col) {
    switch (buffer[col]) {
    case 'X':
      xMap.incrementLineCount(Position(row, col));
      break;
    case 'O':
      oMap.incrementLineCount(Position(row, col));
      break;
    case 'T':
      xMap.incrementLineCount(Position(row, col));
      oMap.incrementLineCount(Position(row, col));
      break;
    case '.':
      *hasEmptySquare = true;
      break;
    }
  }
}

int main (int argc, char** argv) {

  int T;
  std::cin >> T;

  for (unsigned int t = 0; t < T; ++t) {
    bool hasEmptySquare = false;
    PositionToLineMap xMap, oMap;
    std::string buffer;
    std::cin >> buffer;
    fillSquare(xMap, oMap, 0, buffer, &hasEmptySquare);
    for (unsigned int row = 1, l = buffer.length(); row < l; ++row) {
      std::cin >> buffer;
      fillSquare(xMap, oMap, row, buffer, &hasEmptySquare);
    }

    std::cout << "Case #" << t + 1 << ": ";
    if (xMap.hasFullCountedLine()) {
      std::cout << "X won" << std::endl;
    }
    else if (oMap.hasFullCountedLine()) {
      std::cout << "O won" << std::endl;
    }
    else if (hasEmptySquare) {
      std::cout << "Game has not completed" << std::endl;
    }
    else {
      std::cout << "Draw" << std::endl;
    }
  }

  return EXIT_SUCCESS;
}

