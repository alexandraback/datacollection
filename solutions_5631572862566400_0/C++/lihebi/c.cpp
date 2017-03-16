#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>

// #include <gtest/gtest.h>


/**
 *

 4
 4
 2 3 4 1
 4
 3 3 4 1
 4
 3 3 4 3
 10
 7 8 10 10 9 2 9 6 3 3

 Case #1: 4
 Case #2: 3
 Case #3: 3
 Case #4: 6

*/


using namespace std;


int solve(int n, std::vector<int> bff, std::map<int, std::set<int> > revert);
int main(int argc, char* argv[]) {
  int t;
  cin >> t;
  int tmp;
  for (int i=0;i<t;i++) {
    int n;
    cin >> n;
    std::vector<int> bff;
    std::map<int, std::set<int> > revert;
    for (int j=0;j<n;j++) {
      cin >> tmp;
      tmp--; // CAUTION I convert everything to start from 0
      bff.push_back(tmp);
      revert[tmp].insert(i);
    }
    cout << "Case #" << i+1 << ": ";
    int size = solve(n, bff, revert);
    cout << size  << "\n";
  }
  // ::testing::InitGoogleTest(&argc, argv);
  // return RUN_ALL_TESTS();
  return 0;
}

std::set<int> get_cross(std::vector<int> bff, std::set<int> leaf_points) {
  std::set<int> done;
  std::set<int> cross_points;
  for (int leaf : leaf_points) {
    std::set<int> cur_set;
    cur_set.insert(leaf);
    done.insert(leaf);
    int tmp = leaf;
    while (true) {
      tmp = bff[tmp];
      if (cur_set.count(tmp) == 1) {
        // j is the cross point
        cross_points.insert(tmp);
        assert(done.count(tmp));
      }
      if (done.count(tmp) == 1) {
        // previous saw j
        break;
      } else {
        cur_set.insert(tmp);
        done.insert(tmp);
      }
    }
  }
  return cross_points;
}

int circle(int n, std::vector<int> bff, std::map<int, std::set<int> > revert) {
  // cout << "circle"  << "\n";
  std::set<int> done;
  int ret=0;
  for (int i=0;i<n;i++) {
    // cout << i  << "\n";
    if (done.count(i) == 0) {
      std::vector<int> circle;
      done.insert(i);
      circle.push_back(i);
      int tmp = bff[i];
      while (done.count(tmp) == 0) {
        // cout << tmp  << "\n";
        circle.push_back(tmp);
        done.insert(tmp);
        tmp = bff[tmp];
      }
      if (tmp == i) {
        // this may be a perfect circle
        // the only case is to check if everyone has only one revert
        for (int c : circle) {
          if (revert.count(c) > 1) {
            goto next;
          }
        }
        if (ret < (int)circle.size()) ret = circle.size();
      }
    }
  next:;
  }
  // cout << "circle out"  << "\n";
  return ret;
}

int solve(int n, std::vector<int> bff, std::map<int, std::set<int> > revert) {
  int ret = 0;
  // leaf
  std::set<int> leaf_points;
  for (int j=0;j<n;j++) {
    if (revert.count(j) == 0) leaf_points.insert(j);
  }
  int circle_out = circle(n, bff, revert);
  if (ret < circle_out) ret = circle_out;
  // if (leaf_points.empty()) return n;
  // it is possible that non-leaf nodes can also be crosspoint
  std::set<int> cross_points = get_cross(bff, leaf_points);
  // cout << "cross points: ";
  // for (int a : cross_points) {
  //   cout << a  << " ";
  // }
  // cout   << "\n";
  // for all the cross_points, claculate their circle size.
  std::set<int> double_cross;
  for (int cross : cross_points) {
    int tmp = bff[cross];
    int count=1;
    while (tmp != cross) {
      count ++;
      tmp = bff[tmp];
    }
    if (count == 2) {
      // if the circle size != 2, that is final
      // otherwise, double_cross insert both of them
      double_cross.insert(tmp);
      double_cross.insert(bff[tmp]);
    } else {
      if (ret < count) {
        // new larger circle found
        ret = count;
      }
    }
  }

  // then, for every leaf, see if they lead to a double_cross
  for (int leaf : leaf_points) {
    int tmp = leaf;
    std::set<int> cur_set;
    int count = 0;
    while (cur_set.count(tmp) == 0) {
      count ++;
      cur_set.insert(tmp);
      tmp = bff[tmp];
      if (double_cross.count(tmp) == 1) {
        // if yes, bingo
        int size;
        for (int a : revert[tmp]) {
          if (cur_set.count(a) == 0) {
            size = count+1;
            if (ret < size) ret = size;
          }
        }
        size = count;
        if (ret < size) ret = size;
      }
    }
  }
  return ret;
}
