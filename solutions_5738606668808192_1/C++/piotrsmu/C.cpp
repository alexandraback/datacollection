#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
long long n,j,t,jamecoin,tmp,res,mn;
long long to_base(int nr,int base){
	res=0;
	mn=1;
	while(nr>0){
		res+=(nr%2)*mn;
		nr/=2;
		mn*=base;
	}
	return res;
}
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin>>t;
	for(int test_nr=1;test_nr<=t;test_nr++){
		std::cin>>n>>j;
		jamecoin=(1<<(n/2-1))+1;
		std::cout<<"Case #"<<test_nr<<":"<<std::endl;
		for(int i=0;i<j;i++){
		std::cout<<to_base(jamecoin,10)<<to_base(jamecoin,10);
		for(int base=2;base<=10;base++){
			std::cout<<" "<<to_base(jamecoin,base);
		}
		std::cout<<std::endl;
		jamecoin+=2;
		}
	}
}
