#include <cstdio>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
long long n,t,res;
std::string s;
int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin>>t;
	for(int test_nr=1;test_nr<=t;test_nr++){
		std::cin>>s;
		std::vector<char> p,t;
		p.push_back(s[0]);
		for(int i=1;i<s.length();i++){
			if(s[i]<p.back())
				t.push_back(s[i]);
			else
				p.push_back(s[i]);
		}
		
		std::cout<<"Case #"<<test_nr<<": ";
		for(int i=p.size()-1;i>=0;i--)
			std::cout<<p[i];
		for(int i=0;i<t.size();i++)
			std::cout<<t[i];
		std::cout<<std::endl;
		
		
	}
}
