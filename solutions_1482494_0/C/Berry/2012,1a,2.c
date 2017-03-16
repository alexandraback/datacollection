#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>




/* ------------------------------------------------------------------ */
/* ------------------------------------------------------------------ */
/* ---- Berry Merge Sort 'Include' ---------------------------------- */
/* */typedef struct {
	int c;
	int lev;
	int b_demand;
/* */} MSStruct;
/* */
/* */int MS_LeftToBeFirst( MSStruct * Left, MSStruct * Right ) {
	if ( Left[0].c < Right[0].c ) { return 1; }
	if ( (Left[0].c == Right[0].c) && (Left[0].b_demand < Right[0].b_demand) ) { return 1; }
	return 0;
}

/* */
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




int N;

MSStruct * A  = malloc(sizeof(MSStruct) * 1000);
MSStruct * B  = malloc(sizeof(MSStruct) * 1000);

MSStruct * Bs = malloc(sizeof(MSStruct) * 1000);



int n_a;
int n_b;
int n_bs;

unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	N   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );

	int x = 0;
	while ( x < N ) {
		A[x].lev = x;
		A[x].c = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
		B[x].lev = x;
		B[x].c = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
		A[x].b_demand = B[x].c;
		x ++;
	}

ms( A, N );
ms( B, N );

int doublekill;
int lame;

int Ans = 0;


int upper;
int lower;
int bisect;

int hit;


int Stars = 0;

	n_a = N;
	n_b = N;
	n_bs = 0;

hit = 0;

	while ( (n_a > 0) || (n_b > 0) || (n_bs > 0) ) {
		//fprintf(stderr, "entered\n");
		if ( (n_b > 0) && ( B[0].c <= Stars ) ) {
//fprintf(stderr, "B level %d ( %d under %d ). doublekill <<\n", B[0].lev, B[0].c, Stars );
			Ans ++;
			Stars ++;
			doublekill = B[0].lev;
			memmove( B, B+1, (n_b - 1)*sizeof(MSStruct) );
			n_b --;
			// clear(A,doublekill);
			x = 0;
			while ( x < n_a ) {
				if ( A[x].lev == doublekill ) {
//fprintf(stderr, "A level %d ( %d under %d ). doublekill\n", A[x].lev, A[x].c, Stars );
					Stars ++;
					memmove( &(A[x]), &(A[x+1]), ((n_a - x) - 1)*sizeof(MSStruct) );
					n_a --;
					break;
				}
				x ++;
			}

			goto End;

		} else if ( (n_bs > 0) && ( Bs[0].c <= Stars ) ) {

//fprintf(stderr, "Bs level %d ( %d under %d )\n", Bs[0].lev, Bs[0].c, Stars );

			Ans ++;
			Stars ++;
			memmove( Bs, Bs+1, (n_bs - 1)*sizeof(MSStruct) );
			n_bs --;
			goto End;


		} else if ( n_a > 0 ) {
			lower = 0;
			upper = n_a;

			while ( lower < upper ) {
				bisect = lower + ((upper-lower)/2);
				if ( A[bisect].c <= Stars ) {
					lower = bisect + 1;
				} else {
					upper = bisect;
				}
			}

			bisect = lower;

			if ( lower == 0 ) {
				break;
			}

			bisect --;

			if ( A[bisect].c > Stars ) {
				fprintf(stderr, "error, n_a %d, bisect %d\n", n_a, bisect);
			}

//fprintf(stderr, "A level %d ( %d under %d )\n", A[bisect].lev, A[bisect].c, Stars );
			lame = A[bisect].lev;
			Ans ++;
			Stars ++;
			memmove( A+bisect, A+1+bisect, ((n_a - 1)-bisect)*sizeof(MSStruct) );
			n_a --;

			x = 0;
			while ( x < n_b ) {
				if ( B[x].lev == lame ) {
					memcpy( & (Bs[n_bs]), & (B[x]), sizeof(MSStruct) );
					n_bs ++;
					ms(Bs, n_bs);
					memmove( &(B[x]), &(B[x+1]), ((n_b - x) - 1)*sizeof(MSStruct) );
					n_b --;

//fprintf(stderr, "Moved B residue lev %d\n", lame );
					break;
				}
				x ++;
			}

			goto End;

		}


hit ++;
if ( hit == 7 ) { break; }

		End:
		1;


	}
//fprintf(stderr, "end\n" );

	if ( (n_a == 0) && (n_b == 0) && (n_bs == 0) ) {
		printf("Case #%u: %d\n", Case_T + 1,   Ans  );
	} else {
		printf("Case #%u: Too Bad\n", Case_T + 1  );
	}

	Case_T ++;
}

return 0;
}
