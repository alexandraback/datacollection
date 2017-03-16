#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

int str2int(const string &s) {
  stringstream ss(s);
  int a;
  ss >> a;
  return a;
}

string int2str(int a) {
  stringstream ss;
  ss << a;
  return ss.str();
}

int K, N;
map<int, int> keys[1<<20];
bool ok[1<<20];
int ok2[1<<20];

struct Chest {
  int need;
  map<int, int> keys;
};

vector<Chest> chests;
vector<int> seq;

void calckeys(int open) {
  if (open == 0) return;
  for (int i = 0; i < N; ++i) if (open&(1<<i)) {
    keys[open] = keys[open&~(1<<i)];
    keys[open][chests[i].need]--;
    for (map<int, int>::iterator it=chests[i].keys.begin(); it!=chests[i].keys.end(); ++it) {
      keys[open][it->first] += it->second;
    }
    return;
  }
}

// vector<int> seq;
// bool<int> calculated;

bool gen(int open, int pos) {
  if (pos == N) {
    return true;
  }

  if (ok2[open] != -1 && !ok2[open]) return false;

  // cout << open << ' ' << pos << endl;

  map<int, int> &k = keys[open];

  for (int i = 0; i < N; ++i) if (!(open & (1<<i))) {
    if (k[chests[i].need] > 0 && ok[open|(1<<i)]) {
      seq[pos] = i;
      if (gen(open|(1<<i), pos+1)) {
        ok2[open] = 1;
        return true;
      }
    }
  }
  ok2[open] = 0;
  return false;
}

string calc()
{
  cin >> K >> N;

  for (int i = 0; i < (1<<N); ++i) {
    keys[i].clear();
    ok2[i] = -1;
  }
  chests.clear();

  int k;
  for (int i =0; i < K; ++i) {
    cin >> k;
    keys[0][k]++;
  }
  for (int i =0; i < N; ++i) {
    Chest chest;
    cin >> chest.need >> k;
    for (int j = 0; j < k; ++j) {
      int a;
      cin >> a;
      chest.keys[a]++;
    }
    chests.push_back(chest);
  }

  for (int i = 0; i < (1<<N); ++i) {
    calckeys(i);
    //cout << i << " : " << endl;
    ok[i] = true;
    for (map<int, int>::iterator it=keys[i].begin(); it!=keys[i].end(); ++it) {
      if (it->second < 0) { ok[i] = false; break;}
    }
    /*
    for (map<int, int>::iterator it=keys[i].begin(); it!=keys[i].end(); ++it) {
      cout << it->first << ' ' << it->second << endl;
    }
    cout << ok[i] << endl;
    */
  }

  // memset(ok2, -1, sizeof(ok2));
  // cerr << "begin calc" << endl;

  seq.resize(N);
  // seq.resize(1<<N);
  // caculated.resize(1<<N, false);
  bool ret = ok[0] && gen(0, 0);
  if (!ret) return "IMPOSSIBLE";

  stringstream ss;
  for (int i = 0; i < N; ++i) {
    if (i > 0) ss << ' ';
    ss << seq[i] + 1;
  }
  return ss.str();
}

int main(void)
{
  // NOTE: if using getline() to read the input, the following two lines should be
  // added to read the line sepeartor in the first line. 
  string line;
  getline(cin, line);
	int N = str2int(line);

	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
