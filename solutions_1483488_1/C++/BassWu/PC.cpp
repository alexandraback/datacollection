#include<stdio.h>
#include<set>
using namespace std;

int main()
{
	int N;
	int A, B;
	int T;
	scanf("%d", &T);
	for ( int t = 1 ; t <= T ; t++ ) {
		scanf("%d%d", &A, &B);
		int P, p;
		for ( P = 1 , p = 0 ; A/P != 0 ; P*=10 , p++ ) ; 
		P/=10;
		int count = 0;
		for ( int N = A ; N <= B ; N++ ) {
			int M = N;
			set<int> S;
			for ( int i = 0 ; i < p ; i++ ) {
				if ( N < M && M <= B ) {
					if ( S.find(M) != S.end() )	continue;
					count++;
					S.insert(M);
				}
				M = (M%P)*10+(M/P);
			}
		}
		printf("Case #%d: %d\n", t, count);
	}
	return 0;
}
