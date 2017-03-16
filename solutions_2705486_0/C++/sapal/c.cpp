#define dbg if(0)
#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
#include<string>
#include<set>
#include<utility>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FWD(i,b,n) for(int i=(b);i<(n);++i)
#define BWD(i,b,n) for(int i=(int)(n)-1;i>=(b);--i)
#define FOREACH(it,c) for(__typeof((c).end()) it=(c).begin();it!=(c).end();it++)
typedef long long LL;
const int MAXL = 10;
const int MIND = 5;
const int OO = (1<<30)-1;
typedef pair<int,int> PII;
typedef pair<int, PII> PIII;

set<string> dict;
vector<string> patterns[MAXL];

bool is_word(const string &word) {
  return dict.find(word) != dict.end();
}

PIII get_range(const string &pattern) {
  int n = pattern.size();
  PII res(0, MIND-1);
  int cnt = 0;
  FOR(i,n) {
    if (pattern[i] == '*') {
      cnt++;
      res.first = max(res.first, MIND-i-1);
      res.second = min(res.second, n-i-1);
    }
  }
  return PIII(cnt, res);
}

string patternize(const string &word, const string &pattern) {
  string result = word;
  int n = word.size();
  FOR(i,n) {
    if (pattern[i] == '*') result[i] = '*';
  }
  return result;
}

set<PIII> get_ranges_for_word(const string &word) {
  set<PIII> result;
  int n = word.size();
  FOREACH(it, patterns[n-1]) {
    if (is_word(patternize(word, *it))) 
      result.insert(get_range(*it));
  }
  return result;
}

void init() {
  FOR(i,MAXL) {
    int len = i+1;
    string pattern = "";
    FOR(j,len) pattern += ".";
    patterns[i].push_back(pattern);
    FOR(j,len) {
      pattern[j] = '*';
      patterns[i].push_back(pattern);
      FWD(k,j+MIND,len) {
        pattern[k] = '*';
        patterns[i].push_back(pattern);
        pattern[k] = '.';
      }
      pattern[j] = '.';
    }
    //FOREACH(it, patterns[i]) cout << "pattern: " << *it << endl;
  }

  ifstream dict_file;
  dict_file.open("garbled_email_dictionary.txt", ifstream::in);
  FOR(i, 521196) {
    string word;
    dict_file >> word;
    int n = word.size();
    FOREACH(it, patterns[n-1]) {
      dict.insert(patternize(word, *it));
    }
  }
}



int solve() {
  string s;
  cin >> s;
  dbg cout << "word: " << s << endl;
  int n = s.size();
  int best[MIND][n+1];
  FOR(i,MIND) best[i][0] = 0;
  FWD(i,1,n+1) {
    FOR(j,MIND) best[j][i] = OO;
    FWD(len,1,min(MAXL,i)+1) {
      string word = s.substr(i-len,len);
      set<PIII> ranges = get_ranges_for_word(word);
      dbg cout << "trying: " << word << ": ";
      FOREACH(it, ranges) {
        int count = it->first;
        PII range = it->second;
        dbg cout << "[" << count << "<" << range.first << "," << range.second << ">] ";
        if (count == 0 and len < MIND) {
          FWD(k,len,MIND) {
            best[k][i] = min(best[k][i], best[k-len][i-len]);
          }
        } else {
          best[range.second][i] = min(best[range.second][i], best[range.first][i-len] + count);
        }
      }
      dbg cout << endl;
    }
    BWD(j,1,MIND) best[j-1][i] = min(best[j-1][i], best[j][i]);
    dbg {
      FOR(j,MIND)
        cout << "best[" << j << "][" << i << "]: " << best[j][i] << endl;
    }
  }
  int res = OO;
  FOR(i,MIND) res = min(res, best[i][n]);
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  int z;
  cin >> z;
  init();
  FOR(i,z) {
    cout << "Case #" << i+1 << ": " << solve() << endl;
  }
  return 0;
}
