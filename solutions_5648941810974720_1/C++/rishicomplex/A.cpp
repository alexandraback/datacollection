#include <iostream>
#include <string>
using namespace std;

#define LIM
#define MOD
#define INF

typedef long long int ll;

string numbers[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int counts[28];
int ans[10];

int getCharNo(char c) {
  return c - 'A';
}

void removeNumber(int no, int times) {
  //cout << "removeNumber called with " << no << " and " << times << endl;
  if(times == 0) return;
  string number = numbers[no];
  //cout << "number = " << number << endl;
  int i;
  char c;
  for(i = 0; i < (int)number.length(); i++) {
    c = number[i];
    counts[getCharNo(c)] -= times;
  }
  ans[no] += times;
}

void printCounts() {
  int i;
  for(i = 0; i < 26; i++) {
    cout << char('A' + i) << ": " << counts[i] << ", ";
  }
  cout << endl;

}

void work(int index) {
  string inp;
  cin >> inp;
  int i;
  for(i = 0; i < 10; i++) {
    
    ans[i] = 0;
  }
  for(i = 0; i < 28; i++) {
    counts[i] = 0;
  }
  for(i = 0; i < (int)inp.length(); i++) {
    counts[inp[i] - 'A']++;
  }

  //printCounts();
  //zero
  removeNumber(0, counts[getCharNo('Z')]);
  //printCounts();
  //six
  removeNumber(6, counts[getCharNo('X')]);
  //printCounts();
  //two
  removeNumber(2, counts[getCharNo('W')]);
  //printCounts();
  //eight
  removeNumber(8, counts[getCharNo('G')]);
  //printCounts();
  //three
  removeNumber(3, counts[getCharNo('H')]);
  //printCounts();
  //four
  removeNumber(4, counts[getCharNo('R')]);
  //five
  removeNumber(5, counts[getCharNo('F')]);
  //one
  removeNumber(1, counts[getCharNo('O')]);
  //seven
  removeNumber(7, counts[getCharNo('V')]);
  //nine
  removeNumber(9, counts[getCharNo('I')]);

  int j;
  

  cout << "Case #" << index << ": ";
  for(i = 0; i < 10; i++) {
    for(j = 0; j < ans[i]; j++) {
      cout << i;
    }
  }
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  int i;
  for(i = 1; i <= T; i++) work(i);
  return 0;
}
