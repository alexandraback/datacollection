#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

struct hoge
{
  char start;
  char end;
  long combination;
  bool valid;
  int charset;
  string str;
  int num[26];
};

void solve() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;

    std::vector<string> vv;
    for (int i = 0; i < N; i++) {
      string tmp;
      cin >> tmp;
      vv.push_back(tmp);
    }
    
    bool valid = true;
    std::vector<hoge> gr;
    for (int i = 0; i < N; i++) {
      hoge h;
      h.start = vv[i][0];
      h.end   = vv[i][vv[i].size()-1];
      h.combination = 1;
      h.valid = true;
      h.charset = 0;
      h.str = vv[i];
      for (int j = 0; j < 26; j++) {
	h.num[j] = 0;
      }
      if (h.start == h.end) {
	h.num[h.start - 'a'] = 1;
      }
      for (unsigned int j = 0; j < vv[i].size(); j++) {
	if (j >= 1 && (h.charset & (1 << (vv[i][j]-'a'))) && (vv[i][j-1] != vv[i][j])) {
	  valid = false;
	}
	h.charset |= (1 << (vv[i][j]-'a'));
      }
      gr.push_back(h);
    }

    while (true) {
      bool changed = false;
      for (unsigned int i = 0; i < gr.size(); i++) {
	if (!gr[i].valid) {
	  continue;
	}

        for (unsigned int j = 0; j < gr.size(); j++) {
	  if (i == j) {
	    continue;
	  }
	  if (!gr[j].valid) {
	    continue;
	  }
	  if (gr[j].start == gr[i].end) {
	    // // cerr << "merge group " << i << " and " << j << endl;

	    gr[j].valid = false;
	    gr[i].end = gr[j].end;
	    gr[i].combination = (gr[i].combination * gr[j].combination) % 1000000007;
	    gr[i].charset = gr[i].charset | gr[j].charset;
	    gr[i].str = gr[i].str+gr[j].str;
	    if (gr[i].start == gr[j].end) {
	      if (gr[i].num[gr[i].start - 'a'] != 0) {
		for (int k = 1; k <= gr[i].num[gr[i].start - 'a']; k++) {
		  gr[i].combination /= k;
		}
		for (int k = 1; k <= gr[j].num[gr[j].start - 'a']; k++) {
		  gr[i].combination /= k;		  
		}
		for (int k = 1; k <= gr[i].num[gr[i].start - 'a'] + gr[j].num[gr[j].start - 'a']; k++) {
		  gr[i].combination *= k;
		}
		gr[i].num[gr[i].start - 'a'] += gr[j].num[gr[j].start - 'a'];
	      } else {
		gr[i].combination *= 2;
	      }
	    }
	    changed = true;
	  }
	}
      }
      if (!changed) {
	break;
      }
    }

    for (unsigned int j = 0; j < gr.size(); j++) {
      if (!gr[j].valid) {
	continue;
      }
      for (unsigned int k = j+1; k < gr.size(); k++) {
	if (!gr[k].valid) {
	  continue;
	}
	if (gr[j].charset & gr[k].charset) {
	  // cerr << "group " << j << " and " << k << " conflict" << endl;
	  // cerr << gr[j].charset << endl;
	  // cerr << gr[k].charset << endl;
	  valid = false;
	}
      }
    }

    int group_num = 0;
    for (unsigned int j = 0; j < gr.size(); j++) {
      if (!gr[j].valid) {
	continue;
      }
      group_num++;
    }
    // cerr << "group_num= " << group_num << endl;

    long ret = 1;
    for (int j = 1; j <= group_num; j++) {
      ret *= j;
    }
    for (unsigned int j = 0; j < gr.size(); j++) {
      if (!gr[j].valid) {
	continue;
      }
      ret *= gr[j].combination;
      // // cerr << "gr[j].combination= " << gr[j].combination << endl;
    }

    for (unsigned int j = 0; j < gr.size(); j++) {
      if (!gr[j].valid) {
	continue;
      }
      cerr << gr[j].str << " " << gr[j].combination << endl;
    }

    if (valid) {
      std::cout << "Case #" << (t+1) << ": " << (ret % 1000000007) << std::endl;
    } else {
      // cerr << "not valid" << endl;
      std::cout << "Case #" << (t+1) << ": " << 0 << std::endl;      
    }
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}
