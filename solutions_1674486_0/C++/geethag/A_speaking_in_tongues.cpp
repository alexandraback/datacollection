#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
using namespace std;

main()
{
  map< char,char > googlerese_to_normal;
  
  googlerese_to_normal['a'] = 'y';
  googlerese_to_normal['b'] = 'h';
  googlerese_to_normal['c'] = 'e';
  googlerese_to_normal['d'] = 's';
  googlerese_to_normal['e'] = 'o';
  googlerese_to_normal['f'] = 'c';
  googlerese_to_normal['g'] = 'v';
  googlerese_to_normal['h'] = 'x';
  googlerese_to_normal['i'] = 'd';
  googlerese_to_normal['j'] = 'u';
  googlerese_to_normal['k'] = 'i';
  googlerese_to_normal['l'] = 'g';
  googlerese_to_normal['m'] = 'l';
  googlerese_to_normal['n'] = 'b';
  googlerese_to_normal['o'] = 'k';
  googlerese_to_normal['p'] = 'r';
  googlerese_to_normal['q'] = 'z';
  googlerese_to_normal['r'] = 't';
  googlerese_to_normal['s'] = 'n';
  googlerese_to_normal['t'] = 'w';
  googlerese_to_normal['u'] = 'j';
  googlerese_to_normal['v'] = 'p';
  googlerese_to_normal['w'] = 'f';
  googlerese_to_normal['x'] = 'm';
  googlerese_to_normal['y'] = 'a';
  googlerese_to_normal['z'] = 'q';
  googlerese_to_normal[' '] = ' ';

  
  int tests;
  scanf("%d",&tests);
  
  string line;
  getline( cin, line );

  for( int tc = 1 ; tc <= tests ; tc++ )
    {
      getline( cin , line );
      
      printf("Case #%d: ",tc);
      for( int i = 0 ; i < line.length() ; i++ )
	{
	  printf("%c",googlerese_to_normal[ line[i] ] );
	}
      printf("\n");
    }
}
      
