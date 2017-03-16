#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std ;

int pairs[3][10][3][10] ;
int numposs = 0 ;

void update( vector<int> comb )
	{
	 for( int i = 0 ; i < 2 ; i++)
	    {
	    for( int j = i + 1 ; j < 3 ; j++)
		{
		 pairs[i][comb[i]][j][comb[j]] += 1 ;
		}
	    }
	  return ;
	}

void print( int ar[] , vector<int> comb[] , int pos , int ab[] )
	{
	   for( int i = 0 ; i < ar[pos] ; i++)
              {
               ab[pos] = i ;
              if( pos + 1 < 3 ) {
                                print( ar , comb , pos + 1 , ab) ;
                                }
              else { for( int j = 0 ; j < 3 ; j++)
                        {
                        // cout << ab[j] << " " ;
                         comb[numposs].push_back( ab[j] ) ;
                        }
                        //cout << endl ;
                     numposs++ ;
                   }
              }
          return ;
         }

int possible( vector<int> comb ,int K ,int pos)
	{
         int p = 0 ;
	 for( int i = 0 ; i < 2 ; i++)
	    {
	     for( int j = i + 1 ; j < 3 ; j++)
		{
		 if( pairs[i][comb[i]][j][comb[j]] == 0 ) { p++ ; }
		}
		}
	  return p ;
	} 

int val( vector<int> comb )
	{
	  int max = 0 ;
	   for( int i = 0 ; i < 2 ; i++)
	    {
	     for( int j = i + 1 ; j < 3 ; j++)
		{
		 if( pairs[i][comb[i]][j][comb[j]] > max ) { max = pairs[i][comb[i]][j][comb[j]] ;
			//				     cout << max << "inside" << endl ;
			//				    cout << i << comb[i] << j << comb[j] << endl ; 
							}
		}
		}
	 return max ;
	}


int main()
	{
	 int T ;
         cin >> T ;
	 for( int i = 0 ; i < T ; i++)
	     {
	      int ar[3] ;
	      int K ;
	      int ab[3] ;
	      vector<int> comb[1000] ;
		cout << "Case #" << i + 1 << ": " ;
	      for( int j = 0 ; j < 3 ; j++) {
		cin >> ar[j] ; 
		}
		cin >> K ;
	     numposs = 0 ;
	     print( ar , comb , 0 , ab ) ;
	     for( int j = 0 ; j < 2 ; j++)
	         {
		   for( int k = 0 ; k < 10 ; k++)
			{
			 for( int l = j + 1 ; l < 3 ; l++)
				{
				 for( int m = 0 ; m < 10 ; m++)
					{
					 pairs[j][k][l][m] = 0 ;
					}
				}
			}
		}
	
	    int count = 0 ;
	    vector<int> ans[1000] ;
	    int pos = 3 ;
	    int pro = ar[0] * ar[1] * ar[2] ;
	    while( pos > 0 )
		{
		int cnt ;
		 for( int j = 0 ; j < pro ; j++)
		    {
		       cnt = possible( comb[j] , K , pos) ;
		       if( cnt == pos  ) {
				
 if( val( comb[j] ) > K + 1 ) {continue ;}  
					for( int k = 0 ; k < 3 ; k++)
						{
						 ans[count].push_back( comb[j][k] ) ;
						 update( comb[j] ) ;
						}
					count++ ;
					}
			}
		 pos-- ;	 
		}
				 
	         cout << count << endl ;
	         for( int j = 0 ; j < count ; j++)
			{
			  for( int k = 0 ; k < 3 ; k++) { cout << ans[j][k] + 1<< " " ; }
			  cout << endl ;
			}
	 	}      

	return 0 ;
	}
