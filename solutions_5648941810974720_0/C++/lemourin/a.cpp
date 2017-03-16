#include <cstdio>
#include <string>
#include <unordered_map>
#include <algorithm>
#define scanf(args...) (scanf(args) ? : 0)
const int MAXLEN = 1000005;

char buffer[MAXLEN];

std::vector<std::string> data = {
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE"
};

void remove(std::unordered_map<char, int>& occurence,
            std::unordered_map<int, int>& result, int number, char unique) {
  int t = occurence[unique];
  result[number] = t;
  for (char c : data[number])
    occurence[c] -= t;
}

std::string solve() {
  scanf("%s", buffer);
  std::string str = buffer;
  std::unordered_map<char, int> occurence;
  std::unordered_map<int, int> result;

  for (char t : str)
    occurence[t]++;
  
  remove(occurence, result, 0, 'Z');
  remove(occurence, result, 2, 'W');
  remove(occurence, result, 4, 'U');
  remove(occurence, result, 3, 'R');
  remove(occurence, result, 6, 'X');
  remove(occurence, result, 8, 'G');
  remove(occurence, result, 5, 'F');
  remove(occurence, result, 7, 'V');
  remove(occurence, result, 1, 'O');
  remove(occurence, result, 9, 'I');
  
  std::string f;
  for (std::pair<int, int> t : result)
    for (int i = 0; i < t.second; i++)
      f += t.first + '0';
  std::sort(f.begin(), f.end());
  for (auto t : occurence) {
    if (t.second != 0) {
      printf("wtf: %s\n", buffer);
      return f;
    }
  }
  return f;
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; i++)
    printf("Case #%d: %s\n", i, solve().c_str());
}
