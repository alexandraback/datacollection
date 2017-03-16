#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;
int order[11];
bool check[30];
int main() {

  int TC;

  cin >> TC;

  for (int i = 0; i < 10; i++) order[i] = i;

  for (int tc = 1; tc <= TC; tc++) {
    int n;
    int answer = 0;
    cin >> n;

    vector<string> input;

    for (int i = 0; i < n; i++) {
      string tmp;
      cin >> tmp;
      input.push_back(tmp);
    }

    do {
      bool flag = true;
      memset(check, false, sizeof(check));
      

      char prev = input[order[0]][0];
      for (int i = 0; i < n; i++) {
	int sz = (int)input[order[i]].size();
	for (int l = 0; l < sz; l++) {
	  if (prev != input[order[i]][l]) {
	    if (check[input[order[i]][l]-'a']) {
	      flag = false;
	      break;
	    }
	    check[prev-'a'] = true;
	    prev = input[order[i]][l];
	  }
	}

	if ( !flag ) break;
      }
      if (flag) {
	answer++;
      }
      
    } while(next_permutation(order, order+n));

    printf("Case #%d: %d\n", tc, answer);
    input.clear();
  }

  return 0;
}
