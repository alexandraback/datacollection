#include <iostream>
#include <inttypes.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++){
		int64_t R, C, W;
		cin >> R;
		cin >> C;
		cin >> W;
		int64_t y;
		if (C%W)
			y=R*(C / W) + W;
		else
			y = R*(C / W) -1 + W;
		cout << "Case #" << t << ": "<< y<<endl;

	}
}