#include <assert.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned int uint;


#define UPBOUND  2000001

vector<uint> table(UPBOUND);

inline void process(const uint index,
		const uint lower,
		const uint upper,
		const uint digitnumber)
{
	table[index] = 1;
	uint next = index;
	for (uint i = 1; i < digitnumber; i++) {
		next = (next % lower) * 10 + next / lower;
		if (next > lower && next < upper) {
			if (table[next] == 0) {
				table[next] = index;
				table[index]++;
			}
		}
	}
}

uint calculate (const uint lower, const uint upper, uint A, uint B)
{
	uint 	i;
	vector<uint>	active(table);
	uint	result = 0;
	for (i = lower; i < A; ++i) {
		if (active[i] > 1) {
			if (active[i] < 8) {
				active[i]--;
			} else {
				active[active[i]]--;
			}
		}
	}
	for (i = B + 1; i < upper; ++i) {
		if (active[i] > 1) {
			if (active[i] < 8) {
				active[i]--;
			} else {
				active[active[i]]--;
			}
		}
	}

	for (i = lower; i < upper; ++i) {
		if (active[i] > 1 && active[i] < 8) {
			result += active[i] * (active[i]-1) / 2;
		}
	}
	return result;
}

void init()
{
	uint i;
	for (i = 10; i < 100; ++i) {
		if (table[i] == 0) {
			// new item, process it
			process(i, 10, 100, 2);
		}
	}
	for (i = 100; i < 1000; ++i) {
		if (table[i] == 0) {
			// new item, process it
			process(i, 100, 1000, 3);
		}
	}
	for (i = 1000; i < 10000; ++i) {
		if (table[i] == 0) {
			// new item, process it
			process(i, 1000, 10000, 4);
		}
	}
	for (i = 10000; i < 100000; ++i) {
		if (table[i] == 0) {
			// new item, process it
			process(i, 10000, 100000, 5);
		}
	}
	for (i = 100000; i < 1000000; ++i) {
		if (table[i] == 0) {
			// new item, process it
			process(i, 100000, 1000000, 6);
		}
	}
	for (i = 1000000; i < 2000001; ++i) {
		if (table[i] == 0) {
			// new item, process it
			process(i, 1000000, 2000001, 7);
		}
	}

//	for (i = 100; i < 1000000; ++i) {
//		cout << i << " : " << table[i] << endl;
//	}
//	cout << endl;

}

int main() {
	init();
	int 	T;

	cin >> T;
	assert(T > 0 && T <= 100);

	uint A, B;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		assert(A < 2000000 && A <= B);
		uint result;
		if (A >= 1000000) {
			result = calculate(1000000, 2000000, A, B);
		} else if (A >= 100000) {
			result = calculate(100000, 1000000, A, B);
		} else if (A >= 10000) {
			result = calculate(10000, 100000, A, B);
		} else if (A >= 1000) {
			result = calculate(1000, 10000, A, B);
		} else if (A >= 100) {
			result = calculate(100, 1000, A, B);
		} else if (A >= 10) {
			result = calculate(10, 100, A, B);
		} else {
			result = 0;
		}

		cout << "Case #" << i+1 << ": " << result << endl;
	}

	return 0;
}
