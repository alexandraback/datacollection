#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

#define PROBLEM_ID "C"

vector<int> GetDiffs(const string& word1, const string& word2) {
  vector<int> result;
  for (int i = 0; i < word1.size(); ++i) {
    if (word1[i] != word2[i]) {
      result.push_back(i);
    }
  }
  return result;
}

int MinLettersChangedSlow(const string& text, const vector< vector<string> >& dictionary) {
  const int INF = 1000000000;
  vector< vector<int> > min_changed(text.length() + 1, vector<int>(6, INF));
  min_changed[0][5] = 0;
  for (int first_unused = 0; first_unused < text.length(); ++first_unused) {
    for (int last_change = 0; last_change <= 5; ++last_change) {
      if (min_changed[first_unused][last_change] == INF) {
        continue;
      }
      for (int length = 1; length <= 10 && first_unused + length <= text.length(); ++length) {
        string word_candidate = text.substr(first_unused, length);
        for (int word_index = 0; word_index < dictionary[length].size(); ++word_index) {
          vector<int> diffs = GetDiffs(word_candidate, dictionary[length][word_index]);
          if (diffs.size() > 2) {
            continue;
          }
          if (!diffs.empty() && diffs[0] + last_change < 5) {
            continue;
          }
          bool good = true;
          for (int i = 0; i + 1 < diffs.size(); ++i) {
            if (diffs[i + 1] - diffs[i] < 5) {
              good = false;
              break;
            }
          }
          if (!good) {
            continue;
          }
          int new_last_change = diffs.empty() ? min(5, last_change + length) : length - diffs.back() - 1;
          min_changed[first_unused + length][new_last_change] = min(min_changed[first_unused + length][new_last_change], min_changed[first_unused][last_change] + static_cast<int>(diffs.size()));
        }
      }
    }
  }
  return *min_element(min_changed[text.length()].begin(), min_changed[text.length()].end());
}

int MinLettersChanged(const string& text, const set<string>& dictionary) {
  const int INF = 1000000000;
  vector< vector<int> > min_changed(text.length() + 1, vector<int>(5, INF));
  min_changed[0][4] = 0;
  for (int first_unused = 0; first_unused < text.length(); ++first_unused) {
    for (int last_change = 0; last_change <= 4; ++last_change) {
      if (min_changed[first_unused][last_change] == INF) {
        continue;
      }
      for (int length = 1; length <= 10 && first_unused + length <= text.length(); ++length) {
        int next_unused = first_unused + length;
        string word = text.substr(first_unused, length);
        if (dictionary.count(word)) {
          int new_last_change = min(4, last_change + length);
          min_changed[next_unused][new_last_change] = min(min_changed[next_unused][new_last_change], min_changed[first_unused][last_change]);
        }
        for (int change = max(0,  4 - last_change); change < length; ++change) {
          for (char c = 'a'; c <= 'z'; ++c) {
            string candidate = word.substr(0, change) + string(1, c) + word.substr(change + 1);
            if (dictionary.count(candidate)) {
              int new_last_change = min(4, length - change - 1);
              min_changed[next_unused][new_last_change] = min(min_changed[next_unused][new_last_change], min_changed[first_unused][last_change] + 1);
            }
            for (int change2 = change + 5; change2 < length; ++change2) {
              for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                string candidate = word.substr(0, change) + string(1, c) + word.substr(change + 1, change2 - change - 1) + string(1, c2) + word.substr(change2 + 1);
                if (dictionary.count(candidate)) {
                  int new_last_change = min(4, length - change2 - 1);
                  min_changed[next_unused][new_last_change] = min(min_changed[next_unused][new_last_change], min_changed[first_unused][last_change] + 2);
                }
              }
            }
          }
        }
      }
    }
  }
  return *min_element(min_changed[text.length()].begin(), min_changed[text.length()].end());
}

int main() {
  cerr << "reading dictionary..." << endl;
  FILE* f = fopen("garbled_email_dictionary.txt", "r");
  vector<vector<string> > dictionary(11);
  set<string> all;
  while (true) {
    char buffer[100];
    fscanf(f, "%s", buffer);
    if (feof(f)) {
      break;
    }
    string word = buffer;
    dictionary[word.length()].push_back(word);
    all.insert(word);
  }
  fclose(f);
  cerr << "read dictionary" << endl;
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    cerr << "Case #" << test_index + 1 << ": ";
    string text;
    cin >> text;
    int result = MinLettersChanged(text, all);
    cout << "Case #" << test_index + 1 << ": " << result << endl;
    cerr << result << endl;
  }
  return 0;
}
