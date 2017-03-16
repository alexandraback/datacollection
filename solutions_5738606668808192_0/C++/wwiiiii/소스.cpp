#include <cstdio>
#include <vector>
using namespace std;
vector< pair<int, vector<long long int> > > answer;
void dec2bin(long long int);

int num, len;

long long int isPrime(long long int n, int base)//if prime, return -1, else, return divisor, n is 1010111011
{
	long long int target = 0;
	long long int t = 1;
	while (n > 0)
	{
		target += t * (n % 2);
		t *= base;
		n /= 2;
	}
	
	for (long long int i = 3; i*i <= target; i += 2)
	{
		if (i == 1 || i == target) continue;
		if (target%i == 0) return i;
	}
	return -1;
}

void solve()
{
	long long int start = (1 << (len - 1)) + 1;
	long long int end = (1 << len) - 1;
	for (long long int i = start; i <= end; i += 2)
	{
		vector<long long int> divs;
		divs.clear();
		for (int j = 2; j <= 10; j++)
		{
			long long int div = isPrime(i, j);
			if (div == -1) break;
			else divs.push_back(div);
		}
		if (divs.size() == 9) answer.push_back(make_pair(i, divs));
		if (answer.size() == num) break;
	}
}

void input()
{
	scanf("%d %d", &len, &num);
}

void dec2bin(long long int n)
{
	//freopen("coinjam.txt", "w", stdout);
	vector<int> res;
	while (n > 0)
	{
		res.push_back(n % 2);
		n /= 2;
	}
	reverse(res.begin(), res.end());
	for (auto i : res) printf("%d", i);
}

void output(int casen)
{
//	freopen("coinjam.txt", "w", stdout);
	printf("Case #%d:\n", casen);
	for (int i = 0; i < answer.size(); i++)
	{
		//printf("%d ", answer[i].first);
		dec2bin(answer[i].first);
		printf(" ");
		auto res = answer[i].second;
		for (int j = 0; j < res.size(); j++)printf("%lld ", res[j]);
		if (i != answer.size() - 1)puts("");
	}
}

int main()
{
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("coinjamreal.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		answer.clear();
		input();
		solve();
		output(i);
	}
}