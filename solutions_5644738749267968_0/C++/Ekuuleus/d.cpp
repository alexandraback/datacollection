#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

int compare (const void * a, const void * b)
{
//  return sgn ( *(double*)a - *(double*)b );
  if ( *(double*)a <  *(double*)b ) return -1;
  if ( *(double*)a == *(double*)b ) return 0;
  if ( *(double*)a >  *(double*)b ) return 1;
}

void solve (int ci){

	int d , K = 0  , N = 0 ;
	double dN[1000] ;
	double dK[1000] ;

	cin >> d ;

	for ( int idN = 0 ; idN < d ; idN++ ) cin >>dN[idN] ;
	qsort ( dN , d , sizeof ( dN[0] ) , compare ) ;

        for ( int idN = 0 ; idN < d ; idN++ ) cin >>dK[idN] ;
        qsort ( dK , d , sizeof ( dK[0] ) , compare ) ;

//for ( int d1 = 0 ; d1 < d ; d1++ ) cerr << "data " << d1 << " " << dN[d1] << " " << dK[d1] << endl ; 
	int idN = 0 , idK = 0 ;

	for ( idN = 0 ; idN < d , idK < d ; idN++ ){
		// find the first block large than niomis
		for(;idK < d ;idK++ ){
			if (dK[idK] > dN[idN] ){
//cerr << "Ken " <<  dN[idN] << " " <<  dK[idK] << endl  ;
				K++ ; idK++ ;
				break ; 
			}
		}

	}

// deceitful war - get Ken to play largest blocks first.
/*
        idK = d -1 ;

        for ( int idN = 0 ; idN < d , idK >= 0 ; idN++ ){
                // find the first block large than niomis
                for(;idK >= 0 ;idK-- ){
                        if (dK[idK] > dN[idN] ){
//cerr << "Ken " <<  dN[idN] << " " <<  dK[idK] << endl  ;
                                N++ ; idK-- ;
                                break ; 
                        }       
                }

        }
*/
// deceitful war 2 - ken will end up playing his blocks in order,
// whether N wins depends on the ned

	int nl = 0 , nm = d -1 ;
	
	for( idN = idK = d - 1 ; idK >= 0 ; idK -- ){
		if ( dK[idK] < dN[idN] )
			idN--;
	} 
	cout << "Case #" << ci << ": " << d-1 -idN  << " " <<  d- K <<  endl ; 
}
	



int main(){
	int c;
	cin >> c;
	
	for (unsigned int ci = 1 ; ci <= c ; ++ci ){
		solve (ci);
	}
}



