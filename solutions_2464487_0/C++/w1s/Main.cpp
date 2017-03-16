#include <string>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <functional>
#include <algorithm>
#include <numeric>
#include <vector>

#define INT(i) int i; { string line; getline(std::cin, line); stringstream stream(line); stream >> i; } 
#define LINE { string line; getline(std::cin, line); } 

#define INT_LINE_SINGLE(i) int i; { string line; getline(std::cin, line); stringstream stream(line); stream >> i; } 
#define INT_LINE_LIST(v) vector<int> v; { string line; getline(std::cin, line); stringstream stream(line); int n; while(stream >> n) { v.push_back(n); } }
#define INT_LINE_LIST_N(v, n) vector<long long> v; { string line; getline(std::cin, line); stringstream stream(line); long long i, x = 0; while(x++ < n && stream >> i) { v.push_back(i); } }

#define PI 3.14

using namespace std;

void process(int c, long long r, long long t);

int main(void) {
	INT_LINE_SINGLE(cases);

	for(int c = 0; c < cases; c++){
		INT_LINE_LIST_N(info, 2);

		process(c + 1, info[0], info[1]);
	}

	return 0;
}

// r is the seperation of the circles
// t is the millilitres of paint
void process(int c, long long r, long long t)
{
	long long x = 0;

	long long cr = r;
	while(true) {
		// (cr + 1) ^ 2 - cr ^ 2
		long long areaOfRing = (cr << 1) + 1;

		t -= areaOfRing;
		if(t < 0) break;

		cr += 2;
		x++;
	}

	printf("Case #%i: %lu\n", c, x);
}