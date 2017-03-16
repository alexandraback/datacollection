#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
#define pb push_back

int n;
int main(){
	int runs;
	scanf("%d",&runs);
	for(int r = 1; r <= runs; r++){
		scanf("%d",&n);	
		int a[n];
		double sum = 0;
		for( int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
		}
		double G = 2*sum / n, nsum = sum;
		int k = n;
		for( int i = 0; i < n; i++){
			if ( a[i] > G ){
				k--;
				nsum -=a[i];
			}
		}
		double g = ( nsum + sum ) / k;
		
		printf("Case #%d:",r);
		for( int i = 0;  i < n; i++){
			double res = a[i] > G ? 0 : ( g - a[i] ) / sum;
			printf(" %.5lf", res * 100 );
		}
		printf("\n");
	
		

		



	}
	return 0;
}
