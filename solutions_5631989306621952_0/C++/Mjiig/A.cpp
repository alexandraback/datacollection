#include <iostream>
#include <vector>

int getWorst(std::string s){
	int ret=0;
	for(size_t i=0; i<s.length(); i++){
		if(s[i]>=s[ret]){
			ret = i;
		}
	}
	return ret;
}

std::string process(std::string s){
	std::string output="";
	if(!s.empty()){
		int worst = getWorst(s);
		output += s[worst];
		output += process(s.substr(0, worst));
		output += s.substr(worst+1);
	}
	return output; 
}

int main(){
	int cases;
	std::cin >> cases;
	std::string s;
	std::getline(std::cin, s);

	for(int i=0; i<cases; i++){
		std::string input;
		std::getline(std::cin, input);
		std::cout << "Case #" << i+1 << ": " << process(input) << std::endl;
	}

	return 0;
}
