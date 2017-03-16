#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

long long f(long k,long c,long r){
	long long ret=1;
	long long kk=1;
	for (long i=0;i<c;i++){
		ret=ret+kk*(r+c-1-i);
		kk=kk*k;
		//cout<<kk<<endl;
	}
	return ret; 
}

int main(){
	int Test,cnt;
	ifstream in("D-small-attempt1.in");
	ofstream out("D-small-attempt1.out");
	in>>Test;
	for (cnt=1;cnt<=Test;cnt++){
		long k,c,s;
		in>>k;
		in>>c;
		in>>s;
		if (s<ceil((double)k/c)){
			out<<"Case #"<<cnt<<": IMPOSSIBLE"<<endl;
			continue;
		}
		out<<"Case #"<<cnt<<": ";
		for (int i=0;i<ceil((double)k/c)-1;i++){
			out<<f(k,c,i*c)<<" ";
		}
		if (c<k)
			out<<f(k,c,k-c)<<endl;
		else
			out<<f(k,k,0)<<endl;
	}
}
