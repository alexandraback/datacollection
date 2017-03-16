#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

//vector<int> solve(vector<vector<int> > height, int N, vector<bool> used, vector<int> row, vector<int> col)
//{
//}

vector<int> solve(vector<vector<int> > height, int N)
{
  vector<vector<int> > table;
  vector<int> line;
  for (int i = 0; i < N; i++) {
    line.push_back(0);
  }
  for (int i = 0; i < N; i++) {
    table.push_back(line);
  }
  vector<int> index;
  //vector<bool> isrow;
  for (int i = 0; i < height.size(); i++) {
    index.push_back(-1);
  }

  for (int i = 0; i < N; i++) {
    int smallest = 3000;
    for (int j = 0; j < height.size(); j++) {
      if (index[j] == -1) {
        smallest = min(smallest, height[j][i]);
      }
    }
    for (int j = 0; j < height.size(); j++) {
      if (index[j] == -1 && height[j][i] == smallest) {
        index[j] = i;
      }
    }
  }

  vector<vector<vector<int> > > h;
  int missing = -1;
  for (int i = 0; i < N; i++) {
    vector<vector<int> > temp;
    for (int j = 0; j < height.size(); j++) {
      if (index[j] == i) {
        temp.push_back(height[j]);
      }
    }
    h.push_back(temp);
    if (temp.size() == 1) {
      missing = i;
    }
  }

  vector<int> ans;
  for (int i = 0; i < N; i++) {
    //cout << "\n";
    //cout << "DEBUG: " << i << "\n";
    if (i == missing) {
      //cout << "A\n";
      ans.push_back(h[i][0][i]);
    }
    else {
      //cout << "B\n";
      if (h[missing][0][i] == h[i][0][missing]) {
      //cout << "C\n";
        ans.push_back(h[i][1][missing]);
      }
      else {
      //cout << "D\n";
        ans.push_back(h[i][0][missing]);
      }
    }
  }

  return ans;
}

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<vector<int> > height;
    for (int i = 0; i < 2 * N - 1; i++) {
      vector<int> h;
      for (int j = 0; j < N; j++) {
        int k;
        cin >> k;
        h.push_back(k);
      }
      height.push_back(h);
    }
    cout << "Case #" << t << ":";
    vector<int> s = solve(height, N);
    for (size_t i = 0; i < s.size(); i++) {
      cout << " " << s[i];
    }
    cout << "\n";
  }
}

