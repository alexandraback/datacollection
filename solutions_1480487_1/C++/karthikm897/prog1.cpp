#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int t;
	cin >> t;
	for(int p=0;p<t;p++) {
		int n;
		int arr[501];
		double res[501];
		cin >> n;
		double avg;
		double pts;
		double req;
		long long int sum = 0;
		long long int tmax;
		for ( int i=0;i<n;i++){
			cin>>arr[i];
			sum +=arr[i];
		}
		tmax = 2 * sum;
		avg = (double) tmax / n ;
		int k=0;
		double sub = 0;
		for( int i=0;i<n;i++){
			req = avg - arr[i];
			if(req < 0){
				sub += req;
				res[i] = 0;
				continue;
			}
			res[i] = req;
			k++;
		}
		double isub = sub/k;
		printf("Case #%d:",(p+1));
		for( int i=0; i<n; i++){
			if(res[i] != 0){
				res[i] += isub;
			}
			res[i] = (double)(res[i] * 100)/sum;
			printf(" %.6f",res[i]);
		}
		printf("\n");
	}
}
