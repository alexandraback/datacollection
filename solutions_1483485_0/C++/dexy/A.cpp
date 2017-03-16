#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <map>

using namespace std;

//#define BIG
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))

#ifdef BIG
ifstream in("A-large.in") ; ofstream out("A-large.out") ;
#endif

#ifndef BIG
ifstream in("A-small.in") ; ofstream out("A-small.out") ;
#endif



string coded [3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jvqz"} ;
string source [3] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give upzq"} ;

map<char, char> dict ;


int main() {
  ios_base::sync_with_stdio(0) ;
  for (char ch = 'a' ; ch <= 'z' ; ch ++) dict [ch] = '?' ;
  for (int i = 0 ; i < 3 ; i ++) for (int j = 0 ; j < coded [i].size() ; j ++) dict [coded [i] [j]] = source [i] [j] ;
  //for (char ch = 'a' ; ch <= 'z' ; ch ++) cout << ch << ":" << dict [ch] << endl ;
  int numTests ;
  in >> numTests ;
  char buf [200] ;
  in.getline(buf, 200) ;
  for (int test = 1 ; test <= numTests ; test ++) {
    string c, s ;
    in.getline(buf, 200) ; c = string(buf) ;
    s = "" ;
    for (int i = 0 ; i < c.size() ; i ++) s += string(1, dict [c [i]]) ;
    out << "Case #" << test << ": " << s << endl ;
  }
  in.close() ;
  out.close() ;

  return 0;
}
