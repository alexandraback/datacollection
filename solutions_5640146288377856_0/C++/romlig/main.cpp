#include <iostream>
#include <cmath>

using namespace std;

int solve(){
	float R, C, W;
	cin >> R >> C >> W;

	return (R - 1)*ceil(C / W) + ceil((C-W) / W) + W;
}

int main(){
	int T;
	cin >> T;

	for (int i = 0; i < T; i++){
		cout << "Case #" << i + 1 << ": " << solve() << "\n";
	}

	cout << flush;

	return 0;
}