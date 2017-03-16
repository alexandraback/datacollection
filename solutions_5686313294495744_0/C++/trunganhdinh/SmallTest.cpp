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
const int MAX_TOPIC = 16 + 10;

void test(string fopic[], string sopic[], int numTopic, int idTopic, int useTopic[MAX_TOPIC],
                                            int countUseTopic, int & result) {
  if (idTopic == numTopic) {
    int allow = true;
    if (countUseTopic == 0) {
      return;
    }
    for (int id1 = 0; id1 < numTopic; ++ id1) {
      if (useTopic[id1] == 0) {
        bool fAppear = false, sAppear = false;
        for (int id2 = 0; id2 < numTopic; ++ id2) {
          if (id1 == id2) {
            continue;
          }
          if (useTopic[id2] != 0 && fopic[id2] == fopic[id1]) {
            fAppear = true;
          }
          if (useTopic[id2] != 0 && sopic[id2] == sopic[id1]) {
            sAppear = true;
          }
        }
        if (fAppear == false || sAppear == false) {
          allow = false;
          break;
        }
      }
    }
    if (allow == true && numTopic - countUseTopic > result) {
      result = numTopic - countUseTopic;
    }
    return ;
  } else {
    bool fAppear = false, sAppear = false, failed = false;
    for (int id2 = 0; id2 < idTopic; ++ id2) {
      if (useTopic[id2] == 2 && fopic[id2] == fopic[idTopic] ) {
        failed = true;
      }
      if (useTopic[id2] == 1 && sopic[id2] == sopic[idTopic] ) {
        failed = true;
      }
      if (useTopic[id2] != 0 && fopic[id2] == fopic[idTopic] ) {
        fAppear = true;
      }
      if (useTopic[id2] != 0 && sopic[id2] == sopic[idTopic]) {
        sAppear = true;
      }
    }
    useTopic[idTopic] = 0;
    test(fopic, sopic, numTopic, idTopic + 1, useTopic, countUseTopic, result);
    useTopic[idTopic] = 0;
    if (failed == false) {
      if (fAppear == false || sAppear == false) {
        if (fAppear == true) {
          useTopic[idTopic] = 1;
        } else if (sAppear == true) {
          useTopic[idTopic] = 2;
        } else {
          useTopic[idTopic] = 3;
        }

        stack<int> tmp;

        for (int id2 = 0; id2 < idTopic; ++ id2) {
          if (useTopic[id2] == 3 && fopic[id2] == fopic[idTopic] ) {
            useTopic[id2] = 1;
            tmp.push(id2);
          }
          if (useTopic[id2] == 3 && sopic[id2] == sopic[idTopic] ) {
            useTopic[id2] = 2;
            tmp.push(id2);
          }
        }

        ++ countUseTopic;
        test(fopic, sopic, numTopic, idTopic + 1, useTopic, countUseTopic, result);
        -- countUseTopic;
        useTopic[idTopic] = 0;

        while (tmp.empty() == false) {
          int id2 = tmp.top();
          useTopic[id2] = 3;
          tmp.pop();
        }
      }
    }

  }
}

int main() {
  freopen(INPUT, "r", stdin);
  freopen(OUTPUT, "w", stdout);

  int numTest;
  cin >> numTest;

  for (int idTest = 0; idTest < numTest; ++ idTest) {
    int numTopic; cin >> numTopic;
    string fopic[MAX_TOPIC];
    string sopic[MAX_TOPIC];

    int useTopic[MAX_TOPIC];
    for (int topic = 0; topic < numTopic; ++ topic) {
      cin >> fopic[topic] >> sopic[topic];
      useTopic[topic] = 0;
    }

    int result = -1;

    test(fopic, sopic, numTopic, 0, useTopic, 0, result);

    cout << "Case #" << idTest + 1 << ": " << result << endl;
  }

  return 0;
}
