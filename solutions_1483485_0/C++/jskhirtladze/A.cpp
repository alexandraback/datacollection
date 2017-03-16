#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

FILE *fin=freopen("input.txt","r",stdin);
FILE *fout=freopen("output.txt","w",stdout);

char f(char c)
{
 if ( c=='a' ) return 'y';
 if ( c=='b' ) return 'h';
 if ( c=='c' ) return 'e';
 if ( c=='d' ) return 's';
 if ( c=='e' ) return 'o';
 if ( c=='f' ) return 'c';
 if ( c=='g' ) return 'v';
 if ( c=='h' ) return 'x';
 if ( c=='i' ) return 'd';
 if ( c=='j' ) return 'u';
 if ( c=='k' ) return 'i';
 if ( c=='l' ) return 'g';
 if ( c=='m' ) return 'l';
 if ( c=='n' ) return 'b';
 if ( c=='o' ) return 'k';
 if ( c=='p' ) return 'r';
 if ( c=='q' ) return 'z';
 if ( c=='r' ) return 't';
 if ( c=='s' ) return 'n';
 if ( c=='t' ) return 'w';
 if ( c=='u' ) return 'j';
 if ( c=='v' ) return 'p';
 if ( c=='w' ) return 'f';
 if ( c=='x' ) return 'm';
 if ( c=='y' ) return 'a';
 if ( c=='z' ) return 'q';
 return c;
}

main()
{
 int t;
 cin>>t;
 string s;
 getline(cin,s);
 for ( int k=1;k<=t;k++ )
  {
   getline(cin,s);
   for ( int i=0;i<s.size();i++)
    s[i]=f(s[i]);
   cout<<"Case #"<<k<<": "<<s<<endl;
  }
}
