#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
long long n,t,k,c,s;

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin>>t;
	for(int test_nr=1;test_nr<=t;test_nr++){
		std::cin>>k>>c>>s;
		if(s*c<k)
			std::cout<<"Case #"<<test_nr<<": "<<"IMPOSSIBLE"<<std::endl;
		else{
			std::cout<<"Case #"<<test_nr<<":";
			long long val=0;
			for(int j=0;j<(k+c-1)/c;j++){
				long long res=0;
				for(int i=0;i<c;i++){
					res*=k;
					res+=val;
					val++;
					if(val>=k)
						val=0;
				}
				std::cout<<" "<<res+1;
			}
			std::cout<<std::endl;
		}
		
	}
}
