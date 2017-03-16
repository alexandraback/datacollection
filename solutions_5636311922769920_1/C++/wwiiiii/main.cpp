/*
일단 C * S < K면 impossible
C * S >= K면 잘해보자 ㅎㅎ
*/
#include <cstdio>
#include <vector>

using namespace std;
vector<long long int> answer;

int k, c, s;
long long int finlen;
void input()
{
	scanf("%d %d %d", &k, &c, &s);
}

long long int indexOf(vector<int> seq)
{
	long long int index=1;
	long long int step = finlen;
	int seqsize = seq.size();
	for (int i = 0; i < seqsize; i++)
	{
		step /= k;
		index += step*(seq[i] - 1);
	}
	return index;
}

void solve()
{
	answer.clear();
	if (c * s < k) return;
	finlen = 1; for (int i = 0; i < c; i++)finlen *= k;
	int arrlen = k / c;

	if (c >= k)
	{
		vector<int> next;
		for (int j = 1; j <= k; j++) next.push_back(j);
		auto res = indexOf(next);
		answer.push_back(res);
		return;
	}

	for (int i = 0; i < arrlen; i++)
	{
		vector<int> next;
		for (int j = 1; j <= c; j++) next.push_back(i*c + j);
		auto res = indexOf(next);
		answer.push_back(res);
	}
	if (k%c != 0)
	{
		vector<int> next;
		for (int i = k - c + 1; i <= k; i++) next.push_back(i);
		auto res = indexOf(next);
		answer.push_back(res);
	}
}

void output(int casen)
{
	printf("Case #%d: ", casen);
	if (answer.empty() || (answer.size() > s))
	{
		puts("IMPOSSIBLE"); return;
	}
	//if (answer.size() > s) puts("ERRORRRRRRRRRrr");
	for (auto i : answer) printf("%lld ", i);
	puts("");
}

int main()
{
	freopen("D-large.in", "r", stdin);
	freopen("fract.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		input();
		solve();
		output(i);
	}
}