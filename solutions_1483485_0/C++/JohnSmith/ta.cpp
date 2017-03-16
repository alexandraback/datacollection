//
// Qualification round 2012  problem A
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <gmpxx.h>

#include <cstdlib>
#include <math.h>

using namespace std;
string s1="y qee";
string s2="ejp mysljylc kd kxveddknmc re jsicpdrysi";
string s3="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
string s4="de kr kd eoya kw aej tysr re ujdr lkgc jv";

string t1="a zoo";
string t2="our language is impossible to understand";
string t3="there are twenty six factorial possibilities";
string t4="so it is okay if you want to just give up";


int table[256];

void setup_table(void)
{
     unsigned int i;
     int table2[256];

     for (i=0; i<256;i++)
     {
	  table[i]=i;
     }
     for (i='a'; i<='z'; i++)
     {
	  table[i] = 0;
	  table2[i] = 0;
     }

     string s=s1+s2+s3+s4;
     string t=t1+t2+t3+t4;

     string::iterator ii,jj;

     ii=s.begin();
     jj=t.begin();
     
     while (ii != s.end())
     {
	  table[(int) *ii] = *jj;
	  table2[(int) *jj] = 1;
	  ii++;
	  jj++;
     }

     unsigned int c;
     for (i='a'; i<='z'; i++)
     {
	  if (table2[i] == 0) {
	       c = i;
	  }
     }
     for (i='a'; i<='z'; i++)
     {
	  if (table[i] == 0) {
	       table[i] = c;
	  }
     }
}

string translate( string in )
{
     string::iterator i;
     string out;
     for (i=in.begin(); i!=in.end(); i++)
     {
	  out.push_back( table[(int) *i] );
     }

     return out;
}

int main( int argc, char ** argv )
{
     unsigned int n;
     unsigned int i;
     string w;
     char s[200];

     setup_table();

     cin >> n;

     cin.getline( s, 200 );

     for (i=1; i<=n; i++) {

	  cin.getline( s, 200 );
	  w = (string)(s);

	  cout << "Case #" << i << ": ";
	  cout << translate(w) << endl;
     }

     return 0;
}
