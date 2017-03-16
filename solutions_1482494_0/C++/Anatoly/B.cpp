#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");

const int INF = 1000000000;

struct turn {
	int need;
	int receive;
	int index;
	int priority;
};

bool operator <(const turn &a, const turn &b) {
	return a.need < b.need;
}

struct compare {
	bool operator()(const turn &a, const turn &b) const {
		return a.priority < b.priority;
	}
};

int solve(int N, turn *M) {
	int solved[1000] = { 0 };
	turn stack[2][2 * 1000];
	int count[2] = { 0, 0 };
	int used = 0;
	sort(M, M + 2 * N);

	int stars = 0;
	int turns = 0;
	while (stars < 2 * N && count) {
		// Populate stacks.
		while (used < 2 * N && M[used].need <= stars) {
			int q = M[used].receive - 1;
			stack[q][count[q]] = M[used];
			count[q]++;
			push_heap(stack[q], stack[q] + count[q], compare());
			used++;
		}

		// Remove already solved 1-levels from 2-point stack. Add them to the stack #2.
		while (count[1] > 0 && solved[stack[1][0].index] == 1) {
			count[1]--;
			stack[0][count[0]] = stack[1][0];
			pop_heap(stack[1], stack[1] + count[1] + 1, compare());
			push_heap(stack[0], stack[0] + count[0] + 1, compare());
			count[0]++;
		}

		// Remove already solved both levels from 1-point stack.
		while (count[0] > 0 && solved[stack[0][0].index] == 2) {
			pop_heap(stack[0], stack[0] + count[0], compare());
			count[0]--;
		}
		// Note that we do not need to remove anything from stack #2 with solved 1-st level, but not 2-nd.

		if (count[1] > 0) {
			count[1]--;
			solved[stack[1][0].index] = 2;
			pop_heap(stack[1], stack[1] + count[1] + 1, compare());
			stars += 2;
		}
		else if (count[0] > 0) {
			count[0]--;
			solved[stack[0][0].index] = 1;
			pop_heap(stack[0], stack[0] + count[0] + 1, compare());
			stars++;
		}
		else {
			return -1;
		}

		turns++;
	}


	return turns;
}

int main() {
	int T;
	turn M[2 * 1000];

	fin >> T;
	for (int i = 1; i <= T; i++) {
		int N;
		fin >> N;

		for (int j = 0; j < N; j++) {
			M[j * 2 + 0].index = j;
			fin >> M[j * 2 + 0].need;
			M[j * 2 + 0].receive = 1;
	
			M[j * 2 + 1].index = j;
			fin >> M[j * 2 + 1].need;
			M[j * 2 + 1].receive = 2;

			M[2 * j + 0].priority = M[2 * j + 1].need;
			M[2 * j + 1].priority = INF;
		}

		fout << "Case #" << i << ": ";
		int result = solve(N, M);
		if (result > -1) {
			fout << result;
		}
		else {
			fout << "Too Bad";
		}
		fout << "\n";
	}
}