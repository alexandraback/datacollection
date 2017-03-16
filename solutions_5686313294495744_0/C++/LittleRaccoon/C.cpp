#include <stdio.h>
#include <string.h>

#include <string>
#include <map>

using namespace std;

int N;
char TopicA[17][21], TopicB[17][21];
bool marker[17];
map<string, int> mA, mB;

int max(int a, int b)
{
	return a < b? b: a;
}

bool test()
{
	for (int i = 0; i < N; i++) {
		if (marker[i]) continue;
		if (mA[TopicA[i]] > 0 && mB[TopicB[i]] > 0) 
			continue;
		return false;
	}

	return true;
}

int solve(int t, int cnt)
{
	int my, mf;

	if (t >= N) {
		if (test()) 
			return cnt;
		return -1;
	}

	marker[t] = 0;
	mf = solve(t + 1, cnt + 1);

	marker[t] = 1;
	mA[TopicA[t]] += 1;
	mB[TopicB[t]] += 1;
	my = solve(t + 1, cnt);
	mA[TopicA[t]] -= 1;
	mB[TopicB[t]] -= 1;

	return max(mf, my);
}

int main()
{
	int T; 
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) 
			scanf("%s%s", TopicA[i], TopicB[i]);

		mA.clear();
		mB.clear();
		printf("Case #%d: %d\n", t, solve(0, 0));
	}

	return 0;
}

