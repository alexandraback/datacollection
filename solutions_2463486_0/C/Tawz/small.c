/* Warning!
 *
 * This solution uses brute force and is ONLY capable of solving the
 * small input. On the other hand, it should solve the small input
 * very easily. 
 */


#include <stdio.h>
#include <math.h>


int A, B;



int is_square( int x )
{
    int root = (int) sqrt( x );
    return root * root == x;
}


int is_palindrome( int x )
{
    int digits[32];
    int len = 0;
    while( x > 0 ) {
	digits[ len ] = x % 10;
	x /= 10;
	len++;
    }

    for( int d = 0; d < len / 2; ++d ) {
	if( digits[ d ] != digits[ len - d - 1 ] )
	    return 0;
    }

    return 1;
}


int analyze( void )
{
    int num = 0;

    for( int x = A; x <= B; ++x ) {

	if( is_square( x ) && is_palindrome( (int) sqrt( x ) ) && is_palindrome( x ) ) {
	    num += 1;
	}

    }

    return num;
}


int main( void )
{
    /* Read the number of test cases. */
    int num_cases;
    scanf( "%d\n", &num_cases );

    /* For each test case... */
    for( int test = 1; test <= num_cases; ++test ) {

	/* Read bounds. */
	scanf( "%d %d\n", &A, &B );

	/* Print results. */
	int outcome = analyze( );
	printf( "Case #%d: %d\n", test, outcome );
    }

    return 0;
}
