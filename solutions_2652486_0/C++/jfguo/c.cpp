#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <set>
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

LL str2ll(const string &s) {
  stringstream ss(s);
  LL a;
  ss >> a;
  return a;
}

string int2str(int a) {
  stringstream ss;
  ss << a;
  return ss.str();
}
string int2str(LL a) {
  stringstream ss;
  ss << a;
  return ss.str();
}

int R, N, M, K;

map<LL, set<LL> > po;

LL getp(LL cur) {
  LL ans = 1;
  while (cur) {
    ans *= cur%10;
    cur /= 10;
  }
  return ans;
}

LL nor(LL a) {
  string s = int2str(a);
  sort(s.begin(), s.end());
  return str2ll(s);
}

void gen(LL cur, int pos) {
  if (pos == N) {
    po[getp(cur)].insert(nor(cur));
    return;
  }
  for (LL i = 1; i<=M; ++i) {
    gen(cur*10+i, pos+1);
  }
}

void del1(string &s) {
  for (int i=s.length()-1; i>=0; --i) {
    if (s[i] == '1') s.erase(s.begin()+i);
  }
}

LL process(LL a, LL b) {
  string s1 = int2str(a);
  string s2 = int2str(b);

  map<char, int> m1;
  map<char, int> m2;
  for (int i = 0; i < s1.length(); ++i) {
    if (s1[i] != '1') m1[s1[i]]++;
  }
  for (int i = 0; i < s2.length(); ++i) {
    if (s2[i] != '1') m2[s2[i]]++;
  }

  for (map<char,int>::iterator it=m1.begin(); it!=m1.end(); ++it) {
    int &a = m2[it->first];
    if (a < it->second) a = it->second;
  }

  string s;
  for (map<char,int>::iterator it=m2.begin(); it!=m2.end(); ++it) {
    s += string(it->second, it->first);
  }
  // cout << s << endl;

  LL ans;
  if (s.length() > N) ans = -1; else ans = str2ll(s);
  // cout << "pro : " << a << ' ' << b << " : " << ans << endl;

  return ans;
}

int calcnum1(string &s) {
  int ans = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] =='1') ans++;
  }
  return ans;
}

string calc()
{
  cin >> R >> N >> M >> K;

  gen(0, 0);

  /*
  int total=0;
  for (map<LL, set<LL> >::iterator it1=po.begin(); it1!=po.end(); ++it1) {
    set<LL> &can = it1->second;
    cout << it1->first << " : ";
    for (set<LL>::iterator it=can.begin(); it!=can.end(); ++it) {
      cout << *it << ' ';
      total++;
    }
    cout << endl;
  }
  cout << "total:" << total << endl;
  */

  for (int i = 0; i < R; ++i) {
    set<LL> ans;
    for (int j = 0; j < K; ++j) {
      LL a;
      cin >> a;
      if (a == 1) continue;

      set<LL> &s = po[a];
      if (ans.size() == 0) {
        ans = s;
        continue;
      }

      set<LL> t;
      for (set<LL>::iterator it=s.begin(); it!=s.end(); ++it) {
        for (set<LL>::iterator it1=ans.begin(); it1!=ans.end(); ++it1) {
          LL nt = process(*it, *it1);
          if (nt > 0) t.insert(nt);
        }
      }
      ans.swap(t);
    }

    cout << endl;
    if (ans.size() == 0) {
      cout << string(N, '2');
      continue;
    }

    string s="";
    int num1 = 100000;
    for (set<LL>::iterator it1=ans.begin(); it1!=ans.end(); ++it1) {
      string s1=int2str(*it1);
      int t = calcnum1(s1);
      if (t < num1) {
        s = s1;
        num1 = t;
      }
    }

    for (int i = 0; i<s.length(); ++i) {
      if (s[i]=='1') s[i] = '2';
    }
    s += string(N-s.length(), '2');
    cout << s;
  }

  return "";
}

int main(void)
{
  string line;
  getline(cin, line);
	int N = str2int(line);

	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ":";
    calc();
    cout << endl;
	}

	return 0;
}
