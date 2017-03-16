#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long i64;

#define FOREACH(type, collection, arg) for(vector<type>::iterator arg = collection.begin(); arg != collection.end(); arg++)
#define FOREACH_R(type, collection, arg) for(vector<type>::iterator arg = collection.rbegin(); arg != collection.rend(); arg++)

int main(int argc, char *argv[]){
  int T;
  cin >> T;

  char map[] = "ynficwlbkuomxsevzpdrjgthaq";

  getchar();
  for(int t=1;t<=T;t++) {
    printf("Case #%d: ", t);

    string s;
    getline(cin, s);
    for(string::iterator it=s.begin();it!=s.end();it++) {
      if('a' <= *it && *it <= 'z') {
	for(int i=0;i<26;i++)
	  if(map[i] == *it)
	    putchar('a' + i);
      }
      else
	putchar(*it);
    }
    putchar('\n');
  }

  return 0;
}
