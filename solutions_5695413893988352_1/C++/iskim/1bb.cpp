#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

char str1[20], str2[20];
int len;

pair<long long, long long> ans{ 0x7fFFffFFffFFffFF, 0 };
pair<string, string> ans2;

bool makesame()
{
	for (int i = 0; i < len; i++)
	{
		if (str1[i] != '?' && str2[i] != '?' && str1[i] != str2[i]) return false;
	}

	for (int i = 0; i < len; i++)
	{
		if (str1[i] == '?' && str2[i] == '?') str1[i] = '0';
		else if (str1[i] == '?') str1[i] = str2[i];
	}

	printf("%s %s\n", str1, str1);

	return true;
}

void makegreat(bool ssss=false)
{
	for (int i = 0; i < len; i++)
	{
		if (str1[i] == '?')
		{
			if (str2[i] != '9') break;
			continue;
		}
		if (str2[i] == '?')
		{
			if (str1[i] != '0') break;
			continue;
		}
		if (str1[i] > str2[i]) break;
		if (str1[i] < str2[i]) return;
	}

	vector<int> lastdiff;
	// lastdiff: 달라지게 해야만 하는 마지막 자리의 위치의 모음

	for (int i = 0; i < len; i++)
	{
		if (str1[i] == '?')
		{
			if (str2[i] != '9') lastdiff.push_back(i);
			continue;
		}
		if (str2[i] == '?')
		{
			if (str1[i] != '0') lastdiff.push_back(i);
			continue;
		}
		if (str1[i] > str2[i])
		{
			lastdiff.push_back(i);
			break;
		}
		else if (str1[i] < str2[i])
		{
			break;
		}
	}

	for (int diff : lastdiff)
	{
		string s1, s2;
		for (int i = 0; i < len; i++)
		{
			if (i < diff)
			{
				if (str1[i] == '?' && str2[i] == '?') s1.push_back('0'), s2.push_back('0');
				else if (str1[i] == '?') s1.push_back(str2[i]), s2.push_back(str2[i]);
				else s1.push_back(str1[i]), s2.push_back(str1[i]);
			}
			else if (i == diff)
			{
				if (str1[i] == '?' && str2[i] == '?') s1.push_back('1'), s2.push_back('0');
				else if (str1[i] == '?') s1.push_back(str2[i] + 1), s2.push_back(str2[i]);
				else if (str2[i] == '?') s1.push_back(str1[i]), s2.push_back(str1[i] - 1);
				else s1.push_back(str1[i]), s2.push_back(str2[i]);
			}
			else
			{
				s1.push_back(str1[i] == '?' ? '0' : str1[i]);
				s2.push_back(str2[i] == '?' ? '9' : str2[i]);
			}
		}

		if (ssss) swap(s1, s2);
		long long aa = stoll(s1), bb = stoll(s2);

		if (abs(ans.first - ans.second) < abs(aa - bb)) continue;
		if (abs(ans.first - ans.second) == abs(aa - bb))
		{
			if (ans.first < aa) continue;
			if (ans.first == aa&&ans.second < bb) continue;
		}
		ans = { aa,bb };
		ans2 = { s1,s2 };
	}
}

void makeless()
{
	char tmp[20];memcpy(tmp, str1, 20);memcpy(str1, str2, 20);memcpy(str2, tmp, 20);
	makegreat(true);
}

int main()
{
	freopen(R"(C:\Users\Unused\Downloads\B-large.in)", "r", stdin);
	freopen(R"(C:\Users\Unused\Downloads\B-large.out)", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		ans={ 0x7fFFffFFffFFffFF, 0 };
		printf("Case #%d: ", tt);
		scanf("%s%s", str1, str2);
		len = strlen(str1);

		if (makesame()) continue;
		makegreat();
		makeless();

		printf("%s %s\n", ans2.first.c_str(), ans2.second.c_str());
	}
}