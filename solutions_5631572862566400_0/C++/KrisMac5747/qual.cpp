#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <list>
using namespace std;
void print_seen(vector<bool>& seen) {
	for (int i = 0 ; i< seen.size(); ++i) {
		cout << seen[i] << " ";
	}
	cout << endl;
}
int add_kid(int d, int N, vector<int>& friends, vector<bool>& seen, int front, int back) {
	int largest_d = d;
	for (int i = 0; i < N; ++i) {
		if (seen[i]) {
			continue;
		}
		if (friends[i] == front){
			seen[i] = true;
			int left = add_kid(d+1, N, friends, seen, i, back);
			largest_d = max(largest_d, left);
			seen[i] = false;
		}
		if (friends[i] == back) {
			seen[i] = true;
			int right = add_kid(d+1, N, friends, seen, front, i);
			largest_d = max(largest_d, right);
			seen[i] = false;
		}
	}
	return largest_d;
}
int main() {
	fstream fin;
	fin.open("input.txt");
	int cases = 0;
	fin >> cases;
	for (int rnd = 0; rnd < cases; ++rnd) {
		// Do each case here
		int N;
		fin >> N;
		vector<int> friends(N);
		for (int i = 0; i < N; ++i) {
			int num;
			fin >> num;
			friends[i] = num - 1;
		}
		int count = 0;
		vector<bool> visit(N, true);
		list<int> circle;
		for (int start = 0; start < N; ++start) {

			if (!visit[start]) {
				continue;
			}
			vector<bool> seen(N, false);
			int curr_count = 1;
			int loc = friends[start];
			seen[start] = true;
			int prev = start;
			bool closed = false;
			// cout << "*******" << endl;
			while(!seen[loc]) {
				// cout << "Loc = " << loc << endl;
				// print_seen(seen);
				// cout << "Loc: " << loc+1 << ", Prev: " << prev+1 << endl;
				if (prev == friends[loc]) {
					// cout << " Closed!" << endl;
					closed = true;
				}
				seen[loc] = true;
				prev = loc;
				loc = friends[loc];
				curr_count++;
			}
			if (closed) {
				// cout << "Checking Adds: count: " << curr_count << ", front: " << start+1 << ", back: " << prev+1 << endl;
				int add_num = add_kid(0, N, friends, seen, start, prev);
				// cout << "Added: " << add_num << endl;
				count = max(count, curr_count + add_num);
				for (int k = 0; k < N; ++k) {
					if (seen[k]) {
						visit[k] = false;
					}
				}
			}
			// cout << endl;
			// print_seen(seen);
			if (loc == start) { // cycle
				// cout << "Cycle of size " << curr_count << endl;
				// print_seen(seen);
				count = max(count, curr_count);
				for (int k = 0; k < N; ++k) {
					if (seen[k]) {
						visit[k] = false;
					}
				}
			}
		}
		cout << "Case #" << rnd+1 << ": " << count << endl;
	}
	fin.close();
	return 0;
}