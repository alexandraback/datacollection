#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <inttypes.h>

#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19

#define STRINGIZER(x)   # x
#define TO_STRING(x)    STRINGIZER(x)
int success = 0;
int x,y;
__uint128_t getbase(char *tmp,int base)
{
	__uint128_t ret = 0;
	while(*tmp != '\0')
	{
		ret = ret * base;
		if(*tmp == '1')
		{
			ret += 1;
		}
		tmp++;
	}
	return ret;
}
char* int2binstr(__uint128_t num, char *s, size_t size)
{
    s[size-1] = '\0';
    s += size-2;
    while(num)
    {
    	*s = (num & 1) ? '1' : '0';
    	s--;
    	num>>=1;
    }
	return ++s;
}
int isPrime(__uint128_t number) {
    if (number <= 1) return 0; // zero and one are not prime
    if(number%2==0)
    {
    	return 2;
    }
    __uint128_t i;
    for (i=3; i*i<=number&&i<1000; i=i+2) {
        if (number % i == 0) return i;
    }
    return 0;
}
static int print_u128_u(__uint128_t u128)
{
    int rc;
    if (u128 > UINT64_MAX)
    {
        __uint128_t leading  = u128 / P10_UINT64;
        __uint64_t  trailing = u128 % P10_UINT64;
        rc = print_u128_u(leading);
        rc += printf("%." TO_STRING(E10_UINT64) PRIu64, trailing);
    }
    else
    {
        __uint64_t u64 = u128;
        rc = printf("%" PRIu64, u64);
    }
    return rc;
}
void main()
{
	int cases;
	int print;
	char *str = (char *)malloc(sizeof(char)*34);
	scanf("%d",&cases);
	int n = 0;
	__uint128_t num;
	
	char * bin;
	__uint128_t b2,b3,b4,b5,b6,b7,b8,b9,b10;
	while(n<cases)
	{
		n++;
		printf("Case #%d:\n",n);
		scanf("%d%d",&x,&y);
		num = pow(2,x-1)+1;
		while(y)
		{
			//printf("%lld",num);
			//if(x==16)
			//{
				while(1)
				{
					bin = (char *)int2binstr(num,str,34);
					b2=isPrime(num);b3=isPrime(getbase(bin,3));b4=isPrime(getbase(bin,4));b5=isPrime(getbase(bin,5));b6=isPrime(getbase(bin,6));b7=isPrime(getbase(bin,7));b8=isPrime(getbase(bin,8));b9=isPrime(getbase(bin,9));b10=isPrime(getbase(bin,10));
					if(b2&&b3&&b4&&b5&&b6&&b7&&b8&&b9&&b10)
					{
						//printf("%s %lld %lld %lld %lld %lld %lld %lld %lld %lld\n",bin,b2,b3,b4,b5,b6,b7,b8,b9,b10);
						printf("%s ",bin);
						print = print_u128_u(b2);
						printf(" ");
						print = print_u128_u(b3);
						printf(" ");
						print = print_u128_u(b4);
						printf(" ");
						print = print_u128_u(b5);
						printf(" ");
						print = print_u128_u(b6);
						printf(" ");
						print = print_u128_u(b7);
						printf(" ");
						print = print_u128_u(b8);
						printf(" ");
						print = print_u128_u(b9);
						printf(" ");
						print = print_u128_u(b10);
						printf("\n");
						y--;
						num+=2;
						break;
					}
					num+=2;
				}
			//}
			//else if(x == 32)
			//{
				
			//}
		}
	}
	/*scanf("%lld%lld",&x,&y);
	num = 33;
	printf("%lld\n",num);
	bin = int2binstr(num, str, 34);	
	b2=num;b3=getbase(bin,3);b4=getbase(bin,4);b5=getbase(bin,5);b6=getbase(bin,6);b7=getbase(bin,7);b8=getbase(bin,8);b9=getbase(bin,9);b10=getbase(bin,10);
	printf("%s %lld %lld %lld %lld %lld %lld %lld %lld %lld\n",bin,b2,b3,b4,b5,b6,b7,b8,b9,b10);
	b2=isPrime(num);b3=isPrime(getbase(bin,3));b4=isPrime(getbase(bin,4));b5=isPrime(getbase(bin,5));b6=isPrime(getbase(bin,6));b7=isPrime(getbase(bin,7));b8=isPrime(getbase(bin,8));b9=isPrime(getbase(bin,9));b10=isPrime(getbase(bin,10));
	printf("%s %lld %lld %lld %lld %lld %lld %lld %lld %lld\n",bin,b2,b3,b4,b5,b6,b7,b8,b9,b10);*/
}
