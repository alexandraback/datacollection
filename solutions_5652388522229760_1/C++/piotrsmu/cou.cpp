#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
long long n,t,dif,res,tmp,d;
bool dig[10];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin>>t;
	for(int test_nr=1;test_nr<=t;test_nr++){
		std::cin>>n;
		for(int i=0;i<10;i++){
			dig[i]=false;
		}
		dif=0;
		res=0;
		if(n!=0){
			while(dif<10){
				res+=n;
				tmp=res;
				while(tmp!=0){
					d=tmp%10;
					if(!dig[d]){
						dif++;
						dig[d]=true;
					}
					tmp/=10;
				}
			}
			std::cout<<"Case #"<<test_nr<<": "<<res<<std::endl;
		}else
		std::cout<<"Case #"<<test_nr<<": "<<"INSOMNIA"<<std::endl;
		
		
	}
}
