#include <iostream>
#include <vector>

void solve(int k, int c, int s){
	int current = 0;
	std::vector<long long int> answer;
	for(int i=0; i<s && current<k; i++){
		long long int toTest = current;
		current++;
		for(int i=1; i<c; i++){
			toTest=k*toTest+((current<k)?current:0);
			current++;
		}
		answer.push_back(toTest);
	}
	if(current>=k){
		for(size_t i=0; i<answer.size(); i++){
			std::cout << " " << answer[i]+1;
		}
		std::cout << std::endl;
	}else{
		std::cout << " IMPOSSIBLE" << std::endl;
	}
}

int main(){
	int cases;
	std::cin >> cases;
	for(int i=0; i<cases; i++){
		int k, c, s;
		std::cin >> k >> c >> s;
		std::cout << "Case #" << i+1 << ":";
		solve(k, c, s);
	}
	return 0;
}
