#include <iostream>
#include <string>

void solve(int n){
	int SM;
	std::string str;
	std::cin >> SM;
	std::cin >> str;
	int k = 0;
	int a = 0;
	for(int i=0; i<str.size(); ++i){
		a = std::max(a, i-k);
		k+=str[i]-'0';
	}
	std::cout << "Case #" << n << ": " << a << std::endl;
}

int main(){
	int T;
	std::cin >> T;
	int n = 1;
	while(T--) solve(n), ++n;
}