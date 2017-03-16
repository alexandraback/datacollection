#if 0==0

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main()
{

#define SMALL 1

#ifdef SMALL
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
#else
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
#endif

	int i_numCases;
	scanf("%d", &i_numCases);

	char str[2000];
	gets(str);

	for (int i_case = 1 ; i_case <= i_numCases ; i_case++)
	{
		printf("Case #%d: ", i_case);
	
		int d = 0;

		string ans = "";

		gets(str);

		ans.push_back(str[0]);

		for (int i = 1 ; i < strlen(str) ; i++)
		{
			if (str[i] < 'A' || str[i] > 'Z') break;
			if (str[i] < ans[0]) ans.push_back(str[i]); else 
			{
				string t("");
				t.push_back(str[i]);
				ans = t + ans;
			}
		}

		printf("%s\n", ans.c_str());
	}

	return 0;
}

#endif