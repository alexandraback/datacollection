#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std ;

int main()
	{
	int T ;
	cin >> T ;
	for( int i = 0 ; i < T ; i++)
	  {
	   long long B , M ;
	   cin >> B >> M ;
	   cout << "Case #" << i + 1 << ": " ;
	 //  if( M > 17 ) { cout << "IMPOSSIBLE" << endl ; continue ; }
	   int path[B][B] ;
	   int input[B] ;
	   int count = 0 ;
	   for( int j = 0 ; j < B ; j++) { input[j] = 0 ; }
	   for( int j = 0 ; j < B ; j++)
		{
		for( int k = 0 ; k < B ; k++)
		{
	     path[j][k] = 0 ; }
		}
	   for( int j = 0 ; j < B - 1 ; j++)
	      {
	 	path[j][j+1] = 1 ;
		input[j+1]++ ;
		}
	   count++ ;
	   for( int j = 0 ; j < B - 1 ; j++)
	      {
		for( int k = j + 2 ; k < B ; k++)
		   {
		    path[j][k] = 1 ;
		    input[k]++ ;
		    count += input[j] ;
		   }
		if( count >= M ) break ;
	 
		}
	  if( count < M ) { cout << "IMPOSSIBLE" << endl ; continue ; }
	   cout << "POSSIBLE" << endl ;
	   for( int j = 0 ; j < B ; j++)
		{
		 for( int k = 0 ; k < B ; k++)
			{
			 cout << path[j][k];
			}
		 cout << endl ;
		}
		  } 

	return 0 ;
	}
