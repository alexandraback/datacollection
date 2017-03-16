#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>


int recurse(int *motes, int mote_num, int armin, int depth) {
	int i, j, k;

//	if (depth > mote_num)
//		return depth;

	int original_motes[mote_num];
	memcpy(original_motes, motes, mote_num*sizeof(int));

	int change = 1;

	while (change) {

		change = 0;

		for (i = 0; i < mote_num; ++i) {
			if (motes[i] < armin && motes[i] != 0) {
				armin += motes[i];
				motes[i] = 0;
				change = 1;
			}
		}
	}

	for (i = 0; i < mote_num; ++i) {
		if (motes[i] != 0)
			break;
	}

	if (i == mote_num) {
		memcpy(motes, original_motes, mote_num*sizeof(int));
		return 0;
	}

	int best = INT_MAX;

	if (armin > 1) {

		int smallest = INT_MAX;

		for (i = 0; i < mote_num; ++i) {
			if (motes[i] < smallest && motes[i] != 0) {
				smallest = motes[i];
			}
		}

		int new_mote = armin;

		int add = -1;


		while (new_mote <= smallest) {
			++add;
			new_mote += new_mote - 1;
		}

		best = recurse(motes, mote_num, new_mote, depth + 1 + add) + add;
	}

	int largest = INT_MIN;
	int largest_id = -1;

	for (i = 0; i < mote_num; ++i) {
		if (motes[i] == 0)
			continue;

		if (motes[i] > largest) {
			largest = motes[i];
			largest_id = i;
		}
	}

	if (largest_id != -1) {

		int original_mote = motes[largest_id];
		motes[largest_id] = 0;

		int try = recurse(motes, mote_num, armin, depth + 1);

		if (try < best) {
			best = try;
		}

		motes[largest_id] = original_mote;
	}

	memcpy(motes, original_motes, mote_num*sizeof(int));

	return best + 1;
}

int main(int argc, char *argv[]) {

	FILE *f = fopen("1.in", "r");

	int i, j, k, l;

	int t;

	fscanf(f, "%i", &t);

	for (i = 0; i < t; ++i) {
		int a;
		int n;

		fscanf(f, "%i", &a);
		fscanf(f, "%i", &n);

		int motes[n];
		memset(motes, 0, n*sizeof(int));

		for (j = 0; j < n; ++j) {
			fscanf(f, "%i", &(motes[j]));
		}

		int depth = recurse(motes, n, a, 0);

		printf("Case #%i: %i\n", i + 1, depth);
	}


	fclose(f);

	return 0;
}
