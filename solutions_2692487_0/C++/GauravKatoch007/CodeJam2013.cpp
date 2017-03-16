//============================================================================
// Name        : CodeJam2013.cpp
// Author      : Gaurav
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<stdio.h>
#include<algorithm>

#include<vector>
#include<stack>
#include<math.h>
#include<fstream>
#include<string.h>
using namespace std;


int eval(long long A,int start,int N,long long *Arr,int steps){
	int i=start;
	if(A==1)
		return N;
	while(i<N &&  A>Arr[i]){
		A+=Arr[i];
		i++;
		if(A<=Arr[i] && (2*A-1)>Arr[i]){
			A=2*A-1;
			steps++;
		}
	}

	int steps1=steps,steps2=steps;
	if(i<N)
		steps1 = eval(2*A-1,i,N, Arr,steps+1);
	if(i<N)
		steps2 = eval(A,i,N-1,Arr,steps+1);

	return min(steps1,steps2);
}

int main() {

	ofstream file;
	file.open("out.txt");
	int i,j,k,T,N;
	long long A;
	long long Arr[100];
	scanf("%d",&T);

	for(i=0;i<T;i++){
		scanf("%lld %d",&A,&N);
		for(j=0;j<N;j++)
			scanf("%lld",&Arr[j]);
		sort(Arr,Arr+N);
		printf("Case #%d: %d\n",i+1,eval(A,0,N,Arr,0));
		file<<"Case #"<<i+1<<": "<<eval(A,0,N,Arr,0)<<"\n";

	}
}
