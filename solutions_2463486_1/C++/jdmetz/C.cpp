#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

int dbg;
string readLine();
int readIntLine();
vector<int> readVI(int n);
vector<string> readVS(int n);
vector<int> itokens(string s, string sep);
vector<string> stokens(string s, string sep);

/**
 * BigInt class specifically for this problem
 */
class BigInt {
public:
BigInt() { d.resize(1, 0); }
explicit BigInt(const string &s) {
  d = s;
  for (size_t i = 0; i < s.size(); i++) d[s.size()-i-1] = s[i]-'0';
}
bool operator<(const BigInt &other) const {
  if (d.size() != other.d.size()) return d.size() < other.d.size();
  for (int i = d.size()-1; i >= 0; i--) {
    if (d[i] != other.d[i]) return d[i] < other.d[i];
  }
  return false;
}
BigInt sqr() const {
  BigInt s;
  for (size_t i = 0; i < d.size(); i++) {
    int carry = 0;
    for (size_t j = 0; j < d.size(); j++) {
      if (i+j == s.d.size()) s.d.push_back(0);
      carry += s.d[i+j] + d[i] * d[j];
/*if(carry >= 100) {
  printf("Carry %d: i %d, j %d :", carry, (int)i, (int)j);
  print();
  printf("\n");
}*/
      s.d[i+j] = carry%10;
      carry /= 10;
    }
    size_t k = i+d.size();
    while (carry) {
      if (k == s.d.size()) s.d.push_back(0);
      carry += s.d[k];
      s.d[k] = carry%10;
      carry /= 10;
    }
  }
  return s;
}
bool isPalindrome() const {
  size_t s = d.size()-1, e = 0;
  while (s > e) {
    if (d[s] != d[e]) return false;
    s--;
    e++;
  }
  return true;
}
void nextSize() {
  d.push_back(1);
  d[0] = 1;
  for (size_t i = 1; i+1 < d.size(); i++) d[i] = 0;
}
void next012Palindrome() {
  int m = d.size()/2, om = m, odd = d.size()&1;
  if (d.size() == 1) {
    if (d[0] < 3) d[0]++;
    else nextSize();
  } else if (d[0] == 1) {
    int ones = 0;
    for (int i = 0; i <= m; i++) ones += d[i];
    if (odd && ((!d[m] && ones < 5) || (d[m] < 2 && ones < 4))) {
      d[m]++;
      if (!d[m]) ones++;
    } else {
      if (ones == 4+odd) {
        m = 0;
        int onect = d[m];
        while (onect < 4) {
          onect += d[++m];
        }
      }
      while (m >= 0 && d[m] >= 1) m--;
      if (m < 0) {
        d[0] = 2;
        d[d.size()-1] = 2;
        for (size_t i = 1; i+1 < d.size(); i++) d[i] = 0;
      } else {
        d[m]++;
        if (m != om || !(d.size()&1)) {
          int mo = (d.size()&1) ? om+om-m : om+om-m-1;
          d[mo]++;
          for (int i = m+1; i < mo; i++) d[i] = 0;
        }
      }
    }
  } else {
    if ((d.size()&1) && d[m] == 0) {
      d[m] = 1;
    } else {
      nextSize();
    }
  }
/*  printf("Next palindrome: ");
  print();
  printf("\n");
*/
}

void print() const {
  for (int i = d.size()-1; i >= 0; i--) putchar(d[i]+'0');
}

string d;
};

vector<BigInt> fairAndSquare() {
  BigInt p("0"), B("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

  vector<BigInt> fs;
  while (true) {
    p.next012Palindrome();
    BigInt p2 = p.sqr();
    if (B < p2) break;
    if (p2.isPalindrome()) {
      fs.push_back(p2);
/*      p.print();
      printf(" -> ");
      p2.print();
      printf("\n");*/
    }
  }
//  printf("%d fair and square numbers\n", (int)fs.size());
  return fs;
}

void doit(vector<BigInt> &fs, bool print = true) {
  char stra[128], strb[128];
  scanf(" %128s %128s", stra, strb);
  BigInt A(stra), B(strb);

  int64_t ct = 0;
  for (size_t i = 0; i < fs.size(); i++) {
    if (fs[i] < A) continue;
    if (B < fs[i]) break;
    ct++;
  }
  if (print) printf("%lld\n", ct);
}




/**
 * Library code
 */

int main(int argc, char **argv) {
  int wcase = 0;
  if (argc > 1) wcase = atoi(argv[1]);

  vector<BigInt> fs = fairAndSquare();
	int CCT = readIntLine();
	for (int cn = 1; cn <= CCT; cn++) {
    bool print = !wcase || wcase == cn;
		if (print) printf("Case #%d: ", cn);
		doit(fs, print);
	}
	return 0;
}

string readLine() {
	char sz[1000];
	fgets(sz, 1000, stdin);
	int l = strlen(sz);
	if (sz[l-1] == '\n') sz[l-1] = 0;
	return sz;
}
int readIntLine() {
	string s = readLine();
	return atoi(s.c_str());
}
vector<int> readVI(int n = 0) {
	if (!n) scanf("%d ", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d ", &v[i]);
	return v;
}
vector<string> readVS(int n = 0) {
	if (!n) scanf("%d ", &n);
	vector<string> v(n);
	for (int i = 0; i < n; i++) v[i] = readLine();
	return v;
}
vector<string> stokens(string s, string sep = " \n\r\t") {
	vector<string> res;
	size_t start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(s.substr(start, end-start));
	}
	return res;
}
vector<int> itokens(string s, string sep = " \n\r\t") {
	vector<int> res;
	size_t start, end = 0;
	while ((start = s.find_first_not_of(sep, end)) != string::npos) {
		end = s.find_first_of(sep, start);
		res.push_back(atoi(s.substr(start, end-start).c_str()));
	}
	return res;
}

