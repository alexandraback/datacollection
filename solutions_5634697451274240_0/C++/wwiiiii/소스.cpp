#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool isproper(vector<char> cont)
{
	for (int i = 0; i < cont.size(); i++)if (cont[i] == '-') return false;
	return true;
}

void flip(int k, vector<char>& cont)
{
	reverse(cont.begin(), cont.begin() + k);
	for (int i = 0; i < k; i++)
	{
		if (cont[i] == '+') cont[i] = '-';
		else if (cont[i] == '-') cont[i] = '+';
	}
}

bool isMethodAnswer(vector<char> original, vector<int> method)
{
	auto temp = original;
	for (auto i : method)
	{
		flip(i, temp);
	}
	return isproper(temp);
}

vector<char> input()
{
	char str[110];
	vector<char> original;
	scanf("%s\n", str);
	int size = strlen(str);// -1;
	while (str[size-1] == '+') size--;
	for (int i = 0; i < size; i++)original.push_back(str[i]);
	return original;
}

int solve(vector<char> original)
{
	if (original.size() == 0) return 0;
	int res = 1;
	char now = original[0];
	for (int i = 1; i < original.size(); i++)
	{
		if (now != original[i])
		{
			res++; now = original[i];
		}
	}
	return res;
}

void output(int casen, int ans)
{
	printf("Case #%d: %d\n", casen, ans);
}

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("cake.txt", "w", stdout);
	int t; scanf("%d\n", &t);
	for (int i = 1; i <= t; i++)
	{
		auto arg = input();
		auto res = solve(arg);
		output(i, res);
	}
}