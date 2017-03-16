#include <iostream>
#include <vector>

int T;
bool iscons(char c){
	return (c!='a' && c!='e' && c!='i' && c!='o' && c!= 'u');
}

int main(){
	std::cin >> T;
	for(int p=0; p<T; ++p){
		int n;
		std::string s;
		std::cin >> s >> n;
		
		std::vector<int> pos;
		int cnt = 0;
		for(int i=0; i<s.size(); ++i){
			if(iscons(s[i])) ++cnt;
			else cnt = 0;
			
			if(cnt >= n){
				pos.push_back(i);
			}
		}
		
		int j=0;
		long long total = 0;
		for(int i=0; i<s.size(); ++i){
			if(j<pos.size() && pos[j]-n+1<i) ++j;
			if(j<pos.size()){
				total+=(s.size()-pos[j]);
			}
		}
		std::cout << "Case #" << (p+1) << ": " << total << std::endl;
	}
}