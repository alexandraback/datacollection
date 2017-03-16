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

map<long long, long long> vmap;
map<long long,long long>::iterator iter;
vector<vector<long long> > vv;
bool flag = false;

int nck(const int& n, const int& k, int i, int j, std::vector<long long>& v1, std::vector<long long> v2, long long sum) {
  if (j == k) {
    /*
    for (int m=0;m<v2.size();m++) {
      std::cout << v2[m] << " ";
    }
    std::cout << std::endl;
    cout << "sum:" << sum << endl;
    */
    int index = vv.size();
    if ((iter = vmap.find(sum)) != vmap.end()) {
      int index2 = iter->second;
      for (int h=0;h<vv[index2].size();h++) {
        cout << vv[index2][h] << " ";
      }
      cout << endl;
      for (int h=0;h<v2.size();h++) {
        cout << v2[h] << " ";
      }
      cout << endl;
      flag = true;
      return 0;
    } else {
      vv.push_back(v2);
      vmap[sum] = index;
    }
    return 1;
  }
  for (;i<n;i++) {
    v2.resize(j);
    v2.push_back(v1[i]);
    nck(n, k, i+1, j+1, v1, v2, sum+v1[i]);
    if (flag)
      return 0;
  }
  return 0;
}

int main() {
  string line;
  stringstream ss;
  int T = 0;
  getline(cin, line);
  ss << line;
  ss >> T;
  ss.clear();

  for (int t=1;t<=T;t++) {
    flag = false;
    vmap.clear();
    vv.clear();
    getline(cin, line);
    ss << line;
    int N = 0;
    ss >> N;
    vector<long long> v1;
    vector<long long> v2;
    long long num=0;
    for (int i=0;i<N;i++) {
      ss >> num;
      v1.push_back(num);
    }
    ss.clear();
    cout << "Case #" << t << ":" << endl;
    for (int k=1;k<N;k++) {
      long long sum = 0;
      nck(N, k, 0, 0, v1, v2, sum);
      if (flag)
        break;
    }
    if (!flag)
      cout << "Impossible" << endl;
  }

  return 0;
}

