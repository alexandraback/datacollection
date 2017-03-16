#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>

using namespace std;

int main(){
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++){
		int smax;
		cin >> smax;
		int currentPeople = 0;
		int required = 0;
		for (int j = 0; j <= smax; j++){
			char tmp;
			cin >> tmp;
			int people = (tmp - '0');
			required = max(required, (j - currentPeople));
			currentPeople += people;
		}
		cout << "Case #" << (i + 1) << ": " << required << endl;
	}
}
