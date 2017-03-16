#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define for2(x, n) for(unsigned x = 0; x < n; ++x)

using namespace std;

int T, C, D, V, res;

bool sum_up_recursive(vector<int> numbers, int target, vector<int> partial) {
	int s = 0;
	for2 (x, partial.size()) s += partial[x];
	if(s == target){
		return true;
	}
	if (s > target)
		return false;
	for(int i = 0; i < numbers.size(); i++) {
		vector<int> remaining;
		int n = numbers[i];
		for (int j = i + 1; j < numbers.size(); j++) remaining.push_back(numbers[j]);
		vector<int> partial_rec(partial);
		partial_rec.push_back(n);
		if(sum_up_recursive(remaining,target,partial_rec)){
			return true;
		}
	}
	return false;
}


bool sum_up(vector<int> numbers, int target) {
	vector<int> v;
	return sum_up_recursive(numbers, target, v);
}

int check_all(vector<int> d){
	int res = 0;

	for2(x, V){
		if(!sum_up(d, x + 1)){
			d.push_back(x + 1);
			res++;
		}
	}

	return res;
}

int main(){
	vector<int> d;

	scanf("%d", &T);

	for2(x, T){
		res = 0;
		d.clear();
		scanf("%d %d %d", &C, &D, &V);

		for2(y, D){
			int aux;
			scanf("%d", &aux);
			d.push_back(aux);
		}

		res = check_all(d);

		printf("Case #%d: %d\n", x + 1, res);
	}

	return 0;
}
