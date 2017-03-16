#include <iostream>
#include <string>

int main(){
	int T;
	std::cin >> T;
	for(int t=1; t<=T; ++t){
		std::string s,r;
		std::cin >> s;
		std::cout << "Case #" << t << ": ";
		char m=s[0];
		for(int i=0; i<s.size(); ++i)
			if(s[i]>=m){
				m=s[i];
				r=s[i]+r;
			} else
				r+=s[i];
		std::cout << r << '\n';
	}
}
