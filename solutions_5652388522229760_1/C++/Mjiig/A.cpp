#include <iostream>

bool all(bool b[]){
	for(int i=0; i<10; i++){
		if(!b[i]){
			return false;
		}
	}
	return true;
}

int eval(int in){
	bool b[10]={0};
	int current=0;
	while(!all(b)){
		current+=in;
		int copy=current;
		while(copy!=0){
			b[copy%10]=true;
			copy/=10;
		}

	}
	return current;
}

int main(){
	int cases;
	std::cin >> cases;
	for(int i=0; i<cases; i++){
		int n;
		std::cin >> n;
		if(n==0){
			std::cout << "Case #" << i+1 << ": INSOMNIA" << std::endl;
			continue;
		}
		std::cout << "Case #" << i+1 << ": " << eval(n) << std::endl;	
	}
	return 0;
}

