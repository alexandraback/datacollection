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

using namespace std;

typedef long long int LL;
typedef pair<int,int> pii;

#define F first
#define S second
#define pb push_back
#define mp make_pair

int main (void)
{
	int n;
	scanf("%d", &n);

	int contestants[201];
	for(int t = 0; t < n; t++) 
	{
		int c;
		scanf("%d", &c);
		int sum = 0;
		for(int i = 0; i < c; i++)  {
			scanf("%d", &contestants[i]);
			sum += contestants[i];
		}

		int C = 0;
		double S = (double) 2.0*sum/c;
		double SS = sum;
		for(int i = 0; i < c; i++)  {
			if( contestants[i] - S < 0.000001) {
			 	SS += contestants[i];
			 	C++;
			}
		}
		
		S = (double) (SS)/C;
			
		printf("Case #%d: ", t+1);
		for(int i = 0; i < c; i++) {
			double Y_i = S;
			Y_i -= contestants[i];
			Y_i = (double) Y_i/sum;			
			Y_i = max(0.0, Y_i);
			printf("%.6lf", 100.0 * Y_i);
			if(i != c-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
