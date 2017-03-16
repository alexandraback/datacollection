#include <iostream>
#include <vector>

unsigned long long T;
bool iscons(char c){
	return (c!='a' && c!='e' && c!='i' && c!='o' && c!= 'u');
}

int main(){
	std::cin >> T;
	for(unsigned long long p=0; p<T; ++p){
		unsigned long long n;
		std::string s;
		std::cin >> s >> n;
		
		std::vector<unsigned long long> pos;
		unsigned long long cnt = 0;
		for(unsigned long long i=0; i<s.size(); ++i){
			if(iscons(s[i])) ++cnt;
			else cnt = 0;
			
			if(cnt >= n){
				pos.push_back(i);
			}
		}
		
		unsigned long long j=0;
		unsigned long long total = 0;
		for(unsigned long long i=0; i<s.size(); ++i){
			if(j<pos.size() && pos[j]-n+1<i) ++j;
			if(j<pos.size()){
				total+=(s.size()-pos[j]);
			}
		}
		std::cout << "Case #" << (p+1) << ": " << total << std::endl;
	}
}