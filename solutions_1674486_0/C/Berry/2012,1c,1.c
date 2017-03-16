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
#define ds                                double

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




int N;

mr( int, Mat, 1000*1000);

mr( int, MatPar, 1000*1000);

mr( int, MatAns, 1000);


while ( Case_T < Cases ) {
/* --------------------- */
N  = ri

arrayclear( Mat )
arrayclear( MatPar )


int Mi;
int temp;
dor( i, N ) {
	Mi = ri
	dor( j, Mi ) {
		temp = ri;
		Mat[(1000*i) + (temp-1)] = 1;
	}
	MatPar[(1000*i) + i] = 1;
}

dor( i, N ) {
	dor( j, N ) {
		if ( Mat[(1000*i) + j] == 1 ) {
			dor( x, N ) {
				MatPar[(1000*j) + x] |= MatPar[(1000*i) + x];
			}
			dor( x, N ) {
				if ( MatPar[(1000*x) + j] == 1 ) {
					dor(y, N) {
						MatPar[(1000*x) + y] |= MatPar[(1000*j) + y];
					}
				}
			}
		}
	}
}


int Ans = 0;

dor( i, N ) {
	arrayclear( MatAns )
	dor( j, N ) {
		if ( Mat[(1000*j) + i] == 1 ) {
			dor(x,N) {
				MatAns[x] += MatPar[(1000*j) + x];
				if ( MatAns[x] > 1 ) { Ans = 1; goto End; }
			}
		}
	}
}
End:
printf("Case #%u: %s\n", Case_T + 1,  ((Ans==1)?"Yes":"No") );



/* --------------------- */
fprintf(stderr, "\nDone case %d.\r\e[A", Case_T + 1); fflush(stderr);
Case_T ++;
}

return 0;
}
