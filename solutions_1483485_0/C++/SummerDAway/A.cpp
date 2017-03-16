//------------------------------------------------------------------------------
//  Problem : 
//  User    : 
//  Date    : 
//------------------------------------------------------------------------------


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

char A[] = { 'y' , 'h' , 'e' , 's' , 'o' , 'c' , 'v' , 'x' , 'd' , 'u' , 'i' , 
			'g' , 'l' , 'b' , 'k' , 'r' , 
			'z' , 't' , 'n' , 'w' , 'j' , 'p' , 'f' , 'm' , 'a' , 'q' } ;
int N ;
char ch[100000] ;

int main( int argc , char *argv[] )
{
	freopen( "A-small-attempt1.in" , "r" , stdin ) ;
	freopen( "A-small-attempt1.out" , "w" , stdout ) ;
	scanf( "%d" , &N ) ;
	gets( ch ) ;
	for( int i = 0 ; i < N ; i++ ) {
		gets( ch ) ;
		for( int j = 0 ; j < strlen( ch ) ; j++ ) {
			if( ch[j] != ' ' ) {
				ch[j] = A[ch[j]-'a'] ;
			}
		}
		printf( "Case #%d: %s\n" , i+ 1 , ch ) ;
	}
		
	return 0;
}
