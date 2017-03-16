#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

double p[100013];
double acum[100013];

int main(){
   int runs;
   scanf("%d",&runs);
   int A, B;   
   for(int r = 1; r <= runs; r++){
		scanf("%d %d", &A, &B );
		for( int i = 1; i <= A; i++) cin>>p[i];
		acum[0] = 1.0;
		for( int i = 1; i <= A; i++ ) acum[i] = acum[i-1] * p[i];
		double res = 1e25;
		for( int der = 0, izq = A, q = B - A ; izq >= 0; q++, der++, izq-- ){
			double tmp = acum[ izq ] * ( q + der + 1 ) + (1.0 - acum[ izq ])*(q + 1 + der + B + 1);
			res = min( res, tmp );
		}
		res = min( res ,0.0 + B + 1 + 1 );
		printf("Case #%d: %.6lf\n",r,res);
   }
   return 0;
}

