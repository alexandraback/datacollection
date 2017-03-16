#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOREACH(i,c) for(typeof(c.begin()) i=(c).begin();i!=(c).end();++i)
#define REP(i,n) FOR(i,0,n)

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

map<char,char> book, rev;

void solve()
{
	string input;
	getline(cin, input);
	for(int i=0;i<input.length();i++) {
		cout << book[input[i]];
	}
}

void train(string input, string output)
{
	for(int i=0;i<input.length();i++) {
	    book[input[i]] = output[i];
		rev[output[i]] = input[i];
	}
}

int main()
{
  int T;
  train("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
  train("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
  train("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
  train("qz", "zq");
  
  FOR(c,'a','z'+1) {
    //cout << (char)(c) << " " << (char)book[c] << " " << book.count(c) << " " << rev.count(c) << endl;
	assert(1 == book.count(c));
  }
  //exit(0);
  
  cin >> T;
  string input;
  getline(cin, input);
  for(int i=0;i<T;i++) {
    cout << "Case #" << (i+1) << ": ";
    solve();
    cout << endl;
  }
}
