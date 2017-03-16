#define _SCL_SECURE_NO_WARNINGS 
#define _CRT_SECURE_NO_WARNINGS 

#include <cstdio>
#include <string>
#include <algorithm>

int main()
{
	int T;
	scanf("%d", &T);
	for (int cs = 1; cs <= T; ++cs)
	{
		char str[1024];
		scanf("%s", str);
		int n = strlen(str);
		std::string ans = "";
		for (int i = 0; i < n; ++i)
		{
			std::string a = str[i] + ans, b = ans + str[i];
			ans = std::max(a, b);
		}
		printf("Case #%d: %s\n", cs, ans.c_str());
	}
	return 0;
}