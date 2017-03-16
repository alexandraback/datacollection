#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

fstream in, out;

int t, n, a;
vector<int> sizes;

int num_add(int largest, int current) {
	int ret = 0;
	int curr = current;
	if (current == 1) {
		return -1;
	}
	while (curr <= largest) {
		ret++;
		curr += curr - 1;
	}
	return ret;
}

int increase(int current, int times) {
	int ret = current;
	for (int i = 0; i < times; i++) {
		ret += ret - 1;
	}
	return ret;
}

int main() {
	in.open("A-large.in", fstream::in);
	out.open("proba-large.out", fstream::out);

	in >> t;
    for (int i = 0; i < t; i++) {
		sizes.clear();
		in >> a >> n;
		for (int j = 0; j < n; j++) {
			int mote;
			in >> mote;
			sizes.push_back(mote);
		}

		sort(sizes.begin(), sizes.end());
		reverse(sizes.begin(), sizes.end());

		int num_left = n;
		int curr_mote = a;



		while (num_left > 0 && curr_mote > sizes[num_left - 1]) {
			curr_mote += sizes[num_left - 1];
			num_left--;
		}

		int ans = num_left;
		
		int ops = 0;
		while (num_left > 0) {


	
			int factor = num_add(sizes[num_left - 1], curr_mote);
			if (factor == -1) {
				break;
			}
			ops += factor;
			curr_mote = increase(curr_mote, factor);
			while (num_left > 0 && curr_mote > sizes[num_left - 1]) {
				curr_mote += sizes[num_left - 1];
				num_left--;
			}
			
			if (ops + num_left < ans) {
				ans = ops + num_left;
			}
		}

		out << "Case #" << i + 1 << ": " << ans << endl;
	}
    
	in.close();
	out.close();

	return 0;
}
