#include <assert.h>

#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>

#include <string>

#include <vector>
#include <list>

#include <bitset>
#include <valarray>

#include <algorithm>
#include <cmath>

#include <assert.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstddef>  // std::size_t
#include "cstdio"
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <fstream>
// #include <gmpxx.h>
#include <iomanip>
#include <iostream>
#include <list>
#include "map"
#include <math.h>
#include "numeric"
#include "queue"
#include "set"
#include <string>         // std::string
#include <sys/stat.h>
#include <sys/types.h>
#include "utility"
#include <valarray>
#include <vector>
#include <functional>

using namespace std;

inline bool fexists (const string& fname){  struct stat buffer;  return (stat (fname.c_str(), &buffer) == 0); }

unsigned long int A, B, K, n;
int a, b, c;
int i, j, k;
// int x, y, z;



int main(int ac, char** av)
{
  std::ifstream f;
  std::ofstream g;

  if ( ac >= 2 )
  {
    assert( fexists(string(av[1])) );
    f.open(av[1], ios::in);
#ifndef NDEBUG    
    cerr << "INPUT from: " << av[1] << endl;
#endif  
    assert( f.is_open() );

    if( ac >= 3 )
    {
//      assert( fexists(string(av[2])) );
      g.open(av[2], ios::out | ios::trunc);
#ifndef NDEBUG    
      cerr << "OUTPUT to: " << av[2] << endl;
#endif  
      assert( g.is_open() );
    }
    
  } else
  {
    string n(av[0]); // n += ".in";
    
    if( fexists(n + ".in") )
    {
      string nn = n + ".in";
      string nnn = n + ".out";
#ifndef NDEBUG    
      cerr << "INPUT from: " << nn << endl;
      cerr << "OUTPUT to: " << nnn << endl;
#endif  
      f.open(nn.c_str(), ios::in);
      assert( f.is_open() );

      g.open(nnn.c_str(), ios::out | ios::trunc);
      assert( g.is_open() );
    }
  }

#ifndef NDEBUG
  if (!f.is_open())
    cerr << "INPUT from console input stream..." << endl;
  
  if (!g.is_open())
    cerr << "OUTPUT to console output stream..." << endl;
#endif  
  
  istream &in = (f.is_open()) ? f : cin;
  ostream &out = (g.is_open()) ? g : cout;
  
  ////////////////////////////////////////////////////////////////////////////
  
  long int T;  string str; 

  in >> T; getline(in, str); assert( 1 <= T && T <= 100 );

  for (int testcase = 1; testcase <= T; testcase++ )
  {
    out << "Case #" << testcase << ": "; // ' '?!

    in >> A >> B >> K; 
    getline(in, str); 

//    vector < int > v(N); // list<?> // ?????????????
//    bitset<64> b(K);
    n = 0;
     
    for (i = 0; i < A ; i++ ) 
    for (j = 0; j < B ; j++ )
	 if( (i & j) < K )
	   n++;

    out << n; 
//    vector <char> result(N, _F);
//    while (! v.empty())   a = v.front();    v.pop_front(); // list
//    while (! v.empty())   a = v.back();     v.pop_back();
//          vector<?>::iterator it = find( v.begin(), v.end(), a); assert( it != v.end()); assert( (*it) == a );
//          a.erase(it);
//          for( vector<?>::iterator it = v.begin(); it != v.end(); it ++ ) a = *it;
//          assert( find( v.begin(), v.end(), a ) != v.end() );


    // we are finished...
    // check?!
//    for ( i = 0; i < N; i++ )
//      out << ' ' << ((result[i] != _F) ? result[i] : UF );

nexttest:
    // cleanup
//    while (!todo.empty())
//    {
//      assert( todo.back()->_u.size() > 0 );
//      if (todo.back() != NULL)
//        delete (todo.back());
//      todo.pop_back();
//    }


    out << endl;
  }; // main loop !!!
  
  ////////////////////////////////////////////////////////

  if (f.is_open()) f.close();
  if (g.is_open()) g.close();
  
  return 0;
}


/*
// typedef pair<short,char> S;
// const char _F = '?';
struct  Row
{ 
  vector<short> _u;   //  bitset<2000>
  short _m; // -1 means undefined or unset

  Row() : _u(), _m(-1) {};

  Row(vector<short> uu, short mm = -1 ):_u(uu), _m(mm)
  {
  }

  Row(int T): _u(), _m(-1)
  {
    _u.reserve(T);
  }

  inline void init(vector<short> uu, short mm = -1 )
  {
    _u = uu; _m = mm;
  }
};
// typedef vector<Row*> Col;
inline ostream & operator<< (ostream &o, const Row &e)
{
  o << "[ ";
  for( int i = 0; i < e._u.size(); ++i)
    o << e._u[i] << " ";

  return o << "| " << e._m << " ]";
}
*/

/*

typedef pair<short,int> S; 

bool Scmp (const S& i, const S& j) 
{
    return (i.first < j.first); 
}
sort(V.begin(), V.end(), Scmp);


*/
