#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int i,j,k,l;
	int N,T;
	long long *D, *M, *H;
	long long *ti, *di;
	double first[2];
	double second[2];
	cin>>T;
	for(l = 0 ; l < T ; l++){
		cin>>N;
		cout<<"Case #"<<l+1<<": ";
		D = new long long[N];
		M = new long long[N];
		H = new long long[N];
		for(i = 0 ; i < N ; i++)
			cin>>D[i]>>H[i]>>M[i];
		long long count = 0;
		for(i = 0 ; i < N; i++)
			count += H[i];
		if(count < 2){
			cout<<"0\n";
			continue;
		}
		ti = new long long[2];
		di = new long long[2];
		ti[0]=M[0];
		di[0] = D[0];
		if(H[0] == 2){
			ti[1] = M[0] +1;
			di[1] = D[0];
		}
		else{
			ti[1] = M[1];
			di[1] = D[1];
		}
		first[0] = (double)(360 - di[0])*((double)ti[0]/360.0);
		first[1] = first[0] + M[0];

		second[0] = (double)(360 - di[1])*((double)ti[1]/360.0);
		second[1] = second[0] + M[1];

		if(first[0] >= second[1] || first[1] <= second[0])
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}