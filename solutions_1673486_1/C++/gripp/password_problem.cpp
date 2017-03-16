#include <cstdio>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>

#define pb(x) push_back(x)
#define sz() size()
#define f() first
#define s() second
#define b() begin()
#define e() end()

#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
#define fork(n) for(int k=0;k<n;k++)
#define forit(tipo,v) for(tipo::it = (v).begin(); it != (v).end(); it++)

#define trace(x...) 
#define print(x...) trace(printf(x))
#define watch(x) trace(cout << #x" = " << x << "\n")

#define EPS 1e-10

using namespace std ;

int cmp(double a, double b = 0)
{
	        return (a <= b + EPS) ? (a + EPS < b) ? -1 : 0 : 1;
}


#define MAX_A 100010

int main(void)
{
	int cases = 0 ;
	int t, A, B ;
	double pp[MAX_A] ;
	double primeiros, penultimo, ultimo ;
	double expected, optimal ;

	scanf("%d", &t) ;
	while( t-- )
	{
		scanf("%d%d", &A, &B) ;
		fori(A)
		{
			scanf("%lf", &pp[i]) ;
		}
		primeiros = penultimo = ultimo = 1 ;
		fori(A-2)
		{
			primeiros *= pp[i] ;
		}

		ultimo = pp[A-1] ;
		if( A > 1 )
		{
			penultimo = pp[A-2] ;
		}

		watch(A) ;
		watch(B) ;
		// keep
		double p = primeiros * penultimo * ultimo ;
		watch((p * (B - A + 1))) ;
		optimal = (p * (B - A + 1)) + ((1 - p) * (B - A + B + 2)) ;
		watch(optimal) ;

		// one backspace
		p = primeiros * penultimo ;
		expected = p * ultimo * (B-A+1+2) ;
		expected += p * (1-ultimo) * (B-A+1+2) ; 
		expected += (1 - (p * ultimo + p * (1-ultimo))) * (B-A+B+2+2) ;
		watch(expected) ;
		if( cmp(expected, optimal) < 0 )
		{
			optimal = expected ;
		}
		watch(optimal) ;
		
		// two backspace
		p = primeiros ;
		expected = p * penultimo * ultimo * (B-A+1+4) ;
		expected += p * penultimo * (1-ultimo) * (B-A+1+4) ; 
		expected += p * (1-penultimo) * ultimo * (B-A+1+4) ; 
		expected += p * (1-penultimo) * (1-ultimo) * (B-A+1+4) ;
		double acum = p * penultimo * ultimo + p * penultimo * (1-ultimo) + p * (1-penultimo) * ultimo + p * (1-penultimo) * (1-ultimo) ;
		expected += (1 - acum) * (B-A+2+4) ;
		watch(expected) ;
		if( cmp(expected, optimal) < 0 )
		{
			optimal = expected ;
		}
		watch(optimal) ;

		// right way
		expected = B + 2 ;
		watch(expected) ;
		if( cmp(expected, optimal) < 0 )
		{
			optimal = expected ;
		}
		watch(optimal) ;

		printf("Case #%d: %.6lf\n", ++cases, optimal) ;
	}

	return 0 ;
}



