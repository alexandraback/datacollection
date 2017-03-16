#include <iostream>
using namespace std;


int d[101][101];
int r, c;


void remove_num(int num) {
    for (int i=0; i<r; ++i) {
	for (int j=0; j<c; ++j) {
	    if (d[i][j] == num) {
		// check row
		bool same_val = true;
		for (int p=0; p<c && same_val; ++p) {
		    same_val = (d[i][p] == num || d[i][p] == 0);
		}
		if (same_val) {
		    for (int p=0; p<c && same_val; ++p) {
			d[i][p] = 0;
		    }
		}

		same_val = true;
		for (int p=0; p<r && same_val; ++p) {
		    same_val = (d[p][j] == num || d[p][j] == 0);
		}
		if (same_val) {
		    for (int p=0; p<r; ++p) {
			d[p][j] = 0;
		    }
		}
	    }
	}
    }
}

int main() {

    int n;
    cin >> n;
    for (int test=1; test<=n; ++test) {
	cin >> r >> c;
	cout << "Case #" << test << ": ";

	for (int i=0; i<r; ++i) for (int j=0; j<c; ++j) cin >> d[i][j];

	int min = 1;
	int max = 100;
	for (int i=min; i<=max; ++i)
	    remove_num(i);

	int result = 0;
	for (int i=0; i<r; ++i) for (int j=0; j<c; ++j) if (d[i][j] != 0) result++;
	if (result == 0) {
	    cout << "YES" << endl;
	}
	else {
	    cout << "NO" << endl;
	}
    }
}


