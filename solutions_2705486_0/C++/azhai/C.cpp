#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cassert>

using namespace std;

const string DICT_PATH = "words.txt";
const int NUM_LETTERS = 26;
const int NUM_WORDS = 521196;

const int S_LEN_MAX = 5000;
const int GAP_MIN = 5; // TODO: check

struct DictNode {
  bool terminal;
  DictNode * children[NUM_LETTERS];
  DictNode() {
    terminal = false;
    for (int i = 0; i < NUM_LETTERS; i++)
      children[i] = NULL;
  }
};

DictNode *root;

void add_word_to_dict(string s) {
  assert(s.length() > 0);
  DictNode * cur = root;

  /* let's reverse */

  //  for (int i = 0; i < s.length(); i++) {
  for (int i = s.length() - 1; i >= 0; i--) {
    if (cur->children[s[i] - 'a'] == NULL)
      cur->children[s[i] - 'a'] = new DictNode();
    cur = cur->children[s[i] - 'a'];
  }
  cur->terminal = true;
}


string S;
int N;
// second index is gap needed (up to 5)
int min_ops[S_LEN_MAX][GAP_MIN + 1];



void search_dict(int orig_pos, int cur_pos, DictNode *cur,
                 int next_change, int last_change, int num_changes) {
  if (cur->terminal) {
    // found a word

    if (next_change == -1) {
      assert(last_change == -1);

      for (int i = 0; i <= GAP_MIN; i++) {
        int increased_gap = max(0, i - (orig_pos - cur_pos));
        min_ops[orig_pos + 1][i] = min(min_ops[orig_pos + 1][i], min_ops[cur_pos + 1][increased_gap]);
      }

    } else {
      int gap_needed = GAP_MIN - (next_change - cur_pos);
      gap_needed = max(gap_needed, 0);
      int cost_to_here = min_ops[cur_pos + 1][gap_needed];
      int total_cost = cost_to_here + num_changes;

      int trailing_gap = min(GAP_MIN, orig_pos - last_change);
      for (int i = 0; i <= trailing_gap; i++) {
        min_ops[orig_pos + 1][i] = min(min_ops[orig_pos + 1][i], total_cost);
      }
    }
  }

  if (cur_pos < 0) // already reached beginning
    return;
  int c = S[cur_pos] - 'a';

  for (int i = 0; i < NUM_LETTERS; i++) {
    if (cur->children[i] == NULL)
      continue;

    if (i != c) {
      // requires a change
      if (next_change != -1 && next_change - cur_pos < GAP_MIN)
        // changes are too close together
        continue;
      int new_last_change = (last_change != -1 ? last_change : cur_pos);
      search_dict(orig_pos, cur_pos - 1, cur->children[i],
                  cur_pos, new_last_change, num_changes + 1);
    } else {
      // no change required
      search_dict(orig_pos, cur_pos - 1, cur->children[c],
                  next_change, last_change, num_changes);
    }
  }
}

void do_dp(int pos) {
  search_dict(pos, pos, root, -1, -1, 0);
}

void init() {
  cin >> S;
  N = S.length();

  // TODO: initialize dp
  for (int i = 0; i < S_LEN_MAX; i++) {
    for (int j = 0; j <= GAP_MIN; j++) {
      min_ops[i][j] = S_LEN_MAX;
    }
  }

  for (int i = 0; i <= GAP_MIN; i++) {
    min_ops[0][i] = 0;
  }
}

void solve_case(int t) {
  init();

  for (int i = 0; i < N; i++) {
    do_dp(i);
  }

  /*
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= GAP_MIN; j++)
      cout << min_ops[i][j] << " ";
    cout << endl;
  }
  */

  cout << "Case #" << t << ": " << min_ops[N][0] << '\n';
}

int main() {
  root = new DictNode();
  ifstream fin(DICT_PATH.c_str());

  //  int longest = 0;
  int num_words = 0;
  while (!fin.fail()) {
    string s;
    fin >> s;
    if (s.length() == 0)
      continue;

    add_word_to_dict(s); // TODO: maybe reverse s first
    num_words++;
    //    longest = max(longest, (int) s.length());
  }

  assert(num_words == NUM_WORDS);

  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
