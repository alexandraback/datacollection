#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

void taskA() {
  int t = 0;
  std::cin >> t;

  int k = 0;

  std::string s = "";
  while (k < t) {
    std::cin >> s;

    std::vector<int> chars(26, 0);

    for (int i = 0; i < s.length(); ++i) {
      chars[s[i] - 'A']++;
    }

    std::vector<int> answer;

    while (chars['Z' - 'A'] > 0) {
      answer.push_back(0);

      chars['Z' - 'A']--;
      chars['E' - 'A']--;
      chars['R' - 'A']--;
      chars['O' - 'A']--;
    }

    while (chars['W' - 'A'] > 0) {
      answer.push_back(2);

      chars['T' - 'A']--;
      chars['W' - 'A']--;
      chars['O' - 'A']--;
    }

    while (chars['U' - 'A'] > 0) {
      answer.push_back(4);

      chars['F' - 'A']--;
      chars['O' - 'A']--;
      chars['U' - 'A']--;
      chars['R' - 'A']--;
    }

    while (chars['X' - 'A'] > 0) {
      answer.push_back(6);

      chars['S' - 'A']--;
      chars['I' - 'A']--;
      chars['X' - 'A']--;
    }

    while (chars['G' - 'A'] > 0) {
      answer.push_back(8);

      chars['E' - 'A']--;
      chars['I' - 'A']--;
      chars['G' - 'A']--;
      chars['H' - 'A']--;
      chars['T' - 'A']--;
    }

    while (chars['F' - 'A'] > 0) {
      answer.push_back(5);

      chars['F' - 'A']--;
      chars['I' - 'A']--;
      chars['V' - 'A']--;
      chars['E' - 'A']--;
    }

    while (chars['V' - 'A'] > 0) {
      answer.push_back(7);

      chars['S' - 'A']--;
      chars['E' - 'A']--;
      chars['V' - 'A']--;
      chars['E' - 'A']--;
      chars['N' - 'A']--;
    }

    while (chars['T' - 'A'] > 0) {
      answer.push_back(3);

      chars['T' - 'A']--;
      chars['H' - 'A']--;
      chars['R' - 'A']--;
      chars['E' - 'A']--;
      chars['E' - 'A']--;
    }

    while (chars['O' - 'A'] > 0) {
      answer.push_back(1);

      chars['O' - 'A']--;
      chars['N' - 'A']--;
      chars['E' - 'A']--;
    }

    while (chars['I' - 'A'] > 0) {
      answer.push_back(9);

      chars['N' - 'A']--;
      chars['I' - 'A']--;
      chars['N' - 'A']--;
      chars['E' - 'A']--;
    }

    std::sort(answer.begin(), answer.end());

    std::cout << "Case #" << k + 1 << ": ";
    for (int i = 0; i < answer.size(); ++i) {
      std::cout << answer[i];
    }
    std::cout << std::endl;

    ++k;
  }

}

void smallTaskB() {
  int t = 0;
  std::cin >> t;

  int k = 0;

  std::string coders = "", jammers = "";
  std::string res1 = "", res2 = "";
  while (k < t) {
    std::cin >> coders >> jammers;

    int len = coders.size();

    if (len == 1) {
      if (coders[0] == '?' && jammers[0] == '?') {
        res1[0] = '0';
        res2[0] = '0';
      } else if (coders[0] == '?') {
        coders[0] = jammers[0];
      } else if (jammers[0] == '?') {
        jammers[0] = coders[0];
      } else {
        res1[0] = coders[0];
        res2[0] = jammers[0];
      }
    } else if (len == 2) {

    } else if (len == 3) {

    }

    ++k;
  }
}

void taskB() {

  int t = 0;
  std::cin >> t;

  int k = 0;

  std::string coders = "", jammers = "";
  std::string res1 = "", res2 = "";
  while (k < t) {
    std::cin >> coders >> jammers;

    int len = coders.size();


    for (int i = 0; i < len; ++i) {
      if (coders[i] == '?' && jammers[i] == '?') {
        if (i + 1 < len) {

        } else {
          if (i - 1 >= 0) {
            if (res1[i - 1] == res2[i - 1]) {
              res1[i] = '0';
              res2[i] = '0';
            }
          } else {
            res1[i] = '0';
            res2[i] = '0';
          }
        }
      }
    }



    ++k;
  }

}

void taskC() {
  int t = 0;
  std::cin >> t;

  int k = 0;

  while (k < t) {
    int n = 0;
    std::cin >> n;

    std::set<std::string> left_set, right_set;

    std::set<std::pair<std::string, std::string> > good;
    std::set<std::pair<std::string, std::string> > bad;

    int res = 0;

    for (int i = 0; i < n; ++i) {
      std::string left_word = "", right_word = "";
      std::cin >> left_word >> right_word;

      if (left_set.find(left_word) == left_set.end() && right_set.find(right_word) == right_set.end()) {
        good.insert(std::make_pair(left_word, right_word));
        left_set.insert(left_word);
        right_set.insert(right_word);
      } else {
        bad.insert(std::make_pair(left_word, right_word));
      }

    }

    for (auto it = bad.begin(); it != bad.end(); ++it) {
      if (left_set.find(it->first) != left_set.end() && right_set.find(it->second) != right_set.end()) {
        res++;
      }
    }

    std::cout << "Case #" << k + 1 << ": " << res << std::endl;

    ++k;
  }

}

int main() {
  taskC();
  return 0;
}