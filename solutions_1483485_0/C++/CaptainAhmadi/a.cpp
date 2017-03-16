
//Written by Alex H Ahmadi (alex@hamedahmadi.com)

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
using namespace std;

#define FOR(i,n) for (int i=0;i<(n);i++)
#define FORIT(it,s) for (__typeof(s.begin()) it=s.begin(); it!=s.end(); ++it)
#define ALL(x) (x).begin(),(x).end()
#define P(x) cerr<<#x<<" = "<<x<<endl
#define pb push_back

#define zer(x) memset(x,0,sizeof(x));
#define isin(x,s) (s.find(x)!=s.end())

typedef long long ll;
typedef vector <int> vi;
typedef set <int> si;
typedef pair <int, int> pii;

char m[500];

void clear() {
}

void solve(int cnum) {
  string s;
  getline(cin, s);

  cout<<"Case #"<<cnum<<": ";

  FORIT(it, s)
	cout<<m[*it];
  cout<<endl;

}

int main() {
  char a[]="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
  char b[]="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

  zer(m);
  m['z']='q';
  m['q']='z';
  for (int i=0;a[i];i++) {
	m[a[i]]=b[i];
  }

  int nt;
  string ss;
  getline(cin,ss);
  nt=atoi(ss.c_str());
  for (int cnum=1; cnum<=nt; cnum++) {
	clear();
	solve(cnum);
  }
  return 0;
}
