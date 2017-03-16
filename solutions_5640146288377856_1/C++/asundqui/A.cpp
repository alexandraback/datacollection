#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int R, C, W;
		cin >> R >> C >> W;

		int first_hit = C / W;
		int score = first_hit*R + (W - 1);
		if ((first_hit * W) < C)
			++score;
		cout << "Case #" << case_num << ": " << score<< endl;
	}
	return 0;
}