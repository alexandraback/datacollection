#include <iostream>
using namespace std;

void logic(){
	int R, C, W;
	cin >> R >> C >> W;
	int cnt = 0;
	if (R > 2){
		if (W>C / 2)cnt += R - 1;
		else cnt += (R - 1) * 2;
	}
	if (R == 2)
		cnt += C/W;
	cnt += C / W;
	if (C%W != 0) cnt++;
	cnt += W - 1;
	cout << cnt << endl;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i<T; i++){
		cout << "Case #" << i + 1 << ": ";
		logic();
	}
}