#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int war(std::vector<double> &first, std::vector<double> &second){
	std::list<double> qu(first.begin(), first.end());
	int score = 0;
	for(std::vector<double>::const_iterator iter = second.begin(); iter != second.end(); iter++){
		double ele = *iter;
		if (ele > qu.front())
			qu.pop_front();
		else{
			score++;
			qu.pop_back();
		}
	}
	return score;
}

void func(const int cas){
	int N;
	std::vector<double> arr[2];

	std::cin >> N;
	for(int i = 0; i < 2; i++){
		double t;
		for(int j = 0; j < N; j++){
			std::cin >> t;
			arr[i].push_back(t);
		}
		std::sort(arr[i].begin(), arr[i].end());
	}

	std::cout << "Case #" << cas << ": "
		<< (N - war(arr[1], arr[0])) << " "
		<< war(arr[0], arr[1]) << std::endl;
}

int main(){
	int T;
	std::cin >> T;
	for(int cas = 1; cas <= T; cas++)
		func(cas);
	return 0;
}