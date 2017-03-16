#include<iostream>
#include<cstdio>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    int N, M;// size
    int lawn[100][100];// lawn
    cin >> TIME;
    for (int t = 0 ; t < TIME; t++) {
	answer = 1;
	cin >> N >> M;
	for (int i = 0 ; i < N; ++i) {
	    for (int j = 0 ; j < M; ++j) {
		cin >> lawn[i][j];
	    }
	}
	int test_x, test_y;
	for (int i = 0 ; i < N; ++i) {
	    for (int j = 0 ; j < M; ++j) {
		test_x = test_y = 1;
		for (int x = i ; x >=0; --x) {
		    if (lawn[i][j] < lawn[x][j]) {test_x = 0; break;}
		}
		for (int x = i ; x < N; ++x) {
		    if (lawn[i][j] < lawn[x][j]) {test_x = 0; break;}
		}
		for (int y = j ; y >=0; --y) {
		    if (lawn[i][j] < lawn[i][y]) {test_y = 0; break;}
		}
		for (int y = j ; y < M; ++y) {
		    if (lawn[i][j] < lawn[i][y]) {test_y = 0; break;}
		}
		if (test_x == 0 && test_y == 0) break;
	    }
	    if (test_x == 0 && test_y == 0) break;
	}
	if (test_x == 0 && test_y == 0) answer = 0;;

	//output
	printf("Case #%d: %s\n",t+1, (answer==1)?"YES":"NO");
    }
    return 0;
}
