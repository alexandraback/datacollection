#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void print_stack(vector<bool> stack) {
  for (auto it = stack.begin(); it != stack.end(); it++) {
    cout << ((*it) ? "+" : "-");
  }
  cout << endl;
}

vector<bool> flip_at(vector<bool> stack, int boundary) {
  reverse(stack.begin(), stack.begin()+boundary);
  for (int i = 0; i < boundary; i++) {
    stack[i] = !stack[i];
  }
  return stack;
}

map<vector<bool>, long long> cache;

long long flips_required(vector<bool> stack, set<vector<bool> > flip_history) {
  vector<bool> reduced_stack;
  bool started = false;

  auto jt = flip_history.find(stack);
  if (jt != flip_history.end()) {
    return 1000000000L;
  }
  flip_history.insert(stack);
  
  //cout << "Stack: ";
  //print_stack(stack);
  
  reverse(stack.begin(), stack.end());
  for (auto it = stack.begin(); it != stack.end(); it++) {
    if (started || !(*it)) {
      started = true;
      reduced_stack.push_back(*it);
    }
  }
  stack = reduced_stack;
  reverse(stack.begin(), stack.end());

  auto it = cache.find(stack);
  if (it != cache.end()) {
    //cout << "Cached!" << endl;
    return it->second;
  }

  //cout << "Reduced stack: ";
  //print_stack(stack);
  
  if (stack.size() == 0) return 0;

  bool prev = stack[0];

  vector<int> boundaries;
  for (auto it = stack.begin()+1; it != stack.end(); it++) {
    if (*it != prev) {
      boundaries.push_back(it - stack.begin());
      prev = *it;
    }
  }
  boundaries.push_back(stack.size());

  for (auto it = boundaries.begin(); it != boundaries.end(); it++) {
    //cout << " " << *it; 
  }
  //cout << endl;

  long long min_flips = 1000000000000L; // I never remember the limits syntax.
  for (auto boundary = boundaries.begin(); boundary != boundaries.end(); boundary++) {
    vector<bool> flipped_stack = flip_at(stack, *boundary);
    //cout << "Flipped stack: ";
    //print_stack(flipped_stack);
    if (flipped_stack == stack) {
      continue;
    }
    long long required = flips_required(flipped_stack, flip_history) + 1;
    if (required < min_flips) {
      min_flips = required;
    }
  }

  cache[stack] = min_flips;
  return min_flips;
}

int main(int argc, char** argv) {
  int T;

  cin >> T;

  string dummy;
  getline(cin, dummy);
  
  for (int i = 0; i < T; i++) {
    string line;
    getline(cin, line);

    //cout << line << endl;
    
    vector<bool> stack(line.size());
   
    auto s = line.begin();
    auto d = stack.begin();

    for (; s != line.end(); s++, d++) {
      *d = (*s == '+');
    }

    set<vector<bool> > history;

    //print_stack(stack);
    //cout << endl;
    
    cout << "Case #" << (i + 1) << ": " << flips_required(stack, history) << endl;
  }
  
  return 0;
}
