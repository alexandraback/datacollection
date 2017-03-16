#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

// i: 1, j: 2, k: 3
int nsys[4][4] = {{0, 1, 2, 3},
		  {1, 0, 3, 2},
		  {2, 3, 0, 1},
		  {3, 2, 1, 0}};

int nsys_pn[4][4] = {{1, 1, 1, 1},
		     {1, -1, 1, -1},
		     {1, -1, -1, 1},
		     {1, 1, -1, -1}};


int L, X;
string str;
int sum_front[11111][2];
int sum_back[11111][2];

int main() {

  int TC;

  cin >> TC;

  for (int tc = 1; tc <= TC; tc++) {

    cin >> L >> X;
    cin >> str;

    int now = 0;
    int now_pn = 1;
    for (int i = 0; i < L*X; i++) {
      int idx = i % L;
      now_pn *= nsys_pn[now][str[idx]-'i'+1];
      now = nsys[now][str[idx]-'i'+1];
      sum_front[i][0] = now;
      sum_front[i][1] = now_pn;

      // cout << "front" << sum_front[i][0] << " " << sum_front[i][1] << endl;
    }

    now = 0;
    now_pn = 1;
    for (int i = L*X - 1; i >= 0; i--) {
      int idx = i % L;
      now_pn *= nsys_pn[str[idx]-'i'+1][now];
      now = nsys[str[idx]-'i'+1][now];
      sum_back[i][0] = now;
      sum_back[i][1] = now_pn;
      // cout << "back" << sum_back[i][0] << " " << sum_back[i][1] << endl;
    }

    bool result = false;
    bool find_i = false;
    for (int i = 0; i < L*X - 1; i++) {
      if (sum_front[i][0] == 1 && sum_front[i][1] == 1
	  && sum_back[i+1][0] == 1 && sum_back[i+1][1] == 1) find_i = true;

      if (find_i) {
	if (sum_front[i][0] == 3 && sum_front[i][1] == 1
	    && sum_back[i+1][0] == 3 && sum_back[i+1][1] == 1) result = true;
      }
    }
    printf("Case #%d: %s\n", tc, (result)? "YES" : "NO");
  }
  return 0;
}
