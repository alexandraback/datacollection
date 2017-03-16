#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

typedef long long lnt ;

const int SIZE_A = 1000000 + 10 ;
const lnt MAX = 1000000000000000LL + 10 ;

FILE *in , *out ;

int T ;
std::vector< lnt > ans ;

int bs(int le , int ri , lnt tar)
{
	if(tar == 0) return 0 ;
	while(le < ri)
	{
		int mi = (le + ri + 1 >> 1) ;
		lnt val = ans[mi] ;
		if(val < tar) le = mi ;
		if(val == tar) return mi + 1 ;
		if(val > tar) ri = mi - 1 ;
	}
	return le + 1 ;
}

int bs1(int le , int ri , lnt tar)
{
	if(tar == 0) return 0 ;
	for(int i = le ; i <= ri ; ++i)
	{
		if(ans[i] > tar) return i ;
	}
	return 0 ;
}

int isPal(lnt n)
{
	int len = 0 ;
	char str[20] ;
	
	for( ; n != 0 ; n /= 10 , ++len)
		str[len] = n % 10 ;
	
	for(int i = 0 ; i <= len - 1 - i ; ++i)
		if(str[i] != str[len - 1 - i]) return 0 ;
	
	return 1 ;
}

void clear(void)
{
}

int main(void)
{
	for(lnt i = 1 ; i * i <= MAX ; ++i)
	{
		if(isPal(i) == 1 && isPal(i * i) == 1)
		{
			ans.push_back(i * i) ;
		}
	}
	
	printf("%d\n" , ans.size()) ;
	for(int i = 0 ; i < ans.size() ; ++i)
		printf("%2d %I64d\n" , i , ans[i]) ;
	
	//in = fopen("c.in" , "r") ;
	in = fopen("C-large-1.in" , "r") ;
	out = fopen("c.out" , "w") ;
	
	fscanf(in , "%d" , &T) ;
	for(int count = 1 ; count <= T ; ++count , clear())
	{
		lnt a , b ;
		fscanf(in , "%I64d%I64d" , &a , &b) ;
		--a ;
		
		int na = bs1(0 , ans.size() - 1 , a) ;
		int nb = bs1(0 , ans.size() - 1 , b) ;
		
		fprintf(out , "Case #%d: %d\n" , count , nb - na) ;
	}
	
	return 0 ;
}

