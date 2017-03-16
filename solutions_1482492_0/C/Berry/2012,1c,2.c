#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

                                                /* C 99     */
#define dor( A_name , B_limit )           for ( int A_name = 0; A_name < (B_limit); A_name ++ )
#define gor( A_name , B_limit )           int A_name; for (     A_name = 0; A_name < (B_limit); A_name ++ )

#define ri                                 atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
#define rll                               atoll(Mem + q ); q += ( strlen(Mem + q) + 1 );
#define rf                                 atof(Mem + q ); q += ( strlen(Mem + q) + 1 );
#define il                                int64_t
#define ds                                long double

#define cil( A )                          ((int64_t)(A))
#define  cd( A )                          ((double )(A))
#define cll( A )                          ((long long int)(A))

#define mr( A_type, B_name, C_count )     size_t arraysizebytes##B_name = (sizeof(A_type) * (C_count)) ; A_type * B_name = malloc( arraysizebytes##B_name );
#define arrayclear( B_name )              bzero( B_name, arraysizebytes##B_name );
#define usup( A_rop, B_op)                if ( (A_rop) < (B_op) ) { (A_rop) = (B_op); }
#define uinf( A_rop, B_op)                if ( (A_rop) > (B_op) ) { (A_rop) = (B_op); }
#define maxa( A_rop, B_array, C_limit )   int maxa##B_array = 0; while ( maxa##B_array < (C_limit) ) { if ( maxa##B_array == 0 ) { A_rop = B_array[maxa##B_array]; } else { usup(A_rop, B_array[ maxa##B_array ]) } ; maxa##B_array ++; }
#define mina( A_rop, B_array, C_limit )   int maxa##B_array = 0; while ( maxa##B_array < (C_limit) ) { if ( maxa##B_array == 0 ) { A_rop = B_array[maxa##B_array]; } else { uinf(A_rop, B_array[ maxa##B_array ]) } ; maxa##B_array ++; }

                                          void * swapchair;
#define swap( A, B )                             swapchair = malloc(sizeof(A)); memcpy(swapchair, &(A), sizeof(A) ); memcpy( &(A), &(B), sizeof(A) ); memcpy( &(B), swapchair,  sizeof(A) ); free(swapchair);
#define abs( A )                          ( ((A)<0) ? ( 0 - (A) ) : ( A ) )

#if 1
#define fsd( A_fmt , ... )                fprintf(stderr, "%s %d: " A_fmt "\n", __FUNCTION__, __LINE__ , ##__VA_ARGS__ );
#else
#define fsd( ... )                        (void)0 ;
#endif

#define niut( A_rop , B_limit, C_cond )                  while ( A_rop < (B_limit) ) { if ( C_cond ) { break; } A_rop ++; }
#define diut( A_rop , B_limit, C_cond )   int A_rop = 0; while ( A_rop < (B_limit) ) { if ( C_cond ) { break; } A_rop ++; }

#define bst( A_name, B_lower, B_upper, C_cond )    int64_t lower##A_name = B_lower; int64_t upper##A_name = B_upper; int64_t A_name; while ( lower##A_name < upper##A_name ) { A_name = lower##A_name + ((upper##A_name - lower##A_name)/2); if ( ! (C_cond) ) { lower##A_name = A_name + 1; } else { upper##A_name = A_name; } } A_name = upper##A_name;
#define bstf( A_name, B_lower, B_upper, C_cond )   ds lower##A_name = B_lower; ds upper##A_name = B_upper; ds A_name; while ( upper##A_name - lower##A_name > ( cd(1)/cd(10000000000000LL) ) ) { A_name = lower##A_name + ((upper##A_name - lower##A_name)/(cd(2))); if ( ! (C_cond) ) { lower##A_name = A_name; } else { upper##A_name = A_name; } } A_name = upper##A_name;


/* ---------------------- */
/* - Includes ----------- */



/* - Includes ----------- */
/* ---------------------- */


int main( int argc, char ** argv, char ** envp ) {
int File = open(argv[1], O_RDONLY);
size_t Size = lseek(File, 0, SEEK_END);
char * Mem = malloc(Size);
lseek(File, 0, SEEK_SET);
read(File, Mem, Size);
close(File);
unsigned int q = 0;
while ( q < Size ) {
	if ( Mem[q] == 0x0a ) { Mem[q] = 0x00; }
	if ( Mem[q] == 0x20 ) { Mem[q] = 0x00; }
	q++;
}
unsigned int Cases = atoi(Mem);
q = strlen(Mem) + 1;
fprintf(stderr, "Cases: %u\n", Cases);
unsigned int Case_T = 0;




ds D;
int N;
int A;

mr( ds, T, 2000);
mr( ds, P, 2000);
mr( ds, Accs, 250);

mr( ds, Ans, 250);


while ( Case_T < Cases ) {
/* --------------------- */
D = rf
N = ri
A = ri

arrayclear( T )
arrayclear( P )
arrayclear( Accs )


dor( i, N ) {
	T[i] = rf
	P[i] = rf
}

dor( i, A ) {
	Accs[i] = rf
}

ds latest = T[N-1]; // latest drop time clearly can be when the blocking car arrives home




/*nested*/
int NoCrash( ds droptime, ds accel ) {
	// Global: D, N
	// Global, T[], P[]
	int x = 0;
	ds crop_t;
	ds crop_x;
	while ( x < (N-1) ) {
		if ( T[x+1] > droptime ) {
			if ( P[x+1] > D ) {
				if ( P[x] >= D ) {
					return 1;
				}
				crop_t  = (D - P[x]) / ((P[x+1] - P[x])/(T[x+1] - T[x]));
				crop_t += T[x];
				/* oops */
				crop_x = D;
			} else {
				crop_t = T[x+1];
				crop_x = P[x+1];
			}
			if ( (((crop_t-droptime)*(crop_t-droptime)*accel)/((long double)(2))) > crop_x ) {
//				printf("crash dropping at time %lf with accel %lf against %d\n", droptime, accel, x);
				return 0;
			}
		}
		x ++;
	}
	return 1;
}




printf("Case #%u:\n", Case_T + 1 );


dor( a_i, A ) {
	arrayclear( Ans )

	bstf( tempans, 0.0, latest, NoCrash( tempans , Accs[a_i] ) )
	Ans[a_i] = tempans + sqrt(((((long double)(2)) * D) / Accs[a_i] ));

	printf("%.6lf\n", cd(Ans[a_i]) );
}







/* --------------------- */
fprintf(stderr, "\nDone case %d.\r\e[A", Case_T + 1); fflush(stderr);
Case_T ++;
}

return 0;
}
