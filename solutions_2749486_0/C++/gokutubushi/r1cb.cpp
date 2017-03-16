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





string sub1(){
  string ret="";
  int destx;
  int desty;
  cin >> destx;
  cin >> desty;
  
  //cout << destx COMMA desty ENDL;
  
  
  if( destx>0 )
    forn( i, destx )
      ret+="WE";
  else
    forn( i, -destx )
      ret+="EW";
  
  if( desty>0 )
    forn( i, desty )
      ret+="SN";
  else
    forn( i, -desty )
      ret+="NS";
  


  //cout << ":" << ret ENDL;
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
