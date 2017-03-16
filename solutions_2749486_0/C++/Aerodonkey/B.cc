// {{{ C++ headers
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
/// }}}

class Problem {
public:
  Problem(int case_num) : case_num_(case_num) {}
  ~Problem() {}

  void Input();
  void Solve();
  void Output() const;

  static void Initialize();
  static void Finalize();

private:
  struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point& rhs) const {
      return x == rhs.x && y == rhs.y;
    }
    bool operator<(const Point& rhs) const {
      return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
  };

  struct State {
    Point position;
    int step;
    State() : position(), step(0) {}
    State(const Point& position, int step) : position(position), step(step) {}
    bool operator==(const State& rhs) const {
      return position == rhs.position && step == rhs.step;
    }
    bool operator<(const State& rhs) const {
      return position < rhs.position ||
             (position == rhs.position && step < rhs.step);
    }
  };

  enum class Direction {
    UNKNOWN,
    NORTH,
    SOUTH,
    EAST,
    WEST
  };

  struct Move {
    Direction direction;
    State from;
    Move() : direction(Direction::UNKNOWN), from() {}
    Move(Direction direction, const State& state) :
      direction(direction), from(state) {}
  };

  int case_num_;

  int x_;
  int y_;

  std::string moves_;
};

void Problem::Input() {
  std::cin >> x_ >> y_;
}

void Problem::Solve() {
  std::vector<Direction> directions {
    Direction::NORTH,
    Direction::SOUTH,
    Direction::EAST,
    Direction::WEST
  };
  Point origin(0, 0);
  Point target(x_, y_);
  std::queue<State> queue;
  std::map<State, Move> states;
  State initial(origin, 0);
  queue.push(initial);
  states[initial] = Move(Direction::UNKNOWN, initial);
  bool reached = false;
  State final;
  while (!reached && !queue.empty()) {
    State current = queue.front();
    queue.pop();
    for (Direction direction : directions) {
      State next = current;
      ++next.step;
      switch (direction) {
        case Direction::NORTH:
          next.position.y += next.step;
          break;
        case Direction::SOUTH:
          next.position.y -= next.step;
          break;
        case Direction::EAST:
          next.position.x += next.step;
          break;
        case Direction::WEST:
          next.position.x -= next.step;
          break;
        default:
          assert(false);
      }
      if (states.count(next) == 0) {
        queue.push(next);
        states[next] = Move(direction, current);
      }
      if (next.position == target) {
        reached = true;
        final = next;
        break;
      }
    }
  }
  assert(reached);
  while (!(final == initial)) {
    Direction direction = states[final].direction;
    char dir_sign = ' ';
    switch (direction) {
      case Direction::NORTH:
        dir_sign = 'N';
        break;
      case Direction::SOUTH:
        dir_sign = 'S';
        break;
      case Direction::EAST:
        dir_sign = 'E';
        break;
      case Direction::WEST:
        dir_sign = 'W';
        break;
      default:
        break;
    }
    moves_ = dir_sign + moves_;
    final = states[final].from;
  }
}

void Problem::Output() const {
  std::cout << "Case #" << case_num_ << ": " << moves_ << std::endl;
}

void Problem::Initialize() {
}

void Problem::Finalize() {
}

int main() {
  std::ios_base::sync_with_stdio(false);
  Problem::Initialize();
  int num_cases = 0;
  std::cin >> num_cases;
  for (int case_num = 1; case_num <= num_cases; case_num++) {
    Problem problem(case_num);
    problem.Input();
    problem.Solve();
    problem.Output();
  }
  Problem::Finalize();
}
