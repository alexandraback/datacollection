#include <iostream>
#include <fstream>
using namespace std;

long long f(long long t, long long r){
	long long test = 1 ,mid;
	while(test*(2*test+2*r-1) <= t){
		test*=2;
	}
	long long hi = test;
	long long lo = test/2-1;
	while(lo<hi){
		mid = (lo+hi)/2;
		if(mid*(2*mid+2*r-1)<t){
			lo = mid+1;
		}else{
			hi = mid-1;
		}
	}
	while(!(lo*(2*lo+2*r-1)<=t && (lo+1)*(2*(lo+1)+2*r-1)>t)){
		if(lo*(2*lo+2*r-1)>t){
			lo--;
		}else if((lo+1)*(2*(lo+1)+2*r-1)<=t){
			lo++;
		}
	}
	return lo;
}


int main(){
	ifstream fin;
	ofstream fout;

	fin.open("A-large.in");
	fout.open("ALoutput.txt");

	int T;
	fin >> T;
	for(int n =1 ; n<=T ;n++){
		long long r ,t;
		fin >> r >> t;
		long long ans = f(t,r);
		
		fout << "Case #" << n << ": " << ans << endl;
	}

	fin.close();
	fout.close();
}