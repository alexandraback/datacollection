#include <iostream>
#include <vector>
#include <map>

using namespace::std;

vector<int> values;
int maximum = 0;
map<int, map<int, int> > mem;

int max(int a, int b) {
  if (a > b) return a;
  return b;
}

int solve(int index, int energy, int regain) {
  if (index >= values.size()) return 0;
  if (mem.find(index) != mem.end() &&
      mem[index].find(energy) != mem[index].end()) {
    return mem[index][energy];
  }

  int maxi = 0;

  for (int i = 0; i <= energy; i++) {
    int val = i * values[index];
    val += solve(index +  1,
		 min(energy - i + regain, maximum),
		 regain);
    maxi = max(maxi, val);
  }

  mem[index][energy] = maxi;
  
  return maxi;
}

int main(int argc, char *argv[]) {
  int n_cases;
  cin >> n_cases;

  for (int i = 0; i < n_cases; i++) {
    values.clear();
    mem.clear();

    int energy, regain, n_entries;
    cin >> energy >> regain >> n_entries;
    maximum = energy;

    for (int j = 0; j < n_entries; j++) {
      int num;
      cin >> num;
      values.push_back(num);
    }

    cout << "Case #" << i+1 << ": ";
    cout << solve(0, energy, regain) << endl;
  }
}
