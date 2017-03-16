#include <iostream>
#include <vector>
#include <algorithm>

#include <stdint.h>

int main() {
    int numcases;
    std::cin >> numcases;
    for (int casenum = 1; casenum <= numcases; ++casenum) {
	int N;
	std::cin >> N;
	std::vector<std::pair<int, int> > ba(N);
	for (int i = 0; i < N; ++i) {
	    std::cin >> ba[i].second >> ba[i].first;
	}

	std::sort(ba.begin(), ba.end(), std::greater<std::pair<int, int> >());

	// goal: skip as many 1-star ratings as possible.

	// if we have a two-star, take it first.  if we have a
	// one-star, take the one with the most expensive
	// two-star.

	std::vector<int> completions(N, 0);

	int moves = 0;
	int points = 0;
	while (points < 2*N) {
	    bool do_continue = false;
	    for (int i = 0; i < N; ++i) {
		if (ba[i].first <= points) {
		    int c = completions[i];
		    if (c < 2) {
			points += 2 - c;
			moves += 1;
			completions[i] = 2;
			do_continue = true;
		    }
		}
	    }
	    if (do_continue) {
		continue;
	    }



	    // aww, no two-stars.
	    for (int i = 0; i < N; ++i) {
		if (ba[i].second <= points && completions[i] == 0) {
		    points += 1;
		    moves += 1;
		    completions[i] = 1;
		    goto found_one_star;
		}
	    }

	    // fff no one stars.
	    goto no_one_star;

	found_one_star:
	    continue;
	}

	std::cout << "Case #" << casenum << ": ";
	std::cout << moves << std::endl;
	continue;

    no_one_star:
	std::cout << "Case #" << casenum << ": ";
	std::cout << "Too Bad" << std::endl;

    }
}
