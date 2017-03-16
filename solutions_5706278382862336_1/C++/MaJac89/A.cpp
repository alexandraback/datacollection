#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long find_elf(long num, long den, long gen);

int main(int argc, char** argv){
	long T;
	cin>>T;

	for(long i=0; i<T; i++){
		long P, Q;
		char slash;
		cin>>P>>slash>>Q;
		
		cout<<"Case #"<<i+1<<": ";
		long sol = find_elf(P,Q,1);
		if(sol>-1)
			cout<<sol<<"\n";
		else
			cout<<"impossible\n";
	}
	
	return 0;

}

long find_elf(long num, long den, long gen){
	if(den%2)
		return -1;

	den /= 2;

	if((double)num/den>=1.0 || gen>40){
		num-=den;
		if(num>0 && find_elf(num,den,gen)<0)
			return -1;
		return gen;
	}else if(den>1){
		return find_elf(num,den,gen+1);
	}
}
