
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int moto[200];

int play(int me, int pos, int top)
{
	if (pos == N) return 0;

	if (me > moto[pos])
	{
		return play(me + moto[pos], pos+1, top);
	} else
	{
		int steps = 0;
		int me2 = me;

		while (steps < top && me2 <= moto[pos])
		{
			me2 = me2 + me2 - 1;
			steps++;
		}

		if (me2 <= moto[pos]) return N-pos;

		steps += play(me2 + moto[pos], pos+1, top-steps);
		return (steps < N-pos) ? steps : N-pos;
	}
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int a;

		cin >> a >> N;

		for (int i = 0; i < N; i++) cin >> moto[i];
		sort(moto, moto+N);

		cout << "Case #" << t << ": ";

		cout << play(a, 0, N) << endl;
	}
	return 0;
}

