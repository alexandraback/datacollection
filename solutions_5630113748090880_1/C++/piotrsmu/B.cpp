#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
long long n,t,res,tmp;
int height[2501];
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin>>t;
	for(int test_nr=1;test_nr<=t;test_nr++){
		std::cin>>n;
		for(int i=0;i<n*2-1;i++){
			for(int j=0;j<n;j++){
				std::cin>>tmp;
				height[tmp]++;
			}
		}
	
		std::cout<<"Case #"<<test_nr<<":";
		for(int i=0;i<=2500;i++){
			if(height[i]%2){
				std::cout<<" "<<i;
				height[i]=0;
			}
		}
		std::cout<<std::endl;
		
		
	}
}
