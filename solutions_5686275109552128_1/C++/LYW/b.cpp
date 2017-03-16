#include <cstdio>
#include <vector>
using namespace std;

int main(void) {
	int num_test;
	scanf("%d", &num_test);
	for (int testcase = 1; testcase <= num_test; ++testcase) {
		int num_diner;
		int answer = 0;
		vector <int> pancakes;
		scanf("%d", &num_diner);
		for (int i = 0; i < num_diner; ++i) {
			int num_pancakes;
			scanf("%d", &num_pancakes);
			pancakes.push_back(num_pancakes);
			answer = max(answer, num_pancakes);
		}

		for (int i = 1; i <= answer; ++i) {
			int count = 0;
			for (int j = 0; j < num_diner; ++j) {
				count += (pancakes[j] - 1) / i;
			}
			answer = min(answer, i + count); 
		}

		printf("Case #%d: %d\n", testcase, answer);
	}
	return 0;
}


