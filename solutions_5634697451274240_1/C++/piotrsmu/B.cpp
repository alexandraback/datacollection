#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
long long t,res;
std::string s;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin>>t;
	for(int test_nr=1;test_nr<=t;test_nr++){
		std::cin>>s;
		s.append("+");
		res=0;
		for(int i=0;i<s.size()-1;i++){
			if(s[i]!=s[i+1])
			res++;
		}
		std::cout<<"Case #"<<test_nr<<": "<<res<<std::endl;
		
		
	}
}
