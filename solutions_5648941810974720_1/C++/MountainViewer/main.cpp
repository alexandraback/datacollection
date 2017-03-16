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

void taskB() {

}

void taskC() {

}

void taskD() {

}

int main() {
  taskA();
  return 0;
}