#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <list>
#include <map>
#include <deque>
#include <fstream>
#include <string>
using namespace std;

int arr[20];
int N;
int state;
int sum;
int tempSum;
bool visited[20];
vector<int> states1, states2;

void getInput();
void getResult();

void printResult(int state1, int state2) {
	states1.clear();
	states2.clear();

	int index = 0;
	while (state1 > 0) {
		if (state1 & 1)
			states1.push_back(index);
		state1 >>= 1;
		index++;
	}

	index = 0;
	while (state2 > 0) {
		if (state2 & 1)
			states2.push_back(index);
		state2 >>= 1;
		index++;
	}

	cout << arr[states1[0]];
	for (int i = 1; i < states1.size(); i++)
		cout << ' ' << arr[states1[i]];
	cout << endl;

	cout << arr[states2[0]];
	for (int i = 1; i < states2.size(); i++)
		cout << ' ' << arr[states2[i]];
	cout << endl;
}

bool getState(int n) {
	if (tempSum > sum)
		return false;
	if (tempSum == sum)
		return true;

	if (n < 0)
		return false;

	if (visited[n])
		return getState(n - 1);

	if (getState(n - 1))
		return true;

	tempSum += arr[n];
	state += (1<<n);
	if (getState(n - 1))
		return true;

	tempSum -= arr[n];
	state -= (1<<n);
	return false;
}

bool getState() {
	state = 0;
	tempSum = 0;
	return getState(N - 1);
}

bool isValid(int n) {
	sum = 0;
	memset(visited, 0, sizeof(visited));
	
	int index = 0;
	while (n > 0) {
		if (n & 1) {
			visited[index] = true;
			sum += arr[index];
		}

		n >>= 1;
		
		index++;
	}

	return getState();
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin); freopen("c-small0.out", "w", stdout);
	//freopen("C-small-attempt1.in", "r", stdin); freopen("c-small1.out", "w", stdout);
	//freopen("C-small-attempt2.in", "r", stdin); freopen("c-small2.out", "w", stdout);
	//freopen("C-small-attempt3.in", "r", stdin); freopen("c-small3.out", "w", stdout);
	//freopen("C-large.in", "r", stdin); freopen("c-large.out", "w", stdout);

	int cases;
	cin >> cases;
	cin.ignore();
	for (int cnt = 1; cnt <= cases; cnt++) {
		getInput();
		cout << "Case #" << cnt << ":" << endl;
		getResult();
	}

	return 0;
}

void getInput() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

void getResult() {
	sort(arr, arr + N);

	for (int i = 1; i < (1<<(N - 1)); i++) {
		if (isValid(i)) {
			printResult(i, state);
			return;
		}
	}

	cout << "Impossible" << endl;
}
