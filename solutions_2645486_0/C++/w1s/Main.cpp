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
#define INT_LINE_LIST_N(v, n) vector<int> v; { string line; getline(std::cin, line); stringstream stream(line); int i, x = 0; while(x++ < n && stream >> i) { v.push_back(i); } }

using namespace std;

void process(int c, int e, int r, vector<int> v);

int main(void) {
	INT_LINE_SINGLE(cases);

	for(int c = 0; c < cases; c++){
		INT_LINE_LIST_N(l1, 3)
			INT_LINE_LIST(l2);

		process(c + 1, l1[0], l1[1], l2);
	}

	return 0;
}

int test(int maxe, int e, int r, vector<int> v){
	if(v.size() == 1) {
		return e * v[0];
	}

	int vi = v[0];

	bool isMax = *max_element(v.begin(), v.end()) == vi;

	int spend = 0, newx = 0, newe = 0;

	// check futures to see if not doing anything is better
	for(int q = 1; q < v.size(); q++) {
		for(int s = 0; s <= e; s++) {

			int teste = max(min(e - s + r, maxe), 0);
			int testx = (s * v[0]) + test(maxe, teste, r, vector<int>(v.begin() + q, v.end()));

			if(testx > newx) {
				spend = s;
				newe = teste;
				newx = testx;
			}
		}
	}

	e = newe;

	return newx;
}

void process(int c, int e, int r, vector<int> v)
{
	int x = test(e, e, r, v);

	printf("Case #%i: %i\n", c, x);
}