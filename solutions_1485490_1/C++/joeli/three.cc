#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct Set {
	long long number;
	int type;
};

map<pair<long long, long long>, long long> memo[102][102];

long long opt(const vector<Set>& boxes, const vector<Set>&toys, 
              const int boxset, const int toyset, const long long takenboxes, const long long takentoys, int nbr_boxes, int nbr_toys) {
	if (boxset >= nbr_boxes ||
	    toyset >= nbr_toys) return 0;

	if (memo[boxset][toyset].find(make_pair(takenboxes,takentoys)) != memo[boxset][toyset].end()) {
		return memo[boxset][toyset][make_pair(takenboxes,takentoys)];
	}

	if (boxes[boxset].type != toys[toyset].type) {

		long long result = max(opt(boxes,toys,boxset+1, toyset, 0, takentoys, nbr_boxes, nbr_toys),
		                       opt(boxes,toys,boxset,toyset+1, takenboxes, 0, nbr_boxes, nbr_toys));
		memo[boxset][toyset][make_pair(takenboxes,takentoys)] = result;
		return result;
	}
	else {

		long long boxes_left = boxes[boxset].number-takenboxes;
		long long toys_left = toys[toyset].number-takentoys;

		long long result;

		if (boxes_left == toys_left) {
			result = boxes_left + opt(boxes, toys, boxset+1, toyset+1, 0, 0, nbr_boxes, nbr_toys);
		}
		else if (boxes_left < toys_left) {
			result = boxes_left + opt(boxes, toys, boxset+1, toyset, 0, takentoys+boxes_left, nbr_boxes, nbr_toys);
		}
		else {
			result = toys_left + opt(boxes, toys, boxset, toyset+1, takenboxes+toys_left, 0, nbr_boxes, nbr_toys);
		}
		memo[boxset][toyset][make_pair(takenboxes,takentoys)] = result;
		return result;
	}
}

void handle_case(int case_nbr) {
	cout << "Case #" << case_nbr << ": ";

	int N,M;

	cin >> N >> M;

	vector<Set> boxes(N);
	vector<Set> toys(M);

	for (int i = 0; i < N; i++) {
		cin >> boxes[i].number >> boxes[i].type;
	}

	for (int i = 0; i < M; i++) {
		cin >> toys[i].number >> toys[i].type;
	}

	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 102; j++) {
			memo[i][j].clear();
		}
	}

	cout << opt(boxes, toys, 0,0,0,0, N, M) << endl;
}

int main(void) {

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		handle_case(i+1);
	}

	return 0;
}
