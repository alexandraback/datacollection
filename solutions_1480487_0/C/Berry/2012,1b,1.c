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


/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */
/* ---- Berry Merge Sort 'Include' ---------------------------------- */

typedef struct {
	double x;
	int ind;
} MSStruct;

int MS_LeftToBeFirst( MSStruct * Left, MSStruct * Right ) {
	if ( Left[0].x < Right[0].x ) { return 1; }
	return 0;
}

/* */void ms( MSStruct * MS_Source , unsigned int MS_Count) {
/* */	MSStruct * GlobalDumbMS = malloc( sizeof(MSStruct) * MS_Count ); /* include stdlib.h for malloc */
/* */
/* */	MSStruct * MS_Temp = GlobalDumbMS;
/* */	MSStruct * MS_Front = MS_Temp;
/* */	MSStruct * MS_Back  = MS_Source;
/* */
/* */	unsigned int MS_TT_A;
/* */	unsigned int MS_TT_B;
/* */	unsigned int MS_S_A;
/* */	unsigned int MS_S_B;
/* */	unsigned int MS_Size = 1;
/* */	unsigned int MS_T;
/* */	while ( MS_Size < MS_Count ) {
/* */		MS_T = 0;
/* */	
/* */		while ( MS_T < MS_Count ) {
/* */			/*  */
/* */			MS_S_A = MS_Size;
/* */			MS_S_B = MS_Size;
/* */			if ( (MS_T + (MS_Size * 2)) > MS_Count ) {
/* */				if ( (MS_T + MS_Size) >= MS_Count ) {
/* */					MS_TT_A = 0;
/* */					while ( (MS_T + MS_TT_A) < MS_Count ) {
/* */						MS_Front[MS_T + MS_TT_A] = MS_Back[MS_T + MS_TT_A];
/* */						MS_TT_A ++;
/* */					}
/* */					break;
/* */				}
/* */				MS_S_B = MS_Count - (MS_T + MS_Size);
/* */			}
/* */			MS_TT_A = 0;
/* */			MS_TT_B = 0;
/* */			while ( (MS_TT_A < MS_S_A) && (MS_TT_B < MS_S_B) ) {
/* */				if ( MS_LeftToBeFirst( & MS_Back[MS_T + MS_TT_A] , & MS_Back[MS_T + MS_S_A + MS_TT_B] ) ) {
/* */					MS_Front[MS_T + MS_TT_A + MS_TT_B] = MS_Back[MS_T + MS_TT_A];
/* */					MS_TT_A ++;
/* */				} else {
/* */					MS_Front[MS_T + MS_TT_A + MS_TT_B] = MS_Back[MS_T + MS_S_A + MS_TT_B];
/* */					MS_TT_B ++;
/* */				}
/* */			}
/* */			if ( MS_TT_A < MS_S_A ) {
/* */				while ( MS_TT_A < MS_S_A ) {
/* */					MS_Front[MS_T + MS_TT_A + MS_TT_B] = MS_Back[MS_T + MS_TT_A];
/* */					MS_TT_A ++;
/* */				}
/* */			}
/* */			if ( MS_TT_B < MS_S_B ) {
/* */				while ( MS_TT_B < MS_S_B ) {
/* */					MS_Front[MS_T + MS_TT_A + MS_TT_B] = MS_Back[MS_T + MS_S_A + MS_TT_B];
/* */					MS_TT_B ++;
/* */				}
/* */			}
/* */	
/* */			MS_T += (MS_Size * 2);
/* */		}
/* */	
/* */		if ( MS_Front == MS_Source ) {
/* */			MS_Front = MS_Temp;
/* */			MS_Back  = MS_Source;
/* */		} else {
/* */			MS_Front = MS_Source;
/* */			MS_Back  = MS_Temp;
/* */		}
/* */	
/* */		MS_Size <<= 1;
/* */	}
/* */	if ( MS_Back == MS_Temp ) {
/* */		MS_T = 0;
/* */		while ( MS_T < MS_Count ) {
/* */			MS_Front[MS_T] = MS_Back[MS_T];
/* */			MS_T ++;
/* */		}
/* */	}
/* */	free( GlobalDumbMS );
/* */	return;
/* */}
/* */
/* ---- Berry Merge Sort 'Include' ---------------------------------- */
/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */



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

mr( int, S, 200 )

mr( MSStruct, Sd, 200 )
mr( double, Ans, 200 )

double diff;
double goal;

while ( Case_T < Cases ) {
/* --------------------- */
N  = ri

arrayclear( S )
arrayclear( Sd )
arrayclear( Ans )

int TotalScore = 0;

dor( i, N ) {
	S[i] = ri
	TotalScore += S[i];
}

dor( i, N ) {
	Sd[i].x = cd(S[i]) / cd(TotalScore);
	Sd[i].ind = i;
}

ms(Sd, N);

dor( i, N ) {


	Ans[Sd[i].ind] = 1.0;
	double Temp;
	for (int k = i; k < N; k ++ ) {
		goal = (Sd[k].x - Sd[i].x);
		diff = 0.0;
		dor( j, k+1 ) {
			if ( j != i ) {
				diff += ((Sd[i].x + goal) - Sd[j].x);
			}
		}
		if ( diff > (1.0 - goal) ) {
			Temp = goal;
		} else {
			diff = (1.0 - goal) - diff;
			Temp = goal + (diff * (cd(1) / cd(k +1)));
		}
		if ( Ans[Sd[i].ind] > Temp ) {
			if ( Temp < 0 ) {
				fprintf(stderr, "hmm\n\n\n");
			}
			Ans[Sd[i].ind] = Temp;
		}
	}


}

int k  = N-1;
while ( k > 0 ) {
	k --;
	if ( Sd[k].x == Sd[k+1].x ) {
		Ans[Sd[k].ind] = Ans[Sd[k+1].ind];
	}
}





printf("Case #%u:", Case_T + 1);

dor( i, N ) {
	printf(" %lf", Ans[i]*cd(100));
}
printf("\n");

/* --------------------- */
fprintf(stderr, "\nDone case %d.\r\e[A", Case_T + 1); fflush(stderr);
Case_T ++;
}

return 0;
}
