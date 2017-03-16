#include <cstdio>
#include <string>

using namespace std;

void Open() {
	freopen ("input.dat", "r", stdin);
	freopen ("output.dat", "w", stdout);
}

void Close() {
	fclose(stdin);
	fclose(stdout);
}

int FinishCase() {
	int N, S, P;
	int ans = 0;
	scanf ("%d %d %d", &N, &S, &P);
	for (int i = 0; i < N; i++) {
		int score;
		scanf ("%d", &score);
		int maxscore;
		if (score > 0) 
			maxscore = (score + 2) / 3;
		else
			maxscore = 0;
		if (maxscore >= P) ans++;
		else {
			if (score > 1)
				maxscore = (score + 4) / 3;
			else
				maxscore = score;
			if (maxscore >= P && S > 0)
				ans++, S--;
		}
	}
	return ans;
}

int main() {
	int T;
	Open();
	scanf ("%d\n", &T);
	for (int i = 0; i < T; i++)
	{
		int ans = FinishCase();
		printf ("Case #%d: %d\n", i + 1, ans);
	}
	Close();
	return 0;
}