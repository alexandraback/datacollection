#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long int uint64;
#define MAXN 260

int N;
int n[ MAXN ];

int main() {
	int cases;		// number of cases
	int caseID = 1;	// case ID, start from 1

	// freopen("input", "r", stdin);
	//freopen("output", "w", stdout);
	scanf("%d", &cases);
	while (cases--) {
		int sum = 0;
		int sum2 = 0;
		double avg = 0;

		scanf("%d", &N);
		for( int i = 0;i < N; i++ ){
			scanf("%d", &n[i]);
			sum += n[i];
		}
		sum2 = sum * 2;


		double n1 = (double)(sum2) / (double)(N);

		int afterN = N;
		for( int i = 0;i < N; i++ ){
			if( (double)n[i] > n1 ){
				sum2 -= n[i];
				afterN--;
			}
		}

		avg = (double)(sum2) / (double)(afterN);

		//printf("%d %lf\n", afterN, avg);

		printf("Case #%d: ", caseID++);
		for( int i = 0;i < N; i++ ){
			if(i)printf(" ");


			double ansi = 100 * (avg - (double)(n[i])) / (double)sum;
			//printf("%d %lf %d %d\n: ", n[i], avg, sum, afterN);
			printf("%.8lf ", (ansi < 0) ? 0 : ansi);
		}
		printf("\n");
	}
	return 0;
}
