#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

string target;
char arr[100];
double avRes;
int maxB;
int k, l, s;

void dfs(int pos, double p, string str)
{
	if (pos == s)
	{
		int appNum = 0;
		for(int i = 0;i < str.size();i++)
		{
			int j;
			for(j = i;j < str.size() && j - i < target.size();j++)
				if (str[j] != target[j - i])
					break;
			if (j - i >= target.size())
				appNum++;
		}
		maxB = max(maxB, appNum);
		avRes += p * appNum;
		return;
	}

	for(int i = 0;i < k;i++)
	{
		dfs(pos + 1, p * 1.0 / k, str + arr[i]);
	}

}

int main()
{
	int ncase;
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	cin >> ncase;

	for(int icase = 0;icase < ncase;icase++)
	{
		cin >> k >> l >> s;
		for(int i = 0;i < k;i++)
			cin >> arr[i];
		cin >> target;

		avRes = 0;
		maxB = 0;
		dfs(0, 1, "");
		printf("Case #%d: %.7lf\n", icase + 1, maxB - avRes);
	}

	return 0;
}

