#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MALLOC_FAIL abort()

/**
 * Fraction data-structure:
 * f = numerator / denominator
 */
typedef struct s_fraction {
	long int numerator;
	long int denominator;
} Fraction;

long int util_gcd(long int num1, long int num2);
Fraction *fraction_new(long int numerator, long int denominator);
void fraction_delete(Fraction *f);
void fraction_reduce(Fraction *f);

/**
 * Calculates the greatest common divisor.
 * @param num1
 * @param num2
 * @return GCD
 */
long int util_gcd(long int num1, long int num2)
{
	long int tmp;
	num1 = fabs(num1);
	num2 = fabs(num2);
	while (num1 > 0) {
		tmp = num1;
		num1 = num2 % num1;
		num2 = tmp;
	}
	return num2;
}

/**
 * Allocates memory for a fraction structure .
 * Initialize fraction structure .
 * @param numerator
 * @param denominator
 * @return A pointer to the fraction structure on heap . (memmory should
 be de-allocated manually)
 */
Fraction *fraction_new(long int numerator, long int denominator)
{
	Fraction *f = NULL;
	if (!denominator) {
		fprintf(stderr, "Invalid fraction. Denominator cannot be 0 (zero).n");
		return (f);
	}
	f = (Fraction*)malloc(sizeof(Fraction));
	if (!f) {
		MALLOC_FAIL;
	}
	f->numerator = numerator;
	f->denominator = denominator;
	return (f);
}

/**
 * De-allocates the memory associated with a given fraction .
 * @param f The fraction to be free'd .
 */
void fraction_delete(Fraction *f)
{
	if (f) {
		free(f);
	}
}

/**
 * Reduce a fraction to the lowest terms
 * @param f The fraction to be reduced .
 */
void fraction_reduce(Fraction *f)
{
	long int gcd;
	gcd = util_gcd(f->numerator, f->denominator);
	f->numerator /= gcd;
	f->denominator /= gcd;
}



//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//////////////////////////////////////////////////

int main(){
    int i, num_cases;
    long int p, q;
    
    scanf("%d", &num_cases);
    
    for(i=1; i <= num_cases; ++i){
        scanf("%ld/%ld", &p, &q);
        Fraction *f = fraction_new(p, q);
        fraction_reduce(f);
        p = f->numerator;
        q = f->denominator;
        int j;
        for(j = 1; j <= 40; j++){
            long int mypow = pow(2, j);
            if(mypow % q == 0){
                int aux = 0;
                while(p > 1){
                    p = p / 2;
                    aux++;
                }
                if(j-aux > 1){
                    printf("Case #%d: %d\n", i, j-aux);
                }else{
                    printf("Case #%d: %d\n", i, 1);
                }
                break;
            }
        }
        if(j > 40){
            printf("Case #%d: impossible\n", i);
        }

    }
    return 0;
}
