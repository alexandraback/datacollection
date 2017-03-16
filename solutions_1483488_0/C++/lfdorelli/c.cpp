#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#include <set>


using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;

#define F first
#define S second
#define pb push_back
#define mp make_pair

int main (void)
{
	int pot[12];

	pot[0] = 1;
	for(int i = 1; i <= 11; i++)
		pot[i] = pot[i-1] * 10;

	set< pair<int, int> > S; 

	int A, B;
	int t;

	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++) {
		S.clear();

		scanf("%d %d", &A, &B);

		printf("Case #%d: ", caso);
		for(int i = A; i <= B; i++) {
		
			int D = log10(A) + 1;

			for(int x = 1; x < D; x++) {
				int out = 0;
				int res = i;
				for(int t = 0; t < x; t++) {
					out += (res%10) * pot[t];
					res /= 10;
				}

				res += out  * pot[D-x];
				
				if(res >= A && res <= B && res != i) {
					S.insert( mp(i, res));
					S.insert( mp(res, i));
				}
			}
		}
		printf("%d\n", (int) S.size()/2);
	}
	return 0;
}
