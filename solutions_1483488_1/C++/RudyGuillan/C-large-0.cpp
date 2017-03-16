#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int solve(int start, int end) {
	int n = 0;
	int n_digits = 1;
	int tmp_start = start;
	int min_with_digits = 1;
	tmp_start /= 10;
	while(tmp_start) {
		tmp_start /= 10;
		n_digits++;
		min_with_digits *= 10;
	}
	int previous[8];
	for(int current = start; current <= end; current++) {
		int recycled = current;
		for(int i=1; i<n_digits; i++) {
			previous[i-1] = 0;
			int buf = recycled % 10;
			recycled /= 10;
			recycled += min_with_digits * buf;
			if(recycled > current && recycled <= end) {
				bool repeated = false;
				for(int j=0; j<i-1; j++) {
					if(previous[j] == recycled) {
						repeated = true;
						break;
					}
				}		
				if(!repeated) {
					n++;
					previous[i-1] = recycled;
				}
			}
		}
	}
	return n;
}

int main() {
	string input_line;
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		int start, end;
		cin >> start >> end;
		cout << "Case #" << i << ": " << solve(start, end) << endl;
	}
	return 0;
}