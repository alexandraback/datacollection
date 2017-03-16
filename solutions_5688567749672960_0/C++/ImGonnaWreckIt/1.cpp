#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int rev(int N){
	int M=0;
	while(N > 0){
		M = M*10 + N%10;
		N = N/10;
	}
	return M;
}

int numDig(int N){
	int cnt = 0;
	while(N>0){
		cnt++;
		N = N/10;
	}
	return cnt;
}

int main(){
	int i,j,k,l;
	int N,T;
	int *A;
	cin>>T;
	for(l = 0 ; l < T ; l++){
		cin>>N;
		A = new int[N+1];
		for(i = 1 ; i <= min(N,9) ; i++)
			A[i] = i;
		for(i = 10 ; i <= N ; i++){
			A[i] = A[i-1]+1;
			int temp = rev(i);
			if(numDig(temp) == numDig(i) && temp < i)
				A[i] = min(A[i], A[temp]+1);
		}
		cout<<"Case #"<<l+1<<": "<<A[N]<<"\n";
		delete A;
	}
	return 0;
}