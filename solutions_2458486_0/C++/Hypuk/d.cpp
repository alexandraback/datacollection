#include <iostream>
#include <vector>

using namespace std;

bool is_better(vector<int> new_, vector<int> old_) {
  if (old_.size() == 0) return true;
  for (int i = 0; i < new_.size(); ++i) {
    if (old_ [i] < new_ [i])
      return false;
  }
  return true;
}

vector<int> solve(int n, vector<int> required_key, vector<vector<int> > where_contained, vector<vector<int> > where_required) {
  int max = (1 << n);
  vector<vector<int> > best(max);
  best[0].push_back(0);
  for (int mask = 0; mask < max; ++mask) {
    if (best[mask].size() == 0) continue;

    for (int next = 0; next < n; ++next) {
      if ((mask & (1 << next)) > 0) continue;
      int key = required_key[next];
      int cnt_keys = 0;

      for (int i = 0; i < where_contained[key].size(); ++i) {
        int x = where_contained[key][i];
        if (x == -1) cnt_keys++; else {
          if ((mask & (1 << x)) > 0)
            cnt_keys++;          
        }
      }
      for (int i = 0; i < where_required[key].size(); ++i) {
        int x = where_required[key][i];
        if ((mask & (1 << x)) > 0)
          cnt_keys--;
      }

      if (cnt_keys > 0) {
        if (is_better(best[mask], best[mask + (1 << next)])) {
          best[mask + (1 << next)] = best[mask];
          best[mask + (1 << next)].push_back(next + 1);
        }
      }
    }
  }
  return best[max - 1];
}

int main() {
  freopen("d.in", "r", stdin);
  int tn, temp;
  cin >> tn;
  for (int t = 1; t <= tn; ++t) {
    vector<vector<int> > where_contained(201);
    vector<vector<int> > where_required(201);

    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; ++i) {
      cin >> temp;
      where_contained[temp].push_back(-1);
    }

    vector<int> required_key;
    for (int i = 0; i < n; ++i) {
      int key, num_of_keys;
      cin >> key >> num_of_keys;
      where_required[key].push_back(i);
      required_key.push_back(key);
      for (int j = 0; j < num_of_keys; ++j) {
        cin >> temp;
        where_contained[temp].push_back(i);
      }
    }

    vector<int> result = solve(n, required_key, where_contained, where_required);
    cout << "Case #" << t << ": ";
    if (result.size() == 0) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      for (int i = 1; i < result.size(); ++i) {
        cout << result[i];
        if (i == result.size() - 1) {
          cout << endl;
        } else {
          cout << " ";
        }
      }
    }
  }
}
