#include <iostream>
#include <vector>

bool all(std::vector<bool> list){
	for(size_t i=0; i<list.size(); i++){
		if(!list[i]){
			return false;
		}
	}
	return true;
}

std::vector<bool> get(){
	std::string s;
	std::getline(std::cin, s);
	std::vector<bool> ret;
	for(size_t i=0; i<s.length(); i++){
		char c = s[i];
		if(c=='+')
			ret.push_back(true);
		else
			ret.push_back(false);
	}

	return ret;
}

int eval(){
	std::vector<bool> stack;
	stack = get();
	int ret=0;
	while(!all(stack)){
		if(!stack[0]){
			int i=0;
			while(!stack[i]){
				stack[i]=true;
				i++;
			}
			ret+=1;
		}else{
			int i=0;
			while(stack[i]){
				i++;
			}
			while(!stack[i]){
				stack[i]=true;
				i++;
			}
			ret+=2;
		}
	}
	return ret;
}

int main(){
	int cases;
	std::cin >> cases;
	std::string s;
	std::getline(std::cin, s); //clear line from input

	for(int i=0; i<cases; i++){
		std::cout << "Case #" << i+1 << ": " << eval() << std::endl;
	}
}

