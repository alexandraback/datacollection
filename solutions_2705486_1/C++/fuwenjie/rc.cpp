#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
#include <set>
//#include <map>
//#include <queue>
#include <iomanip>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

//vector<string> dict;
const int MM = 456976;
vector<string> ind[456976];
string s;

inline int str_to_index(const string& s) {
  return ((26*(s[0]-'a')+s[1]-'a')*26+s[2]-'a')*26+s[3]-'a';
}

void iter(const string& s, const string& orgs) {
  if (s.length() >= 4) {
    ind[str_to_index(s)].push_back(orgs);
    return;
  }
  for (char ch = 'a'; ch <= 'z'; ++ch) iter(s + ch, orgs);
}

bool better(int& dst, int src) {
  if ((unsigned)src < (unsigned)dst) {
    dst = src;
    return true;
  }
  return false;
}

int match(int i, int j, const string& word, int& cnt) {
  cnt = 0;
  if (i + word.length() > s.length()) return -1;
  if (word.length() <= j) return max(0, (int)(j - word.length()));
  int j1 = 0;
  for (int k = j; k < word.size(); ++k) {
    if (word[k] != s[i+k]) {
      if (j1 > 0) return -1;
      j1 = 4;
      cnt++;
    } else {
      if (j1 > 0) j1--;
    }
  }
  return j1;
}

int main()
{
  ifstream fin2("garbled_email_dictionary.txt");
/*
  string s;
  dict.reserve(521196);
  while (fin2 >> s) {
    dict.push_back(s);
  }
  int i;
  for (i = 0; i < dict.size() - 1; i++)
    if (dict[i] > dict[i+1])
      cout << "wrong order: " << dict[i] << ' ' << dict[i+1] << endl;
  cout << endl;
  for (i = 0; i < dict.size(); i++)
    if (dict[i].length() == 1) cout << dict[i] << endl;
  cout <<  endl;
  for (i = 0; i < dict.size(); i++)
    if (dict[i].length() == 2) cout << dict[i] << endl;
  cout <<  endl;
*/

  while (fin2 >> s) {
    if (s.length() == 1) cerr << s << endl;
    else iter(s, s);
  }

	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
                fin >> s;
                int n = s.length();
                int d[4010][5];
                mset(d, 255);
                d[0][0] = 0;
                for (int i = 0; i < n; ++i) {
                  for (int j = 1; j < 5; ++j) better(d[i][j], d[i][j-1]);
                  if (d[i][4] < 0) continue;
                  //single
                  if (s[i] == 'a' || s[i] == 'i') {
                    for (int j = 1; j < 5; ++j)
                      if (d[i][j] >= 0) better(d[i+1][j-1], d[i][j]);
                  } else {
                    if (d[i][0] >= 0) better(d[i+1][4], d[i][0] + 1);
                  }
                  string t = s.substr(i, 4);
                  while (t.length() < 4) t += 'a';
                  {
                    vector<string>& vs = ind[str_to_index(t)];
                    for (int k = 0; k < vs.size(); ++k) {
                      //cerr << i << " try " <<  vs[k] << endl;
                      int cnt;
                      int ret = match(i, 4, vs[k], cnt);
                      if (ret >= 0) {
                        int wl = vs[k].length();
                        if (better(d[i+wl][ret], d[i][4]+cnt)) {
                          //cerr << i << ':' << 4 << ' ' << vs[k] << ' '
                          //     << d[i+wl][ret] << "(+" << cnt << ")" << endl;
                        }
                      }
                    }
                  }
                  for (int z = 3; z >= 0; z--) {
                    if (d[i][z] >= 0) {
                      for (char ch = 'a'; ch <= 'z'; ++ch) if (ch != t[z]) {
                          string t1 = t;
                          t1[z] = ch;
                          vector<string>& vs = ind[str_to_index(t1)];
                          for (int k = 0; k < vs.size(); ++k) {
                            //cerr << i << ' ' << z << " try " <<  vs[k] << endl;
                            int cnt;
                            int ret = match(i, z, vs[k], cnt);
                            if (ret >= 0) {
                              int wl = vs[k].length();
                              if (better(d[i+wl][ret], d[i][z]+cnt)) {
                                //cerr << i << ':' << z << ' ' << vs[k] << ' '
                                //     << d[i+wl][ret] << "(+" << cnt << ")" << endl;
                              }
                            }
                          }
                        }
                    }
                  }
                }
		int ans = -1;
                for (int j = 0; j < 5; ++j) better(ans, d[n][j]);
		fout << "Case #" << tind << ": " << ans << endl;
	}
	return 0;
}
