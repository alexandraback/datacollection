#include <iostream>
using namespace std;

int f(int R, int C, int W)
{
	int miss = R * (C / W) - 1;
	return miss + W + (W > 1 && C % W);
}

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for(int u = 1; u <= T; ++u)
	{
		int R, C, W;
		cin >> R >> C >> W;

		int a = f(R, C, W);
		
		cout << "Case #" << u << ": " << a << endl;
	}
	return 0;
}