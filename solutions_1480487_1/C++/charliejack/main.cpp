#include <cstring>
#include <iostream>

using namespace std;


int iPoint[200];
double fAnswer[200];
int N;

void solver()
{
	int sum = 0;
	int sum2 = 0;
	double average;

	for( int i=0; i<N; i++ ){
		cin >> iPoint[i];
		sum += iPoint[i];

	}
	sum2 = sum * 2;
	
	double fWaterFilling = (double)(sum2) / (double)(N);

	int afterN = N;
	for( int i = 0;i < N; i++ ){
		if( (double)iPoint[i] > fWaterFilling ){
			sum2 -= iPoint[i];
			afterN--;
		}
	}

	average = (double)(sum2) / (double)(afterN);

	for( int i = 0;i < N; i++ ){
		if( i > 0 )printf(" ");

		double ansi = 100 * (average - (double)(iPoint[i])) / (double)sum;
		printf("%.8lf ", (ansi < 0) ? 0 : ansi);
	}
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int nQuestion;
	cin >> nQuestion;

	for( int i=1; i<=nQuestion; i++ ){
		cin >> N;

		printf("Case #%u: ", i);
		solver();
		printf("\n");
	}

	fclose (stdout);
}