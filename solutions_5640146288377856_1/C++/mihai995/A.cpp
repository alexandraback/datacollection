#include <iostream>
using namespace std;

int compute(int R, int C, int W){
	return R * ( (C + W - 1) / W ) + W - 1;
}

int main(){
	int times, R, C, W;
	cin >> times;
	for (int nr = 1; nr <= times; nr++){
		cin >> R >> C >> W;
		cout << "Case #" << nr << ": " << compute(R, C, W) << '\n';
	}
	return 0;
}
