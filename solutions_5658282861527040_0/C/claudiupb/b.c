#include <stdio.h>
#include <strings.h>
#ifdef D
#define print_line() printf("%d\n",__LINE__)
#define print_int(a) printf("%d\n",a)
#define print_float(a) printf("%.7f\n",a)
#define print_char(a) printf("%c\n",a)
#define print_string(a) printf("%s\n",a)
#else
#define print_line()
#define print_int(a)
#define print_float(a)
#define print_char(a)
#define print_string(a)
#endif
/*
void sort_of (unsinged int *A, unsinged int *B, unsinged int *K)
{
	unsigned int temp;
	if (*B>*A)
	{
		temp=*A;
		*A=*B;
		*B=temp;
	}
	
	if (*K > *B)
		*K=*B;
	if (*K > *A)
		*K= *A;
	
}
unsigned int msb_idx(unsigned  int x); */
int main(){
	int t,T;
	unsigned int A,B,K;
	unsigned int count;

	int i,j;
	scanf("%d\n",&T);
	print_int(T);
	for (t=1;t<=T;t++)
	{
		//ways=1;

		scanf("%d %d %d\n",&A,&B,&K);
		//print_int(t); print_int(A);print_int(B);print_int(K);
		//sort(&A,&B,&K);
		//msb_A=msb_idx(A);
		//msb_B=msb_idx(B);
		//msb_K=msb_idx(K);
		count = 0;
		for (i=0;i<A; i++)
		{
			for (j=0; j<B; j++)
			{
				if ((i & j) < K)
				{
					count++;
//					printf("%d %d %d\n",i,j,t);
				}
			}
		}
		printf("Case #%d: %d\n",t,count);
	}
	
}

/*
unsigned int
ones32(unsigned int x)
{
        x -= ((x >> 1) & 0x55555555);
        x = (((x >> 2) & 0x33333333) + (x & 0x33333333));
        x = (((x >> 4) + x) & 0x0f0f0f0f);
        x += (x >> 8);
        x += (x >> 16);
        return(x & 0x0000003f);
}
unsigned int
msb_idx(unsigned int x)
{
        return(ones((x & -x) - 1));
}
*/