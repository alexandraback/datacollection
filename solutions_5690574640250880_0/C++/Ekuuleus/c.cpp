#include <iostream>
#include <limits>

using namespace std;

void solve (int ci){


	int R,C,M ;
	int F ;
	int R2 , R1 ;

	cin >> R >> C >> M ;
	
	cerr << "case #" << ci << ":" << R << " " << C << " " << M << endl;
		F = (R * C ) - M ;
	bool S = false ;

	cout << "Case #" << ci << ":" << endl ;

	if ((R == 1 ) || ( C == 1 )) {
		if ( F==0 ){
			cout << "Impossible" << endl;
		} else { 
			for ( int irow = 0 ; irow < R ; irow++ ){
				for ( int icol = 0 ; icol < C ; icol++ ){
					if ((irow == 0 ) && (icol == 0 )) {
						cout << 'c' ;
					} else {
						if (--F >0 ) cout << "." ; else cout << "*" ;
					}
				}
				cout  << endl ;
			}
		}
	} else {
		switch (F){
			case 1:
				S = true ; 
				break ;
			case 0:
			case 2:
			case 3:
			case 5:
			case 7:
				S = false ;
				break ;
			default: 
				if (( R == 2 ) or  ( C == 2 )) 
					S = (( F % 2 ) == 0 ) ;
				else
					S = true;
				break;
		}

// cant have a row or column with 1 gap.
// either a row or column has all mines, or at least 2 gaps

// in effect, no point keeping 2 spaces for last space line 
// as can put  1 mine in 2 rows previous.  cant carry 1
// so if Free is 1 grater than row length or 1 


		if ( S == false ){
			cout << "Impossible" << endl;
		} else { 
		
// last line needs 2 or 3 depending on free cells - if rows or cols == 2
// then cant do odd number of mines, R2 is what we keep for the last line
// where there are free cells
			R2 = 2 + ( (F) % 2 );

			if ((( C == 3 ) ) && ( R2 == 3) ) R2 = 2;
			if (( (M%4) == 3 ) && (C == 4 ) && (F > 9)) R2 = 2;

// Calculate row 1 and 2 length if less then full length 

			if (( F - R2 ) >= ( C*2 )) {
				R1 = C;  // Fill row upto end - we have enough in any circumstance

			} else {
				if (R2==2) R2=0 ;
				R1 = ( F - R2) / 2;
			
				//if ( R1 == 1 ) R1 = 2 ; // C3	
			}

			F -= R2 ;

			for ( int irow = 0 ; irow < R ; irow++ ){
			
				if ((( (F+R2) <= C ) && (irow > 1)) || (irow == R-1)) { 
					F+=R2 ; R2 = 0 ; R1 = C ;} 

				for ( int icol = 0 ; icol < C ; icol++ ){

			
					if ((irow == 0 ) && (icol == 0 )) {
						cout << 'c' ;
						F-- ;
					} else {
						if ( ((F ) > 0) && (icol <R1) ) 
							{ F-- ;	cout << "." ;}
						else cout << "*" ;
					}		
				}	
				cout << endl ;
			}
		}
	}

}



int main(){
	int c;
	cin >> c;
	
	for (unsigned int ci = 1 ; ci <= c ; ++ci ){
		solve (ci);
	}
}



