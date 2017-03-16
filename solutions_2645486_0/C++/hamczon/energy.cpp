#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>
using namespace std;

int max_score(int e, int r, int n, int v[]) {
	int ret = 0;
	
	int **c = new int*[n];
	for(int i = 0; i < n; ++i)
		c[i] = new int[e+1];
	
	for(int i = n-1; i >= 0; --i) {
		for(int j = 0; j <= e; ++j) {
			if(i == n-1)
				c[i][j] = j * v[i];
			else {
				int max = 0;
				for(int k = 0; k <= j; ++k) {
					int m = j - k + r > e ? e : j - k + r;
					int tmp = k * v[i] + c[i+1][m];
					if(tmp > max) max = tmp;
				}
				c[i][j] = max;
			}
		}
	}
	
	ret = c[0][e];

	for(int i = 0; i < n; ++i) delete[] c[i];
	delete[] c;

	return ret;
}

int main(int argc, char **argv) {
    ifstream input(argv[1], ios::in);
    ofstream output("output.txt", ios::out);

    int T;
    input>>T;
	
	int v[10000];    
    for(int i = 1; i <= T; ++i) {
        int e, r, n;
		input>>e>>r>>n;

		for(int j = 0; j < n; ++j)
			input>>v[j];
		
        output<<"Case #"<<i<<": "<<max_score(e, r, n, v)<<endl;
    }

    return 0;
}
