#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("a-small.out", "w", stdout);
  map<char, char> letters;
  string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
  string ts1 = "our language is impossible to understand";
  string s2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
  string ts2 = "there are twenty six factorial possibilities";
  string s3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
  string ts3 = "so it is okay if you want to just give up";
  letters['q'] = 'z';
  letters['z'] = 'q';
  letters[' '] = ' ';
  for(int i = 0; i < s1.length(); ++i)
    letters[s1[i]] = ts1[i];
  for(int i = 0; i < s2.length(); ++i)
    letters[s2[i]] = ts2[i];
  for(int i = 0; i < s3.length(); ++i)
    letters[s3[i]] = ts3[i];
  
  int t; scanf("%d\n", &t);
  for(int i = 0; i < t; ++i)
  {
    string s; 
    getline(cin, s);
    cout << "Case #" << i + 1 << ": ";
    for(int j = 0; j < s.length(); ++j)
      cout << letters[s[j]];
    cout << endl;
  }
  return 0;
}