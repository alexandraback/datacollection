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
#include <strings.h>

using namespace std;

int solution[1000001];

int invert(int n){
	int inverted = 0;
	while(n != 0){
		inverted *= 10;
		inverted += (n % 10);
		n = n / 10;
	}
	return inverted;
}

void calculateAll(){
	bool solved[1000001];
	bzero(solved, sizeof(solved));
	solution[0] = 0;
	solution[1] = 1;
	queue< pair<int, int> > pending;
	pending.push(make_pair(1, 1));
	solved[1] = true;
	solved[0] = true;
	while(pending.size()){
		int next = pending.front().first;
		int cost = pending.front().second;
		pending.pop();
		int n1 = next + 1;
		if ((n1 <= 1000000) && (!solved[n1])){
			solution[n1] = cost + 1;
			solved[n1] = true;
			pending.push(make_pair(n1, cost + 1));
		}
		int n2 = invert(next);
		if ((n2 <= 1000000) && (!solved[n2])){
			solution[n2] = cost + 1;
			solved[n2] = true;
			pending.push(make_pair(n2, cost + 1));
		}
	}
}

int main(){
	int tests;
	cin >> tests;
	calculateAll();
	for (int t = 0; t < tests; t++){
		int N;
		cin >> N;
		cout << "Case #" << (t+1) << ": " << solution[N] << endl;
	}
}
