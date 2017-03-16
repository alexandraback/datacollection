#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

const char c[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
const char m[] = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int mapping[26];
int reverse_mapping[26];

void add_mapping(char from, char to) {
  mapping[from - 'a'] = to;
  reverse_mapping[to - 'a'] = from;
}

void problem_a(int argc, char* argv[])
{
  for (int i = 0; i < 26; ++i) {
    mapping[i] = -1;
    reverse_mapping[i] = -1;
  }

  for (int i = 0; i < strlen(c); ++i) {
    if (c[i] != ' ')
      add_mapping(c[i], m[i]);
  }

  add_mapping('y', 'a');
  add_mapping('e', 'o');
  add_mapping('q', 'z');

  int unknown = 0;
  for (int i = 0; i < 26; ++i) {
    if (mapping[i] == -1) {
      unknown++;
    }
  }

  if (unknown == 1) {
    for (int i = 0; i < 26; ++i) {
      if (mapping[i] == -1) {
        for (int j = 0; j < 26; ++j) {
          if (reverse_mapping[j] == -1) {
            mapping[i] = 'a' + j;
            reverse_mapping[j] = 'a' + i;
            goto DONE;
          }
        }
      }
    }
  }
DONE:;

  for (int i = 0; i < 26; ++i) {
    if (mapping[i] == -1) {
      printf("unknown mapping: %c\n", 'a' + i);
    }
  }

  int num_tests;
  cin >> num_tests;
  string s;
  getline(cin, s);
  for (int i = 0; i < num_tests; ++i) {
    getline(cin, s);
    printf("Case #%d: ", i+1);
    for (int j = 0; j < s.size(); ++j) {
      printf("%c", s[j] == ' ' ? ' ' : mapping[s[j] - 'a']);
    }
    printf("\n");
  }

}

int num_highest = 0;
int total_highest = 0;
int googlers;
int scores[100];
int counted[100];
int avg;

void n_choose_k_runner(int start, int end, int k, int *p, int ofs) {
  for (int i = start; i < end; ++i) {
    p[ofs] = i;
    if (ofs == k-1) {
      // check the guys that got specials
      int bonus_complete = 0;
      for (int j = 0; j < googlers; ++j) {
        if (counted[j])
          continue;

        int d = scores[j] - avg;
        int a = avg;
        int b = d - d/2;
        int c = d/2;
        if (a - c == 2) {
          // check if this is ok when using a special
          for (int kk = 0; kk < k; ++kk) {
            if (p[kk] == j) {
              counted[j] = 1;
              bonus_complete++;
              break;
            }
          }
        }
      }

      total_highest = max(total_highest, num_highest + bonus_complete);
    } else {
      n_choose_k_runner(i+1, end+1, k, p, ofs+1);
    }
  }
}

void n_choose_k(int n, int k) {
  int b[200];
  n_choose_k_runner(0, n-k+1, k, b, 0);
}

void problem_c(int argc, char* argv[])
{
  int num_tests;
  cin >> num_tests;
  string s;
  getline(cin, s);

  for (int i = 0; i < num_tests; ++i) {
    int specials;
    cin >> googlers >> specials >> avg;

    for (int j = 0; j < googlers; ++j)
      cin >> scores[j];

    num_highest = 0;
    total_highest = 0;

    // count how many reach avg without the specials
    for (int j = 0; j < googlers; ++j) {
      counted[j] = 0;
      int d = scores[j] - avg;
      int a = avg;
      int b = d - d/2;
      int c = d/2;

      if (scores[j] >= avg * 3 || a-c == 1) {
        num_highest++;
        counted[j] = 1;
      }
    }
    if (specials)
      n_choose_k(googlers, specials);

    printf("Case #%d: %d\n", i+1, total_highest);

    getline(cin, s);
  }


}

void equal_sums_small(int argc, char* argv[])
{
  int num_tests;
  cin >> num_tests;
  string s;
  getline(cin, s);

  for (int i = 0; i < num_tests; ++i) {

    int nums;
    cin >> nums;
    vector<int> cur;
    int tmp;
    for (int j = 0; j < nums; ++j) {
      cin >> tmp;
      cur.push_back(tmp);
    }

    map<long long, int> sums;

    printf("Case #%d:\n", i+1);

    bool found = false;

    for (int j = 1; j < 1 << 20; ++j) {
      long long sum = 0;
      for (int k = 0; k < 20; ++k) {
        if (j & (1<<k)) {
          sum += cur[k];
        }
      }

      auto it = sums.find(sum);
      if (it != sums.end()) {

        int tmp = it->second;
        for (int k = 0; k < 20; ++k) {
          if (tmp & (1<<k)) {
            printf("%d%s", cur[k], k < 19 ? " " : "");
          }
        }
        printf("\n");

        for (int k = 0; k < 20; ++k) {
          if (j & (1<<k)) {
            printf("%d%s", cur[k], k < 19 ? " " : "\n");
          }
        }
        printf("\n");
    
        found = true;
        break;

      } else {
        sums[sum] = j;
      }

    }

    if (!found)
      printf("Impossible\n");


    getline(cin, s);
  }

}

int main(int argc, char* argv[])
{
  equal_sums_small(argc, argv);
  return 0;
}
