/* Warning!
 *
 * This solution uses a semi-brute force strategy and should be
 * capable of solving the medium-sized problem but probably not the
 * very large problem. 
 */


#include <stdio.h>



typedef struct num_s
{
    int len;
    int digits[ 128 ];
} num;


num A, B;
num table[ 20000 ];
int tbllen = 0;


void num_zero( num *a )
{
    a->len = 0;
}

void num_first( num *a, int len )
{
    a->len = len;
    for( int k = 0; k < len; ++k ) {
	if( k == 0 || k == len - 1 )
	    a->digits[ k ] = 1;
	else
	    a->digits[ k ] = 0;
    }
}


int num_le( num *a, num *b )
{
    if( a->len < b->len )
	return 1;
    if( a->len > b->len )
	return 0;
    for( int k = a->len - 1; k >= 0; --k ) {
	if( a->digits[ k ] < b->digits[ k ] )
	    return 1;
	if( a->digits[ k ] > b->digits[ k ] )
	    return 0;
    }

    return 1;
}



void num_print( num *a )
{
    for( int k = 0; k < a->len; ++k ) {
	putchar( '0' + a->digits[ k ] );
    }
    putchar( '\n' );
}


int is_palindrome( num *a )
{
    for( int k = 0; k < a->len / 2; ++k ) {
	if( a->digits[ k ] != a->digits[ a->len - k - 1 ] )
	    return 0;
    }
    return 1;
}



int next_palindrome_with_same_number_of_digits( num *a )
{
    if( a->len == 1 ) {
	if( a->digits[ 0 ] == 9 )
	    return 0;
	a->digits[ 0 ] += 1;
	return 1;
    }
    
    int lo = (a->len - 1) / 2;
    int hi = a->len - lo - 1;
    do { 
	/* Increase palindromic pair. */
	a->digits[ hi ] += 1;
	a->digits[ lo ] = a->digits[ hi ];
	if( a->digits[ lo ] > 9 ) {
	    /* Overflow - reset. */
	    a->digits[ lo ] = a->digits[ hi ] = 0;
	} else {
	    /* Success. */
	    return 1;
	}
	/* Next palindromic pair. */
	lo -= 1;
	hi += 1;
    } while( lo >= 0 );

    return 0;
}



void num_square( num *a, num *sq )
{
    for( int k = 0; k < 2 * a->len; k++ ) 
	sq->digits[ k ] = 0;

    for( int d1 = 0; d1 < a->len; ++d1 ) {
	for( int d2 = 0; d2 < a->len; ++d2 ) {
	    int rem = a->digits[ d1 ] * a->digits[ d2 ];
	    int k = d1 + d2;
	    do {
		sq->digits[ k ] += rem;
		rem = sq->digits[ k ] / 10;
		sq->digits[ k ] = sq->digits[ k ] % 10;
		++k;
	    } while( rem > 0 );
	}
    }
    sq->len = 2 * a->len;
    if( sq->digits[ sq->len - 1 ] == 0 )
	sq->len--;
}


void num_copy( num *a, num *b )
{
    b->len = a->len;
    for( int k = 0; k < a->len; ++k )
	b->digits[ k ] = a->digits[ k ];
}


void build_table( void )
{
    tbllen = 0;

    /* For each number of digits. */
    for( int len = 1; len <= 8; ++len ) {

	/* First palindromic number of that length. */
	num a;
	num_first( &a, len );

	/* Enumerate all palindromes of that length. */
	do {

	    /* Square the palindrome. */
	    num aa;
	    num_square( &a, &aa );
	    
	    /* Fair and square? */
	    if( is_palindrome( &aa ) ) {
		num_copy( &aa, &table[ tbllen ] );
		tbllen++;
	    }
	} while( next_palindrome_with_same_number_of_digits( &a ) );
    }
    //printf( "TABLE LENGTH: %d\n", tbllen );
}


int analyze( void )
{
    /* Number of fair and square numbers. */
    int cnt = 0;

    /* Scan the table. */
    //num_print( &A );
    //num_print( &B );
    for( int k = 0; k < tbllen; ++k ) {
	if( num_le( &A, &table[ k ] ) && num_le( &table[ k ], &B ) ) {
	    //printf( "... %d ... ", k ); 
	    //num_print( &table[ k ] );
	    cnt++;
	}
    }

    return cnt;
}


void num_read( num *a )
{
    a->len = 0;
    while( 1 ) {
	int ch = getchar( );
	if( ch >= '0' && ch <= '9' ) {
	    int d = ch - '0';
	    a->digits[ a->len++ ] = d;
	} else {
	    break;
	}
    }
    /* Reverse. */
    for( int k = 0; k < a->len / 2; ++k ) {
	int tmp = a->digits[ k ];
	a->digits[ k ] = a->digits[ a->len - k - 1 ];
	a->digits[ a->len - k - 1 ] = tmp;
    }
}


int main( void )
{
    build_table( );

    /* Read the number of test cases. */
    int num_cases;
    scanf( "%d\n", &num_cases );

    /* For each test case... */
    for( int test = 1; test <= num_cases; ++test ) {

	/* Read bounds. */
	num_read( &A );
	num_read( &B );

	/* Solve. */
	int outcome = analyze( );

	/* Print results. */
	printf( "Case #%d: %d\n", test, outcome );
    }

    return 0;
}
