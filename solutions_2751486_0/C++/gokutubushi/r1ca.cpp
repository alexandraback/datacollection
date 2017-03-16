#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include <math.h>
#define fore(I,D) for(unsigned int(I)=0;(I)<(D).size();++(I))
#define forn(I,S) for(unsigned int(I)=0;(I)<(S);++(I))
#define ALL(C) (C).begin(),(C).end()
#define COUNT(C,N) count(ALL(C),(N))
#define SORT(C) sort(ALL(C))
#define REV(C) reverse(ALL(C))
#define UNIQ(C) (C).erase( unique(ALL(C)), (C).end());
#define FIND(C,N) find(ALL(C),N)
#define FILL(C,N) fill(ALL(C),N)
#define REPLACE(C,N1,N2) replace(ALL(C),N1,N2)
#define COMMA <<","<<
#define ENDL <<endl
//#include <iomanip>
using namespace std;
// time g++ -Wall -O2 -mtune=pentium-m qualb.cpp ; time cat sample.in | ./a.exe | tee out



bool isvowel( char c ){
  string vowels="aeiou";
  fore( i, vowels )
    if( c==vowels[i] )
      return true;
  return false;
}

string bitstring( string s ){
  string ret="";
  fore( i, s )
    ret+= ( isvowel(s[i]) ? "1" : "0" );
  
  return ret;
}

int sub1(){
  int ret=0;
  string name;
  double n;
  cin >> name;
  cin >> n;
  //cout << "name,n=" << name COMMA n ENDL;
  
  string bs=bitstring( name );
  string ns="";
  forn( i, n )
    ns+="0";
  
  for( unsigned int i=0 ; i<bs.length() ; i++ )
    for( unsigned int j=0 ; i+j<bs.length() ; j++ )
      if( -1!=( (bs.substr( i, j+1 )).find(ns) ) ){
	//cout << (bs.substr( i, j+1 )) ENDL;
	//cout << (name.substr( i, j+1 )) ENDL;
	ret++;
      }
  
  //cout << "a,x=" << a COMMA x ENDL;  
  return ret;
}


int main (int argc, char*argv[]){
  int T;
  cin >> T;
  
  //cout << T ENDL;
  for ( int i=0 ; i<T ; i++ ){
    cout << "Case #" << i+1 << ": " ;

    cout << sub1();
    //cout.precision(6);
    //cout << sub1();
    //printf("%6f",sub1());
    cout << endl;
  }
  
  return 1;
};
