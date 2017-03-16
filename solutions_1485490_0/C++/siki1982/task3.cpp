#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>


using namespace std;

#define PI acos(-1.)
#define EPS 1e-7
#define LL long long
#define UI unsigned int

struct Item {
  LL num;
  int type;
};


LL count(int i, int j, LL rem1, LL rem2, vector<Item> boxes, vector<Item> toys) {
  if (i == boxes.size() || j == toys.size()) return 0;
  //cerr << i << " " << j << " " << endl;
  boxes[i].num -= rem1;
  toys[j].num -= rem2;

  if (boxes[i].type == toys[j].type) {
    //cerr << "equal" << endl;
    if (boxes[i].num < toys[j].num) {
      return boxes[i].num + count(i + 1, j, 0, toys[j].num - boxes[i].num, boxes, toys);
    } else if (boxes[i].num > toys[j].num) {
      return toys[j].num + count(i, j + 1, boxes[i].num - toys[j].num, 0, boxes, toys);
    } else {
      return toys[j].num + count(i + 1, j + 1, 0, 0, boxes, toys);
    }
  } else {
    //cerr << "boxes " << count(i + 1, j, 0, 0, boxes, toys) << endl;
    //cerr << "toys " << count(i, j + 1, 0, 0, boxes, toys) << endl;
    return max(count(i + 1, j, 0, 0, boxes, toys), count(i, j + 1, 0, 0, boxes, toys));
  }
}


int main() {
  // Declare members
  int num_case;
  cin >> num_case;
  int N, M;
  vector<Item> boxes;
  vector<Item> toys;



  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    boxes.clear();
    toys.clear();
    cin >> N;
    cin >> M;
    boxes.resize(N);
    toys.resize(M);

    for (int i = 0; i < N; i++) {
      cin >> boxes[i].num;
      cin >> boxes[i].type;
    }

    for (int i = 0; i < M; i++) {
      cin >> toys[i].num;
      cin >> toys[i].type;
    }

    LL max = count(0, 0, 0, 0, boxes, toys);

    // Print output for case j
    cout << "Case #" << nc << ": " << max << endl;
  }


  return 0;
}
