#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

#define INTMAX 0x7FFFFFFF
#define LONGMAX 0x7FFFFFFFFFFFFFFF

long long reverse(long long n){
	long long r=0;
	while(n!=0){
		long long h=n%((long long)10);
		n=n/((long long)10);
		r = ((long long)10)*r;
		r = r+h;
	}
	return r;
}

long long solve(long long n){
	if(n<=20)
		return n;
	int dig=0;
	long long test = 1;
	while(n>=test){
		dig++;
		test = ((long long)10)*test;
	}
	//printf("%i -1 ",n);
	dig=dig-dig/2;
	long long mod =1; 
	for(int i=0; i<dig; i++)
		mod = ((long long)10)*mod;
	//printf("%i -2 ",n);
	long long r = n%mod;
	long long m = n-r;
	//printf("%i -3 ",n);
	if(r==0)
		return (solve(n-1)+1);
	if(reverse(m+1)<m+1)
		return (solve(reverse(m+1))+r);
	return (solve(m-1)+r+1);
}

int main(){
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		long long N;
		cin>>N;
		//printf("#");
		cout<<"Case #"<<i<<": "<<solve(N);
		if(i!=T)
			cout<<"\n";
	}
}