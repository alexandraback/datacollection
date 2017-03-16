#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef long long ll;

using namespace std;

void solveCase()
{
	int R, C, W;
	cin >> R >> C >> W;
	int s = 0;
	int score = 0;
	for (int r = 0; r < R; r++)
	{
		for (int c = W - 1; c < C; c+=W)
		{
			s++;
			int a = W;
			if (c == C - 1)
				a--;
			score = MAX(score, s + a);
		}
	}
	cout << score;
}

int main()
{
	int cases;
	cin >> cases;
	for (int c = 0; c < cases; c++)
	{
		cout << "Case #" << c + 1 << ": ";
		solveCase();
		cout << endl;
	}
}