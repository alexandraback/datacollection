#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <cmath>

//#define NDEBUG

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

const char INPUT[] = "HelloWorld.inp";
const char OUTPUT[] = "SmallTest.out";

const long MAX_LONG = 2000000000;

int getIdx(string s, char c) {
  size_t tmp = s.find(c);
  if (tmp == string::npos) {
    return -1;
  } else {
    return (int) tmp;
  }
}

void test(string c, string j, long & min, string & resultC, string & resultJ) {
  int qAtC = getIdx(c, '?'); int qAtJ = getIdx(j, '?');
  if (qAtC == -1 && qAtJ == -1) {
    long intC = atol(c.c_str()); long intJ = atol(j.c_str());
    long absDiff = labs(intC - intJ);
    if (absDiff < min) {
      resultC = c; resultJ = j;
      min = absDiff;
    } else if (absDiff == min) {
      long intResultC = atol(resultC.c_str());
      long intResultJ = atol(resultJ.c_str());
      if (intC < intResultC || (intC == intResultC && intJ < intResultJ)) {
        resultC = c; resultJ = j;
      }
    }
    return;
  } else if (qAtC != -1) {
    for (char digit = '0'; digit <= '9'; ++ digit) {
      c[qAtC] = digit;
      test(c, j, min, resultC, resultJ);
    }
    c[qAtC] = '?';
    return;
  } else {
    for (char digit = '0'; digit <= '9'; ++ digit) {
      j[qAtJ] = digit;
      test(c, j, min, resultC, resultJ);
    }
    j[qAtJ] = '?';
  }
}

int main() {
  freopen(INPUT, "r", stdin);
  freopen(OUTPUT, "w", stdout);

  int numTest;
  cin >> numTest;

  for (int idTest = 0; idTest < numTest; ++ idTest) {
    string c, j;
    cin >> c >> j;

    string resultC, resultJ;
    long tmp = MAX_LONG;

    test(c, j, tmp, resultC, resultJ);

    cout << "Case #" << idTest + 1 << ": " << resultC << " " << resultJ << endl;
  }

  return 0;
}
