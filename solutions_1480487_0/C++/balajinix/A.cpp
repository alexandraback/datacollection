#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
  string line;
  stringstream ss;
  int T = 0;
  getline(cin, line);
  ss << line;
  ss >> T;
  ss.clear();

  for (int t=1;t<=T;t++) {
    getline(cin, line);
    ss << line;
    int N=0;
    ss >> N;
    double num=0;
    double sum=0;
    vector<double> orig;
    for (int i=0;i<N;i++) {
      ss >> num;
      sum+=num;
      orig.push_back(num);
    }
    double orig_sum = sum;
    ss.clear();
    vector<double> v = orig;
    bool all_equal = false;
    while (sum > 0) {
      double min=v[0];
      double second_min=v[1];
      if (min > second_min) {
        second_min = v[0];
        min = v[1];
      } else if (min == second_min) {
        bool flag = false;
        for (int i=1;i<N;i++) {
          if (v[i] > min) {
            flag = true;
            second_min = v[i];
            break;
          }
        }
        if (!flag) {
          all_equal = true;
          break;
        }
      }
      for (int i=0;i<N;i++) {
        if (v[i] < min) {
          second_min = min;
          min = v[i];
        }
      }
      double cost=0;
      double count=0;
      for (int i=0;i<N;i++) {
        if (v[i] == min) {
          count++;
          cost += (second_min - min);
        }
      }
      double dist = 0;
      if (cost > sum) {
        dist = cost/count;
        for (int i=0;i<N;i++) {
          if (v[i] == min) {
            v[i] += dist;
          }
        }
        break;
      } else {
        dist = second_min - min;
        for (int i=0;i<N;i++) {
          if (v[i] == min) {
            v[i] += dist;
            sum-=dist;
          }
        }
      }
    }
    if (all_equal) {
      double dist = sum/N;
      for (int i=0;i<N;i++) {
        v[i] += dist;
      }
    }
    cout << "Case #" << t << ": ";
    for (int i=0;i<N;i++) {
      v[i] -= orig[i];
      v[i] = (v[i]*100)/orig_sum;
      // cout << v[i] << " ";
      printf("%9.6f ", v[i]);
    }
    cout << endl;
  }

  return 0;
}

