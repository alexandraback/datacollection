#include <string>
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

main()
{
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i++) {
		int num_ct, num_has_vote;
		double sum_pt, avg_sc, perc, fn_sc, fn_pool;
		int j;
		scanf("%d", &num_ct);

		sum_pt = 0;
		int *pts = new int[num_ct];
		for (j = 0; j < num_ct; j++) {
			scanf("%d", &pts[j]);
			sum_pt += pts[j];
		}
		avg_sc = sum_pt * 2 / num_ct;
		num_has_vote = 0;
		fn_pool = 0;
		bool *has_vote = new bool[num_ct];
		for (j = 0; j < num_ct; j++) {
			if ((avg_sc - pts[j]) > 0) {
				fn_pool += pts[j] *2;
				has_vote[j] = true;
				num_has_vote++;
			} else {
				fn_pool += pts[j];
				has_vote[j] = false;
			}

		}
		fn_sc = fn_pool / num_has_vote;
		
		cout << "Case #" << i << ": ";
		cout.precision(10);
		for (j = 0; j < num_ct; j++) {
			if(has_vote[j]) {
				perc = (fn_sc - pts[j])* 100 / (sum_pt);
				cout << perc << " ";
			} else {
				cout << "0.0 ";
			}
		}

		cout << endl;
		delete[] pts;
	}


}

