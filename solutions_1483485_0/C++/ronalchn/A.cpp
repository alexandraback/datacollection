#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

//             "abcdefghijklmnopqrstuvwxyz"
char convert[]="                z        q";
//char convert[]='    o    u  l  r        a';
string a="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
string b="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
void solve(int t) {
  string str;
  getline (cin,str);
  for (int i=0;i<str.length();i++) {
    if (str[i]==' ') continue;
    str[i]=convert[str[i]-'a'];
  }
  printf("Case #%d: %s\n",t,str.c_str());
}

int main() {
  for (int i=0;i<a.length();i++) {
    if (a[i]==' ') continue;
    else convert[a[i]-'a']=b[i];
  }
  int T;
  cin >> T;
  //cout << "abcdefghijklmnopqrstuvwxyz" << endl;
  //cout << convert << endl;
  getline (cin,a);
  for (int t=1;t<=T;t++) {
    solve(t);
  }
  return 0;
}
